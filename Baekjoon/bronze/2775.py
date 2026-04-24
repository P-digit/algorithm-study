cache = {}

def get_resident(floor, room):
    if floor == 0:
        cache[(floor, room)] = room
        return room
    
    if (floor, room) not in cache:
        cache[(floor, room)] = sum([get_resident(floor-1,i) for i in range(1,room+1)])
        
    return cache[(floor, room)]
    

    

for _ in range(int(input())):
    f = int(input())
    r = int(input())
    print(get_resident(f, r))
