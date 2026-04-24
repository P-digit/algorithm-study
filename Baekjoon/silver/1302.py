import sys
import heapq as hq

input = sys.stdin.readline

def mysubmit_1():


    class books():
        book_list = {}

        def __init__(self, name):
            self.name = name

    for _ in range(int(input())):
        bn = input().strip()
        sb = books(bn)
        if bn not in books.book_list:
            books.book_list[bn] = 1
        else:
            books.book_list[bn] += 1

    maxsell = max(books.book_list.values())
    result = []

    for key, value in books.book_list.items():
        if value == maxsell:
            result.append(key)
    result.sort()
    print(result[0])


def mysubmit_2():
    bk_list = []
    pq = []
    for _ in range(int(input())):
        count = 0
        bn = input().strip()
        for book in bk_list:
            if bn == book[-1]:
                book[0] -= 1
                count +=1
                break
        if count == 0:
            bk_list.append([-1, bn])
        
    for book in bk_list:
        hq.heappush(pq, book)
    print(hq.heappop(pq)[-1])

def sol_1():
    d = {}
    l = []
    for _ in range(int(input())):
        book = input().strip()
        if d.get(book):
            d[book] -= 1
        else:
            d[book] = -1
    for k, v in d.items():
        l.append((v, k))
    l.sort()
    print(l.pop(0)[-1])


mysubmit_2()