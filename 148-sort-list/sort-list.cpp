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
    ListNode* findMiddle(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;

        }
        return slow;
    }
    ListNode* merge(ListNode* left,ListNode* right){
        ListNode* dummy =new ListNode(0);
        ListNode* ptr=dummy;
        
        while(left!=NULL && right!= NULL){
            if(left->val<right->val){
                ptr->next=left;
                left=left->next;
            }else{
                ptr->next=right;
                
                right=right->next;

            }
            ptr=ptr->next;
        }
        while(left!=NULL){
            ptr->next=left;
            left=left->next;
            ptr=ptr->next;
            
        }
        while(right!=NULL){
            ptr->next=right;
            right=right->next;
            ptr=ptr->next;
        }

        return dummy->next;
    }

    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* mid=findMiddle(head);
        ListNode* left=head;
        ListNode* right=mid->next;
        mid->next=NULL;
        left=sortList(left);
        right=sortList(right);
        return merge(left,right);
        
    }
};