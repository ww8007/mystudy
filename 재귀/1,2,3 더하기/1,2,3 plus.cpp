#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int check(int sum, int goal)
{
	if (sum > goal)
		return 0;
	if (sum == goal)
		return 1;
	int ans = 0;
	for (int i = 1; i <= 3; i++)
	{
		ans += check(sum + i, goal);
	}
	return ans;
}

int main(void)
{
	int num;
	cin >> num;

	while (num--)
	{
		int num2;
		cin >> num2;
		cout << check(0, num2) << '\n';
	}
	return 0;
}