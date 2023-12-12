def can_make_packs(cards, max_pack_size, m):
    pack_count = 0
    start = 0
    last_occurrence = {}
    
    for end, card in enumerate(cards):
        if card in last_occurrence and last_occurrence[card] >= start:
            start = last_occurrence[card] + 1
        
        if end - start + 1 == max_pack_size:
            pack_count += 1
            start = end + 1
        
        last_occurrence[card] = end
    
    return pack_count >= m

n, m = map(int, input().split())
cards = list(map(int, input().split()))

start = 1
end = n
result = 0

while start <= end:
    mid = (start + end) // 2
    if can_make_packs(cards, mid, m):
        result = mid
        start = mid + 1
    else:
        end = mid - 1

print(result)
