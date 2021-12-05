/*
Platform :- Leetcode
Contest:- Leetcode Weekly contest 270
Approach :- first take all the elemnts of linked list and store in vector now remove the middle element and create a new linked list of those array of elements and return the head
            of this new linked list
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
    ListNode* deleteMiddle(ListNode* head) {
        vector<int>temp;
        ListNode*ans=NULL;
        
        while(head){
            temp.push_back(head->val);
            head=head->next;
        }
        
        int n=temp.size();
        n/=2;
        temp.erase(temp.begin()+n);
        
        ListNode* start = new ListNode();
        for(int i=0;i<temp.size();++i){
            ListNode* vl = new ListNode();
            vl->val=temp[i];
            
            if(i==0){
               start = vl;
               ans = start;
            }
            else{
                start->next = vl;
                start=start->next;
            }
        }
        
        return ans;
    }
};
