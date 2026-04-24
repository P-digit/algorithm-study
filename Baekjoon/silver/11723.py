import sys

N = int(sys.stdin.readline())


S = set()

def cal(ord):
    global S

    if 'add' in ord:
        _, n = ord.split()
        S.add(int(n))
    elif 'remove' in ord:
        _, n = ord.split()
        S.remove(int(n)) if int(n) in S else 0
    elif 'check' in ord:
        _, n = ord.split()
        print(1 if int(n) in S else 0)
    elif 'toggle' in ord:
        _, n = ord.split()
        S.add(int(n)) if int(n) not in S else S.remove(int(n))
    elif ord == 'all':
        S = set(e for e in range(1, 20 + 1))
    elif ord == 'empty':
        S = set()

for _ in range(N):
    ord = sys.stdin.readline().strip('\n')
    cal(ord)