#User function Template for python3

#Function to find a continuous sub-array which adds up to a given number.
#User function Template for python3

#Function to find a continuous sub-array which adds up to a given number.
class Solution:
    def subArraySum(self,arr, n, s): 
       #Write your code here
        lr = [0,0] 
        sum = 0
       
        while(1) :
           
            if sum == s :
                if(sum == 0) : return [-1]
                
                lr[0]+=1
                return lr
                
            elif sum < s :
                
                if(lr[1]==n):
                    break
                
                sum+=arr[lr[1]]
                lr[1]+=1
                
            
            elif sum > s :
                sum-=arr[lr[0]]
                lr[0]+=1
            
        
        return [-1]        

#{ 
 # Driver Code Starts
#Initial Template for Python 3

import math

def main():
        T=int(input())
        while(T>0):
            
            NS=input().strip().split()
            N=int(NS[0])
            S=int(NS[1])
            
            A=list(map(int,input().split()))
            ob=Solution()
            ans=ob.subArraySum(A, N, S)
            
            for i in ans:
                print(i, end=" ")
                
            print()
            
            T-=1


if __name__ == "__main__":
    main()
# } Driver Code Ends