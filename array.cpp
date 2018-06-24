#include <iostream>
using namespace std;
typedef struct TriTable
{
    int row = 0;
    int col = 0;
    int data = 0;
} TriTab[100];
void creat(TriTable *TriTab)
{
    for (int i = 0; i < 100; i++)
    {
        cout << "Enter the row, col and data(Enter -1 to exit):";
        cin >> TriTab[i].row;
        if (TriTab[i].row == -1)
            break;
        cin >> TriTab[i].col;
        cin >> TriTab[i].data;
    }
    return;
}
void output(TriTable *TriTab)
{
    for (int i = 0; i < 100; i++)
    {
        cout << "row, col and data:";
        cout << TriTab[i].row << " " << TriTab[i].col << " " << TriTab[i].data;
    }
    return;
}
int main()
{
    TriTable TriTab[100];
    creat(TriTab);
}

// typedef int Etype;
// typedef struct OLnode
// {
//     int i, j;
//     Etype e;
//     struct OLnode *right, *down;
// } OLnode, *OLink;
// typedef struct
// {
//     OLink *rh, *ch;
//     int norow, nocol, noe;
// } Crosslist;
// void creatMatrix(Crosslist *M);
// void out_M(Crosslist M);
// void search_M(Crosslist *M);
// void query_M(Crosslist M, int row, int col);
// Crosslist ma, mb, mr;
// int z;
// int main()
// {
//     creatMatrix(&ma);
//     search_M(&ma);
//     cout << "Input the row and col of element you want to query:";
//     int m = 0, n = 0;
//     cin >> m >> n;
//     query_M(ma, m, n);
// }
// void out_M(Crosslist M)
// {
//     int i;
//     OLnode *p;
//     cout << "\n  m=" << M.norow << "   n=" << M.nocol << "   t=" << M.noe << "\n";
//     for (i = 1; i <= M.norow; i++)
//     {
//         p = M.rh[i];
//         if (p)
//         {
//             cout << "\n i=" << i;
//             while (p)
//             {
//                 cout << "   (";
//                 cout.width(3);
//                 cout << p->i;
//                 cout.width(3);
//                 cout << p->j;
//                 cout.width(4);
//                 cout << p->e;
//                 cout << ")";
//                 p = p->right;
//             }
//         }
//         cout << "\n";
//     }
// }

// void creatMatrix(Crosslist *M)
// {
//     int m, n, t, row, col, i, j;
//     Etype va;
//     OLnode *p, *q, *s;
//     cout << "\n  m n t=";
//     cin >> m >> n >> t;
//     M->rh = (OLink *)::operator new((m + 1) * sizeof(OLink));
//     if (!M->rh)
//         exit(-1);
//     M->ch = (OLink *)::operator new((n + 1) * sizeof(OLink));
//     if (!M->ch)
//         exit(-1);
//     for (i = 1; i <= m; i++)
//         M->rh[i] = NULL;
//     for (j = 1; j <= n; j++)
//         M->ch[j] = NULL;
//     M->norow = m;
//     M->nocol = n;
//     M->noe = t;
//     for (i = 1; i <= M->noe; i++)
//     {
//         cout << "\n i j e =";
//         cin >> row >> col >> va;
//         p = (OLnode *)::operator new(sizeof(OLnode));
//         p->i = row;
//         p->j = col;
//         p->e = va;
//         q = M->rh[row];
//         s = q;
//         while (q != NULL && q->j < col)
//         {
//             s = q;
//             q = q->right;
//         }
//         p->right = q;
//         if (q == M->rh[row])
//             M->rh[row] = p;
//         else
//             s->right = p;
//         q = M->ch[col];
//         while (q && q->i < row)
//         {
//             s = q;
//             q = q->down;
//         }
//         p->down = q;
//         if (q == M->ch[col])
//             M->ch[col] = p;
//         else
//             s->down = p;
//     }
// }
// void search_M(Crosslist *M)
// {
//     Etype x;
//     cout << "Input the data you want to search:";
//     cin >> x;
//     OLnode *p;
//     for (int i = 1; i <= M->norow; i++)
//     {
//         p = M->rh[i];
//         if (p)
//         {
//             while (p)
//             {
//                 if (p->e == x)
//                 {
//                     cout << "   (";
//                     cout.width(3);
//                     cout << p->i;
//                     cout.width(3);
//                     cout << p->j;
//                     cout << ")";
//                 }
//                 p = p->right;
//             }
//         }
//         cout << "\n";
//     }
//     return;
// }
// void query_M(Crosslist M, int row, int col)
// {
//     OLnode *p;
//     for (int i = 1; i <= M.norow; i++)
//     {
//         p = M.rh[i];
//         if (p)
//         {
//             while (p)
//             {
//                 if (row == p->i && col == p->j)
//                     cout << p->e;
//                 p = p->right;
//             }
//         }
//     }
// }
