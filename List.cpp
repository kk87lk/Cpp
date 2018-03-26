#include <iostream>
#include <malloc.h>
#define ElementType int
#define MaxSize 10
 
using namespace std;

typedef struct LNode *List;
struct LNode
{
      ElementType Data[MaxSize];
      int Last;
};
struct LNode L;
List PtrL;

List MakeEmpty()
{
      List Ptrl;
      Ptrl = (List)malloc(sizeof(struct LNode));
      Ptrl->Last = -1;
      return PtrL;
}
int Find(ElementType X, List PtrL)
{
      int i = 0;
      while (i <= PtrL->Last && PtrL->Data[i] != X)
            i++;
      if (i > PtrL->Last)
            return -1;
      else
            return i; 
}
void Insert(ElementType X, int i, List PtrL)
{
      int j = 0;
      if (PtrL->Last == MaxSize - 1)
      {
            cout << "The List is full." << '\n' <<endl;
            return;
      }
      if (i < 1 || i > PtrL->Last + 1)
      {
            cout << "Illegal location!" << '\n' <<endl;
            return;
      }
      for (j = PtrL->Last; j >= i - 1; j--)
            PtrL->Data[j + 1] = PtrL->Data[j];
      PtrL->Data[i - 1] = X;
      PtrL->Last++;
      return;
}
void Delete(int i, List PtrL)
{
      int j = 0;
      if (i < 1 || i > PtrL->Last + 1)
      {
            cout << "The element " << i << " doesn't exist." << endl;
            return;
      }
      for(j = i;j <= PtrL->Last; j++)
            PtrL->Data[j - 1] = PtrL->Data[j];
      PtrL->Last--;
      return;
}
void Display(List PtrL)
{
      for (int c = 0; c <= PtrL->Last; c++)
            cout << PtrL->Data[c];
}
int main()
{
      MakeEmpty();
      int num = 0;
      while(cin >> num)
      {
            int z = 0;
            PtrL->Data[z] = num;
            PtrL->Last = z;
            z++;
      }
      Display(PtrL);
}