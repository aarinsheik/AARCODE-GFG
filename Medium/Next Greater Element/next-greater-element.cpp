//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        // Your code here
        // vector <long long> res;
        // stack <int> st;
        // unordered_map <int,int> m;
        
        // st.push(arr[0]);
        // m[arr[0]]=-1;
        
        // for(int i=1 ; i<n ; i++){
            
        //     m[arr[i]]=-1;
        //     while(!st.empty() and arr[i]>st.top()){
        //         m[st.top()]=arr[i];
        //         st.pop();
        //     }
        //     st.push(arr[i]);
            
        // }
        
        // for(int i=0 ; i<n ; i++){
        //     res.push_back( m[arr[i]] );
        // }
        // return res;
        
        /*--- above code also works , but fails in time complexity---*/
        vector <long long> res;
        stack <long long> st;
        
        reverse(arr.begin() , arr.end());
        
        st.push(arr[0]);
        res.push_back(-1);
        
        
        for(int i=1 ; i<n ; i++){
            while(!st.empty() and arr[i]>=st.top()){
                st.pop();
            }
            if(st.empty()){
                res.push_back(-1);
                st.push(arr[i]);
                continue;
            }
            res.push_back(st.top());
            st.push(arr[i]);
        }
        
        reverse(res.begin() , res.end() );
        return res;
        
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
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution obj;
        vector <long long> res = obj.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}
// } Driver Code Ends