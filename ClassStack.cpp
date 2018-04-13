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
int main()
{
    Stack S;
    StackList s = NULL;
    int i = -1;
    while (i != 0)
    {
        system("cls");
        cout << "1--Creat one stacklist." << endl;
        cout << "2--Push stack." << endl;
        cout << "3--Pop stack&print." << endl;
        cout << "4--Print stack." << endl;
        cout << "0--Exit." << endl;
        cin >> i;
        switch(i)
        {
            case 1:
            {
                system("cls");
                int Size;
                cout << "Input how many elements you want to store into the Stack:";
                cin >> Size;
                s = S.creat(Size); //Maxsize == Size
                cout << "Successful created.";
                fflush(stdin);
                getchar();
                break;
            }
            case 2:
            {
                system("cls");
                ElementType m;
                cout << "Input the value you want to insert into the Stack:";
                cin >> m;
                S.Push(s, m); //Push Element-m into the Stack
                cout << "Successful inserted.";
                fflush(stdin);
                getchar();
                break;
            }
            case 3:
            {
                system("cls");
                ElementType value;
                value = S.Pop(s);//Print the top data
                cout << value << endl;
                cout << "Successful outputed.";
                fflush(stdin);
                getchar();
                break;
            }
            case 4:
            {
                system("cls");
                S.outputStack(s);
                cout << "Successful outputed.";
                fflush(stdin);
                getchar();
                break;
            }
            case 0:
            {
                return 0;
            }
            default:
                system("cls");
                cout << "Error option." << endl;
                fflush(stdin);
                getchar();
                break;
        }
    }
}
