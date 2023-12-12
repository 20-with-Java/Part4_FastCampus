import sys

class MinPriorityQueue:
    def __init__(self):
        self.heap = [0]

    def push(self, x):
        self.heap.append(x)
        current = len(self.heap) - 1
        while current > 1:
            parent = current // 2
            if self.heap[parent] <= self.heap[current]:
                break
            self.heap[parent], self.heap[current] = self.heap[current], self.heap[parent]
            current = parent

    def pop(self):
        if len(self.heap) == 1:
            return 0
        ret = self.heap[1]
        self.heap[1] = self.heap[-1]
        self.heap.pop()
        current = 1
        while current * 2 < len(self.heap):
            left = current * 2
            right = current * 2 + 1
            child = left
            if right < len(self.heap) and self.heap[right] < self.heap[left]:
                child = right
            if self.heap[current] <= self.heap[child]:
                break
            self.heap[current], self.heap[child] = self.heap[child], self.heap[current]
            current = child
        return ret

pq = MinPriorityQueue()
n = int(input())

for _ in range(n):
    x = int(sys.stdin.readline())
    if x == 0:
        sys.stdout.write(str(pq.pop()) + "\n")
    else:
        pq.push(x)

