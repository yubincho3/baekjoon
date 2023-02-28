#include <bits/stdc++.h>
#define INF 0x7f7f7f7f
using namespace std;

int arr[16][16];
int dp[65536][16];
int n;

int TSP(int visit, int now)
{
	visit |= (1 << now);
	
	if (visit == (1 << n) - 1)
	{
		if (arr[now][0] > 0)
			return arr[now][0];
		
		return INF;
	}
	
	int& ret = dp[visit][now];
	
	if (ret > 0)
		return ret;
	
	ret = INF;
	
	for (int i = 0; i < n; i++)
	{
		if (i != now && !(visit & (1 << i)) && arr[now][i] > 0)
		{
			int temp = TSP(visit, i) + arr[now][i];
			ret = min(ret, temp);
		}
	}
	
	return ret;
}

int main(void)
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &arr[i][j]);
	
	int ans = TSP(0, 0);
	printf(ans ^ INF ? "%d" : "-1", ans);
	
	return 0;
}

