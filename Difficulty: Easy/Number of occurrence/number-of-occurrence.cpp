//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int countFreq(vector<int>& arr, int x) {
        // code here
        int n=arr.size();
        int h=n-1 , l=0 , m=0 , fo=-1;
	    
	    while(h>=l){
	        
	        m=floor((h+l)/2);
	        
	        if(arr[m]==x){
	            fo=m;
	            break;
	        }
	        
	        else if(arr[m]>x){
	            h=m-1;
	        }
	        else{
	            l=m+1;
	        }
	    }
	    
	    l=fo-1 ;
	    h=fo+1 ;
	    
	    if(fo==-1){
	        return 0;
	    }
	    
	    int co=1 , a1=1 , a2=1 ;
	    
	    while(a1 or a2){
	        if(a1 and l>=0 and arr[l]==x){
	           co++; 
	           l--;
	        }
	        else{
	            a1=0;
	        }
	        
	        if(a2 and h<n and arr[h]==x){
	            co++;
	            h++;
	        }
	        else{
	            a2=0;
	        }
	    }
	
	    return co;
    }
};


//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.countFreq(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends