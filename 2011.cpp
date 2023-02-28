#include <bits/stdc++.h>
using namespace std;

char arr[5001];
int dp[5001] = { 1, 1 };

int solve(void)
{
    if (*arr == '0')
		return 0;
    
	int len = strlen(arr);
	
    for (int i = 2; i <= len; i++)
	{
		int n = (arr[i - 2] - '0') * 10 + arr[i - 1] - '0';
		
        if (n >= 10 && n <= 26)
            dp[i] = dp[i - 2] % 1000000;
        
        if (arr[i - 1] != '0')
			dp[i] = (dp[i - 1] + dp[i]) % 1000000;
    }
    
    return dp[len];
}

int main(void)
{
	scanf("%s", arr);
    printf("%d\n", solve());
    
    return 0;
}

