/*
Platform :- Leetcode
Approach :- Traverse through the linked list and maintain a set off all the adress of visited nodes of linked list if we got to one visited node then this is the 
            starting node of cycle and we return this else we return NULL at the end.
*/
 
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        set<ListNode*>used;
        
        if(!head)return NULL;
        
        
        while(head){
            if(used.size()){
                if(used.find(head)==used.end()){
                    used.insert(head);
                    head=head->next;
                }
                else{
                    return head;
                }
            }
            else{
                used.insert(head);
                head=head->next;
            } 
        }
        return NULL;
    }
};
