#include <bits/stdc++.h>
#define N_MAX 21
using namespace std;

vector<tuple<int, int, int>> shark; // x, y, d
int dir[N_MAX * N_MAX][4][4];
int smell[N_MAX][N_MAX][2]; // smellCnt, smellHost
int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };
int n, m, k, t;

int solve(void)
{
	int ret = -1;
	
	for (int s = 0; s <= 1000; s++)
	{
		bool flag = true;
		
		for (int i = 1; i <= m; i++)
		{
			int x, y, d;
			tie(x, y, d) = shark[i];
			
			if (x == -1)
				continue;
			
			smell[y][x][0] = k;
			smell[y][x][1] = i;
			flag = i == 1;
		}
		
		if (flag == true)
			return s;
		
		for (int i = 1; i <= m; i++)
		{
			int x, y, d;
			tie(x, y, d) = shark[i];
			
			if (x == -1)
				continue;
			
			tuple<int, int, int> nxt;
			int target[2] = { 0, i };
			
			bool flag = false;
			
			for (int t = 0; t < 2; t++)
			{
				for (int j = 0; j < 4; j++)
				{
					int *prior = dir[i][(d + j) % 4];
					
					for (int k = 0; k < 4; k++)
					{
						int nd = prior[k];
						int nx = x + dx[nd];
						int ny = y + dy[nd];
						
						if (nx < 0 || ny < 0 || nx >= n || ny >= n)
							continue;
						
						if (smell[ny][nx][1] == target[t])
						{
							nxt = tie(nx, ny, nd);
							flag = true;
							break;
						}
					}
					
					if (flag == true)
						break;
				}
				
				if (flag == true)
					break;
			}
			
			shark[i] = nxt;
		}
		
		for (int i = 1; i <= m; i++)
		{
			int xi, yi, di;
			tie(xi, yi, di) = shark[i];
			
			if (xi == -1)
				continue;
			
			for (int j = i + 1; j <= m; j++)
			{
				int xj, yj, dj;
				tie(xj, yj, dj) = shark[j];
				
				if (xj == -1)
					continue;
				
				if (xi == xj && yi == yj)
					shark[j] = make_tuple(-1, -1, -1);
			}
		}
		
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (--smell[i][j][0] <= 0)
				{
					smell[i][j][0] = 0;
					smell[i][j][1] = 0;
				}
			}
		}
	}
	
	return -1;
}

int main(void)
{
	scanf("%d %d %d", &n, &m, &k);
	shark.resize(m + 1);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &t);
			
			if (t != 0)
				shark[t] = make_tuple(j, i, 0);
		}
	}
	
	for (int i = 1; i <= m; i++)
	{
		scanf("%d", &t);
		get<2>(shark[i]) = --t;
	}
	
	for (int i = 1; i <= m; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				scanf("%d", &dir[i][j][k]);
				dir[i][j][k]--;
			}
		}
	}
	
	printf("%d\n", solve());
	
	return 0;
}

