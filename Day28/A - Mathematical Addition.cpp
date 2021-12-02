/*
Platform :- Codeforces 
Contest :- Codeforces Round 755 Div 2
Approach :- Simplify the given expression and you will come to this final equation ( v^2 * x = - (u^2)*y) of  (x = -u^2)  and y = v^2
*/
#include<bits/stdc++.h>
using namespace std;


int main(){
    int t;
    cin>>t;
    
    while(t--){
        long long a,b;
        cin>>a>>b;
        
        /*
         x/a + y/b = (x+y)/(a+b)
         
         x/a  + y/b = (x)/(a+b) + (y/a+b)
         
        */
        
        long long x=-1;
        x*=a;
        x*=a;
        
        long long y=b*b;
        cout<<x<<" "<<y<<"\n";
        
    }
}
