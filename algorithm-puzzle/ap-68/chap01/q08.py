N = 12
cnt = 0

vector = [(0, 1), (0, -1), (-1, 0), (1, 0)] # (y, x)

def abc(point, movable, move_list):
    if point not in move_list:
        if movable == 1:
            return 1
        else:
            sm = 0
            for i in range(4):
                move_list.append(point)
                sm += abc((point[0]+vector[i][0], point[1]+vector[i][1]), movable-1, move_list.copy())
            return sm
    else:
        return 0
    

print(abc((-1,0), 15, [(0,0)])*4)
        
        


