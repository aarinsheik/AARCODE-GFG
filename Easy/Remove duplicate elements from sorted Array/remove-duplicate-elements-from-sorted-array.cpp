//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
public:
    int remove_duplicate(int a[],int n){
        // code here
        
        //(TLE error)
        // for(int i=0; i<n-1 ; i++){
            
        //     if(a[i]==a[i+1]){
        //         for(int j=i+1 ; j<n-1 ; j++){
        //             a[j]=a[j+1];
        //         }
        //         i--;
        //         n--;
        //     }
            
        // }
        // return n;
        
        // (Alternate code)
        
        vector <int> v;
        
        v.push_back(a[0]);
        
        for(int i=1; i<n ; i++){
            if(!v.empty() and v.back()!=a[i]){
                v.push_back(a[i]);
            }
        }
        for(int j=0 ; j<v.size() ; j++){
            a[j]=v[j];
        }
        return v.size();
    }
};

//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        int a[N];
        for(int i=0;i<N;i++)
        {
            cin>>a[i];
        }
    Solution ob;
    int n = ob.remove_duplicate(a,N);

    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    }
}
// } Driver Code Ends