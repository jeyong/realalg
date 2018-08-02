

class Graph:
    def __init__(self):
        self.vertexs = [[1, 2], [0, 3, 4], [0, 4], [1, 4], [1, 2, 3]] 
    def __str__(self):
        return str(vertexs)
    
    def BFT(self, start):
        visited = []
        queue = []
        queue.append(start)
        while len(queue) != 0 :
            cur = queue[0]
            queue = queue[1:]
            if cur in visited :
                continue

            print(cur, "->")
            visited.append(cur)

            neighbors = self.vertexs[cur]
            for n in neighbors :
                if n in visited:
                    continue
                queue.append(n)

g = Graph()
g.BFT(0)
