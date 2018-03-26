#include <iostream>

using namespace std;

typedef int ElementType;

struct SNode
    {
      ElementType *Data;
      int MaxSize;
      int Top;
    };
typedef struct SNode *StackList;

class Stack
{   
private: 
    bool CheckFull(StackList L) 
    {
        return (L->Top == L->MaxSize - 1);
    }
    bool CheckEmpty(StackList L) 
    {
        return (L->Top == -1);
    }
public:
    static StackList creat(int MaxSize)
    {
        StackList L = (StackList)malloc(sizeof(struct SNode));
        L->Data = (ElementType *)malloc(MaxSize * sizeof(ElementType));
        L->Top = -1;
        L->MaxSize = MaxSize;
        return L;
    }

    bool Push(StackList L, ElementType X)
    {
        if (CheckFull(L))
        {
            cout << "Full" << endl;
            return false;
        }
        else
        {
            L->Data[++(L->Top)] = X;
            return true;
        }
    }

    ElementType Pop (StackList L)
    {
        if (CheckEmpty(L))
        {
            cout << "Empty" << endl;
            return 0;
        }
        else
        {
            return L->Data[(L->Top)--];
        }
    }
};
int main()
{
    Stack S;
    StackList s;
    s = S.creat(10);
    int i = 0;
    S.Push(s, 1);
    S.Push(s, 2);
    S.Push(s, 3);
    i = S.Pop(s);
    cout << i << endl;
    i = S.Pop(s);
    cout << i << endl;
}


















