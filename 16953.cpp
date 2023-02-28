#include <bits/stdc++.h>
using namespace std;

long long a, b;
int minV = INT_MAX;

void dfs(long long a, int cnt)
{
	if (a > b)
		return;
	
	if (a == b)
		minV = min(minV, cnt);
	
	dfs(a * 2, ++cnt);
	dfs(a * 10 + 1, cnt);
}

int solve(void)
{
	dfs(a, 1);
	
	return (minV ^ INT_MAX ? minV : -1);
}

int main(void)
{
	scanf("%lld %lld", &a, &b);
	printf("%d\n", solve());
	
	return 0;
}

