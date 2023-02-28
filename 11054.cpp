#include <bits/stdc++.h>
using namespace std;

int arr[1002];
int dp1[1002];
int dp2[1002];
int n, ans;

int main(void)
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &arr[i]);
		
		for (int j = 0; j < i; j++)
			if (arr[i] > arr[j])
				dp1[i] = max(dp1[i], dp1[j] + 1);
	}
	
	for (int i = n; i >= 1; i--)
	{
		for (int j = n + 1; j > i; j--)
			if (arr[i] > arr[j])
				dp2[i] = max(dp2[i], dp2[j] + 1);
		
		ans = max(ans, dp1[i] + dp2[i] - 1);
	}
	
	printf("%d\n", ans);
	
	return 0;
}

