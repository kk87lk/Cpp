#include <iostream>
#include <queue>

using namespace std;

typedef struct BiTNode
{
	int data;
	BiTNode *leftchild = NULL, *rightchild = NULL;
} BiTNode;
BiTNode *creat_1()
{
	BiTNode *t, *p, *v[20];
	int e;
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
}
BiTNode *creat_2() //p115
{
}
void inorder(BiTNode *p)
{
	if (p)
	{
		inorder(p->leftchild);
		cout << p->data;
		// printf("%3d", p->data);
		inorder(p->rightchild);
	}
}

int main()
{
}