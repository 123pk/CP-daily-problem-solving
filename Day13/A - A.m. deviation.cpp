/*
Platform :- Codeforces
Contest:-  Codeforces Round 754 
Approach :- It is optimal to choose either a or c and decrease or increase them and choose ''b' and accordingly increase or decrease . The value of ( a*c - 2*b ) differ by 3 .
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        long long a,b,c;
        cin>>a>>b>>c;
        
        long long dif=(a+c)-(2*b);
        if(dif==0)cout<<0<<"\n";
        else{
            long long ans;
            //if dif > 0 or dif<0
            long long z=abs(dif/3);
            if(dif<0){
                dif+=(z*3);
                ans=abs(dif);
                dif+=3;
                ans=min(ans,abs(dif));
            }
            else{
                dif-=abs(z*3);
                ans=dif;
                dif-=3;
                ans=min(ans,abs(dif));
            }
            cout<<ans<<"\n";
        }
        
    }
}
