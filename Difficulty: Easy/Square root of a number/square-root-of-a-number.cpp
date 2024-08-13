//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to find square root
// x: element to find square root
class Solution {
  public:
    long long int findsqrt( long long int num , long long int l , long long int h ){
        
        long long int m=(l+h)/2;
        
        if(m*m==num or ( m*m<num and (m+1)*(m+1)>num ) ){
            return m;
        }
        
        if(m*m<num)
            return findsqrt(num , m , h );
        else
            return findsqrt(num, l , m );
        
    }
    
    long long int floorSqrt(long long int n) {
        // Your code goes here
        if(n==1 or n==0) return n;
        
        return findsqrt(n , 0 , n );
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        Solution obj;
        cout << obj.floorSqrt(n) << endl;
    }
    return 0;
}

// } Driver Code Ends