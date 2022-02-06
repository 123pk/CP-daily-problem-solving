
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n,k;
        cin>>n>>k;
        
        
        string s;
        cin>>s;
        int f=0;
        int ans = 1;
        for(int i=0;i<(n/2);++i){
            if(s[i]!=s[n-1-i]){
                f=1;break;
            }
        }
        
        if(f && k){
            ans++;
        }
        
            cout<<ans<<"\n";
        
    }
}
