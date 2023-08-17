//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // Function to find floor of x
    // n: size of vector
    // x: element whose floor is to find
    int findFloor(vector<long long> v, long long n, long long x){
        
        // Your code here
        vector < pair<int,int> > v1;
        
        for(int i=0 ; i<n ; i++){
            if(v[i]<=x){
                pair<int,int> q ;
                q.first=v[i];
                q.second=i;
                v1.push_back(q);
            }
        }
        
        int max=-999999 , mxi=-1;
        
        for(int i=0 ; i<v1.size() ; i++){
            if(v1[i].first>=max){
                max=v1[i].first;
                mxi=v1[i].second;
            }
        }
        
        return mxi;
        
    }
};


//{ Driver Code Starts.

int main() {
	
	long long t;
	cin >> t;
	
	while(t--){
	    long long n;
	    cin >> n;
	    long long x;
	    cin >> x;
	    
	    vector<long long> v;
	    
	    for(long long i = 0;i<n;i++){
	        long long temp;
	        cin >> temp;
	        v.push_back(temp);
	    }
	    Solution obj;
	    cout << obj.findFloor(v, n, x) << endl;
	   
	}
	
	return 0;
}
// } Driver Code Ends