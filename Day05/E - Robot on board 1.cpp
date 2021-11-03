/*
Platform :- Codeforces
Contest :- Codeforces Contest 753 Div 3
Approach :- First find the index upto which our robot can execute the command , now start from cell (1,1) and reach out to the end adjusting the starting index accordingly.
             I took the command from that index to 0 and changed 'U'-->'D','L'-->'R' and vice versa and started from index (1,1) and accordingly shifted the position executing the command
             if some command cannont be executed I leaved that and moved to next command since I know he will be able to attend that command and reach it the final position at end.
             
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n,m;
        cin>>n>>m;
        
        string s;
        cin>>s;
        
        int idx=0,x=0,y=0,z=0;
        int mx1=0,mx2=0,mn1=INT_MAX,mn2=INT_MAX;
        
        //find the index upto which our robot can executed instruction in given order
        for(int i=0;i<s.size();++i){
            if(s[i]=='L'||s[i]=='R'){
                if(s[i]=='L'){
                    if((mx1-(x-1))>=m){
                        break;
                    }
                    x--;
                    mn1=min(mn1,x);
                }
                else{
                    if(mn1==INT_MAX)z=0;
                    else z=mn1;
                    
                    if(mx1-z>=m)break;
                    else{
                        x++;
                        mx1=max(mx1,x);
                    }
                }
            }
            else{
                if(s[i]=='U'){
                    if((mx2-(y-1))>=n){
                        break;
                    }
                    y--;
                    mn2=min(mn2,y);
                }
                else{
                    if(mn2==INT_MAX)z=0;
                    else z=mn2;
                    
                    if(mx2-z>=n)break;
                    else{
                        y++;
                        mx2=max(mx2,y);
                    }
                }
            }
            idx++;
        }
        
        //cout<<idx<<" check \n";
        string temp = "";
        for(int i=idx-1;i>=0;--i){
            if(s[i]=='R')temp+='L';
            else if(s[i]=='L')temp+='R';
            else if(s[i]=='D')temp+='U';
            else temp+='D';
        }
        
        int xx=1,yy=1;
        for(int i=0;i<temp.size();++i){
            if(temp[i]=='L'){
                if((yy-1)>=1){
                    yy--;
                }
            }
            else if(temp[i]=='R'){
                if((yy+1)<=m){
                    yy++;
                }
            }
            else if(temp[i]=='D'){
                if((xx+1)<=n){
                    xx++;
                }
            }
            else{
                if((xx-1)>=1)xx--;
            }
        }
        cout<<xx<<" "<<yy<<"\n";
    }
}
