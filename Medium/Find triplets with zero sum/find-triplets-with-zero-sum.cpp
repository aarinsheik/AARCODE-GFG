//{ Driver Code Starts
#include<bits/stdc++.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

// } Driver Code Ends
/* You are required to complete the function below
*  arr[]: input array
*  n: size of array
    //Function to find triplets with zero sum.
    /* You are required to complete the function below
*  arr[]: input array
*  n: size of array
*/
class Solution{
  public:
    //Function to find triplets with zero sum.
    bool findTriplets(int arr[], int n)
    { 
        //Your code here
        vector <int> po;
        vector <int> ne;
        unordered_map <int,int> pom;
        unordered_map <int,int> nem;
        int co=0, fg=0;
        
        for(int i=0 ; i<n ; i++){
            if(arr[i]>=0){
                po.push_back(arr[i]);
                pom[arr[i]]+=1;
            }
            else{
                ne.push_back( abs(arr[i]) );
                nem[abs(arr[i])]+=1;
            }
        }
        
        if(pom[0]>=3){
            return 1;
        }
        if( po.size()==0 or ne.size()==0 ){
            return 0;
        }
        
        
        for(int i=0 ; i<po.size()-1 ; i++){
            for(int j=1+i ; j<po.size() ; j++){
                if(nem[ po[i]+po[j] ]){
                    return 1;
                }
            }
        }
        
        for(int i=0 ; i<ne.size()-1 ; i++){
            for(int j=1+i ; j<ne.size() ; j++){
                if(pom[ ne[i]+ne[j] ]){
                    return 1;
                }
            }
        }
        return 0;
    }
};


//{ Driver Code Starts.
int main()
{
    int t;
	cin>>t;
	while(t--){
    	int n;
    	cin>>n;
    	int arr[n]={0};
    	for(int i=0;i<n;i++)
    		cin>>arr[i];
    	Solution obj;
        if(obj.findTriplets(arr, n))
            cout<<"1"<<endl;
        else 
            cout<<"0"<<endl;
	}
    return 0;
}
// } Driver Code Ends