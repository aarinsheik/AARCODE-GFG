//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:    
    vector<int> rotation(int n)
    {
        // Code Heree
        queue <int> q;
        vector <int> res;
        int k=n-1;
        q.push(n);
        
        
        for(int i=0 ; i<n-1 ; i++){
            
            q.push(k);
            
            for(int j=0 ; j<k ; j++){
                int s=q.front();
                q.push(s);
                q.pop();
            }
            k--;
        }
        
        while(!q.empty()){
            res.push_back(q.front());
            q.pop();
        }
        reverse(res.begin() , res.end() );
        
        return res;
    }
};


//{ Driver Code Starts.

int main()
{
    Solution obj;
    int t;
    cin>>t;
    while(t--)
    {
        int n; cin >> n;
        vector<int > ans;
        ans = obj.rotation(n);
        for(int i:ans)
            cout<< i << " ";
        cout << endl;
        
    }
    return 0;
}

// } Driver Code Ends