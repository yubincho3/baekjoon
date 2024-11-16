INF = 987654321

def solve():
    global n
    dist[1] = 0

    for _ in range(n - 1):
        for u, v, w in uvw:
            if dist[u] != -INF and dist[v] < dist[u] + w:
                dist[v] = dist[u] + w
                prev[v] = u

    for u, v, w in uvw:
        if dist[u] != -INF and dist[v] < dist[u] + w:
            if v == n:
                return [-1]

            dist[v] = INF

    ans = [n]

    while n != 1:
        ans.append(prev[n])
        n = prev[n]

    return ans[::-1]

(n, m), *uvw = map(lambda s: [*map(int, s.split())], open(0))

dist = [-INF] * (n + 1)
prev = [0] * (n + 1)

print(*solve())
