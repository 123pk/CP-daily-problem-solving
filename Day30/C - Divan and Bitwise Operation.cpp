/*
Platform :- Codeforces
Contest :- Codeforces Contest 757 Div 2
APPROACH :- Here we need to know some key points that are each bit of any element is set 2^n-1 times while finding XOR of all subsequences ,
            so we will find OR of all the elements and sum of all XOR of all subesequence is ( OR_Value * 2^n-1 )% mod 
*/
#include<bits/stdc++.h>
using namespace std;
 

long long find(long long a,long long b)
{
    long long res=1;
    long long mod=1e9+7;
    
    while(b){
    
        if(b&1){
            res=(res*a)%mod;
        }
        b>>=1;
        a=(a*a)%mod;
    }
    return res;
}

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n,m;
        cin>>n>>m;
          
         ;
        long long val=0;
        for(int i=0;i<m;++i){
            cin>>l>>r>>x;
            val|=x;
        }
                
        long long mod=1e9+7;
        val=(val*find(2,n-1))%mod;
                
        cout<<val<<"\n";
    }
}
