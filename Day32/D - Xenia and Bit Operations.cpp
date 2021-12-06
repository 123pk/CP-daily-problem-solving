/*
Platform :- Codeforces
Contest :- Codeforces Round 197 Div 2
Approach :- The operations said in problem statement is suitable for tree operation , a perfect complete binary tree is formed if we will perform the operations , so we will create
            the complete binary tree with operations and we will update leaf to root path which will take logn operations and overall time complexity of program is goint to ( m*log(n)) 
*/
#include<bits/stdc++.h>
using namespace std;

void update(int idx,long long value,vector<long long>&graph){
     graph[idx]=value;
     //cout<<idx<<" ";
      int d=0;
     while(idx){
         idx=((idx+1)/2)-1;
      //   cout<<idx<<" ";
         if(d%2){
             graph[idx] = (graph[(2*idx)+1] xor graph[(2*idx)+2]);
         }
         else{
             graph[idx] = (graph[(2*idx)+1]|graph[(2*idx)+2]);
         }
         d++;
     }
  //   cout<<"\n";
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n,q;
    cin>>n>>q;
    
    int size = (1<<n);
    
    //create a tree complete binary tree and for updation we can use segment tree
    // so we jut need to change value of nodes in that particular path
    int m = (size*2)-1;
    vector<long long>graph(m);
    
    for(int i=m/2;i<m;++i){
        cin>>graph[i];
    }
    
    //let us fill the data in empty cells /nodes of tree
    int it = n-1, ele,idx=m/2;
    idx--;
    int g = 0;
    
    while(1){        
        ele = (1<<it);
        // cout<<ele<<" "<<it<<" checkig \n";
        for(int i=0;i<ele;++i){
            // cout<< (2*(idx-i))+1<<" "<<((2*(idx-i))+2)<<" the children of "<<(idx-i)<<"---> ";
            if(g==0){
                graph[idx-i]=(graph[(2*(idx-i))+1]|graph[(2*(idx-i))+2] );
               // cout<<"* ";
                
            }
            else{
                graph[idx-i]=(graph[(2*(idx-i))+1] xor graph[(2*(idx-i))+2] );
                
            }//cout<<graph[idx-i]<<" \n";
        }
        idx-=ele;
        it--;
        if(g)g=0;
        else g=1;
        
        if(ele==1)break;
    }
    
    
    
    //now we will check if the entered values are leaf of tree or not 
    /* for(int i=0;i<m;++i){
        cout<<graph[i]<<" ";
    }
    cout<<"\n";*/
     
      
    long long value;
    for(int i=0;i<q;++i){
        cin>>idx>>value;
        idx--;
        update(((m/2)+idx),value,graph);
        cout<<graph[0]<<"\n";
    }
}
