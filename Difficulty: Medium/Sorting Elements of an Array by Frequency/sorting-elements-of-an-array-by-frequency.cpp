//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Complete this function
    // Function to sort the array according to frequency of elements.
    vector<int> sortByFreq(vector<int>& arr) {
        // Your code here
        map<int , priority_queue< int , vector<int> , greater<int> > > mp;
        map<int,int> frq;
        
        for(int i=0 ; i<arr.size() ; i++){
            frq[arr[i]]++;
        }
        
        for(auto i : frq ){
            mp[i.second].push(i.first);
        }
        
        arr.clear();
        for(auto i=mp.rbegin() ; i!=mp.rend() ; i++ ){
            
            while( !(i->second).empty() ){
                
                for(int j=0 ; j<i->first ; j++)
                    arr.push_back((i->second).top());
                    
                (i->second).pop();
            }
        }
        
        return arr;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution obj;
        vector<int> v;
        v = obj.sortByFreq(arr);
        for (int i : v)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends