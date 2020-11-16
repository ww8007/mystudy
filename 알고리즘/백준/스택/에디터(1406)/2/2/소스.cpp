#include <iostream>
#include <stack>
#include <string>	

using namespace std;

int main(void)
{
	string a;
	cin.tie(0);
	cin.sync_with_stdio(false);

	getline(cin, a);


	stack <char> my;
	stack <char> my1;

	int i;
	for (i = 0; i < a.size(); i++)
	{
		my1.push(a[i]);
	}
	
	int num;
	cin >> num;
	while (num--)
	{
		char m;
		cin >> m;
		if (m == 'L')
		{
			if (!my1.empty())
			{
				char n = my1.top();
				my.push(n);
				my1.pop();
			}
		}
		else if (m == 'D')
		{
			if (!my.empty())
			{
				char n = my.top();
				my1.push(n);
				my.pop();
			}
		}
		else if (m == 'B')
		{
			if (!my1.empty())
			{
				my1.pop();
			}
		}
		else if (m == 'P')
		{
			char n;
			cin >> n;
			my1.push(n);
		}
	}

	stack <char> k;
	int mysize = my1.size();
	for (int i = 0; i < mysize; i++)
	{
		char f = my1.top();
		my1.pop();
		k.push(f);
	}
	
	for (i = 0; i < mysize; i++)
	{
		cout << k.top();
		k.pop();
	}
	int secsize = my.size();
	for (int i = 0; i < secsize; i++)
	{
		cout << my.top();
		my.pop();
	}
}