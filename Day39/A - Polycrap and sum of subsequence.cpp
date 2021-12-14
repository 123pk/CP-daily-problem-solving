/*
Platform :- Codeforces
Contest :- Codeforces Round 760 Div 3
Approach :- Sort the array , the two smallest element are already in main array we cannot generate them , now out of 3rd or 4 element we have to choose any one as our final element
            if sum of first two element > 3rd element then we choose 3rd element else we choose 4th one.
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
         
        vector<long long>ans;
        vector<long long> A(7);
        for(int i=0;i<7;++i)cin>>A[i];
        sort(A.begin(),A.end());
        int f=0;
         
        
        cout<<A[0]<<" "<<A[1]<<" ";
        if((A[0]+A[1])>A[2])cout<<A[2]<<"\n";
        else cout<<A[3]<<"\n";
    }
}
