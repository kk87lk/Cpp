#include <iostream>
#include <memory>

using namespace std;

struct SNode
    {
      char *Data;
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
        L->Data = new char[1000];
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

    bool Push(StackList L, char X)
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

    char Pop (StackList L)
    {
            return L->Data[--(L->Top)];
    }
};

bool judge(char st2[], char st1[])
{
    Stack S;
    StackList s = NULL;
    s = S.creat();
    char com;
    int c = 0;
    while(st2[c] != '@' && st2[c] != '\0')
    {
        S.Push(s, st2[c]);
        c++;
    }
    while(st1[c + 1] != '@')
    {
        com = S.Pop(s);
        if(com != st1[c + 1])
            return false;
        c++;
    }
    return true;
}

int main()
{
    cout << "Input the string:" ;
    char st[1000], st2[1000];
    cin >> st;
    int i = 0;
    for (;;)
    {
        if(st[i] == '#')
            break;
        st2[i] = st[i];
        i++;
    }
    st2[i] = '\0';
    int flag = judge(st2, st);
    if (flag == true)
        cout << "Yes";
    else
        cout << "No";
}