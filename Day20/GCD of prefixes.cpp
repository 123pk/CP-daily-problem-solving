/*
Platform :- Codechef
Contest :- Codechef Starters 17
Approach :- The first element of GCD Array is going to be the same for oringinal array , now we will find gcd of prefix and compare with the current element A[i] , if for any index
            GCD_of_prefix[i]<A[i] then we cannot have any such array else we print the same given array.
*/
#include<bits/stdc++.h>
using namespace std;


/*
GCD  = (x*y)

*/

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        
        long long A[n];
        for(int i=0;i<n;++i)cin>>A[i];
        
        long long mn=A[0];
        int f=0;
        for(int i=0;i<n;++i){
            mn=__gcd(mn,A[i]);
            if(A[i]>mn){
                f=1;break;
            }
             
        }
        
        if(f)cout<<"-1\n";
        else{
            for(auto &x:A)cout<<x<<" ";
            cout<<"\n";
        }
    }
}
