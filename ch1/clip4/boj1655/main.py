import sys
import heapq

n = int(input())
small = []  # 작은 값들을 저장하는 힙
big = []    # 큰 값들을 저장하는 힙

for _ in range(n):
    num = int(sys.stdin.readline())
    if len(small) == len(big):
        heapq.heappush(small, -num)
    else:
        heapq.heappush(big, num)

    if small and big:
        if -small[0] > big[0]:
            small_val = -heapq.heappop(small)
            big_val = heapq.heappop(big)
            heapq.heappush(small, -big_val)
            heapq.heappush(big, small_val)
    
    sys.stdout.write(str(-small[0]) + "\n")
