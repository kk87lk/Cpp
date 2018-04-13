#include <iostream>
#include <memory>

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
    StackList creat(int MaxSize)
    {
        StackList L = new struct SNode;
        L->Data = new ElementType[MaxSize];
        L->Top = -1;
        L->MaxSize = MaxSize;
        return L;
    }

    bool outputStack(StackList L)
    {
        if (CheckEmpty(L))
        {
            cout << "Empty stack!" << endl;
            return false;
        }
        int re = L->Top;
        for (; L->Top > -1; )
        {
            cout << "No." << L->Top + 1 << "is" << L->Data[--(L->Top)] << endl;
        }
        L->Top = re;
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
            L->Data[(L->Top)++] = X;
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
            return L->Data[--(L->Top)];
        }
    }
};
int  main()
{
    int se = 3;
    while (se == 3)
    {
        cout << "Input the function you want to choose:" << '\n';
        cin << se;
}