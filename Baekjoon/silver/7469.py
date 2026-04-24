import sys

input = sys.stdin.readline

n, m = map(int, input().split())

class Node():
    arr = []


    def __init__(self, value, N):
        self.value = value
        self.N = N
        


arr = [e for e in map(int, input().split())]

dic = {}


        







"""
first_dic = {}

ix = 1
for e in map(int, input().strip("\n").split()):
    first_dic[ix] = e
    ix = (int(ix) + 1)


for _ in range(m):
    dic = {}
    lo, hi, find = map(int, input().split())
    for i in range(lo, hi+1):
        dic[i-lo+1] = first_dic[lo]

    print(dic[find]) """

    