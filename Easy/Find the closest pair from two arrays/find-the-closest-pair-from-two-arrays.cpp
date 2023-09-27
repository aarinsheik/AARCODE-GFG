//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function teamplate for C++

class Solution{
  public:
    vector<int> printClosest(int arr[], int brr[], int n, int m, int x) {
        //code here
        int i=0 , j=m-1 , mv = 1e9 , sum=0 ;
        vector <int> res;
        
        while(i<n and j>-1){
            
            sum=arr[i]+brr[j];
            
            if( abs(sum-x)<mv ){
                res.clear();
                res = {arr[i],brr[j]};
                mv = abs(sum-x);
            }
            
            if(sum==x){
                return res;
            }
            else if(i<n and sum<x){
                i++;
            }
            else if(j>-1 and sum>x){
                j--;
            }
        }
        // cout<<res[0]<<" "<<res[1]<<endl;
        return res;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	int m,n,x;
	while(t--)
    {
        cin>>n>>m;
        int a[n],b[m];
        
        for(int i=0;i<n;i++)
            cin>>a[i];
            
        for(int i=0;i<m;i++)
            cin>>b[i];
            
        cin>>x;
        
        vector<int> ans;
        Solution ob;
        ans = ob.printClosest(a, b, n, m, x);
        cout << abs(ans[0] + ans[1] - x) << endl;
        
    }
    return 0;
}

// } Driver Code Ends