class Solution {
  public:
    vector<int> commonElements(vector<int> &a, vector<int> &b, vector<int> &c) {
        // code here
        vector<int> res;
        
        int i=0,j=0,k=0 ;
        
        while(i<a.size() and j<b.size() and k<c.size()){
            
            if(a[i]==b[j] and b[j]==c[k]){
                res.push_back(a[i]);
                while(i<a.size() and a[i]==res[res.size()-1])i++;
                while(j<b.size() and b[j]==res[res.size()-1])j++;
                while(k<c.size() and c[k]==res[res.size()-1])k++;
            }
            
            if(a[i]>=b[j] and a[i]>=c[k]){
                while(j<b.size() and b[j]<a[i])j++;
                while(k<c.size() and c[k]<a[i])k++;
            }
            if(b[j]>=a[i] and b[j]>=c[k]){
                while(i<a.size() and a[i]<b[j])i++;
                while(k<c.size() and c[k]<b[j])k++;
            }
            if(c[k]>=a[i] and c[k]>=b[j]){
                while(i<a.size() and a[i]<c[k])i++;
                while(j<b.size() and b[j]<c[k])j++;
            }
            
        }
        
        return res;
            
    }
};