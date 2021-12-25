/*
Platform :- Codeforces
Contest :- Codeforces Global Round 18
Approach :- Pre compute prefix sum of count of binary bits , for all values from 1 to 200000 , you can store details of 32 bits it is sufficient for following constraints
            now for each l and r find the count of bits in range (r-(l+1)) ,  the ( (r-(l+1))-max_count )is our answer
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    vector<int>z(32);
    vector<vector<int>>P;
    string temp="";
    P.push_back(z);
    for(int i=1;i<=200000;++i){
        temp = bitset<32>(i).to_string();
        reverse(temp.begin(),temp.end());
        for(int j=0;j<32 ;++j){
            z[j]+=(temp[j]-'0');
          //  cout<<z[j]<<" ";
        }
      //  cout<<"\n";
        P.push_back(z);
    }
    
    while(t--){
        int l,r;
        cin>>l>>r;
        
        vector<int>A = P[r];
        //for(int i=0;i<32;++i)cout<<A[i]<<" ";
       // cout<<"\n";
        
        if(l!=1){
            for(int i=0;i<32;++i){
                A[i]-=P[l-1][i];
            }
        }
        int ans=0;
        for(int i=0;i<32;++i){
          //  cout<<A[i]<<" ";
            ans=max(ans,A[i]);
        }
        ans=(r-l)+1-ans;
        cout<<ans<<"\n";
    }
}
