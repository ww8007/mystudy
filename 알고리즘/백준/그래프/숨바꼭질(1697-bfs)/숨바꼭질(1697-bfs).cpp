//백준 : 숨바꼭질 1697번 bfs
//문제
//
//수빈이는 동생과 숨바꼭질을 하고 있다.수빈이는 현재 점 N(0 ≤ N ≤ 100, 000)에 있고, 동생은 점 K(0 ≤ K ≤ 100, 000)에 있다.
//수빈이는 걷거나 순간이동을 할 수 있다.만약, 수빈이의 위치가 X일 때 걷는다면 1초 후에 X - 1 또는 X + 1로 이동하게 된다.순간이동을 하는 경우에는 1초 후에 2 * X의 위치로 이동하게 된다.
//수빈이와 동생의 위치가 주어졌을 때, 수빈이가 동생을 찾을 수 있는 가장 빠른 시간이 몇 초 후인지 구하는 프로그램을 작성하시오.
//
//입력 
//
//첫 번째 줄에 수빈이가 있는 위치 N과 동생이 있는 위치 K가 주어진다.N과 K는 정수이다.
//5 17
//출력
//
//수빈이가 동생을 찾는 가장 빠른 시간을 출력한다.
//4
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, k;
bool check[1000000];
queue<int> q;
int dist[1000000];


int main(void)
{
	cin >> n >> k;
	check[n] = true;
	dist[n] = 0;
	q.push(n);
	while (!q.empty())
	{
		int pt = q.front();
		q.pop();
		if (pt - 1 >= 0)
		{
			if (check[pt - 1] == false)
			{
				q.push(pt - 1);
				check[pt - 1] = true;
				dist[pt - 1] = dist[pt] + 1;
			}
		}
		if (pt + 1 < 1000000)
		{
			if (check[pt + 1] == false)
			{
				q.push(pt + 1);
				check[pt + 1] = true;
				dist[pt + 1] = dist[pt] + 1;
			}
		}
		if (pt * 2 < 1000000)
		{
			if (check[pt*2] == false)
			{
				q.push(pt * 2);
				check[pt * 2] = true;
				dist[pt * 2] = dist[pt] + 1;
			}
		}
		
		
	}
	cout << dist[k] << '\n';
	return 0;
}