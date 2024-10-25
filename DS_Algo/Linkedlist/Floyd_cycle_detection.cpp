/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// Time O(N) | Space O(1).
class Solution {
public:
    bool hasCycle(ListNode *head) {
        
        if(head==NULL){
            return false;
        }

        ListNode* temp=head->next;
        if(temp and temp->next){
            temp=temp->next->next;

        }else return false;

        while(head and temp){
            if(temp==head){
                return true;
            }
            if(temp and temp->next){
                temp=temp->next->next;

            }else break;
            head=head->next;
        }

        return false;
    }
};
