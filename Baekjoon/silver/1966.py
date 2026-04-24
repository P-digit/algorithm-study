from collections import deque

T = int(input())
for _ in range(T):
    printer_queue = deque()
    N, M = map(int, input().split())
    doc = [n for n in map(int, input().split())]


    for j in range(len(doc)):
        printer_queue.append((doc[j], j))
    
    count = 0
    top = max(doc)
    while True:
        head = printer_queue.popleft()
        if head[0] != top:
            printer_queue.append(head)
        else:
            count += 1
            if head[-1] == M:
                break
            doc.remove(head[0])
            top = max(doc)
    print(count)
    
    
    
    


