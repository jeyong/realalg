class Node:
    def __init__(self, val):
        self.val = val 
        self.left = self.right = None
    
class BSTree :
    def __init__(self):
        self.root = None 

    def __str__(self):
        return "my tree"

    def BFT(self):
        queue = []
        queue.append(self.root)
        while len(queue) != 0 :
            cur = queue[0]
            queue = queue[1:]

            print(cur.val, "->")
            if cur.left != None:
                queue.append(cur.left)
            if cur.right != None:
                queue.append(cur.right)

    def add(self, val):
        n = Node(val)

        if self.root == None :
            self.root = n
            return 
        
        cur = self.root
        while cur != None :
            if cur.val < val :
                if cur.right == None :
                    cur.right = n 
                    break 
                cur = cur.right
            else:
                if cur.left == None :
                    cur.left = n
                    break 
                cur = cur.left

    
t = BSTree()
t.add(1)
t.add(2)
t.add(3)
t.add(4)
t.BFT()
