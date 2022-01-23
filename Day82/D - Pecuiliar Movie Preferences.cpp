/*
Platform :- Codeforces
Contest :- Codeforces Round 767 Div 2
Approach :- Since the size of string is 3, and we need atmax 2 strings to get one palindrom ant aleast one string . Take care of all the cases which will result in palindrome.
            Case 1 :- Size of string is 1,  then it is already a plaindrome 
            Case 2 :- Size is 2 , if both characters are equal then also it is a palindrome , else we need to find "reverse" string of this
            Case 3 :-  Size is 3, if all characters are equal then it is already a palindrome , else we try to find reverse and check if we can find another string of size 2 
                        which will form it palindrome and there are two cases when we add that string to the begiining of it and if at the end take care of that.
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        
        vector<string>P;
        set<string>Q,R;
        string s;
        int f=0;
        for(int i=0;i<n;++i){
            cin>>s;
            P.push_back(s);
           
            
            if(s.size()==1){
                f=1;
            }
            else {
               if(s[0]==s[s.size()-1]){
                   f=1;
               }   
            }
             
        }
        
        string temp="";
        for(int i=0;i<n;++i){
            
            if(P[i].size()==1){
                f=1;break;
            }
            else{
                if(P[i].size()==2){
                    //if both equa;
                    if(P[i][0]==P[i][1]){
                      //  cout<<" * ";
                        f=1;break;
                    }
                    else{
                        if(Q.size()){
                            temp="";
                            temp+=P[i][1];
                            temp+=P[i][0];
                            if(Q.find(temp)!=Q.end()){
                              f=1;
                             //   cout<<" && ";
                              break;
                            }
                            
                            if(R.size()){
                                if(R.find(temp)!=R.end()){
                                    f=1;
                                    break;
                                }
                            }   
                        }
                        
                    }
                }
                else{
                    //check for reverse 
                   if(Q.size()){ temp="";
                    temp+=P[i][2];
                    temp+=P[i][1];
                    temp+=P[i][0];
                    if(Q.find(temp)!=Q.end()){
                      //  cout<<" %% ";
                        f=1;break;
                    }
                    
                    temp="";
                    temp+=P[i][2];
                    temp+=P[i][1];
                    //cout
                    if(Q.find(temp)!=Q.end()){
                     //  cout<<temp<<" ^^ ";
                        f=1;
                        break;
                    }
                    
                    
                    
                   }
                    temp="";
                    temp+=P[i][0];
                    temp+=P[i][1];
                    R.insert(temp);
                }
            }
             Q.insert(P[i]);
        }
        
        if(f)cout<<"YES\n";
        else cout<<"NO\n";
    }
}
