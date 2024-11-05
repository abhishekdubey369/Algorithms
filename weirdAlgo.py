class Solution:

    def __init__(self):
        self.result = []

    def weirdAlgo(self,n:int):
        self.result.append(n)
        if n == 1:
            return self.result
        elif n%2==0:
            n=n//2
            return self.weirdAlgo(n)
        else:
            n=n*3+1
            return self.weirdAlgo(n)

if __name__ == "__main__":
    
    n = int(input())
    sol = Solution()

    for i in sol.weirdAlgo(n):
        print(i , end=" ")
