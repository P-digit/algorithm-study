import sys

N = int(input())
board = []

for _ in range(N):
    board.append([e for e in map(int, sys.stdin.readline().split())])

def dnq(y, x, n):
    b = 0
    w = 0
    def search(y, x, n):
        is_homo = True
        factor = -1
        for i in range(n):
            if is_homo:
                for j in range(n):
                    chk = board[y+i][x+j]
                    if factor == -1:
                        factor = chk
                    else:
                        if chk != factor:
                            is_homo = False
                            break
        return (is_homo, factor)
    if n == 1:
        if search(y,x,n)[1]:
            b += 1
        else:
            w += 1
    else:
        trial = search(y,x,n)
        if trial[0]:
            if trial[1]:
                b += 1
            else:
                w += 1
        else:
            cp1 = dnq(y, x, n//2)
            cp2 = dnq(y, x+n//2, n//2)
            cp3 = dnq(y+n//2, x, n//2)
            cp4 = dnq(y+n//2, x+n//2, n//2)
            w += cp1[0] + cp2[0] + cp3[0] + cp4[0]
            b += cp1[1] + cp2[1] + cp3[1] + cp4[1]

    return (w, b)

print(*dnq(0,0,N), sep='\n')