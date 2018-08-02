
class Graph:
    def __init__(self):
        self.vertexs={"S":{"A":6, "B":2}, "A":{"F":1}, "B": {"A":3, "F":5}, "F": None}
        self.costs = {}
        for i in list(self.vertexs.keys()):
            self.costs[i] = 1000

    def __str__(self):
        return str(self.vertexs)
    def showcost(self):
        print(self.costs)
    def dij(self, start):
        self.visited = []
        if start not in list(self.vertexs.keys()):
            return

        self.costs[start] = 0
        v = self.getMinUnvisited()
        while v != None :
            
            if self.vertexs[v] != None :
                neighbors = list(self.vertexs[v].keys())
            else:
                neighbors = []
            
            self.visited.append(v)
            for n in neighbors:
                if self.costs[n] > self.costs[v] + self.vertexs[v][n]:
                    self.costs[n] = self.costs[v] + self.vertexs[v][n]
            v = self.getMinUnvisited()
            print(v)

    def getMinUnvisited(self):
        index = None 
        smallest = 1000
        for i in self.costs :
            if i in self.visited:
                continue
            else:
                if smallest > self.costs[i]:
                    smallest = self.costs[i]
                    index = i 
        return index

    def BFT(self, start):
        if list(self.vertexs.keys()).count(start) == 0 :
            return 
        q = []
        visited = []
        q.append(start)
        while len(q) > 0 :
            v = q[0]
            q = q[1:]
            if v in visited:
                continue 
            print (v, "-> ")
            visited.append(v)
            if self.vertexs[v] :
                q.extend(self.vertexs[v])

if __name__ == "__main__":
    g = Graph()
    g.dij("S")
    g.showcost()
