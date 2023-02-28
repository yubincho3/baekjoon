#include <bits/stdc++.h>
using namespace std;

int arr[101][101];
int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };
int n, m;

int solve(void)
{
	int ret = 0;
	
	while (++ret)
	{
		bool visit[101][101] = {};
		int cnt[101][101] = {};
		
		queue<pair<int, int>> q;
		
		q.push(make_pair(0, 0));
		visit[0][0] = true;
		
		while (!q.empty())
		{
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			
			for (int i = 0; i < 4; i++)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];
				
				if (nx < 0 || ny < 0 || nx > m || ny > n)
					continue;
				
				if (!visit[ny][nx] && !arr[ny][nx])
				{
					q.push(make_pair(nx, ny));
					visit[ny][nx] = true;
				}
				
				cnt[ny][nx] += arr[ny][nx];
			}
		}
		
		bool flag = false;
		
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				if (cnt[i][j] >= 2)
					arr[i][j] = 0;
				
				flag |= arr[i][j];
			}
		}
		
		if (!flag)
			break;
	}
	
	return ret;
}

int main(void)
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%d", &arr[i][j]);
	
	printf("%d\n", solve());
	
	return 0;
}

