//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    
    int gcd(int n1, int n2) {
        if (n2 != 0)
            return gcd(n2, n1 % n2);
        else
            return n1;
    }

    pair<int,int> addfr(int n1, int d1, int n2,int d2)
    {
    //Your code here
            pair<int,int> fr ;
            int lcm = (d1*d2)/gcd(d1,d2);
            
            int s1 = (n1*lcm)/d1 - (n2*lcm)/d2 ;
            
            fr.first = s1/gcd(s1,lcm);
            fr.second = lcm/gcd(s1,lcm);
            
            return fr;
     }
     
     pair <int,int> simp(pair<int,int> s){
        pair<int,int> r ;
        int n=s.first;
        int d=s.second;
        r.first = n/gcd(n,d);
        r.second = d/gcd(n,d);
        return r;
     }
     
    int countFractions(int n, int num[], int den[])
    {
        map < pair<int,int> ,int> fmap;
        int co=0;
        pair<int,int> fr;
        pair<int,int> one;
        
        one.first=1;
        one.second=1;
        
        for(int i=0 ; i<n ; i++){
            fr.first = num[i];
            fr.second = den[i];
            if( fmap[ addfr(1 , 1 , fr.first , fr.second ) ] )
                co+=fmap[ addfr(1 , 1 , fr.first , fr.second ) ];
            
            fmap[simp(fr)]+=1;
        }
        return co;
        
        
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
        int numerator[n],denominator[n];
        for(int i=0;i<n;i++)
            cin>>numerator[i];
        for(int i=0;i<n;i++)
            cin>>denominator[i];
        Solution ob;
        int ans=ob.countFractions(n,numerator,denominator);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends