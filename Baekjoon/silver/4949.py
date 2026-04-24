import sys

input = sys.stdin.readline


while True:
    stk = []
    P = input().strip('\n')

    if P ==".":
        break

    for e in P:
        if e == "(" or e == "[":
            stk.append(e)
        else:
            if stk:
                if e == ")":
                    if stk[-1] != "(":
                        stk.clear()
                        stk.append(-1)
                        break
                    else:
                        stk.pop(-1)
                elif e == "]":
                    if stk[-1] != "[":
                        stk.clear()
                        stk.append(-1)
                        break
                    else:
                        stk.pop(-1)
            else:
                if e ==")" or e == "]":
                    stk.append(-1)
                    break
    print("no" if stk else "yes")
    