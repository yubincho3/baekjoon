import sys
input = sys.stdin.readline

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

def solve():
    lps = get_lps(s)
    m = len(s)

    q, r = divmod(m, m - lps[m - 1])

    return 1 if r != 0 else q

while (s := input().strip()) != '.':
    print(solve())
