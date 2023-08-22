//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find minimum number of operations that are required 
    //to make the matrix beautiful.
    int findMinOpeartion(vector<vector<int> > mat, int n)
{
        // code here 
        vector <int> SR(n,0) ;
        vector <int> SC(n,0) ;
        int mr , mc , i , j , s=0 ;
        
        for (i=0 ; i<n ; i++){
            for(j=0 ; j<n ; j++){
                SR[i]+=mat[i][j];
                SC[j]+=mat[i][j];
            }
        }
        mr = *max_element(SR.begin() , SR.end());
        mc = *max_element(SC.begin() , SC.end());
        
        if(mr>mc){
            for(i=0;i<n;i++){
                s+=(mr-SR[i]);
            }
        }
        else{
            for(i=0;i<n;i++){
                s+=(mc-SC[i]);
            }
        }
        
        return s;
        
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
        vector<vector<int> > matrix (n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>matrix[i][j];
        Solution ob;
        cout << ob.findMinOpeartion(matrix, n) << endl;
    }
    return 0;
}


// } Driver Code Ends