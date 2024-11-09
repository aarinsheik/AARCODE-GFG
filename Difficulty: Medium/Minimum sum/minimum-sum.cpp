//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    
    string add_str(string a , string b){
        
        string res="";
        int rem=0 , i=a.size()-1 , j=b.size()-1 ;
        
        while(i>=0 and j>=0){
            
            int v= rem + int(a[i]-'0') + int(b[j]-'0') ;
            
            if(v>9)
                res.push_back( char(v%10 + '0') );
            else
                res.push_back( char(v)+'0' );
            rem = v/10;
            
            i--;
            j--;
        }
        
        while(i>=0){
            int v= rem + int(a[i])-'0';
            
            if(v>9)
                res.push_back( char(v%10 + '0') );
            else
                res.push_back( char(v)+'0' );
                
            rem = v/10;
            
            i--;
        }
        while(j>=0){
            int v= rem + int(b[j])-'0';
            
            if(v>9)
                res.push_back( char(v%10 + '0') );
            else
                res.push_back( char(v)+'0' );
                
            rem = v/10;
            
            j--;
        }
        
        if(rem!=0){
            res.push_back( char(rem+'0') );
        }
        
        reverse( res.begin() , res.end() );
        return res;        
    }
    
    string minSum(vector<int> &arr) {
        // code here
        sort(arr.begin() , arr.end());
        
        string a1="" , b1="" ;
        int co=0;
        
        for(auto i : arr){
            if(i!=0){
                
                if(co%2==0)
                    a1.push_back(char(i+'0'));
                else
                    b1.push_back(char(i+'0'));
                
                co++;
            }
        }
        
        return add_str( a1 , b1 );
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;
        string ans = ob.minSum(a);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends