def solve(s):
    ans = 0

    slen, i = len(s), 0
    while i < slen:
        ans += s[0] != s[i]
        while i < slen and s[0] != s[i]:
            i += 1
        i += 1

    return ans

s = input()
print(solve(s))
