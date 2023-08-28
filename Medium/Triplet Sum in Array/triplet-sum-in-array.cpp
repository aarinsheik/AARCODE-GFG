//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool find3Numbers(int ar[], int n, int x)
    {
        //Your Code Here
        unordered_map < int , pair<int,int> > mp;
        
        for(int i=0 ; i<n ; i++){
            for(int j=i+1 ; j<n ; j++){
                pair <int,int> p{i,j};
                mp[ ar[i]+ar[j] ]=p;
            }
        }
        
        for(int i=0;i<n;i++ ){

            if( mp[x-ar[i]].first and mp[x-ar[i]].second and i!=mp[x-ar[i]].first and i!=mp[x-ar[i]].second ){
                return true;
            }
        }
        
        return false;
    }

};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,X;
		cin>>n>>X;
		int i,A[n];
		for(i=0;i<n;i++)
			cin>>A[i];
		Solution ob;
        cout <<  ob.find3Numbers(A, n, X) << endl;
    }
}

// } Driver Code Ends