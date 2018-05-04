#include <iostream>

#define ElementType int

using namespace std;
#define MaxSize 10
struct Queue1
{
    ElementType Data = 99999; 
    struct Queue1 *front = NULL;
    struct Queue1 *next = NULL;
};
typedef struct Queue1 *Queue;
class QueueNode
{
    private:
        bool IsEmpty(Queue Q)
        {
            if (Q == NULL)
                return true;
            else
                return false;
        }

    public:
        void Creat(Queue &Q)
        {
            Q = new Queue1;
            Q->next = NULL;
            getchar();
        }

        void Add(Queue &Q)
        {
        	if (Q->Data == 99999)
        	{
        		cin >> Q->Data;
        		system("pause");
        		return;
			}
            Queue p, EoQ = Q;
            p = new Queue1;
            while(EoQ->next != NULL)
                EoQ = EoQ->next;
            cin >> p->Data;
            p->front = EoQ;
            p->next = NULL;
            EoQ->next = p;
            system("pause");
        }

        void Delete(Queue &Q)
        {
            Queue EoQ = Q;
        	while(EoQ->next != NULL)
        		EoQ = EoQ->next;
            if (Q->Data == 99999)
            {
                cout << "Empty" << '\n';
                system("pause");
                return;
            }
            else
                {
                    cout << Q->Data << endl;
                    if(EoQ->next == Q->next)
                    {
                    	Q->Data = 99999;
					}
					else
					{
						Q = Q->next;
						Q->front = NULL;
					}
                }
            system("pause");
        }
};
int main()
{
    QueueNode q;
    Queue Q;
    int op = -1;
    while(op != 0)
    {
        system("cls");
        cout << "1-creat." << endl;
        cout << "2-add." << endl;
        cout << "3-delete." << endl;
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
            default:
                cout << "Wrong option.";
        }
    }
}