//{ Driver Code Starts
// CPP program to check whether the given array
// is perfect or not.
#include <iostream>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    int check(int arr[], int n)
    {
        // Complete the function
        int inc=1 , con=0 , dec=0;
        
        for(int i=0 ; i<n-1 ; i++){
            
            if(arr[i]<arr[i+1] and inc==1){
                continue ;
            }
            else if(arr[i]==arr[i+1] and inc==1){
                inc=0;
                con=1;
            }
            else if(arr[i]==arr[i+1] and con==1){
                continue;
            }
            else if(arr[i]>arr[i+1] and (con==1 or inc==1) ){
                dec=1;
                inc=0;
                con=0;
            }
            else if(arr[i]>arr[i+1] and dec==1){
                continue ;
            }
            else{
                return 0;
            }
                
        }
        
        return 1;
        
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
        int arr[n];
        for (int i=0; i<n; i++)
           cin>>arr[i];
        Solution ob;
        if (ob.check(arr, n))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}
// } Driver Code Ends