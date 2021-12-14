/*
Platform :- Codeforces
Contest :- Codeforces Round 760 Div 3
Approach :- Since the elements at odd position shoudl be colored in same color and even position in same color and both colors need to be differnt , so we compute GCD of even index
           and odd index elements , if both of them is 1 then we cannot choose any such value , else we choose the values and check if any of them satisfy the condition or not .
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        
        long long A[n];
        long long odd=1,eve=1;
        for(int i=0;i<n;++i){
            cin>>A[i];
            if(i%2==0){
                if(i==0)odd=A[i];
                else odd=__gcd(odd,A[i]);
            }
            else{
                if(i==1)eve=A[i];
                else eve = __gcd(eve,A[i]);
            } 
        }
        
        if(odd==1 && eve ==1)cout<<0<<"\n";
        else{
            int f=0;
            if(odd!=1)
            {//else cout<<eve<<"\n";
            
            for(int i=1;i<n;i+=2){
                if(A[i]%odd==0){
                    f=1;break;
                }
            }
            if(f==0){
                cout<<odd<<"\n";
                continue;
            }
            
            
            }
            
            f=0;
            if(eve!=1){
                 for(int i=0;i<n;i+=2){
                if(A[i]%eve==0){
                    f=1;break;
                }
            }
            if(f==0){
                cout<<eve<<"\n";
                continue;
            }
            }
            cout<<"0\n";
        }
        
    }
}
