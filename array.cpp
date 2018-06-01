#include <iostream>
using namespace std;
typedef int Etype;
typedef struct OLnode
{
    int i, j;                    /* 行号、列号域 */
    Etype e;                     /*  数据域      */
    struct OLnode *right, *down; /* 行向的、列向的指针域 */
} OLnode, *OLink;                /* 数据元素结点类型  */
typedef struct
{
    OLink *rh, *ch;
    int mu, nu, tu;
} Crosslist; /* 十字链表行、列表头  */
/* 函数声明 */
void creatMatrix(Crosslist *M);
void out_M(Crosslist M);
void search_M(Crosslist *M, Etype x);
void query_M(Crosslist M, int row, int col);
Crosslist ma, mb, mr;
int z;
/*  主函数 */
int main()
{
    creatMatrix(&ma);
    out_M(ma);
} /* main */
/* 十字链表的输出  */
void out_M(Crosslist M)
{
    int i;
    OLnode *p;
    /*  输出矩阵的总行数、总列数、非零元素总个数 */
    cout << "\n  m=" << M.mu << "   n=" << M.nu << "   t=" << M.tu << "\n";
    for (i = 1; i <= M.mu; i++)
    {
        p = M.rh[i]; /*  指向第i行 */
        if (p)
        {
            cout << "\n i=" << i;
            while (p)
            {
                cout << "   (";
                cout.width(3);
                cout << p->i;
                cout.width(3);
                cout << p->j;
                cout.width(4);
                cout << p->e;
                cout << ")";
                p = p->right;
            }
        }
        cout << "\n";
    }
    system("cls");
}

void creatMatrix(Crosslist *M)
{
    int m, n, t, row, col, i, j;
    Etype va;
    OLnode *p, *q, *s;
    /*  输入矩阵的总行数、总列数、非零元素总个数 */
    cout << "\n  m n t=";
    cin >> m >> n >> t;
    M->rh = (OLink *)::operator new((m + 1) * sizeof(OLink));
    if (!M->rh)
        exit(-1);
    M->ch = (OLink *)::operator new((n + 1) * sizeof(OLink));
    if (!M->ch)
        exit(-1);
    for (i = 1; i <= m; i++)
        M->rh[i] = NULL;
    for (j = 1; j <= n; j++)
        M->ch[j] = NULL;
    M->mu = m;
    M->nu = n;
    M->tu = t; /*  建立成空十字链表  */
    /* 以下为非零元素的逐一输入和插入 */
    for (i = 1; i <= M->tu; i++)
    {
        cout << "\n i j e =";
        cin >> row >> col >> va;
        p = (OLnode *)::operator new(sizeof(OLnode));
        p->i = row;
        p->j = col;
        p->e = va;
        /*  在第row行上链接 */
        q = M->rh[row];
        s = q;
        while (q != NULL && q->j < col)
        {
            s = q;
            q = q->right;
        }
        p->right = q;
        if (q == M->rh[row])
            M->rh[row] = p;
        else
            s->right = p;
        /* 在第col列上链接    */
        q = M->ch[col];
        while (q && q->i < row)
        {
            s = q;
            q = q->down;
        }
        p->down = q;
        if (q == M->ch[col])
            M->ch[col] = p;
        else
            s->down = p;
    } /* for */
} /* creatMatrix */
void search_M(Crosslist *M, Etype x)
{
    for (int i = 0; i < M->mu; i++)
    {
        for (int j = 0;;)
        {
            p = M->rh[i];
            if (p->e == x)
            {
                p = p->right;
                j++;
            }
            else
            {
                cout << "row:" << i << "col:" << j;
            }
        }
    }
    return;
}
void query_M(Crosslist M, int row, int col)
{
    // if((row > M.mu || row < 0) || (col > M.nu || col < 0))
    // {
    //     cout << "Invalid input.";
    //     return;
    // }
    // for (int i = 0; i < row; i++)
    //     M = M.down;
    // for (int j = 0; j < col; j++)
    //     M = M.right;
    OLnode *p;
    p = M.rh[row];
    for (int j = 0; j < col; j++)
        p = p->right;
    cout << '\n'
         << p->e;
}

    //--------------------------------------------------------------

#include <iostream>
using namespace std;
typedef int Etype;
typedef struct TripleTable
{
    int col, row; /* 行号、列号域 */
    Etype e;      /*  数据域      */
} TriTable;
