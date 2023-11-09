#include <iostream>
using namespace std;
int n;
struct ans {
	int num;
	int total;
	int chinese;
};
ans stu[5];
int main()
{
	cin >> n;
	int c, m, e, t;
	for (int i = 0; i < n; ++i)
	{
		cin >> c >> m >> e;
		t = c + m + e;
		for (int j = 0; j < 5; ++j)
		{
			if (t > stu[j].total)
			{
				for (int k = 4; k > j; --k)
					stu[k] = stu[k - 1];
				stu[j].total = t;
				stu[j].chinese = c;
				stu[j].num = i + 1;
				break;
			}
			else if (t == stu[j].total && c > stu[j].chinese)
			{
				for (int k = 4; k > j; --k)
					stu[k] = stu[k - 1];
				stu[j].total = t;
				stu[j].chinese = c;
				stu[j].num = i + 1;
				break;
			}
		}
	}
	for(int i = 0; i < 5; ++i)
		cout << stu[i].num << ' ' << stu[i].total << endl;
	return 0;
}