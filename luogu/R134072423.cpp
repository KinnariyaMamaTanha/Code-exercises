#include <iostream>
#include <stack>
using namespace std;
int n;
struct node
{
	node* lchild;
	node* rchild;
	int num;
	int poptime = 0;
	node(): num(0), lchild(nullptr), rchild(nullptr) {}
	node(node* l, node* r, int n): num(n), lchild(l), rchild(r) {}
	~node() {}
};
node* nodes[1000001];

void preOrder(node* r);
void midOrder(node* r);
void postOrder(node* r);
int main()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)
		nodes[i] = new node;
	int tmpl, tmpr;
	for (int i = 1; i <= n; ++i)
	{
		cin >> tmpl >> tmpr;
		if (tmpl)
			nodes[i]->lchild = nodes[tmpl];
		if (tmpr)
			nodes[i]->rchild = nodes[tmpr];
		nodes[i]->num = i;
	}
	preOrder(nodes[1]);
	cout << endl;
	midOrder(nodes[1]);
	cout << endl;
	postOrder(nodes[1]);
	return 0;
}

void preOrder(node* r)
{
	stack<node*> ns;
	ns.push(r);
	node* tmp;
	while (!ns.empty())
	{
		tmp = ns.top();
		ns.pop();
		if (tmp->rchild != nullptr)
			ns.push(tmp->rchild);
		if (tmp->lchild != nullptr)
			ns.push(tmp->lchild);
		cout << tmp->num << ' ';
	}
}

void midOrder(node* r)
{
	stack<node*> ns;
	ns.push(r);
	node* tmp;
	while (!ns.empty())
	{
		tmp = ns.top();
		ns.pop();
		if (tmp->poptime == 0)
		{
			ns.push(tmp);
			if (tmp->lchild != nullptr)
				ns.push(tmp->lchild);
			tmp->poptime = 1;
		}
		else if (tmp->poptime == 1)
		{
			cout << tmp->num << ' ';
			if (tmp->rchild != nullptr)
				ns.push(tmp->rchild);
			tmp->poptime = 0;
		}
	}
}

void postOrder(node* r)
{
	stack<node*> ns;
	ns.push(r);
	node* tmp;
	while (!ns.empty())
	{
		tmp = ns.top();
		ns.pop();
		if (tmp->poptime == 0)
		{
			ns.push(tmp);
			tmp->poptime = 1;
			if (tmp->lchild != nullptr)
				ns.push(tmp->lchild);
		}
		else if (tmp->poptime == 1)
		{
			ns.push(tmp);
			tmp->poptime = 2;
			if (tmp->rchild != nullptr)
				ns.push(tmp->rchild);
		}
		else if (tmp->poptime == 2)
			cout << tmp->num << ' ';
	}
}