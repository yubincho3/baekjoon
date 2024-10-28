dp = [[[0] * 102 for _ in range(102)] for _ in range(102)]

s1, s2, s3 = map(lambda s: s.strip(), open(0))

len1 = len(s1)
len2 = len(s2)
len3 = len(s3)

for i in range(1, len1 + 1):
    for j in range(1, len2 + 1):
        for k in range(1, len3 + 1):
            if s1[i - 1] == s2[j - 1] == s3[k - 1]:
                dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1
            else:
                dp[i][j][k] = max(dp[i - 1][j][k], dp[i][j - 1][k], dp[i][j][k - 1])

print(dp[len1][len2][len3])
