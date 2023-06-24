# Node = [val, next]
# List: size, tail

class Empty (Exception):
    pass

class Queue_Circular_LinkedList:
    """implements queue using circular linked list"""
    class _Node:
        """class to represent node of the list"""
        def __init__(self, val=0, next_node=None):
            self._val = val
            self._next = next_node  

    def __init__(self):
        self._len = 0
        self._tail = None
    
    def enque(self, val):
        """enques an element at the tail of the queue"""
        node = self._Node(val, None)
        if self.is_empty():
            node._next = node
        else:
            node._next = self._tail._next
            self._tail._next = node
        self._tail = node
        self._len += 1          

    def deque(self) -> int:
        if self.is_empty():
            raise Empty('underflow')
        val = self._tail._next._val
        if len(self) == 1:
            self._tail = None
        else:
            self._tail._next = self._tail._next._next
        self._len -= 1
        return val

    def front(self) -> int:
        if self.is_empty():
            raise self.Empty('undeflow')
        return self._tail._next._val
        
    def rotate(self, times: int=1):        
        if len(self):
            for n in range(times):                
                self._tail = self._tail._next

    def __len__(self):
        return self._len
    
    def is_empty(self):
        return len(self) == 0
    
def basic_test_queue():
    q = Queue_Circular_LinkedList()
    for num in range(10, 21):
        q.enque(num)
        
    while q.is_empty()==False:
        print(q.front())
        q.deque()    

def rotate_test_circular_queue():
    q = Queue_Circular_LinkedList()
    for num in range(10, 20):
        q.enque(num)
    
    print(f'q size before rotation: {len(q)}')

    for itr in range(len(q)):
        print(q.front())
        q.rotate()            
    print(f'q size AFTER rotation: {len(q)}')


if __name__=='__main__':
    #basic_test_queue()
    rotate_test_circular_queue()



    
