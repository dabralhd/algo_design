class LinkedQueue:
    class Node:
        def __init__(self, val=0, prev=None, next_node=None):
            '''initializes a node with a given value, prev, and next_node pointers'''
            self.val = val
            self.next = next_node
            self.prev = prev

    def __init__(self):
        '''initializes a queue'''
        self.size = 0        
        self.head = None
        self.tail = None

    def enque(self, val: int):
        '''create a new node, and insert it before this node'''        
        temp = self.Node(val, None, self.tail)
        self.tail = temp
        if self.head is None:
            self.head = temp
        self.size += 1

    def deque(self) -> int:
        if self.is_empty() is True:
            raise "stack is empty"
        val = self.head.val        
        self.head = self.head.prev
        self.size -= 1
        if self.head:
            self.head.next = None
        if self.size == 0:
            self.tail = None            
        return val

    def front(self):
        if self.is_empty():
            raise "stack is empty"
        return self.head.val
            
    def __len__(self):
        return self.size
    
    def is_empty(self):
        return len(self) == 0

def test_queue():
    list = LinkedQueue()
    for num in range(10, 21):
        list.enque(num)
        
    head = list
    while head:
        print(head.front())
        head.deque()
                
if __name__=="__main__":
    test_queue()
    # f = 9.1
    # print('Hello world')
    # print(id(f))
    # f = 0.3
    # print(id(f))
    # f += 1
    # print(id(f))


