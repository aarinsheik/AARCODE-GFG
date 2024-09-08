#User function Template for python3
class Solution:
    def minJumps(self, arr):
        #code here
        ind = 0
        nj = 0
        n = len(arr)
        
        
        while(1) :
            if(ind+arr[ind]<n-1) :
                lst = []
                ilst = []

                lst = arr[ind+1:ind+arr[ind]+1]
                ilst = [ k for k in range(ind+1,ind+arr[ind]+1) ]
                
                for i in range(0,len(lst)):
                    lst[i] = lst[i]+i

                if(lst) : ind = ilst[lst.index(max(lst))]
                else : return -1

                nj+=1
                if ind == 0 : return -1
                
            
            elif ind+arr[ind]>=n-1 :
                return nj+1  
                




#{ 
 # Driver Code Starts
#Initial Template for Python 3
if __name__ == '__main__':
    T = int(input())
    for i in range(T):
        # n = int(input())
        Arr = [int(x) for x in input().split()]
        ob = Solution()
        ans = ob.minJumps(Arr)
        print(ans)

# } Driver Code Ends