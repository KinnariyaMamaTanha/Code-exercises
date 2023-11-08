#include <iostream>
using namespace std;
int n, m;
int stu[1000];
int main()
{
	cin >> n >> m;
	int tmp;
	for (int i = 0; i < m; ++i)
	{
		cin >> tmp;
		++stu[tmp];
	}
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= stu[i]; ++j)
			cout << i << ' ';
	return 0;
}