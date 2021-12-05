/*
Platform :- Leetcode
Contest :- Leetcode Weekly contest 270
Approach :- We store the frequency of each digit of array and now run a loop from 100 to 998 since we just need three digit even number if the frequency of digit of number can
           be satisifed and we have atleast that frequency of particular digits then we can create that number and add to our answer.
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
