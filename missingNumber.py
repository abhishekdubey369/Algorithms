class Solution:
    def __init__(self):
        self.Missing = 0

    def swap(self,x:int,y:int)-> (int , int):

        a = x + y
        b = x - y

        return (a-b)//2 , (a+b)//2

    def missingNumber(self,N)-> int:
        for i in N:
            self.Missing +=i 
        return self.Missing

if __name__=="__main__":
    
    lim = int(input())
    lim = lim*(lim+1)//2
    temp = input()
    n = [int(i) for i in temp.split(" ")]
    sol = Solution()
    print(lim - sol.missingNumber(n))
