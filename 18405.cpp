#include <bits/stdc++.h>
using namespace std;
using Tuple = tuple<int, int, int>;

priority_queue<Tuple, vector<Tuple>, greater<Tuple>> pq;
queue<pair<int, int>> q;
int arr[201][201];
int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };
int n, k, s, x, y;

int solve(void)
{
	while (s--)
	{
		int size = q.size();
		
		while (size--)
		{
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			
			for (int i = 0; i < 4; i++)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];
				
				if (nx < 0 || ny < 0 || nx >= n || ny >= n || arr[ny][nx])
					continue;
				
				arr[ny][nx] = arr[y][x];
				q.push({nx, ny});
			}
		}
	}
	
	return arr[x - 1][y - 1];
}

int main(void)
{
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &arr[i][j]);
			if (arr[i][j] != 0)
				pq.push(make_tuple(arr[i][j], j, i));
		}
	}
	scanf("%d %d %d", &s, &x, &y);
	
	while (!pq.empty())
	{
		q.push({get<1>(pq.top()), get<2>(pq.top())});
		pq.pop();
	}
	
	printf("%d\n", solve());
	
	return 0;
}

