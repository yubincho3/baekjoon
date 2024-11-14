import sys
input = sys.stdin.readline

INF = 987654321

def solve():
    dist[1] = 0

    for _ in range(n - 1):
        for s, e, t in edges:
            dist[e] = min(dist[e], dist[s] + t)

    for s, e, t in edges:
        if dist[e] > dist[s] + t:
            return 'YES'

    return 'NO'

for _ in range(int(input())):
    n, m, w = map(int, input().split())
    dist = [INF] * (n + 1)

    edges = []

    for _ in range(m):
        s, e, t = map(int, input().split())
        edges.append([s, e, t])
        edges.append([e, s, t])

    for _ in range(w):
        s, e, t = map(int, input().split())
        edges.append([s, e, -t])

    print(solve())
