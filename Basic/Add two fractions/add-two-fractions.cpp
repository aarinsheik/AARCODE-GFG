//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


void addFraction(int num1, int den1, int num2,
                 int den2);

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int a,b,c,d,resultNum,resultDen;
        cin>>a>>b>>c>>d;
        addFraction(a,b,c,d);

    }
}

// } Driver Code Ends


/*You are required to complete this function*/
int gcd(int a , int b){
    if(a==b){
        return a;
    }
    else if(a>b){
        return gcd(a-b,b);
    }
    else{
        return gcd(a,b-a);
    }
}

void addFraction(int n1, int d1, int n2,int d2)
{
//Your code here
        int lcm = (d1*d2)/gcd(d1,d2);
        
        int s1 = (n1*lcm)/d1 + (n2*lcm)/d2 ;
        
        int rn = s1/gcd(s1,lcm);
        lcm = lcm/gcd(s1,lcm);
        
        cout<<rn<<'/'<<lcm<<endl;
 }