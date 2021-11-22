/*
Platform :- Codeforces
Contest :- Educational Round 118
Approach :- first first the 'a' as first element and 'b' as first element of second half in array , use a map to only use unused values between 1 and n if we are not able to fill
           any half with given constrants then we print -1 , else we start filling max values in first half going from 'n' to >'a'and from 1 to <b' in second half, all used exactly one
           time
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n,a,b;
        cin>>n>>a>>b;
        
        int x=a,y=b;
        map<int,int>P;
        P[a]++;
        P[b]++;
        vector<int>A(n);
        A[0]=a;
        a=n;
        int d=n/2,f=0;
        //now we will increase it d times if we reach the max before reaching the
        //end then the solutions is not available
        for(int i=1;i<d;++i){
            while(P[a])a--;
            if(a<x){
               // cout<<" * ";
                f=1;break;
            }
            P[a]++;
            A[i]=a;
        }
        
        if(f)cout<<"-1\n";
        else{
            //now we will start with initialising d
            A[d]=b;
            b=1;
            for(int i=d+1;i<n;++i){
                while(P[b])b++;
                if(b>y){
                    //cout<<" ** ";
                    f=1;break;
                }
                P[b]++;
                A[i]=b;
            }
           
            if(f)cout<<"-1\n";
            else {
                for(auto &x:A)cout<<x<<" ";
                cout<<"\n";
            }
        }
    
    }
}
