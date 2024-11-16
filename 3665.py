import sys
input = sys.stdin.readline

def solve():
    adj = [[False] * (n + 1) for _ in range(n + 1)]
    inc = [0] * (n + 1)

    t_len = len(t)
    for i in range(t_len):
        for j in range(i + 1, t_len):
            adj[t[j]][t[i]] = True
            inc[t[i]] += 1

    for a, b in ab:
        if not adj[a][b]:
            a, b = b, a

        adj[a][b] = False
        adj[b][a] = True
        inc[b] -= 1
        inc[a] += 1

    v = []

    for i in range(1, n + 1):
        if inc[i] == 0:
            v.append(i)

    ans = []
    uncertain = False

    while v:
        if len(v) > 1:
            uncertain = True

        now = v.pop()
        ans.append(now)

        for i in range(1, n + 1):
            if not adj[now][i]:
                continue

            inc[i] -= 1
            if inc[i] == 0:
                v.append(i)

    if len(ans) < n:
        return ['IMPOSSIBLE']

    if uncertain:
        return ['?']

    return ans[::-1]

for _ in range(int(input())):
    n = int(input())
    t = [*map(int, input().split())]
    ab = [[*map(int, input().split())] for _ in range(int(input()))]

    print(*solve())
