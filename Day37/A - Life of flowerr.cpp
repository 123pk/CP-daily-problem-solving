/*
Platform :- Codeforces
Contest :- Codeforces Round 759
Approach :- If there are two continuous days with no watering then answer is "-1" else if there are more than 1 days of continuous watering days then we add "5" to height else 1
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        
        int A[n];
        for(int i=0;i<n;++i){
            cin>>A[i];
        }
        
        int ans=1;
        int d=0,c=0;
        for(int i=0;i<n;++i){
            if(A[i]){
                d++;
                if(d>=2)ans+=5;
                else ans++;
                c=0;
            }
            else{
                c++;
                if(c==2){
                    ans=-1;
                    break;
                }
                d=0;
            }
        }
        cout<<ans<<"\n";
    }
}
