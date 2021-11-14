/*
Platform :- Coding Competitions with Google
Approach :- For each character in string 's' , we will find the number of operations we will need to covert to some character of 'f' for all characters of 'f' since string f can have
            atmax 26 characters hence this will take O(N*26) in worst time which is well inside our limit.
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
        string s,f;
        cin>>s>>f;
        
        int ans=0;
        for(int i=0;i<s.size();++i){
            int c=0;
            
            for(int j=0;j<f.size();++j){
                if(j==0){
                    if(f[j]>=s[i]){
                        c=min(f[j]-s[i],(s[i]-'a')+1+('z'-f[j]));
                    }
                    else{
                        c=min(s[i]-f[j],(f[j]-'a')+1+('z'-s[i]));
                    }
                }
                else{
                    if(f[j]>=s[i]){
                        c=min(c,min(f[j]-s[i],(s[i]-'a')+1+('z'-f[j])));
                    }
                    else{
                        c=min(c,min(s[i]-f[j],(f[j]-'a')+1+('z'-s[i])));
                    }
                }
            }
            
            ans+=c;
            
        }
        
        cout<<ans<<"\n";
    }
}
