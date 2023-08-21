//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    //Function to insert heap.
    priority_queue<int> max;
    priority_queue<int,vector<int>,greater<int> >min;
    // double pm=1e9;
    
    void insertHeap(int &x)
    {
        if(!max.empty() and x>max.top()){
            min.push(x);
        }
        else{
            max.push(x);
        }
        balanceHeaps();
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
        if((min.size()+max.size())%2==0 and min.size()>max.size()){
            while( min.size()!=max.size() ){
                max.push(min.top());
                min.pop();
            }
        }
        else if((min.size()+max.size())%2==0 and min.size()<max.size()){
            while( max.size()!=min.size() ){
                min.push(max.top());
                max.pop();
            }
        }
        else if((min.size()+max.size())%2!=0 and min.size()<max.size()){
            while( max.size()!=min.size()+1 ){
                min.push(max.top());
                max.pop();
            }
        }
        else if((min.size()+max.size())%2!=0 and min.size()>max.size()){
            while( max.size()!=min.size()+1 ){
                max.push(min.top());
                min.pop();
            }       
        }
    }
    
    //Function to return Median.
    double getMedian()
    {   
        double pm;
        if((min.size()+max.size())%2==0){
            pm=(max.top()+min.top())/2.0;
            return pm;
        }
        else{
            return max.top();
        }
    }
};


//{ Driver Code Starts.

int main()
{
    int n, x;
    int t;
    cin>>t;
    while(t--)
    {
    	Solution ob;
    	cin >> n;
    	for(int i = 1;i<= n; ++i)
    	{
    		cin >> x;
    		ob.insertHeap(x);
    	    cout << floor(ob.getMedian()) << endl;
    	}
    }
	return 0;
}
// } Driver Code Ends