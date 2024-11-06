def find(x):
    if parent[x] != x:
        parent[x] = find(parent[x])
    return parent[x]

def union(u, v):
    u = find(u)
    v = find(v)

    if u == v:
        return False

    if level[u] > level[v]:
        u, v = v, u
    if level[u] == level[v]:
        level[v] += 1
    parent[u] = v

    return True

n, *xys = map(lambda s: [*map(float, s.split())], open(0))
n = int(n[0])

parent = [i for i in range(n)]
level = [0 for _ in range(n)]
dist = []

for i in range(n):
    x1, y1 = xys[i]
    for j in range(i + 1, n):
        x2, y2 = xys[j]
        dist.append(((x1 - x2)**2 + (y1 - y2)**2, i, j))

ans = 0

for m, x, y in sorted(dist):
    if union(x, y):
        ans += m ** 0.5

print(ans)
