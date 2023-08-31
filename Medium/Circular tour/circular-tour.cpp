//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};


// } Driver Code Ends
/*
The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};*/

/*You are required to complete this method*/
class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
       //Your code here
       int i=0 , st=0 , rp=0 , fg=0 ;
       map <int,int> mp;
       
       while(fg<n){
           
           rp+=p[i].petrol;
           
           if(fg==0) st=i;

           if(rp >= p[i].distance){
               fg++;
               rp-=p[i].distance;
           }
           else{
               if(mp[i]) return -1;
               
               mp[i]=1;
               fg=0;
               rp=0;
               
           }
           
           i=(++i)%n;
       }
       
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
        int n;
        cin>>n;
        petrolPump p[n];
        for(int i=0;i<n;i++)
            cin>>p[i].petrol>>p[i].distance;
        Solution obj;
        cout<<obj.tour(p,n)<<endl;
    }
}

// } Driver Code Ends