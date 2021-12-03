/*
Platform :- Codeforces
Contest :- Codeforces Global Round 17
Approach :- Since we only need to remove one element we will look for the two elements A[i] & A[n-1-i] where A[i]!=A[n-1-i] , if removing any of these doesnot give us a palindromic
            array then we cannot create one else we can always create one .
*/
#include<bits/stdc++.h>
using namespace std;

bool check(int val,vector<int>&A){
    vector<int>temp;
    for(auto &x:A){
        if(x==val)continue;
        temp.push_back(x);
    }
    int m=temp.size();
    
    for(int i=0;i<(m/2);++i){
        if(temp[i]!=temp[m-1-i])return false;
    }
    return true;
}

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        
        vector<int>A(n);
        for(int i=0;i<n;++i)cin>>A[i];
        
        //since we just need to remove only one element 
        // it will be either A[i] or A[n-1-i] where A[i]!=A[n-1-i]
        int f=0;
        for(int i=0;i<n/2;++i){
            if(A[i]!=A[n-1]){
                if(check(A[i],A)||check(A[n-1-i],A)){
                    break;
                }
                f=1;
                break;
            }
        }
        
        if(f)cout<<"NO\n";
        else cout<<"YES\n";
    }
}
