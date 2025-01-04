## Sort LL
* T:O(nlogn), S:O(1)
```cpp
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
    
    ListNode* merge(ListNode* left,ListNode* right){

        if(left==NULL){
            return right;
        }
        if(right==NULL){
            return left;
        }

        if(left->val<right->val){
            left->next=merge(left->next,right);
            return left;
        }else{
            right->next=merge(left,right->next);
            return right;
        }
    }

    ListNode* mergeSort(ListNode* head){

        if(head==NULL){
            return NULL;
        }
        if(head->next==NULL){
            return head;
        }

        //determine middle
        ListNode* a=head,*b=head->next;

        while(b and b->next){
            a=a->next;
            b=b->next->next;
        }

        ListNode* mid=a->next;
        a->next=NULL;

        ListNode* left=mergeSort(head);
        ListNode* right=mergeSort(mid);

        return merge(left,right);
    }

    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
    }
};
```
