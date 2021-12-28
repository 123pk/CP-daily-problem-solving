/*
Platform :- Codeforces
Contest :- Codeforces Round 763 Div 2
Approach :- Bruteforce the operations .
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n,m,x,y,a,b;
        cin>>n>>m>>x>>y>>a>>b;
        
        int ans=0;
        int f=0;
        int d1=1,d2=1;
        while(1){
            if(x==n&&y==m){
              ans+=(min(n-a,m-b));
              break;
            }
            else{
                if(x==a||y==b)break;
                if(x==n){
                    d1=-1;
                }
                else if(y==m){
                    d2=-1;
                }
                x+=d1;
                y+=d2;
            }
            ans++;
            //cout<<x<<" "<<y<<" "<<d1<<" "<<d2<<" "<<ans<<"\n";
        }
        
        cout<<ans<<"\n";
        
    }
}
