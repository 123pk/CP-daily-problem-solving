/*
Platform :- Codeforces
Contest :- Codeforces Round 756 Div 3
Approach :- The max number of teams can be created is (a+b)/4 , and min(a,b)
*/
#include <iostream>

using namespace std;

int main() {
     int t;
     cin>>t;
     
     while(t--){
         long long a,b;
         cin>>a>>b;
         
         long long ans=(a+b)/4;
         ans=min(ans,min(a,b));
         cout<<ans<<"\n";
     }
}
