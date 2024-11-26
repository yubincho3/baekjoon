def get_lps(p):
    m = len(p)
    lps = [0] * m

    i, j = 1, 0
    while i < m:
        if p[i] == p[j]:
            j += 1
            lps[i] = j
            i += 1
        elif j == 0:
            lps[i] = 0
            i += 1
        else:
            j = lps[j - 1]

    return lps

def kmp(a, p):
    lps = get_lps(p)
    n, m = len(a), len(p)
    i, j = 0, 0

    while i < n:
        if a[i] == p[j]:
            i += 1
            j += 1
        elif j == 0:
            i += 1
        else:
            j = lps[j - 1]

        if j == m:
            yield i - j + 1
            j = lps[j - 1]

t = input()
p = input()
ans = [*kmp(t, p)]

print(len(ans))
print(*ans)
