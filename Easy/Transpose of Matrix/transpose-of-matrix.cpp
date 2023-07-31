//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{   
    public:  
    //Function to find transpose of a matrix'
    //Function to find transpose of a matrix.
    void transpose(vector<vector<int> >& ma, int n)
    { 
        // code here 
        int k=0 ;
        for (int i=0 ; i<n ; i++){
            for (int j=k ; j<n ; j++){
                int t = ma[i][j];
                ma[i][j] = ma[j][i];
                ma[j][i] = t;
                
            }
            k++;
        }    
    }

};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int n;
        cin>>n;
        vector<vector<int> > matrix(n,vector<int>(n)); 

        for(int i=0; i<n; i++)
        {
            for( int j=0; j<n; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        ob.transpose(matrix,n);
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
                cout<<matrix[i][j]<<" ";
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends