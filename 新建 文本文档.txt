#include <iostream>
#include <cmath>
using namespace std;
int n, m;
struct node
{
	int num;
	int val;
	node* next;
	node(): num(0), val(0), next(nullptr) {}
	node(int n, int v, node* N): num(n), val(v), next(N) {}
	~node() {}
};
node* head = new node;
int main()
{
	cin >> n;
	m = pow(2, n);
	int tmp;
	head->next = new node;
	node* p = head;
	for (int i = 0; i < m; ++i)
	{
		p->next = new node;
		p = p->next;
		cin >> tmp;
		p->val = tmp;
		p->num = i + 1;
	} // 最后p指向尾节点处，保留下来
	node* q;
	for (int i = 1; i < n; ++i)
	{
		q = head->next;
		while (q->next != p)
		{
			if (q->val > q->next->val)
			{
				q->next = q->next->next;
			}
			else
			{
				node* r = head->next;
				while (r->next != q)
					r = r->next;
				r->next = q->next;
				q = q->next;
			}
			q = q->next;
		} // q->next == p 的情况单独处理
		if (q->val > p->val)
		{
			p = q;
			p->next = nullptr;
		}
		else
		{
			node* r = head->next;
			while (r->next != q)
				r = r->next;
			r->next = p;
		}
	}
	cout << ((head->next->val > p->val) ? p->num : head->next->num);
	return 0;
}