#User function template for Python

class Solution:	
	def binarysearch(self, arr, n, k):
		# code here
		# code here
        l=0
        h=n-1 
        m = 0
        i=-1
        
        while(l<=h):

            if (l+h)%2==0 :m = int((l+h)/2)
            else :m = int((l+h)/2)+1
            
            if (k==arr[m]):
                return m
                
            elif k<arr[m]  :
                h = m-1
                
            elif(k>arr[m]):
                l = m+1

        return i
		    
		    


#{ 
 # Driver Code Starts
#Initial template for Python

if __name__ == '__main__':
    t=int(input())
    for i in range(t):
        n=int(input())
        arr=list(map(int, input().strip().split(' ')))
        k=int(input())
        ob = Solution()
        print (ob.binarysearch(arr, n, k))


# } Driver Code Ends