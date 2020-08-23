#include <iostream>
#include <algorithm>
using namespace std;

int num;
int t[21];
int p[21];
int ans = 0;

void go(int day, int sum)
{
	if (day == num + 1)
	{
		ans = max(ans, sum);
		return;
	}
	if (day > num + 1)
		return;
	
	
	go(day + 1, sum);
	go(day + t[day], sum + p[day]);
}

int main(void)
{
	cin >> num;
	for (int i = 1; i <= num; i++)
	{
		cin >> t[i] >> p[i];
	}
	go(1, 0);
	cout << ans << '\n';
	return 0;
}