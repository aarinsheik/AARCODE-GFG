//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
    int thirdLargest(int a[], int n)
    {
         //Your code here
         vector <int> t({-1,-1,-1}) ;
         
         
         for(int i=0 ; i<3 ; i++){
             
            int m=0 ; 
            for(int j=0 ; j<n ; j++){
                if(m<a[j] and j!=t[0] and j!=t[1] and j!=t[2] ){
                    m=a[j];
                    t[i]=j;
                }
            }
            
         }
         
         return a[t[2]];
    }

};


//{ Driver Code Starts.
 
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution obj;
	    cout<<obj.thirdLargest(a,n)<<endl;
    }
}   
// } Driver Code Ends