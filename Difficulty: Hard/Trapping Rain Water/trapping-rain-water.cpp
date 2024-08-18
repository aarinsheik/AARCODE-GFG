//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    
    long long trappingWater(int arr[], int n){
        // code here
        
        vector<long long> rt(n,-1) , lt(n,-1);
        
        long long mx=-1;
        
        for(long long p=0 ; p<n ; p++){
            
            if(arr[p]>mx){
                if(p+1<n and arr[p]==arr[p+1]){
                    continue;
                }    
                mx=arr[p]; 
            }
            else{
                rt[p]=mx;
            }
        }
        
        mx=-1;
        
        for(long long p=n-1 ; p>=0 ; p-- ){
        
            if(arr[p]>mx){
                if(p-1>=0 and arr[p]==arr[p-1]){
                    continue;
                }
               mx=arr[p]; 
            }
            else{
                lt[p]=mx;
            }
            
        }
        
        long long i=0;
        
        while(i<n){
            if(rt[i]>0 and lt[i]>0 ){
                break;
            }
            else{
                i++;
            }
        }
        
        
        long long j=n-1;
        
        while(j>=0){
            if(rt[j]>0 and lt[j]>0 ){
                break;
            }
            else{
                j--;
            }
        }
        
        long long ans=0;
        
        for(int i=0 ; i<n ; i++){
            if(rt[i]>0 and lt[i]>0){
                ans+= min(rt[i],lt[i]) - arr[i] ;
            }
        }
        
        return ans;
        
    }
    
};

//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends