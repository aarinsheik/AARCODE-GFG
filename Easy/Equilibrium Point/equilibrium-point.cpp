//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long ar[], int a) {
    
        // Your code here
        int eq=-1 , i=0 , j ;
        int sl=0 , sr=0 ;
    
        j=a-1;
        
        while(i<=j){
            
            if(sl<sr){
                sl+=ar[i];
                i++;
            }
            else if(sr<sl){
                sr+=ar[j];
                j--;
            }
            else if(sr==sl && i==j ){
                eq=i+1;
                break;
            }
            else{
                sl+=ar[i];
                sr+=ar[j];
                i++;j--;
            }
            
        }
        
        return eq;
    }
        
        

};

//{ Driver Code Starts.


int main() {

    long long t;
    
    //taking testcases
    cin >> t;

    while (t--) {
        long long n;
        
        //taking input n
        cin >> n;
        long long a[n];

        //adding elements to the array
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        Solution ob;

        //calling equilibriumPoint() function
        cout << ob.equilibriumPoint(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends