colors = {"black":0, "brown":1, "red":2, "orange":3, "yellow":4, "green":5, "blue":6, "violet":7, "grey":8, "white":9}




result = ''

for i in range(3):
    resistance = input()
    if i == 2:
        result = int(result) * (10 ** colors[resistance])
    else:
        result += str(colors[resistance])

print(result)