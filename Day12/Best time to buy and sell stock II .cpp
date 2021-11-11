/*
Platform :- Leetcode
Approach :- As we can sell and buy stock on same day so we will do store the stock value in stack and if the value of stack is greater than the current stock price then we remove the
            top value of stack and add the current stock price to the stack else we will sell the stock and add the profit to our answer , and replace stack top with current stock value. 
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0;
        stack<int>P;
        for(int i=0;i<prices.size();++i){
            if(i==0)P.push(prices[i]);
            else {
                if(P.top()>=prices[i]){
                    P.pop();
                    P.push(prices[i]);
                }
                else{
                    ans+=(prices[i]-P.top());
                    P.pop();
                    P.push(prices[i]);
                }
            }
        }
        
        return ans;
    }
};
