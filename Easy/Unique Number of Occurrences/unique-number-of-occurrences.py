
from typing import List


class Solution:
    def isFrequencyUnique(self, n : int, arr : List[int]) -> bool:
        
        u = []
        j=0
        k=1
        
        arr.sort()
        
        for i in range(0,len(arr)-1) :
        
            if(arr[i] == arr[i+1]) :
                k+=1
        
            else :
                u.append(k)
                k=1
        
        u.append(k)
        u.sort()
        
        
        for i in range(0,len(u)-1) :
        
            if(u[i] == u[i+1]) :
                return False
        
        return True
            
        






#{ 
 # Driver Code Starts

class IntArray:
    def __init__(self) -> None:
        pass
    def Input(self,n):
        arr=[int(i) for i in input().strip().split()]#array input
        return arr
    def Print(self,arr):
        for i in arr:
            print(i,end=" ")
        print()


if __name__=="__main__":
    t = int(input())
    for _ in range(t):
        
        n = int(input())
        
        
        arr=IntArray().Input(n)
        
        obj = Solution()
        res = obj.isFrequencyUnique(n, arr)
        
        result_val = 1 if res else 0
        print(result_val)

# } Driver Code Ends