/*
Platform :- Leetcode
Contest :- Leetcode Weekly contest 272
Approach :- For a particular subarray of size 'x' number of such descents is (x*(x+1))/2 , so we traverse from 0 to n-1 and find those subarray and add the following values
            to our answer.
*/
class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long ans=0;
        long long c=0;
        for(int i=0;i<prices.size();++i){
            if(i==0){
                c++;
                if(i==prices.size()-1){
                    ans+=(c*(c+1))/2;
                }
                
            }
            else{
                if((prices[i-1]-prices[i])==1){
                    c++;
                }
                else{
                    ans+=(c*(c+1))/2;
                    c=1;
                }
                
                if(i==prices.size()-1){
                    ans+=(c*(c+1))/2;
                }
            }
        }
        return ans;
    }
};
