/*
Platform :- Codeforces
Contest :- Codeforces Round 766
Approach :- if there is no black cell then we can't color our cell 'r',' c' , else we need atmost 2 steps , if any cell in row 'r' or any cell in coloumn 'c'
           is colored black then we need atmax 1 , if the cell itself is black then 0
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n,m,r,c;
        cin>>n>>m>>r>>c;
        
        int d=2;
        int f=0;
        char ch[n][m];
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                cin>>ch[i][j];
                if(ch[i][j]=='B'){
                    f=1;
                    if(i==(r-1)||(j==c-1))d=1;
                }
            }
        }
        
        if(f==0)cout<<"-1\n";
        else if(ch[r-1][c-1]=='B') cout<<0<<"\n";
        else {
            cout<<d<<"\n";
        }
    }
}
