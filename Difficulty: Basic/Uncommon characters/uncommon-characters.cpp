//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
        string UncommonChars(string A, string B)
        {
            // code here
            string st ;
            map<char,int> mp1 , mp2;
            vector<char> vs;
            
            for( int i=0 ; i<A.size() ; i++ ){
                if( !mp1[A[i]] ) mp1[A[i]]++;
            }
            
            for( int i=0 ; i<B.size() ; i++ ){
                if( !mp2[B[i]] ) mp2[B[i]]++;
            }
            
            int i=0;
            
            while(i<A.size()){
                if( !mp2[A[i]] ){
                    vs.push_back(A[i]);
                    mp2[A[i]]++;
                }
                i++;
            }
            
            i=0;
            while(i<B.size()){
                if( !mp1[B[i]] ){
                    vs.push_back(B[i]);
                    mp1[B[i]]++;
                }
                i++;
            }
            
            if(vs.size()==0){
                return "-1";
            }
            
            sort(vs.begin() , vs.end() );
            
            st.clear();
            for(int i=0 ; i<vs.size() ; i++)
                st.push_back(vs[i]);
            
            return st;
            
        }
};



//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string A,B;
        cin>>A;
        cin>>B;
        Solution ob;
        cout<<ob.UncommonChars(A, B);
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends