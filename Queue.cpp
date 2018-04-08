#include <iostream>

#define ElementType int

using namespace std;
#define MaxSize 10
struct Queue1
{
    ElementType Data[MaxSize];
    int rear;
    int front;//head
};
typedef struct Queue1 *Queue;
class QueueSequence
{
    private:
        bool IsFull(Queue Q)
        {
            if (Q->rear == MaxSize)
                return true;
            else
                return false;
        }
        bool IsEmpty(Queue Q)
        {
            if (Q->rear == Q->front)
                return true;
            else
                return false;
        }

    public:
        Queue *Creat(Queue &Q)
        {
            Q = new int[12];
            Q->rear = 0;
            Q->front = 0;
            getchar();
            return &Q;
        }

        void Add(Queue Q)
        {
            if (IsFull(Q) == true)
            {
                cout << "Full" << '\n';
                return;
            }
            else
                {
                    cin >> Q->Data[Q->rear];
                    (Q->rear)++;
                }
            getchar();
        }

        void Delete(Queue Q)
        {
            if (IsEmpty(Q) == true)
            {
                cout << "Empty" << '\n';
                return;
            }
            else
                cout << Q->Data[(Q->front)++] << endl;
            getchar();
        }

        void Output(Queue Q)
        {
            if (IsEmpty(Q) == true)
            {
                cout << "Empty" << '\n';
                getchar();
                getchar();
                return;
            }
            else
            {
                for(int co = Q->front; co < Q->rear; co++)
                {
                    cout << co << " " << Q->Data[co] << '\n';
                }
                getchar();
            }
            getchar();
        }
};
int main()
{
    QueueSequence q;
    Queue Q;
    int op = -1;
    while(op != 0)
    {
        system("cls");
        cout << "1-creat." << endl;
        cout << "2-add." << endl;
        cout << "3-delete." << endl;
        cout << "4-output" << endl;
        cout << "0-exit." << endl;
        cin >> op;
        switch (op)
        {
            case 0:
               return -1;
            case 1:
                {q.Creat(Q);
                break;}
            case 2:
               {q.Add(Q);
                break;} 
            case 3:
               {q.Delete(Q);
                break;} 
            case 4:
               {q.Output(Q);
                break;}  
            default:
                cout << "Wrong option.";
        }
    }
    
    

}
//creatqueue
//isfull q
//add q
//isempty q
//delete q