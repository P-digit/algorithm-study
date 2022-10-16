r, c = map(int, input().split())
board = [input() for _ in range(r)] 
chg_list = []

def paint_tile(board):
    arr = []
    for i in range(2):
        count = 0
        for j in range(8):
            for k in range(4):
                if i % 2: # 처음 W맞
                    if j % 2:
                        if board[j][2*k] != "B":
                            count += 1

                        if board[j][2*k+1] != "W":
                            count += 1
                    else:
                        if board[j][2*k] != "W" :
                            count += 1

                        if board[j][2*k+1] != "B":
                            count += 1

                else: # 처음 B 맞
                    if j % 2:
                        if board[j][2*k] != "W":
                            count += 1

                        if board[j][2*k+1] != "B":
                            count += 1
                    else:
                        if board[j][2*k] != "B":
                            count += 1
                            
                        if  board[j][2*k+1] != "W":
                            count += 1

        arr.append(count)          
    return min(arr)


for i in range(r-7):
    for j in range(c-7):
        ext_board = [board[i+k][j:j+8] for k in range(8)]
        chg_list.append(paint_tile(ext_board))

print(min(chg_list))



""" 

        if ext_board[0][0] == 'W':
            for l in range(8):
                if l % 2 == 0:
                    for k in range(4):
                        if ext_board[l][2*k] != "W":
                            chg += 1
                        if ext_board[l][2*k+1] != "B":
                            chg += 1
                else:
                    for k in range(4):
                        if ext_board[l][2*k] != "B":
                            chg += 1
                        if ext_board[l][2*k+1] != "W":
                            chg += 1

        else:
            for l in range(8):
                if l % 2 == 0:
                    for k in range(4):
                        if ext_board[l][2*k] != "B":
                            chg += 1
                        if ext_board[l][2*k+1] != "W":
                            chg += 1
                else:
                    for k in range(4):
                        if ext_board[l][2*k] != "W":
                            chg += 1
                        if ext_board[l][2*k+1] != "B":
                            chg += 1

        chg_list.append(chg)

 """