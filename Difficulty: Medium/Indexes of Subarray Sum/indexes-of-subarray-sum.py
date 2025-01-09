#User function Template for python3
class Solution:
    def subarraySum(self, a, s):
        # code here
       v=a[0]
       i=0
       j=0
       n = len(a)
       
       while i<n :
           
            if v==s :
               j=j+1
               i=i+1
               return [j,i]
               
            elif v<s and i<n-1:
               i=i+1
               v+=a[i]
               
               
            elif v>s and i>j and j<n-1 :
                v-=a[j]
                j=j+1
                
            elif v>s and i==j and i<n-1 :
                i=i+1
                v=a[i]
                j=j+1
            
            else : 
                break
                
       return [-1]


#{ 
 # Driver Code Starts
# Initial Template for Python 3

if __name__ == '__main__':
    tc = int(input().strip())
    while tc > 0:
        arr = list(map(int, input().strip().split()))
        d = int(input().strip())
        ob = Solution()
        result = ob.subarraySum(arr, d)
        print(" ".join(map(str, result)))
        tc -= 1
        print("~")

# } Driver Code Ends