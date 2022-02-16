/*
Platform :- Leetcode
Approach :- We perform the operation by check if we have next pointer is not empty and swapping the values ,
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
    ListNode* swapPairs(ListNode* head) {
        if(!head)return NULL;
        if(!head->next)return head;
        ListNode*temp=head;
        ListNode*end=NULL;
        while(temp){
            if(temp->next){
                swap(temp->val,temp->next->val);
                if(temp->next->next){
                    end=temp->next->next;
                
                }else{
                    break;
                }
                temp=end;
            }
            else{
                break;
            }
        }
        
        return head;
    }
};
