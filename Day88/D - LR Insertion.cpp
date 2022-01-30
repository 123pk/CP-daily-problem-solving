/*
Platform :- Atcoder
Contest :- Atcoder Beginner Contest 237
Approach :- We thing this problem as going back from last value which is 'n' to '0' , we use deque for this 
           we reverse the path and change 'L' to 'R' and vice versa as are going in back , now if we have 'L' command the we add to the front else we add to the end of queue,
           we add value 'd' which is 'n' in starting as we decrement it after each operation at the we end we print all the values and that is our desired sequence.
*/
#include<bits/stdc++.h>
using namespace std;

bool comp(pair<int,int>&P,pair<int,int>&Q){
    if(P.first==Q.first)return P.second<Q.second;
    return P.first<Q.first;
}

int main(){
    int n;
    cin>>n;
    
     string s;
     cin>>s;
     
     reverse(s.begin(),s.end());
     for(int i=0;i<n;++i){
         if(s[i]=='L')s[i]='R';
         else s[i]='L';
     }
     
     deque<int>P;
     P.push_back(n);
     int d=n-1;
     for(int i=0;i<n;++i){
         if(s[i]=='L')P.push_front(d);
         else P.push_back(d);
         d--;
     }
     
     for(auto x:P)cout<<x<<" ";
     cout<<"\n";
}
