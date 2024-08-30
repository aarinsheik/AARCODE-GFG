#include <iostream>
using namespace std;

int main() {
	//code
	int t=0;
	cin>>t;
	
	newcase:
	while(t--){
	    int n=0;
	    string st="";
	    cin>>n;
	    cin>>st;
	    
	    int oc=0 , zc=0 ;
	    for(int i=0 ; i<n ; i++){
	        
	        st[i]=='1' ? oc++ : zc++ ;
	        
	        if(zc<oc){
	            cout<<"no"<<endl;
	            goto newcase;
	        }
	            
	    }
	    
	    if(zc!=oc){
	        cout<<"no"<<endl;
	        continue;
	    }
	    
	    cout<<"yes"<<endl;
	    
	    
	}
	return 0;
}