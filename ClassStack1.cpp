#include <iostream>
#include <memory>

using namespace std;

struct SNode
    {
      int *Data;
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
    StackList creat()
    {
        StackList L = new struct SNode;
        L->Data = new int[1000];
        L->Top = -1;
        L->MaxSize = 1000;
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

    bool Push(StackList L, int X)
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

    int Pop (StackList L)
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

void tran1022(int num)
{
    Stack S;
    StackList s = NULL;
    s = S.creat();
    int Quotient = num, Remainder = -1;
    while (Quotient == 0)
    {   
        Remainder = Quotient % 2;
        S.Push(s, Remainder);
        Quotient = Quotient / 2;
    }
    cout << "The number " << num << " has been transformed into (";
    while (s->Top > -2)
    {
        cout << s->Data;
    }
    cout << ")B" << '\n';
}

void tran1028(int num)
{
    
}

int  main()
{
    int i = -1;
    while (i != 0)
    {
        system("cls");
        cout << "1--10 to 2." << endl;
        cout << "2--10 to 8." << endl;
        cout << "0--Exit." << endl;
        cin >> i;
        switch(i)
        {
            case 1:
            {
                system("cls");
                int num;
                cout << "Input the number:";
                cin >> num;
                tran1022(num);
                cout << "Successful transformed.";
                fflush(stdin);
                getchar();
                break;
            }
            case 2:
            {
                system("cls");
                int num;
                cout << "Input the number:";
                cin >> num;
                //function 8
                cout << "Successful transformed.";
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