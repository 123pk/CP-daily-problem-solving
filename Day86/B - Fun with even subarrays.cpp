/*
Platform :- Codefoces
Contest :- Codeforces Round 768 Div 2
Approach :- Start with the last element if the second last is not equal then we make it equal to last and increment our size and count of operation and descent to i-c index
            if we found some element which is already equal then we just add to our current pack and decrease the index .
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
        for(int i=0;i<n;++i)cin>>A[i];
        
        int last=A[n-1],c=0,ans=0;
        for(int i=n-1;i>=0;){
            if(A[i]==last){
                i--;
                c++;
            }
            else {
                ans++;
                i-=c;
                c*=2;
            }
        }
        cout<<ans<<"\n";
    }
}
