import queue
import collections
import sys

class BinaryTree:
    _k_invalid_num = -1

    class _Node:
        def __init__(self, val=0, left=None, right=None):
            self._val = val
            self._left = left
            self._right = right

    class _BalanceInfo:
        def __init__(self, balanced= True, height = 0):
            self._balanced = balanced
            self._height = height  
    

        def set_left(self, node):
            set._left = node

        def set_right(self, node):
            set._right = node

    def __init__(self, invalid_num=-1):
        self._k_invalid_num = invalid_num
        self._root = self._Node()

    def __init__(self, nums: list[int]):
        '''initialize a binray tree using a list of integer. 
        use self._k_invalid_num to indicate number not allowed in list'''
        if nums:
            q = queue.SimpleQueue()
            self._root = self._Node(nums[0])
            q.put(self._root)
            for idx in range(1, len(nums), 2):      
                p = q.get()          
                if nums[idx] != self._k_invalid_num:
                    p._left = self._Node(nums[idx])
                    q.put(p._left)
                if idx+1 < len(nums) and nums[idx+1]!=self._k_invalid_num:
                    p._right = self._Node(nums[idx+1])
                    q.put(p._right)


    def _inorder(self, node):
        if node:                
            self._inorder(node._left)
            print(node._val, end=', ')
            self._inorder(node._right)

    def inorder(self):
        print('inorder: ', end=' ')
        self._inorder(self._root)
        print('')

    def _preorder(self, node):
        if node:
            print(node._val, end=', ')
            self._preorder(node._left)
            self._preorder(node._right)

    def preorder(self):
        print('preorder: ', end=' ')        
        self._preorder(self._root)
        print('')

    def _postorder(self, node):
        if node:
            self._postorder(node._left)
            self._postorder(node._right)
            print(node._val, end=', ')     

    def postorder(self):
        print('postorder: ', end=' ')                
        self._postorder(self._root)
        print('')

    def is_height_balanced(self):
        def _balance_info(root):
            if root:
                left_info = _balance_info(root._left)
                if not left_info._balanced:
                    return self._BalanceInfo(False, 0)
                                
                right_info = _balance_info(root._right)
                if not right_info._balanced:
                    return self._BalanceInfo(False, 0)               

                return self._BalanceInfo(abs(left_info._height-right_info._height)<=1,
                                    max(left_info._height, right_info._height) + 1)

            return self._BalanceInfo(True, -1)
        return _balance_info(self._root)._balanced
    
    def is_symmetric(self):
        def _is_mirror_image(left, right):            
            if not left and not right:
                return True
            elif left and right:
                return  left._val==right._val and \
                        _is_mirror_image(left._left, right._right) and \
                        _is_mirror_image(left._right, right._left)
            return False
        
        if not self._root:
            return True
        return _is_mirror_image(self._root._left, self._root._right)
    
    def get_LCA(self, first, second):
        LCAInfo = collections.namedtuple('LCAInfo', ['count', 'lca'])
        def contains(node, first, second):
            if node:
                l_inf = contains(node._left, first, second)
                if l_inf.count == 2:
                    return l_inf
                r_inf = contains(node._right, first, second)
                if r_inf.count == 2:
                    return r_inf
                count = l_inf.count + r_inf.count + int(node is first) + int(node is second)
                return LCAInfo(count, node if count==2 else None)
            return LCAInfo(0, None)
        return contains(self._root, first, second)

    def sum_root_to_leaf(self):                
        def sum_helper(node):            
            if node:
                self._pathsum = self._pathsum<<1 | node._val
                sum_helper(node._left)
                sum_helper(node._right)

                if node._left is None and node._right is None:
                    self._total += self._pathsum
                self._pathsum >>= 1                    

        self._pathsum = 0
        self._total = 0
        sum_helper(self._root)
        return self._total     

    def check_bst_property(self):
        self._kmin = float('-inf')
        def helper_checkbst(node):
            if node:
                lresult = helper_checkbst(node._left)
                if node._val > self._kmin:                    
                    self._kmin = node._val
                else:
                    print(f'bst property breaks at node: {node._val}')
                    return False
                rresult = helper_checkbst(node._right)    
                return lresult and rresult
            return True
        return helper_checkbst(self._root)
    
    def firsk_key_greater_than(self, key: int):
        KeyStatus = collections.namedtuple('KeyStatus', ['key', 'valid'])
        valid = False
        candidate = float('-inf')
        def helper_first_key_greater_than(node, key):
            nonlocal candidate
            nonlocal valid
            curr = node
            while curr:
                if curr._val > key:
                    candidate = curr._val
                    valid = True
                    curr = curr._left
                else:
                    curr = curr._right
            return candidate

            # if status.valid:
            #     return status.key
            # return None
        return helper_first_key_greater_than(self._root, key)
        #return self.status.key


def traverse(bt: BinaryTree):
    bt.preorder()
    bt.inorder()
    bt.postorder()    

def test_traversal(nums: list[int]):
    traverse(BinaryTree(nums))   

def test_height_balance(nums: list[int]):
    t = BinaryTree(nums)
    traverse(t)
    print(f'balanced? {t.is_height_balanced()}')

def get_node(root, val: int):
    '''get node with given integer value'''
    if root:
        if root._val==val:
            return root
        else:
            return get_node(root._left, val) or get_node(root._right, val)
    return None

def test_lca():
    t = BinaryTree([10,20, 15, 1, -1, 17, 100, 2, 3, 70, -1, -1, 50])
    node1 = get_node(t._root, 3)
    node2 = get_node(t._root, 1)
    result = t.get_LCA(node1, node2)
    if result:
        print(result.lca._val)
    else:
        print('NoneType returned')

def test_sum_root_to_leaf():
    t = BinaryTree([1, 0, 1, 
                    0, 1, 0, 0, \
                    0, 1, -1, 1, -1, 0, -1, 0, \
                    -1, -1, -1, -1, 0, -1, 1, 0, -1, -1,\
                    -1, -1, -1, 1, -1, -1])
    t.preorder()
    print(f'root to leaf sum: {t.sum_root_to_leaf()}')

def test_check_bst_property():
    t = BinaryTree([25,20, 80, 4, -1, 75, 100, 2, 10, 70, -1, -1, 150])
    print(t.check_bst_property())

def test_first_key_greater_than():    
    t = BinaryTree([25,20, 80, 4, -1, 75, 100, 2, 10, 70, -1, -1, 150])
    t.inorder()
    print(t.firsk_key_greater_than(69))



if __name__ == '__main__':
    #test_traversal([1,-1, 2,3,4])
    test_traversal([10,20, 15, 1, -1, 17, 100, 2, 3, 70, -1, -1, 50])
    #test_height_balance([10,20, 15, 1, -1, 17, 100, 2, 3, 70, -1, -1, 50])
    #test_sum_root_to_leaf()
    #test_lca()
    #test_check_bst_property()
    #test_first_key_greater_than()



            











        




    