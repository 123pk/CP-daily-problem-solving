/*
Platform:- Leetcode
Contest :- Leetcode Bi weekly contest 69
Approach :- Store the node values in array now itterate on first half and find max ( A[i]+A[n-1-i])
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
    int pairSum(ListNode* head) {
        vector<int>A;
        while(head){
            A.push_back(head->val);
            head=head->next;
        }
        
        int ans=0;
        int n=A.size();
        for(int i=0;i<n/2;++i){
            ans=max(ans,A[i]+A[n-1-i]);
        }
        return ans;
    }
};
