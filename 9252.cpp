#include <bits/stdc++.h>
using namespace std;

char str1[1001], str2[1001];
int dp[1001][1001][3]; // 최대 길이, 이전 dp값의 인덱스(i, j) 순서

pair<int, string> solve()
{
    const int len1 = strlen(str1);
    const int len2 = strlen(str2);

    for (int i = 1; i <= len1; i++)
    {
        for (int j = 1; j <= len2; j++)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                dp[i][j][0] = dp[i - 1][j - 1][0] + 1;
                dp[i][j][1] = i - 1;
                dp[i][j][2] = j - 1;
            }
            else
            {
                bool flag = dp[i - 1][j][0] > dp[i][j - 1][0];

                dp[i][j][0] = max(dp[i - 1][j][0], dp[i][j - 1][0]);
                dp[i][j][1] = i - flag;
                dp[i][j][2] = j - !flag;
            }
        }
    }

    string temp;

    int i = len1, j = len2;

    while (i && j)
    {
        if (str1[i - 1] == str2[j - 1])
            temp.push_back(str1[i - 1]);
        tie(i, j) = tie(dp[i][j][1], dp[i][j][2]);
    }

    return {dp[len1][len2][0], string(temp.rbegin(), temp.rend())};
}

int main()
{
    scanf("%s  %s", str1, str2);

    auto [lcsLen, lcsStr] = solve();

    printf("%d\n", lcsLen);
    if (lcsLen != 0)
        printf("%s\n", lcsStr.c_str());

    return 0;
}
