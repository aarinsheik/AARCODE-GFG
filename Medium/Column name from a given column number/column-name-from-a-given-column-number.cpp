//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    string colName (long long int n)
    {
        // your code here
        vector <int> al ;
        string st;
        int rem , fg=0 ;
        
        while(n>26){
            rem=n%26;
            
            if(fg==1){
                fg=0;
                if(rem==0){
                    rem=26;
                    fg=1;
                }
                rem=rem-1;
            }
            
            if(rem==0) {
                fg=1;
                rem=26;
            }
            
            al.push_back(rem);
            n=floor(n/26);
        }    
        
        if(fg==1){
            n=n-1;
        }
        al.push_back(n);
    
    
        for(int i= (al.size()-1) ; i>=0 ; i--){
            st.push_back( (char)(64+al[i]) );
        }
        
        return st;

    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
	{
		long long int n; cin >> n;
		Solution ob;
		cout << ob.colName (n) << '\n';
	}
}

// } Driver Code Ends