//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
    //code
        sort(a.begin() , a.end());
        
        int f=0 , l=m-1;
        int dif = a[l]-a[f];
        int j=f , i=m-1;
        
        while(i<a.size()){
            if(a[i]-a[j] < dif ){
                f = j;
                l = i;
                dif = a[l]-a[j];
            }
            i++;
            j++;
        }
        
        return dif;
    }   
};

//{ Driver Code Starts.
int main() {
	long long t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		vector<long long> a;
		long long x;
		for(long long i=0;i<n;i++)
		{
			cin>>x;
			a.push_back(x);
		}
		
		long long m;
		cin>>m;
		Solution ob;
		cout<<ob.findMinDiff(a,n,m)<<endl;
	}
	return 0;
}
// } Driver Code Ends