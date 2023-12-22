#include <iostream>
using namespace std;
int a[100];
int count(int* a, int n, int m);
int main()
{
	int N, mean = 0;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> a[i];
		mean += a[i];
	}
	mean /= N;
	cout << count(a, N, mean);
	return 0;
}
int count(int* a, int n, int m)
{
	if (n == 0)
		return 0;
	if (a[0] == m)
		return count(a + 1, n - 1, m);
	else if (a[0] + a[1] == 2 * m)
		return 1 + count(a + 2, n - 2, m);
	else
	{
		a[1] -= m - a[0];
		return 1 + count(a + 1, n - 1, m);
	}
}
