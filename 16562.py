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

(n, m, k), ais, *vws = map(lambda s: [*map(int, s.split())], open(0))

parent = [i for i in range(n + 1)]
level = [0 for _ in range(n + 1)]

for v, w in vws:
    union(v, w)

cost = sum(a for a, i in sorted((a, i + 1) for i, a in enumerate(ais)) if union(i, 0))
print(cost if cost <= k else 'Oh no')
