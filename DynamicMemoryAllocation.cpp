#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 512
typedef struct Node Node;
struct Node{
    int pid;//-1 == null
    int tag;//0 == unused 1 == used
    int location;
    int size;
    Node* front;
    Node* next;
};
Node *headpoint, *head, *tail;
void IntializeMemory(int size) {
	headpoint = (Node *)malloc(sizeof(Node));
    head = (Node *)malloc(sizeof(Node));
    tail = (Node *)malloc(sizeof(Node));
    headpoint->pid = -1; //4byte
    headpoint->tag = -1;//4byte
    headpoint->location = -1;//4byte
    headpoint->size = -1;//4byte
    headpoint->front = NULL;//8byte
    headpoint->next = head;//8byte
    head->pid = -1; //4byte
    head->tag = 0;//4byte
    head->location = 0;//4byte
    head->size = size;//4byte
    head->front = headpoint;//8byte
    head->next = tail;//8byte
    tail->pid = -1; //4byte
    tail->tag = -1;//4byte
    tail->location = -1;//4byte
    tail->size = -1;//4byte
    tail->front = head;//8byte
    tail->next = NULL;//8byte
}
Node* FindFreeSpace(int size){
    Node *newNode = (Node *)malloc(sizeof(Node));
    Node *tempNode = headpoint;
    while(tempNode)
        if(tempNode->size >= size && tempNode->tag == 0)
            break;
        else
            tempNode = tempNode->next;
    if(tempNode)
        return tempNode;
    else
        return NULL;
}
Node* FindNode(int pid){
    Node *tempNode = headpoint;
    while(tempNode)
        if(tempNode->pid == pid)
            return tempNode;
        else
            tempNode = tempNode->next;
    if(tempNode)
        return tempNode;
    else
        return NULL;
}
void Allocate(int pid, int size){
    Node *tempNode = FindFreeSpace(size);
    if(tempNode) {
        if(tempNode->size == size) {
            tempNode->pid = pid;
            tempNode->tag = 1;
        }else {
            Node *newNode = (Node *)malloc(sizeof(Node));
            newNode->pid = pid;
            newNode->tag = 1;
            newNode->size = size;
            tempNode->size -= size;
            newNode->location = tempNode->location;
            tempNode->location += size;
            newNode->front = tempNode->front;
            tempNode->front->next = newNode;
            newNode->next = tempNode;
            tempNode->front = newNode;
        }
        }else printf("空间不足\n");
    }
void Free(int pid) {
    Node *tempNode = FindNode(pid);
    if(tempNode) {
        if(tempNode->front->tag == 0 && tempNode->next->tag == 0) {
            tempNode->front->tag = 0;
            tempNode->front->pid = -1;
            tempNode->front->size += tempNode->size + tempNode->next->size;
            tempNode->front->next = tempNode->next->next;
            tempNode->next->next->front = tempNode->front;
        } else if(tempNode->front->tag == 0) {
            tempNode->front->tag = 0;
            tempNode->front->pid = -1;
            tempNode->front->size += tempNode->size;
            tempNode->next->front= tempNode->front;
            tempNode->front->next = tempNode->next;
        } else if(tempNode->next->tag == 0) {
            tempNode->tag = 0;
            tempNode->pid = -1;
            tempNode->size += tempNode->next->size;
            tempNode->next->next->front = tempNode;
            tempNode->next = tempNode->next->next;
        } else {
            tempNode->tag = 0;
            tempNode->pid = -1;
        }
    } else
        printf("无此进程");
}

void Display(){
    Node *node = headpoint->next;
    while(node->next){
        printf("pid:%d tag:%d location:%d size:%d ",node->pid,node->tag, node->location, node->size);
        printf("\n");
        node = node->next;
    }
    printf("\n");
}
int main(){
    int x = 0, pid = 0,size = 0;
    while(1){
        printf("1.初始化内存\n");
        printf("2.请求内存\n");
        printf("3.释放内存\n");
        printf("0.退出\n");
        printf("请选择:");
        scanf("%d", &x);
        switch (x){
        case 1 :
            printf("输入内存总量:");
            scanf("%d", &size);
            IntializeMemory(size);
            printf("内存列表:\n");
            Display();
            break;
        case 2:
            printf("输入pid与申请大小 空格隔开:");
            scanf("%d %d",&pid, &size);
            Allocate(pid, size);
            printf("内存列表:\n");
            Display();
            break;
        case 3:
            printf("输入你要释放的pid:");
            scanf("%d", &pid);
            Free(pid);
            printf("内存列表:\n");
            Display();
            break;
        case 0:
            printf("谢谢使用!\n");
            exit(1);
            break;
        }
    }
}