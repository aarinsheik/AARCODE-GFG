#User function Template for python3

class Solution:
    
    def merge(self,a,low,mid,high):
        
        i = low 
        j = mid+1
        k = []
        
        while(i<=mid and j<=high) :
            if( a[i][0]<=a[j][0] ):
                k.append( (a[i][0],a[i][1]) )
                i+=1
            
            else:
                k.append( (a[j][0],a[j][1]) )
                j+=1
        
        while(i<=mid): 
            k.append( (a[i][0],a[i][1]) )
            i+=1
        while(j<=high): 
            k.append( (a[j][0],a[j][1]) )
            j+=1
            
        for b in range(low,high+1):
            a[b]=k[b-low]
        
        return a
    
    def MS(self,a,l,h):
        
        m = int((l+h)/2)
        if(l<h):
            a = self.MS(a,l,m)
            a = self.MS(a,m+1,h)
            a = self.merge(a,l,m,h)
        return a
    
    #Function to find the minimum number of platforms required at the
    #railway station such that no train waits.

    def minimumPlatform(self,n,art,dep):
        
        s=0
        k = []
        pt = 1
        tup = []
        for (i,j) in zip( art , dep) :
            tup.append((i,j))

        tup = self.MS(tup,0,n-1)
        

        for i in range(0,n-1) :
    
            if  tup[i][1]>= tup[i+1][0] :
                    
                if k :
                    s = min(k)

                if( k and s<tup[i+1][0] ) :
                    pt-=1
                    k.remove(s)
            
                pt+=1
                k.append( tup[i][1] )
      
        return pt


#{ 
 # Driver Code Starts
#Initial Template for Python 3
import atexit
import io
import sys

#Contributed by : Nagendra Jha


if __name__ == '__main__':
    test_cases = int(input())
    for cases in range(test_cases) :
        n = int(input())
        arrival = list(map(int, input().strip().split()))
        departure = list(map(int, input().strip().split()))
        ob=Solution()
        print(ob.minimumPlatform(n,arrival,departure))
# } Driver Code Ends