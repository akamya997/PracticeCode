from queue import Queue

class graph:

    def __init__(self,maxv):
        self.maxv = maxv
        self.v = []
        for i in range(maxv):
            self.v.append([])

    def addedge(self,u,v):
        self.v[u].append(v)

def toposort(G):
    res = []
    deg = [0] * G.maxv
    q = Queue()
    for i in range(G.maxv):
        for j in G.v[i]:
            deg[j] += 1
    for i in range(G.maxv):
        if deg[i]==0:
            q.put(i)
    while q.empty() == False:
        u = q.get()
        res.append(u)
        for x in G.v[u]:
            deg[x] -= 1
            if deg[x] == 0:
                q.put(x)
    print(res)

if __name__ == '__main__':
    v = 9;
    G = graph(v)
    G.addedge(0,6)
    G.addedge(0,2)
    G.addedge(1,4)
    G.addedge(1,2)
    G.addedge(4,5)
    G.addedge(4,3)
    G.addedge(3,8)
    G.addedge(6,7)
    G.addedge(7,8)
    G.addedge(2,3)
    G.addedge(3,5)
    toposort(G)

