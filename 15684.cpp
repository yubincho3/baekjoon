#include <bits/stdc++.h>
using namespace std;

bool arr[11][31];
int n, m, h, a, b;
int ans = -1;

bool test(void)
{
	for (int i = 1; i <= n; i++)
	{
		int now = i;
		
		for (int j = 1; j <= h; j++)
		{
			if (arr[now][j])
				now++;
			else if (arr[now - 1][j])
				now--;
		}
		
		if (now != i)
			return false;
	}
	
	return true;
}

void backtracking(int prev, int cnt)
{
	if (cnt > 3)
		return;
	
	if (test())
	{
		ans = (ans == -1 || ans > cnt ? cnt : ans);
		return;
	}
	
	for (int i = prev; i <= h; i++)
	{
		for (int j = 1; j < n; j++)
		{
			if (arr[j - 1][i] || arr[j][i] || arr[j + 1][i])
				continue;
			
			arr[j][i] = true;
			backtracking(i, cnt + 1);
			arr[j][i] = false;
		}
	}
}

int main(void)
{
	for (scanf("%d %d %d", &n, &m, &h); m--;)
	{
		scanf("%d %d", &a, &b);
		arr[b][a] = true;
	}
	
	backtracking(1, 0);
	printf("%d\n", ans);
	
	return 0;
}

