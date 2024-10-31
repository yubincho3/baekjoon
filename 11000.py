import heapq

st = sorted([*map(int, x.split())] for x in [*open(0)][1:])
heap = [0]

for s, e in st:
    if heap[0] <= s:
        heapq.heappop(heap)
    heapq.heappush(heap, e)

print(len(heap))
