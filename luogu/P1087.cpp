#include <iostream>
#include <stack>
using namespace std;
int n, N = 1;
struct node {
	char ch;
	int poptime = 0;
	node* lchild;
	node* rchild;

	node(): ch('\0'), lchild(nullptr), rchild(nullptr) {}
	node(char c, node* l = nullptr, node* r = nullptr): ch(c), lchild(l), rchild(r) {}
	~node() {}
};
node* root = new node;
bool s[1030];
char jdg(bool a[], int start, int end); // 左闭右开
void build(bool a[], int start, int end, node* r); // 左闭右开
void postOrder(node* r);

int main()
{
	cin >> n;
	char tmp;
	while (n)
	{
		--n;
		N *= 2;
	}
	for (int i = 0; i < N; ++i)
	{
		cin >> tmp;
		s[i] = (tmp == '0') ? 0 : 1;
	}
	build(s, 0, N, root);
	postOrder(root);
	return 0;
}

char jdg(bool a[], int start, int end)
{
	bool zero = 0, one = 0;
	for (int i = start; i < end; ++i)
	{
		if (a[i])
			one = 1;
		else
			zero = 1;
		if (one && zero)
			break;
	}
	if (one && zero)
		return 'F';
	else if (one && !zero)
		return 'I';
	else
		return 'B';
}

void build(bool a[], int start, int end, node* r)
{
	r->ch = jdg(a, start, end);
	if (end - start == 1)
		return;
	r->lchild = new node;
	build(a, start, (start + end) / 2, r->lchild);
	r->rchild = new node;
	build(a, (start + end) / 2, end, r->rchild);
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
		{
			cout << tmp->ch;
		}
	}
}
