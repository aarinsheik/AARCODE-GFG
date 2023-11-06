//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> matrixSum(int n, int m, vector<vector<int>> mat, int q, vector<int> que[])
    {
        // code here
        vector <int> res;
        
        for(int i=0 ; i<q ; i++){
            
            // int d1[]={ que[i][1]-que[i][0] , que[i][1]-que[i][0] , que[i][1]-que[i][0] , que[i][1] , que[i][1] , que[i][1]+que[i][0] , que[i][1]+que[i][0] , que[i][1]+que[i][0]  };
            // int d2[]={ que[i][2]-que[i][0] , que[i][2] , que[i][2]+que[i][0] , que[i][2]-que[i][0] , que[i][2]+que[i][0] , que[i][2]-que[i][0] , que[i][2] , que[i][2]+que[i][0] };
            int z=que[i][1]-que[i][0] , x=que[i][2]-que[i][0] ;
            int sum=0;
            
            int a=z , b=x ;
            while( a>=z and a<=z+(que[i][0]*2) ){
                if(a>=0 and a<n and b>=0 and b<m ) sum+=mat[a][b] ;
                a++;
            }
            
            a=z , b=x+1 ;
            while( b>x and b<x+(que[i][0]*2) ){
                if(a>=0 and a<n and b>=0 and b<m ) sum+=mat[a][b] ;
                b++;
            }
            
            a=z+(que[i][0]*2) , b=x+1 ;
            while( b>x and b<x+(que[i][0]*2) ){
                if(a>=0 and a<n and b>=0 and b<m ) sum+=mat[a][b] ; 
                b++;
            }
            
            a=z , b=x+(que[i][0]*2) ;
            while( a>=z and a<=z+(que[i][0]*2) ){
                if(a>=0 and a<n and b>=0 and b<m ) sum+=mat[a][b] ; 
                a++;
            }
            
            res.push_back(sum);
        }
        
        return res;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m, q, ty, i, j;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++)
            for(int j = 0;j < m;j++)
                cin>>mat[i][j];
        cin>>q;
        vector<int> queries[q];
        for(int k = 0;k < q;k++){
            cin>>ty>>i>>j;
            queries[k].push_back(ty);
            queries[k].push_back(i);
            queries[k].push_back(j);
        }
        
        Solution ob;
        vector<int> ans = ob.matrixSum(n, m, mat, q, queries);
        for(int u: ans)
            cout<<u<<"\n";
    }
    return 0;
}
// } Driver Code Ends