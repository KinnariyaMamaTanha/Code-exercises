#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

bool cmp(string& a, string& b)
{
	return a + b > b + a;
}

int main()
{
	int n;
	cin >> n;
	string* nums = new string[n];
	for (int i = 0; i < n; ++i)
		cin >> nums[i];
	sort(nums, nums + n, cmp);
	for (int i = 0; i < n; ++i)
		cout << nums[i];
	return 0;
} 
//6
//321 32 407 135 13 217 