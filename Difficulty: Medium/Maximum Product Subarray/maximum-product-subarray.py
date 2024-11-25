#User function Template for python3
class Solution:

	# Function to find maximum
	# product subarray
	def maxProduct(self,arr):
    	    
        if not arr:
            return 0
    
        max_ending_here = min_ending_here = max_so_far = arr[0]
    
        for num in arr[1:]:
            if num < 0:
                # Swap because multiplying by a negative flips max and min
                max_ending_here, min_ending_here = min_ending_here, max_ending_here
    
            max_ending_here = max(num, max_ending_here * num)
            min_ending_here = min(num, min_ending_here * num)
    
            max_so_far = max(max_so_far, max_ending_here)
    
        return max_so_far

		# code here


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    tc = int(input())
    while tc > 0:
        arr = list(map(int, input().strip().split()))
        ob = Solution()
        ans = ob.maxProduct(arr)
        print(ans)
        tc -= 1

# } Driver Code Ends