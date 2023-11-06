//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int hopscotch(int n, int m, vector<vector<int>> mat, int ty, int i, int j)
    {
        // code here
        int sum=0;
        
        int dx1e[]={ -1 , -1 , -1 , 0 , 0 , 1 };
        int dy1e[]={ -1 , 0 , 1 ,  -1 , 1 , 0 };
        
        int dx1o[]={ -1 , 0 , 0 , 1 , 1 , 1 };
        int dy1o[]={ 0 , -1 , 1 , -1 , 0 , 1};
        
        int dx2e[]={ -2 , -2 , -2 , -1 , -1 , 0 , 0 , 1 , 1 , 1 , 1 , 2 };
        int dy2e[]={  -1 , 0 , 1 , -2 , 2 ,-2 , 2 , -2 , -1 , 1 , 2 , 0 };
        
        int dx2o[]={ 2 , 2 , 2 , 1 , 1 , 0 , 0 , -1 , -1 , -1 , -1 , -2 };
        int dy2o[]={ -1 , 0 , 1 , -2 , 2 ,-2 , 2 , -2 , -1 , 1 , 2 , 0 };
        
        if(ty==0){
            
            if(j%2==0){
                
                for(int k=0 ; k<6 ; k++){
                    if(dx1e[k]+i>=0 and dx1e[k]+i<n and dy1e[k]+j>=0 and dy1e[k]+j<m ) sum+=mat[dx1e[k]+i][dy1e[k]+j] ;
                }    
            }
            else{
                for(int k=0 ; k<6 ; k++){
                    if(dx1o[k]+i>=0 and dx1o[k]+i<n and dy1o[k]+j>=0 and dy1o[k]+j<m ) sum+=mat[dx1o[k]+i][dy1o[k]+j] ;
                }
            }
            
            
        }
        else{
            
            if(j%2==0){
                for(int k=0 ; k<12 ; k++){
                    if(dx2e[k]+i>=0 and dx2e[k]+i<n and dy2e[k]+j>=0 and dy2e[k]+j<m ) sum+=mat[dx2e[k]+i][dy2e[k]+j] ;
                } 
            }
            else{
                for(int k=0 ; k<12 ; k++){
                    if(dx2o[k]+i>=0 and dx2o[k]+i<n and dy2o[k]+j>=0 and dy2o[k]+j<m ) sum+=mat[dx2o[k]+i][dy2o[k]+j] ;
                }
            }
        }
        
        return sum;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m, ty, i, j;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++)
            for(int j = 0;j < m;j++)
                cin>>mat[i][j];
        cin>>ty>>i>>j;
        
        Solution ob;
        cout<<ob.hopscotch(n, m, mat, ty, i, j)<<"\n";
    }
    return 0;
}
// } Driver Code Ends