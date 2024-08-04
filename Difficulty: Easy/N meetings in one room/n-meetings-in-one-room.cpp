//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room
    
    int maxMeetings(int n , int st[], int end[])
    {
        // Your code here
        vector<pair<int,int>> v;
        int mx=1, pr ;
        
        for(int i=0 ; i<n ; i++){
            v.push_back({ end[i], st[i] });
        }
        
        sort(v.begin() , v.end());
        pr = v[0].first;        
        
        for( int i=0 ; i<n-1 ; i++){
            if( pr<v[i+1].second ){
                mx++;
                pr=v[i+1].first;
            }
        }
        
        return mx;
    }

};




//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++)
            cin >> start[i];

        for (int i = 0; i < n; i++)
            cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(n, start, end);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends