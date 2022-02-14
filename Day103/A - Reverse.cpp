/*
Platform :- Codeforces
Contest :- Codeforces Round 771 Div 2
Approach :- Find the first index where A[i] ! = i and find the values where 'i' is present in array and reverse the array from (i to index[i]) and print the array
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
        vector<int>idx(n);
        for(int i=0;i<n;++i){
            cin>>A[i];
            A[i]--;
            idx[A[i]] = i;
        }
        
        int last = -1;
        for(int i=0;i<n;++i){
            if(A[i]!=i){
                last = i;
                break;
            }
            else cout<<(i+1)<<" ";
        }
        
        if(last == -1){
            cout<<"\n";
            continue;
        }
        for(int i = idx[last] ; i>=last;--i){
            cout<<(A[i]+1)<<" ";
        }
        
        for(int i = idx[last]+1 ; i<n;++i )cout<<(A[i]+1)<<" ";
        cout<<"\n";
        
        
    }
}
