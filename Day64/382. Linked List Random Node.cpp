/*
Platform :- Leetcode
Approach :- In c++ we have a function called "rand()" which generates random values from [0 to RAND_MAX ] range which is upto 32567 or so , we can create an array and store all
            the values of linked list and let m = 'size of array'  , and we chooose index as ( rand()%m ) as this will generate values in range [0,m) and return value at that index 
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int m;
    vector<int>val;
    Solution(ListNode* head) {
     
        while(head){
            val.push_back(head->val);
            head=head->next;
        }
       // for(auto &x:val)cout<<x<<" ";
       // cout<<"\n";
        m=val.size();
    }
    
    int getRandom() {
        if(m==0)return 0;
        
        int idx = rand()%m;
        return val[idx];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
