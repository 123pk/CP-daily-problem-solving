/*
Platform :- Codechef
Contest :- Codechef starters 21
Approach :- Count no of prime factors of 'm' let it be 'x' and store the factors of 'n' we our answer is the biggest factor of 'n' which is also <= 'x' .  
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        long long n,m;
        cin>>n>>m;
        
         
       // finding factors of m
        set<long long>zz,z;
        for(long long i=2;i*i<=m;++i){
            if(m%i==0){
                z.insert(i);
                z.insert(m/i);
            }
        }
        

        
        long long ans=0;
        int f=0;
        //finding prime factors of n
        for(auto &x:z){
           
            int f=0;
            for(int j=2;j*j<=x;++j){
                if(x%j==0){
                    f=1;break;
                }
            }
            if(f==0)ans++;
        }
        
        
         for(long long i=1;i*i<=n;++i){
            if(n%i==0){
                zz.insert(i);
                zz.insert(n/i);
            }
        } 
      
        if(m>1)ans=max(ans,1ll);
        long long val=0;
        for(auto &x:zz){
            if(ans>=x)val=max(val,x);
            else break;
        }
        ans=min(ans,val);
        cout<<ans<<"\n";
    }
}
