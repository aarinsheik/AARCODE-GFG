//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    bool isSafe( int r , int c , vector<vector<int>> qp ){
        
        for(int i=0 ; i<=r ; i++){
            for(int j=0 ; j<qp[0].size() ; j++ ){
                
                if( qp[i][j]==1 ){
                    if(i==r or j==c or abs(i-r)==abs(j-c) )
                        return false;
                }
            }
        }
        
        return true ;
    }
    
    void findQueensPlace( int row , vector<vector<int>> qp , vector<vector<int>> &res ){
           
        if(row==qp.size()){
            
            vector<int> a;
            
            for(int i=qp.size()-1 ; i>=0 ; i--){
                for(int j=qp[i].size()-1 ; j>=0 ; j--){
                    if(qp[j][i]==1){
                        a.push_back(j+1);
                    }
                }
            }
            res.push_back(a);
            
            return ;
        }
          
        for(int col=qp.size()-1 ; col>=0 ; col--){
            
            if( isSafe( row , col , qp ) ){
                
                qp[row][col]=1;
                findQueensPlace( row+1 , qp , res );
                qp[row][col]=0;
                
            }
        }  
    }
    
    vector<vector<int>> nQueen(int n) {
        // code here
        vector<vector<int>> qp(n , vector<int> (n,0) ) ;
        vector<vector<int>> res ;
        
        findQueensPlace( 0 , qp , res ) ;
        sort(res.begin() , res.end());
        return res;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends