N = input()
m_list = []
if len(N) <= 3:
    test = 1

    while True:
        if test == int(N):
            break
        result = 0
        for i in range(len(str(test))):
            result += int(str(test)[i])
        result += test

        if result == int(N):
            m_list.append(test)
        
        test += 1
    

else:
    test = int(N) - pow(10, len(N)-2)

    while True:
        if test == int(N):
            break
        result = 0
        for i in range(len(str(test))):
            result += int(str(test)[i])
        result += test

        if result == int(N):
            m_list.append(test)
        
        test += 1
        
        
print(min(m_list) if m_list else 0)





