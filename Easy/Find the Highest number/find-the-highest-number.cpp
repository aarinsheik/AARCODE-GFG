//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int findPeakElement(vector<int>& a) 
    {
        // Code here.
        int l=0 , h=a.size()-1;
        
        while( l<=h ){
            
            int m = (l+h)/2;

            if(l==h-1){
                if(a[l]>a[h]){
                    return a[l];
                }
                else if(a[l]<a[h]){
                    return a[h];
                }
            }
            else if( (m+1<a.size() and m-1>=0 and a[m]>a[m+1] and a[m]>a[m-1]) ){
                return a[m];
            }
            else if(m+1<a.size() and m-1>=0 and a[m]<a[m+1] and a[m]>a[m-1]){
                l=m;
            }
            else if(m+1<a.size() and m-1>=0 and a[m]>a[m+1] and a[m]<a[m-1]){
                h=m;
            }
            
        }
        
        return -1;
    }
};



//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n;
    	cin >> n;
    	vector<int>a(n);
    	for(int i = 0; i < n; i++)
    		cin>>a[i];
    	Solution ob;
    	int ans = ob.findPeakElement(a);
    	cout << ans << "\n";
    }
	return 0;
}


// } Driver Code Ends