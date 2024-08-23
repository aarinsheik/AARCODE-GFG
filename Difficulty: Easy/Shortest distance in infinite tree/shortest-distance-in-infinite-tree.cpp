//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
public:
      int distance(int X, int Y)
      {
          // code here
          int x = max(X,Y) , y=min(X,Y) , h=0 ;
          map<int,int> xp ;
          
          while(x>0){
              x=x/2;
              h++;
              xp[x]=h;
          }
          
          h=0;
          
          while(y>0){
              if(xp[y]){
                  return h+xp[y];
              }
              y=y/2;
              h++;
          }
          
          return 1;
      }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        long long X,Y;
        cin>>X>>Y;
        Solution ob;
        cout << ob.distance(X,Y) << endl;
    }
    return 0; 
}
// } Driver Code Ends