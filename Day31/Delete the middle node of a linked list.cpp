/*
Platform :- Leetcode
Contest:- Leetcode Weekly contest 270
Approach :- first take all the elemnts of linked list and store in vector now remove the middle element and create a new linked list of those array of elements and return the head
            of this new linked list
*/
class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        map<int,int>P;
        for(auto &x:digits)P[x]++;
        
        vector<int>ans;
        
        for(int i=100;i<=998;i+=2){
            //check for the frequency of values
            vector<int>z(10);
            int temp=i;
            while(temp){
                z[temp%10]++;
                temp/=10;
            }
            int f=0;
            for(int i=0;i<=9;++i){
                if(P[i]<z[i]){
                    f=1;break;
                }
            }
            if(f==0)ans.push_back(i);
        }
        
        return ans;
    }
};
