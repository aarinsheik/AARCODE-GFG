#User function Template for python3

class Solution:
    
    
    #Function to sort the array according to difference with given number.
    def sortAbs(self,a, n, k):
        
        a = sorted(a,key = lambda x: abs(x-k))
        
        # q = a[:]
        # for i in range(0,n) :
        #     q[i] = abs(a[i]-k)
        
        # w = q[:]
        # w.sort()
        # e = []
        
        # for i in range(0,len(w)) :
        #     for j in range(0,len(q)) :
        #         if w[i] == q[j] :
        #             e.append(a[j])
        #             q[j] = -999 
                
        
        # for i in range(0,n-1) :
        #     for j in range(0,n-1-i) :
        #         if(q[j]>q[j+1] ):
        #             q[j+1] , q[j] = q[j] , q[j+1]
        #             a[j+1] , a[j] = a[j] , a[j+1]
                
        return a
            

            


#{ 
 # Driver Code Starts
#Initial Template for Python 3
import atexit
import io
import sys

_INPUT_LINES = sys.stdin.read().splitlines()
input = iter(_INPUT_LINES).__next__
_OUTPUT_BUFFER = io.StringIO()
sys.stdout = _OUTPUT_BUFFER

@atexit.register

def write():
    sys.__stdout__.write(_OUTPUT_BUFFER.getvalue())

if __name__=='__main__':
    t = int(input())
    for tt in range(t):
        n,k = map(int, input().strip().split())
        a = list(map(int, input().strip().split()))
        ob=Solution()
        print(*ob.sortAbs(a,n,k))
        
    	 
# } Driver Code Ends