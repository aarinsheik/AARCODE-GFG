//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

// } Driver Code Ends
class Solution
{
    public:
    
    int one_round( int is , int js , int ie  ,int je , vector<vector<int>> &a , int &k ){
        
        for(int tjs=js ; tjs<=je ; tjs++ ){
            k--;
            if(k==0) return a[is][tjs];
        }
        
        for(int tis=is+1 ; tis<=ie ; tis++ ){
            k--;
            if(k==0) return a[tis][je];
        }
        
        for(int tje=je-1 ; tje>=js ; tje-- ){
            k--;
            if(k==0) return a[ie][tje];
        }
        
        for(int tie=ie-1 ; tie>is ; tie-- ){
            k--;
            if(k==0) return a[tie][js];
        }
        
        return -1;
        
            
    }    
    /*You are required to complete this method*/
    int findK(int a[MAX][MAX],int n,int m,int k)
    {
 		// Your code goes here.
 		int is=0 , js=0 , ie=n-1 , je=m-1 ;
 		int res=-1;
 		
 		vector<vector<int>> ar(n,vector<int> (m,0));
 		
 		for(int i=0 ; i<n ; i++){
 		    for(int j=0 ; j<m ; j++){
 		        ar[i][j]=a[i][j];
 		    }
 		}
 		
 		while(is<=ie and js<=je ){
 		    
 		    res = one_round( is , js , ie , je , ar , k );
 		    
 		    if(res!=-1){
 		        return res;
 		    }
 		    is++; js++;
 		    ie--; je--;
 		    
 		}
 		
 		return res;	
 		
 		
    }
};





//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        int a[MAX][MAX];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }
        Solution ob;
        cout<<ob.findK(a,n,m,k)<<endl;
        
       
    }
}
// } Driver Code Ends