#User function Template for python3

class Solution:
    def len_num(self, s):
        # Function to calculate the length of the number
        c = 0
        while s:
            s = s // 10
            c += 1
        return c
    
    def karatsuba(self, x, y):
        # Base case for recursion
        if x < 10 or y < 10:
            return x * y
        
        # Determine the size of the numbers
        n = max(self.len_num(x), self.len_num(y))
        half = n // 2
        
        # Split the digit sequences in the middle
        a = x // (10**half)
        b = x % (10**half)
        c = y // (10**half)
        d = y % (10**half)
        
        # Recursively calculate three products
        ac = self.karatsuba(a, c)
        bd = self.karatsuba(b, d)
        ad_plus_bc = self.karatsuba(a + b, c + d) - ac - bd
        
        # Combine the results to get the final product
        return ac * (10**(2 * half)) + ad_plus_bc * (10**half) + bd
    
    def karatsubaAlgo(self, A, B):
        # Convert binary strings A and B to integers
        a = int(A, 2)
        b = int(B, 2)
        
        # Perform the Karatsuba multiplication
        return self.karatsuba(a, b)


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__': 
    t = int (input ())
    for _ in range (t):
        A,B = map(str,input().split())
        
        ob = Solution()
        print(ob.karatsubaAlgo(A,B))
# } Driver Code Ends