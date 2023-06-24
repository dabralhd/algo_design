__x = 2

class Person:
    def __init__(self, x: int, y: int):
        self.x = x
        self._y = y
        self.__y = 100*self._y

    def __repr__(self):
        return(f'x: {self.x}, _y: {self._y}, __y: {self.__y}')

if __name__=='__main__':
    p1 = Person(10, 20)
    print(p1)
    print(p1._y)
    print(p1._Person__y)
    print(f'__x: {__x}')


