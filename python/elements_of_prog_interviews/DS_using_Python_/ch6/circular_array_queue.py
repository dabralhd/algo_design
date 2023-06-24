class Circular_Buffer_Queue:
    CAPACITY = 10
    def __init__(self):
        self.buffer = [int] * self.CAPACITY
        self.size = 0
        self.front = 0

    def enqueue(self, val: int):
        if self.full():
            raise Exception('Overflow')
        avail = (self.front + self.size) % self.CAPACITY
        self.buffer[avail] = val
        self.size += 1

    def dequeue(self) -> int:
        if self.empty():
            raise Exception('underflow')
        val = self.buffer[self.front]
        self.front = (self.front + 1) % self.CAPACITY
        self.size -= 1
        return val

    def empty(self)->bool:
        return self.size == 0
    
    def full(self)->bool:
        return self.size == self.CAPACITY
    
    def __len__(self) -> int:
        return self.size
    

def test_circular_queue():
    q = Circular_Buffer_Queue()
    for i in range(10):
        q.enqueue(i)

    for i in range(10):
        print(f'queue length: {len(q)}, front: {q.dequeue()}')
    print(f'final queue length: {len(q)}')

if __name__ == '__main__':
    test_circular_queue()


        
        