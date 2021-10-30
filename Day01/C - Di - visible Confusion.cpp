/*
Platform :- Codeforces
Contest :- Codeforces Round 752 Div 2
Approach :- A[i]%(i+1) !=0 if (i+1) is not a mulitple fo A[i], since A[i] is upto 10^9 so we can have upto 16 factorial , basic idea idea is to check from (i+1) to max(0,(i+1)-17)
            if still A[i] is divisible then answer doesnot exit .
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
        
        //reverse(A.begin(),A.end());
        int f=0;
      //  priority_queue<pair<int,long long>>P;
        
        for(int i=n-1;i>=0;--i){
            int d=0;
            int z=i+2;
            int g=0;
            while(d<=18 && z){
                if(A[i]%z){
                    g=1;
                    break;
                }
                z--;
                d++;
            }
            if(g==0||z==0){
                f=1;break;
            }
            
        }
        if(f)cout<<"NO\n";
        else {
          cout<<"YES\n";
        }
        
    }
}
