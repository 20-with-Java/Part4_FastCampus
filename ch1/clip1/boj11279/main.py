import sys

class MaxPriorityQueue:
    def __init__(self):
        self.heap = []
    
    def push(self, x):
        heapq.heappush(self.heap, -x)
    
    def pop(self):
        if not self.heap:
            return 0
        return -heapq.heappop(self.heap)

import heapq

n = int(sys.stdin.readline())
pq = MaxPriorityQueue()

for _ in range(n):
    x = int(sys.stdin.readline())
    if x == 0:
        sys.stdout.write(str(pq.pop()) + "\n")
    else:
        pq.push(x)

