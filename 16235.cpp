#include <bits/stdc++.h>
#define MAX 11
using namespace std;

vector<int> tree[MAX][MAX];
int food_add[MAX][MAX];
int food[MAX][MAX];
int dx[] = { -1, 0, 1, 1, 1, 0, -1, -1 };
int dy[] = { -1, -1, -1, 0, 1, 1, 1, 0 };
int n, m, k, x, y, z;

bool outOfRange(int x, int y)
{
	return (x < 1 || y < 1 || x > n || y > n);
}

void simulation(void)
{
	// 봄 
	vector<tuple<int, int, int>> dead;
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			int deadIdx = -1;
			
			sort(tree[i][j].begin(), tree[i][j].end());
			for (int t = 0; t < tree[i][j].size(); t++)
			{
				if (food[i][j] < tree[i][j][t])
				{
					deadIdx = t;
					break;
				}
				else
				{
					food[i][j] -= tree[i][j][t];
					tree[i][j][t]++;
				}
			}
			
			if (deadIdx != -1)
			{
				auto& nowTree = tree[i][j];
				
				for (int t = deadIdx; t < nowTree.size(); t++)
					dead.push_back(make_tuple(j, i, nowTree[t]));
				
				nowTree.erase(nowTree.begin() + deadIdx, nowTree.end());
			}
		}
	}
	
	// 여름 
	for (auto& t : dead)
	{
		int x, y, age;
		tie(x, y, age) = t;
		
		food[y][x] += age / 2;
	}
	
	// 가을 
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			vector<pair<int, int>> newTrees;
			vector<int> v;
			
			for (int age : tree[i][j])
			{
				if (age % 5 == 0)
				{
					for (int d = 0; d < 8; d++)
					{
						int nx = j + dx[d];
						int ny = i + dy[d];
						
						if (outOfRange(nx, ny))
							continue;
						
						newTrees.push_back({nx, ny});
					}
				}
			}
			
			for (auto temp: newTrees)
				tree[temp.second][temp.first].push_back(1);
		}
	}
	
	// 겨울 
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			food[i][j] += food_add[i][j];
}

int solve(void)
{
	while (k--)
		simulation();
	
	int ret = 0;
	
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			ret += tree[i][j].size();
	
	return ret;
}

int main(void)
{
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			scanf("%d", &food_add[i][j]);
			food[i][j] = 5;
		}
	}
	
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d %d", &y, &x, &z);
		tree[y][x].push_back(z);
	}
	
	printf("%d\n", solve());
	
	return 0;
}

