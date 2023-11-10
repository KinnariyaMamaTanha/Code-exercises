#include <iostream>
using namespace std;
int stu[2000001];
int n, m, tmp;
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		cin >> stu[i];
	for (int i = 0; i < m; ++i)
	{
		cin >> tmp;
		cout << stu[tmp] << endl;
	}
	return 0;
}
