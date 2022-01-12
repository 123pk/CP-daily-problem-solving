/*
Platform :- Codechef
Contest :- Exun 2021-22 Division 2 (Rated)
Approach :- We can identify 
          1. "odd"  if 'n' is 'odd' and 'a' is 'odd' ,
          2. "even" if 'n' is '1' and 'a' is even or 'n' is even and 'a' is 'odd'
          3. else it is 'Impossible' to predict
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        long long n,a;
        cin>>n>>a;
        
     //   string temp = bitset<32>(a).to_string();
      //  reverse(temp.begin(),temp.end());
        
        if(n%2 && a%2)cout<<"Odd\n";
        else if((n==1 && a%2==0) || (n%2==0 && a%2) )cout<<"Even\n";
        else cout<<"Impossible\n";
    }
}
