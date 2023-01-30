class Solution:
    def fastPower(self, x: float, n: int) -> float:
        if x == 1.0:
            return 1.0
        if n == 1:
            return x
        if n < 0:
            x = 1 / x
            n = -n
            return self.fastPower(x, n)
        elif n > 0:                 
            if n % 2 == 0:
                return self.fastPower(x, n//2) ** 2
            else:
                y =  self.fastPower(x, n//2) ** 2
                y *= x
                return y
        return 1.0

    def myPow(self, x: float, n: int) -> float:
        if x == 1.0:
            return 1.0
        return self.fastPower(x, n)
