//백준 2667 단지 번호 붙이기 
//<그림 1>과 같이 정사각형 모양의 지도가 있다. 1은 집이 있는 곳을, 0은 집이 없는 곳을 나타낸다.
//철수는 이 지도를 가지고 연결된 집들의 모임인 단지를 정의하고, 단지에 번호를 붙이려 한다.
//여기서 연결되었다는 것은 어떤 집이 좌우, 혹은 아래위로 다른 집이 있는 경우를 말한다.대각선상에 집이 있는 경우는 연결된 것이 아니다. 
//<그림 2>는 <그림 1>을 단지별로 번호를 붙인 것이다.지도를 입력하여 단지수를 출력하고, 각 단지에 속하는 집의 수를 오름차순으로 정렬하여 출력하는 프로그램을 작성하시오.
//예제 입력 
//7
//0110100
//0110101
//1110101
//0000111
//0100000
//0111110
//0111000
//예제 출력
//3
//7
//8
//9
//dfs로 풀어보기 (도움 받음)
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "stdio.h"
#include <cstdio>
using namespace std;

int a[26][26];
int d[26][26];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
int num;
int ans[26 * 26];
void dfs(int x, int y, int cnt)
{
	d[x][y] = cnt;
	for (int k = 0; k < 4; k++)
	{
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (nx >= 0 && nx < num && ny >= 0 && ny < num)
		{
			if (a[nx][ny] == 1 && d[nx][ny] == 0)
				dfs(nx, ny, cnt);
		}
	}
}


int main(void)
{
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
		{
			scanf_s("%1d", &a[i][j]);
			d[i][j] = 0;
		}
	}
	int cnt = 0;
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
		{
			if (a[i][j] == 1 && d[i][j] == 0)
				dfs(i, j, ++cnt);
		}
	}
	cout << cnt << '\n';
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
		{
			ans[d[i][j]]++;
		}
	}
	sort(ans + 1, ans + cnt + 1);
	for (int i = 1; i <= cnt; i++)
	{
		cout << ans[i] << '\n';
	}
	return 0;
}