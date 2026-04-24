import sys

input = sys.stdin.readline

list = set()
for _ in range(int(input())):
    list.add(int(input()))
    
print(*list, sep='\n')