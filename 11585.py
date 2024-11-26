import math

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

def kmp(t, p):
    lent, lenp = len(t), len(p)
    lps = get_lps(p)
    i, j, cnt = 0, 0, 0

    while i < lent:
        if t[i] == p[j]:
            i += 1
            j += 1
        elif j == 0:
            i += 1
        else:
            j = lps[j - 1]

        if j == lenp:
            j = lps[j - 1]
            cnt += 1

    return cnt

_, p, t = open(0)

p = p.split()
t = t.split()

b = len(t)
a = kmp((t * 2)[:-1], p)
g = math.gcd(a, b)
print(f'{a // g}/{b // g}')
