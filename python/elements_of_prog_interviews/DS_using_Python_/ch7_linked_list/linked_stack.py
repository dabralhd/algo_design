class LinkedStack:
    class Node:
        def __init__(self, val=0, next_node=None):
            '''initializes a node with a given value'''
            self.val = val
            self.next = next_node

    def __init__(self):
        self.size = 0        
        self.head = None

    def push(self, val: int):
        '''creates a new node, and insert it at the head of stack'''        
        temp = self.Node(val, self.head)
        self.head = temp
        self.size += 1

    def pop(self) -> int:
        '''pops a value from the stack'''
        if self.is_empty() is True:
            raise "stack is empty"
        val = self.head.val
        self.head = self.head.next
        self.size -= 1
        return val

    def top(self):
        '''retrieves value at the top of the stack, does not pop'''
        if self.is_empty() is True:
            raise "stack is empty"
        return self.head.val
            
    def __len__(self):
        return self.size
    
    def is_empty(self):
        return len(self) == 0

def test_stack():
    list = LinkedStack()
    for num in range(10, 21):
        list.push_front(num)
        
    head = list
    while head:
        print(head.top())
        head.pop()
                
if __name__=="__main__":
    test_stack()
    # f = 9.1
    # print('Hello world')
    # print(id(f))
    # f = 0.3
    # print(id(f))
    # f += 1
    # print(id(f))


