/*
Platform :- Codeforces
Contest :- Codeforces Round 761 Div 2
Approach :- there are two cases 
           Case 1 :- N is odd then also there are two cases 
                    i. if (N+1)/2 is odd then we have ( (N+1)/2 - 2 , (N+1)/2 + 2 , 1) 
                    ii. if (N+1)/2 is even then  we have ((N+1)/2 - 1 , (n+1)/2 + 1 , 1)
           
           Case 2 :- N is even then we have ( N/2 , N/2-1 , 1 ) as gcd of odd and even is 1 so this is correct .
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
      
        
        long long n;
        cin>>n;
        
        if(n%2){
            long long val = n/2;
            if(val%2){
                cout<<(val-2)<<" "<<val+2<<" "<<1<<"\n";
            }
            else{
                cout<<(val-1)<<" "<<(val+1)<<" "<<1<<"\n";
            }
        }
        else cout<<(n/2)<<" "<<((n/2)-1)<<" "<<1<<"\n";
        
    }
}
