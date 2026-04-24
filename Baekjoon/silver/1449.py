def mysubmit():


    n, l = map(int, input().split())
    coords = list(map(int, input().split()))

    sp = 0
    ep = 1
    count = 0
    use_coord = 0

    while use_coord < len(coords) and ep <= len(coords):
        if ep == len(coords):
            count += 1
            use_coord += abs(sp-ep)
            break
        
        if abs(coords[sp] - coords[ep]) + 1 > l:
            use_coord += abs(sp-ep)
            count += 1
            sp = ep

        ep += 1
    print(count)

def sol():
    N, L = map(int, input().split())
    coord = [False] * 1001
    for i in map(int, input().split()):
        coord[i] = True

    ans = 0
    x = 0

    while x < 1001:
        if coord[x]:
            ans += 1
            x += L
        else:
            x += 1

    print(ans)