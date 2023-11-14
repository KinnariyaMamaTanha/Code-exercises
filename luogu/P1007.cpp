#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main()
{
	int l, n;
	cin >> l >> n;
	int max = -1, min = -1;
	int tmp;
	for (int i = 0; i < n; ++i)
	{
		cin >> tmp;
		int a, b;
		if (tmp > l + 1 - tmp)
			a = l + 1 - tmp, b = tmp;
		else
			a = tmp, b = l + 1 - tmp;
		if (a > min)
			min = a;
		if (b > max)
			max = b;
	}
	if (min == -1)
		cout << 0 << ' ';
	else
		cout << min << ' ';
	if (max == -1)
		cout << 0;
	else
		cout << max;
	return 0;
}
