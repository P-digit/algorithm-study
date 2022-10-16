import sys
from math import ceil
N, M = map(int , sys.stdin.readline().split())

tree_height = [e for e in map(int, sys.stdin.readline().split())]

lv = 0
rv = 1_000_000_000
cut = ceil((lv + rv) / 2)

while True:
    cut = ceil((lv + rv) / 2)
    if lv == rv or cut == lv or cut == rv:
        break

    get_tree = 0
    for e in tree_height:
        if e - cut > 0:
            get_tree += (e - cut)
    if get_tree >= M:
        lv = cut
    else:
        rv = cut

if lv == rv:
    print(rv)
else:
    print(lv)