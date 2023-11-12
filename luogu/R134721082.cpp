#include <iostream>
#include <queue>
using namespace std;
int n;
string tmp, s;
priority_queue<string, vector<string>, greater<string>> ss;
int main()
{
	cin >> n;
	while (n)
	{
		--n;
		cin >> tmp;
		ss.push(tmp);
	}
	cin >> s;
	int l = s.length();
	while (!ss.empty())
	{
		tmp = ss.top();
		if (tmp.length() >= l)
		{
			int i;
			for (i = 0; i < l; ++i)
				if (s[i] != tmp[i])
					break;
			if (i == l)
				cout << tmp << endl;
		}
		ss.pop();
	}
	return 0;
}