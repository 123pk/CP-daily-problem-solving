/*
Platform :- Codeforces
Contest :- Codeforces Round 752 Div 2
Approach :- The basic idea is for even size array we can choose subarray of size '1' and LIS is equal to 1 and xor of 1 even number of times is 0 ,
            for odd we need to find a subarray of size 2 whose LIS is 1 then it is possible else it is not.
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
        for(int i=0;i<n;++i){
            cin>>A[i];
        }
        
        if(n%2==0){
            cout<<"YES\n";
        }
        else{
            int f=0;
            for(int i=1;i<n;++i){
                if(A[i]<=A[i-1]){
                    f=1;break;
                }
            }
            if(f)cout<<"YES\n";
            else cout<<"NO\n";
        }
        
    }
}
