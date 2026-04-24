N = int(input())
M = int(input())

graph = []

for _ in range(M):
    a, b = map(int, input().split())
    if len(graph) == 0:
        graph.append(set([a, b]))
    else:
        chk_a = -1
        chk_b = -1

        for i in range(len(graph)):
            chk_set = graph[i]
            if a in chk_set:
                chk_a = i
            if b in chk_set:
                chk_b = i
        
        if chk_a == -1 and chk_b == -1:
            graph.append(set([a, b]))
        else:
            if chk_a == -1 or chk_b == -1:
                if chk_a > chk_b:
                    graph[chk_a].add(b)
                else:
                    graph[chk_b].add(a)
            elif chk_a == chk_b:
                continue
            else:
                new_graph = set().union(graph[chk_a], graph[chk_b])
                graph[chk_a] = new_graph
                graph.pop(chk_b)

for s in graph:
    if 1 in s:
        print(len(s)-1)
        break