//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    
    int fg=0 , f2=0;
    void rec_rev(stack <int> &st ,queue <int> &rs){
    
        if(fg==0){
           
           if(st.empty()){
               fg=1;
           }
           else{
                rs.push(st.top());
                st.pop();
           }
           rec_rev(st,rs);
       }
        else if(fg==1){
           
           if(rs.empty()){
               f2=1;
           }
           else{
           st.push(rs.front());
           rs.pop();
           rec_rev(st,rs);
           }
       }
       
       if(f2==1){
            return;
        }
       
    }
    void Reverse(stack<int> &St){
       
       queue <int> rs ;
       fg=0;
       rec_rev(St,rs);
    }
};

//{ Driver Code Starts.


int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        stack<int> St;
        for(int i=0;i<N;i++){
            int x;
            cin>>x;
            St.push(x);
        }
        Solution ob;
        ob.Reverse(St);
        vector<int>res;
        while(St.size())
        {
            res.push_back(St.top());
            St.pop();
        }
        for(int i = res.size()-1;i>=0;i--)
        {
            cout<<res[i]<<" ";
        }
        
        cout<<endl;
    }
}
// } Driver Code Ends