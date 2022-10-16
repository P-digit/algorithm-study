import sys
import heapq as hq

def mysubmit():

    a = {}
    minabs = 0


    for _ in range(int(sys.stdin.readline())):
        i = int(sys.stdin.readline())
        if i == 0:
            if len(a) == 0:
                print(0)
            else:
                if len(a[minabs]) == 1:
                    print(a[minabs][0])
                    del a[minabs]
                    if len(a) != 0:
                        minabs = min(a.keys())
                else:
                    a[minabs].sort()
                    print(a[minabs][0])
                    a[minabs].remove(a[minabs][0])

        else:
            if len(a) == 0:
                minabs = abs(i)
            if abs(i) not in a:
                a[abs(i)] = [i]
            else:
                a[abs(i)].append(i)


def solution_1():
    input = sys.stdin.readline
    pq = []
    for _ in range(int(input())):
        x = int(input())
        if x:
            hq.heappush(pq, (abs(x), x))
        else:
            print(hq.heappop(pq)[-1] if pq else 0)

def solution_2():
    input = sys.stdin.readline
    min_heap = []
    max_heap = []

    for _ in range(int(input())):
        i = int(input())
        if i == 0:
            if min_heap:
                if max_heap:

                    if max_heap[0] == min_heap[0]:
                        print(-hq.heappop(max_heap))

                    elif max_heap[0] > min_heap[0]:
                        print(hq.heappop(min_heap))

                    elif max_heap[0] < min_heap[0]:
                        print(-hq.heappop(max_heap))
                else:
                    print(hq.heappop(min_heap))
            else:
                if max_heap:
                    print(-hq.heappop(max_heap))
                else:
                    print(0)

        else:
            if i > 0:
                hq.heappush(min_heap,i)
            else:
                hq.heappush(max_heap,abs(i))

        


solution_2()

    