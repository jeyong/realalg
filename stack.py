class Stack :
    def __init__(self, top=0):
        self.top = top
        self.arr = [] 
    def __str__(self):
        return str(self.arr)

    def push(self, val):
        self.arr.append(val)
        self.top+=1

    def pop(self):
        if len(self.arr) == 0:
            return None
        v = self.arr[len(self.arr)-1]
        self.arr = self.arr[:len(self.arr)-1]
        return v 


s = Stack()
s.push(1)
s.push(2)
s.push(3)
print(s)
s.pop()
print(s)
s.pop()
print(s)
