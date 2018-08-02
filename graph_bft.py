
class Graph:
    def __init__(self):
        self.vertexs={"S":["A", "B"], "A":["F"], "B": ["A", "F"], "F": None}

    def __str__(self):
        return str(self.vertexs)

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
    g.BFT("S")
