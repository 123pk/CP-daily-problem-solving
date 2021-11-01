/*
Platform :- Codeforces
Contest :- Codeforces Round 752 Div 2
Approach :- After some itteration the array becomes non changing , so for each itteration we store the array in map and for some k >=d where 'd' is the max number of itteration
            then we took that last array and for all other values we print the 'xth' element.
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        
        vector<int>A,start;
        map<int,vector<int>>P;
        map<vector<int>,int>R;
        for(int i=0;i<n;++i){
            int x;
            cin>>x;
            A.push_back(x);
        }//cout<<"check "<<endl;
        start=A;
        P[0]=A;
        R[A]++;
        
        map<int,int>Q,Z;
        int d=0;
        while(1){
            Q=Z;
            for(auto &x:start){
                Q[x]++;
            }
            
            for(auto &x:start){
                x=Q[x];
            }
            if(R[start]>0){
                break;
            }
            d++;
            P[d]=start;
            R[start]++;
        }
        
        int q;
        cin>>q;
       // cout<<"check "<<endl;
        
        for(int i=0;i<q;++i){
            int x,k;
            cin>>x>>k;
            
            k=min(d,k);
            x--;
            cout<<P[k][x]<<"\n";
        }
        
        
    }
}
