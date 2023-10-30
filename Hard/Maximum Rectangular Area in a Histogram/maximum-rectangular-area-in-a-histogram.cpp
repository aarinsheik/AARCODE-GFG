//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    stack <int> st;
    
    void presmo(vector <int> &ps ,long long arr[] , int n ){
        
        for(int i=0 ; i<n ; i++){
            
            if(st.empty()){
                st.push(i);
                ps.push_back(-1);
            }
            else if( arr[st.top()] >= arr[i] ){
               
                while(!st.empty() and arr[st.top()] >= arr[i] ){
                    st.pop();
                }
                if(st.empty()){
                    st.push(i);
                    ps.push_back(-1);    
                }
                else{
                    ps.push_back(st.top());
                    st.push(i);
                }
            }
            else if( arr[st.top()] < arr[i] ){
                ps.push_back(st.top());
                st.push(i);
            }
        }
    }
    
    
    long long getMaxArea(long long arr[], int n)
    {
        // Your code here
        vector <int> ps , ns ;
        
        st = stack<int>();
        
        presmo( ps , arr , n );
        reverse( arr ,arr+n );
        
        st = stack<int>();
        presmo( ns , arr , n );
        
        for(int i=0 ; i<n ; i++){
            ns[i]=n-1-ns[i];
        } 
        
        reverse( ns.begin() ,ns.end() );
        
        long long ar=0 , mar=0 ;
        
        reverse( arr ,arr+n );
        for(int i=0 ; i<n ; i++){
            
            ar = (arr[i])*(ns[i]-ps[i]-1);
            if(mar<ar) mar=ar;
        }
        
        return mar;
    }
};


//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends