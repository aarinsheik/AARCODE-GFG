//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    
    int bfs( int N , vector<int> &kp , vector<int> &tp , vector<vector<int>> &vis  ){

		vis[kp[0]-1][kp[1]-1]=1;
        
        int d1[]={ 2 , 2 , -2 , -2 , -1 , 1 , -1 , 1  } ;
        int d2[]={ -1 , 1 , -1 , 1 , 2 , 2 , -2 , -2 } ;
        int res=0 , co1=1 , co2=0 , fg=0;
        
        queue <vector<int>> q;
        q.push(kp);
        
        while(!q.empty()){
            
            vector <int> t1 ;
            t1 = q.front() ;
            q.pop();
            
            if(fg%2==0){
                co1--;
            }
            else{
                co2--;
            }
            
            
            if(t1[0]==tp[0] and t1[1]==tp[1] ){
                return res;
            }   
            
            for(int i=0 ; i<8 ; i++){
	            if( t1[0]+d1[i] >= 1 and t1[1]+d2[i] >=1 and t1[0]+d1[i] <=N and t1[1]+d2[i] <=N ){
	                
	                if( !vis[t1[0]+d1[i]-1 ][ t1[1]+d2[i]-1 ] ){
	                    
	                    vis[ t1[0]+d1[i]-1 ][ t1[1]+d2[i]-1 ]=1;
	                    vector<int> t2({ t1[0]+d1[i] ,  t1[1]+d2[i] });
	                    q.push(t2);
	                    (fg%2==0)?co2+=1:co1+=1;
	                    
	                }
	                
	            }
            }
            if(co1==0 and fg%2==0){ 
                res++;
                fg++;
            }
            if(co2==0 and fg%2!=0){ 
                res++;
                fg++;
            }
            
        }
        
        return -1;
        
    }
    
	int minStepToReachTarget(vector<int>&KP, vector<int>&TP, int N){
	    // Code here
	    vector<vector<int>> vis(N , vector<int>(N,0) ) ;
	    
	    int res = bfs( N , KP , TP , vis )  ;
	
	    return res;
	    
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends