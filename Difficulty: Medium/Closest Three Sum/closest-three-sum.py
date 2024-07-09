#User function Template for python3

# arr    : list of integers denoting the elements of the array
# target : as specified in the problem statement

class Solution:
    def threeSumClosest (self, arr, tar):
    # Your Code Here
        dif = 1e9
        val=-1
        
        arr.sort()
        
        for i in range(len(arr)-2) :
            j = i+1
            k=len(arr)-1
            
            while( j<k ):
                sm = arr[i]+arr[j]+arr[k]
                
                if abs(sm-tar)<dif :
                    dif=abs(sm-tar)
                    val = sm
                   
                elif abs(sm-tar)==dif :
                    val = max(sm,val)
                    
                if(tar==sm):
                    return sm
                if( tar>=sm ):
                    j+=1
                elif( tar<sm ):
                    k-=1
                    
        return val
            
#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())

    for _ in range(t):
        A = list(map(int, input().strip().split()))
        k = int(input())
        ob = Solution()
        print(ob.threeSumClosest(A, k))

# } Driver Code Ends