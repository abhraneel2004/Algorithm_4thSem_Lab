inf = 999

def djikstra(n, source):
    d = [inf]*n
    parent = [-1]*n
    d[source] = 0
    parent[source] = "Start"
    S = []
    Q = [i for i in range(n)]
    while len(Q)>0:
        m = d[0]
        u = Q[0]
        for i in Q:
            if i not in S and d[i]<m:
                u = i
                m = d[i]
        Q.remove(u)
        S.append(u)
        for v in range(n):
            if (graph[u][v]!=0 and graph[u][v]!=inf) and (d[v]> d[u]+graph[u][v]):
                parent[v] = chr((u+65))
                d[v] = d[u]+graph[u][v]
                
    print("parent: ",parent)
    print("cost: ",d)


graph = []
with open("aw.txt", 'r') as file:
    content = file.readline()

    n = int(content.strip())
    for line in file:
        line = line.strip().split()
        for i in range(len(line)):
            line[i] = int(line[i].strip())
        graph.append(line)
    
source = int(input(f"Enter the source vertext (0-{n-1}): "))
djikstra(n, source)