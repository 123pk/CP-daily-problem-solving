/*
Platform :- Codechef
Contest :- Codechef starters 21
Approach :- First convert all values of array into binary form of 64 bit and store the frequency of each bit then if the frequency of 'ith' bit is >=2 
            then we will add (i<<2) to our answer .
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        
        vector<int>P(64);
        long long A[n];
        for(int i=0;i<n;++i){
            cin>>A[i];
            string z=bitset<64>(A[i]).to_string();
            reverse(z.begin(),z.end());
            for(int j=0;j<64;++j){
                if(z[j]-'0')P[j]++;
            }
        }
        
        long long ans=0;
        int dif=(n)/2;
       
        
        for(int i=0;i<64;++i){
            if(P[i]>=2)ans+=(1<<i);
        }
        cout<<ans<<"\n";
    }
}
