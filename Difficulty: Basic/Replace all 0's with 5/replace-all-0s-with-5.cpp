//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int convertFive(int n);


// } Driver Code Ends
/*you are required to complete this method*/
class Solution {
  public:
    int convertFive(int n) {
        // Your code here
        int res=0 , x=0; 
        
        if(n==0){
            return 5;
        }
        
        while(n){
            
            int val = n%10;
            
            if(val==0){
                res = 5*pow(10,x) + res;
            }
            else{
                res = val*pow(10,x) + res;
            }
            
            n=n/10;
            x++;
        }
        
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.convertFive(n) << endl;
    }
}
// } Driver Code Ends