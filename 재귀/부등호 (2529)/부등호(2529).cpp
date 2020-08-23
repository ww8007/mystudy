#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

char a[11];
bool b[10];
int my[11];
int max1[11];
int min1[11];
int num;
int cnt = 0;

bool aa()
{
	for (int i = 1; i <= num+1; i++)
	{
		if (a[i] == '<')
		{
			bool d = my[i - 1] < my[i];
			if (d == false)
				return false;
		}
		else if (a[i]== '>')
		{
			bool d = my[i - 1] > my[i];
			if (d == false)
				return false;
		}
	}
	
	return true;
}
void pt(int index)
{
	if (index == num+1)
	{
		bool k = aa();
		if (k)
		{
			cnt++;
			if (cnt == 1)
			{
				for (int i = 0; i <= num; i++)
				{
					min1[i] = my[i];
				}
			}
			for (int i = 0; i <= num; i++)
			{
				max1[i] = my[i];
			}
			
			return;
		}
		
	}
	for (int i = 0; i <= 9; i++)
	{
		if (b[i])
			continue;
		b[i] = true;
		my[index] = i;
		pt(index + 1);
		b[i] = false;
	}
}
int main(void)
{
	
	cin >> num;
	for (int i = 1; i <= num; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < num; i++)
	{
		max1[i] = 0;
		min1[i] = 9;
	}
	pt(0);
	for (int i = 0; i <= num; i++)
	{
		cout << max1[i];
	}
	cout << '\n';
	for (int i = 0; i <= num; i++)
	{
		cout << min1[i];
	}
	cout << '\n';
}