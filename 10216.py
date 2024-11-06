import sys
input = sys.stdin.readline

def find(x):
    if parent[x] != x:
        parent[x] = find(parent[x])
    return parent[x]

def union(u, v):
    u = find(u)
    v = find(v)

    if u == v:
        return

    if level[u] > level[v]:
        u, v = v, u
    if level[u] == level[v]:
        level[v] += 1

    parent[u] = v

for _ in range(int(input())):
    n = int(input())

    parent = [i for i in range(n)]
    level = [0 for _ in range(n)]
    xyr = [[*map(int, input().split())] for _ in range(n)]

    for i in range(n):
        ix, iy, ir = xyr[i]
        for j in range(i + 1, n):
            jx, jy, jr = xyr[j]

            if (ix - jx) ** 2 + (iy - jy) ** 2 <= (ir + jr) ** 2:
                union(i, j)

    groups = set(find(i) for i in range(n))
    print(len(groups))
