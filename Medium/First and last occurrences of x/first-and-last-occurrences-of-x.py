#User function Template for python3


def find(arr,n,x):
    # code here
    s=-1 
    e=-1
    fg=0 
    
    for i in range(n):
        if(arr[i]==x and fg==0):
            s=i
            e=i
            fg=1
        if(fg==1 and i==n-1):
            break
        if(fg==1 and i<n and arr[i]==arr[i+1]):
            e+=1
        elif(fg==1 and i<n and arr[i]!=arr[i+1]):
            break
    
    return (s,e)
    

#{ 
 # Driver Code Starts
t=int(input())
for _ in range(0,t):
    l=list(map(int,input().split()))
    n=l[0]
    x=l[1]
    arr=list(map(int,input().split()))
    ans=find(arr,n,x)
    print(*ans)
# } Driver Code Ends