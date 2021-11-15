/*
Platform :- Leetcode
Contest :- Leetcode Weekly contest 267
Approach :- repeatedly perform the operations as said in problem statement
*/
class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        set<int>temp;
        for(int i=0;i<tickets.size();++i){
            temp.insert(i);
        }
        
        int ans=0,f=0;
        vector<int>z;
        while(!temp.empty()){
            z.clear();
            for(auto &x:temp){
                tickets[x]--;
                ans++;
                if(tickets[x]==0){
                    if(x==k){
                        f=1;
                        break;
                    }
                    z.push_back(x);
                }
            }
            if(f)break;
            
            //I WANT TO REMOVE THE VALUES WHICH ARE ZERor
            for(int i=z.size()-1;i>=0;--i)temp.erase(z[i]);
            
            
        }return ans;
         
    }
};
