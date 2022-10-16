def my():

    n = int(input())

    for i in range(n):
        ps = input()
        result = ""
        while True:
            ps = ps.replace("()", "")
            if "()" not in ps:
                break
        if len(ps) > 0:
            result = "NO"
        else:
            result = "YES"
        print(result)

def b():
    for _ in range(int(input())):
        stk = []
        isVPS = True
        for ch in input():
            if ch == '(':
                stk.append(ch)
            else:
                if stk:
                    stk.pop()
                else:
                    isVPS = False
                    break
        if stk:
            isVPS = False
        print('YES' if isVPS else "NO")

b()