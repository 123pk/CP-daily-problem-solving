/*
Platform :- Coding Competition with Google
Approach :- First creat a vector of character which store the color required for creating all the combinations like for 'A'(Grey) it will store {'R','B','Y'} and so on 
            now we will look for how many times we need to color the boxes with each color individually , like for sequence GPR , we will color all 3 three cell in 1 time , 
            cell 1 and 2 with blue color in 1 time and cell 1 with color yellow in 1 time hence answer is 3 for this.
*/
#include<bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    
    for(int z=1;z<=t;++z){
        cout<<"Case #"<<z<<": ";
        
        int n;
        string s;
        cin>>n>>s;
        
        //I am trying to mainain a vector of llength n where we will have account of colr we need 
        vector<vector<char>>P(n);
        for(int i=0;i<n;++i){
            if(s[i]=='U'){
                continue;
            }
            else if(s[i]=='R'){
                P[i].push_back('R');
            }
            else if(s[i]=='B'){
                P[i].push_back('B');
            }
            else if(s[i]=='Y'){
                P[i].push_back('Y');
            }
            else if(s[i]=='O'){
                P[i]={'R','Y'};
            }
            else if(s[i]=='G'){
                P[i]={'B','Y'};
            }
            else if(s[i]=='P'){
                P[i]={'R','B'};
            }
            else{
                P[i]={'R','Y','B'};
            }
        }
        
        //now number of times we nee to paint red
        int ans=0;
        int f=0,g=0;
        for(int i=0;i<n;++i){
           // for(auto &x:P[i])cout<<x<<" ";
            //cout<<"\n";
            if(P[i].size()){
                
                if(f){
                    g=0;
                    for(int j=0;j<P[i].size();++j){
                       if(P[i][j]=='R'){
                          g=1;
                        }
                     }
                     
                     if(g==0||i==n-1){
                         f=0;
                         ans++;
                     }
                      
                    continue;
                }
                 
                for(int j=0;j<P[i].size();++j){
                    if(P[i][j]=='R'){
                        f=1;
                    }
                }
                
                if(f && i==n-1){
                    ans++;
                }
            }
            else {
                if(f){
                    f=0;
                    ans++;
                }
            }
            
        }
        //cout<<ans<<" ";
        f=0,g=0;
        for(int i=0;i<n;++i){
            if(P[i].size()){
                
                if(f){
                    g=0;
                    for(int j=0;j<P[i].size();++j){
                       if(P[i][j]=='Y'){
                          g=1;
                        }
                     }
                     
                     if(g==0||i==n-1){
                         f=0;
                         ans++;
                     }
                    continue;
                }
                
                for(int j=0;j<P[i].size();++j){
                    if(P[i][j]=='Y'){
                        f=1;
                    }
                }
                
                if(f && i==n-1){
                    ans++;
                }
            }
            else {
                if(f){
                    ans++;
                    f=0;
                }
            }
        }
        //cout<<ans<<" ";
        f=0,g=0;
        for(int i=0;i<n;++i){
            if(P[i].size()){
                
                if(f){
                    g=0;
                    for(int j=0;j<P[i].size();++j){
                       if(P[i][j]=='B'){
                          g=1;
                        }
                     }
                     
                     if(g==0||i==n-1){
                         f=0;
                         ans++;
                     }
                    continue;
                }
                
                for(int j=0;j<P[i].size();++j){
                    if(P[i][j]=='B'){
                        f=1;
                    }
                }
                
                if(f && i==n-1){
                    ans++;
                }
            }
            else {
                if(f){
                    f=0;
                    ans++;
                }
            }
        }
        
        cout<<ans<<"\n";
    }
}
