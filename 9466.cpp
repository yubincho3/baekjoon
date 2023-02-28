#include <bits/stdc++.h>
using namespace std;

int arr[100001];
bool visit[100001];
bool done[100001];
int t, n, ans;

void dfs(int now)
{
	visit[now] = true;
	
	int next = arr[now];
	
	if (!visit[next])
		dfs(next);
	else if (!done[next])
	{
		for (int i = next; i != now; i = arr[i])
			ans++;
		
		ans++;
	}
	
	done[now] = true;
}

int solve(void)
{
	for (int i = 1; i <= n; i++)
		if (!visit[i])
			dfs(i);
	
	int ret = n - ans;
	
	memset(visit, 0, sizeof(visit));
	memset(done, 0, sizeof(done));
	ans = 0;
	
	return ret;
}

int main(void)
{
	for (scanf("%d", &t); t--;)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d", &arr[i]);
		
		for (int i = 1; i <= n; i++)
			if (!visit[i])
				dfs(i);
		
		printf("%d\n", solve());
	}
	
	return 0;
}

