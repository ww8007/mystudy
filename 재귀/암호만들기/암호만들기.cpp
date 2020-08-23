#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

bool check(string& pw)
{
	int ja = 0;
	int mo = 0;
	for (char x : pw)
	{
		if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u') {
			mo += 1;
		}
		else {
			ja += 1;
		}
	}
	return ja >= 2 && mo >= 1;
}

void go(int n, vector<char>& my, string pw, int i)
{
	if (pw.length() == n)
	{
		if (check(pw))
		{
			cout << pw << '\n';
		}
		return;
	}
	if (i == my.size())
		return;
	go(n, my, pw + my[i], i + 1);
	go(n, my, pw, i + 1);
}


int main(void)
{
	int num, num2;
	cin >> num >> num2;
	vector<char> a(num2);
	for (int i = 0; i < num2; i++)
	{
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	go(num, a, "", 0);

	return 0;
}