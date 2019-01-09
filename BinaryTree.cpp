#include <iostream>
#include <queue>
#include <stack>

using namespace std;

typedef struct BiTNode
{
	int data;
	BiTNode *leftchild = NULL, *rightchild = NULL;
} BiTNode;
BiTNode *creat_1()
{
	BiTNode *t, *p, *v[20];
	int e = 0;
	queue<int> Q;
	int i = 0, j = 0;
	while (1)
	{
		cin >> i;
		if (i == -1)
			break;
		cin >> j;
		Q.push(i);
		Q.push(j);
	}
	while (!Q.empty())
	{
		i = Q.front();
		Q.pop();
		p = new BiTNode();
		p->data = Q.front();
		Q.pop();
		v[i] = p;
		if (i == 1)
			t = p;
		else
		{
			int j = i / 2;
			if (i % 2 == 0)
				v[j]->leftchild = p;
			else
				v[j]->rightchild = p;
		}
	}
	return t;
}
BiTNode *creat_2() //p115
{
	BiTNode *t;
	int e = 0;
	cin >> e;
	if (e == 0)
		t = NULL;
	else
	{
		t = new BiTNode;
		t->data = e;
		t->leftchild = creat_2();
		t->rightchild = creat_2();
	}
	return (t);
}
void Inorder_Traversal(BiTNode *p)
{
	if (p)
	{
		Inorder_Traversal(p->leftchild);
		cout << p->data << " ";
		Inorder_Traversal(p->rightchild);
	}
}
void Level_Traversal(BiTNode *p)
{
	BiTNode *T = p, *r;
	queue<BiTNode *> q;
	if (!T)
		return;
	q.push(T);
	while (!q.empty())
	{
		r = q.front();
		cout << r->data << " ";
		q.pop();
		if (r->leftchild)
			q.push(r->leftchild);
		if (r->rightchild)
			q.push(r->rightchild);
	}
}
void Preorder_Traversal_nonrecursion(BiTNode *p)
{
	BiTNode *T = p;
	stack<BiTNode *> s;
	while (T || s.empty())
	{
		while (T)
		{
			s.push(T);
			cout << T->data << " ";
			T = T->leftchild;
		}
		if (!s.empty())
		{
			T = s.top();
			s.pop();
			T = T->rightchild;
		}
	}
}
int Max(int a, int b)
{
	if (a >= b)
		return a;
	else
		return b;
}
int Depth(BiTNode *p)
{
	int d = -1, depth_R = -1, depth_L = -1;
	if (!p)
		return 0;
	if (p->leftchild)
		depth_L = Depth(p->leftchild);
	if (p->rightchild)
		depth_R = Depth(p->rightchild);
	d = Max(depth_L, depth_R);
	return d + 1;
}

int main()
{
	BiTNode *T;
	int i = 0;
	int n = 0;
	int c = 0;
A:
	cout << "题目1 2 3：";
	cin >> i;
	switch (i)
	{
	case 0:
		return 0;
		break;
	case 1:
	B:
		cout << "方法1 2：";
		cin >> c;
		switch (c)
		{
		case 0:
			system("cls");
			goto A;
		case 1:
			T = creat_1();
			break;
		case 2:
			T = creat_2();
			break;
		default:
			system("cls");
			goto B;
		}
		Level_Traversal(T);
		break;
	case 2:
	C:
		cout << "方法1 2：";
		cin >> c;
		switch (c)
		{
		case 0:
			system("cls");
			goto A;
		case 1:
			T = creat_1();
			break;
		case 2:
			T = creat_2();
			break;
		default:
			system("cls");
			goto C;
		}
		Preorder_Traversal_nonrecursion(T);
		break;
	case 3:
	D:
		cout << "方法1 2：";
		cin >> c;
		switch (c)
		{
		case 0:
			system("cls");
			goto A;
		case 1:
			T = creat_1();
			break;
		case 2:
			T = creat_2();
			break;
		default:
			system("cls");
			goto D;
		}
		n = Depth(T);
		cout << n;
		break;
	default:
		return 0;
	}
}