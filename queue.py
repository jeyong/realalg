class Queue:
    def __init__(self):
        self.arr = []
        self.top = -1
        self.tail = -1
    def __str__(self):
        return str(self.arr)

    def pop(self):
        if len(self.arr) == 0:
            return None
        r = self.arr[0]
        self.arr = self.arr[1:]
        return r 

    def push(self, val):
        self.arr.append(val) 


q = Queue()
q.push(1)
q.push(2)
q.push(3)
print(q)
q.pop()
print(q)
q.pop()
print(q)
