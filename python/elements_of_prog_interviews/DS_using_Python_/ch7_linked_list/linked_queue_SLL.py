class LinkedQueue_SLL:
    class Node:
        def __init__(self, val=0, next_node=None):
            '''initializes a node with a given value'''
            self.val = val
            self.next = next_node

    def __init__(self):
        self.size = 0        
        self.head = None
        self.tail = None

    def enque(self, val: int):
        '''creates a new node, and insert it at the tail of queue'''        
        temp = self.Node(val)
        if self.tail:
            self.tail.next = temp
        self.tail = temp
        if self.head is None:
            self.head = temp
        self.size += 1

    def deque(self) -> int:
        '''deque a value from the stack'''
        if self.head:
            val = self.head.val
            self.head = self.head.next
            self.size -= 1
            if self.size==0:
                self.tail = None
            return val
        raise "underflow!"

    def front(self):
        '''retrieves value at the front of the queue, does not pop'''
        if self.head:
            return self.head.val
        raise "underflow!"
            
    def __len__(self):
        return self.size
    
    def is_empty(self):
        return len(self) == 0

def test_queue():
    list = LinkedQueue_SLL()
    for num in range(10, 21):
        list.enque(num)
        
    while list.is_empty()==False:
        print(list.front())
        list.deque()
                
if __name__=="__main__":
    test_queue()
    # f = 9.1
    # print('Hello world')
    # print(id(f))
    # f = 0.3
    # print(id(f))
    # f += 1
    # print(id(f))


