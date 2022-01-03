
/*
Platform :- Codeforces
Contest :- Codeforces Hello 2022
Approach :- we can place atmax (n+1)/2 rookie on the board . if there are more than it then it is not possible . it is always optimal to place on main diagonal and keeping a gap of 1
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n,k;
        cin>>n>>k;
        
        int val =(n+1)/2;
        if(val<k)cout<<"-1\n";
        else{
            for(int i=0;i<n;++i){
                for(int j=0;j<n;++j){
                    if(i==j){
                        if(i%2==0){
                            if(k){
                                cout<<"R";
                                k--;
                            }
                            else cout<<".";
                        }
                        else cout<<".";
                    }
                    else cout<<".";
                }
                cout<<"\n";
            }
        }
    }
}
