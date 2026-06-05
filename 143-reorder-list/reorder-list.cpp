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
    ListNode* reverse(ListNode* head){
        ListNode* prev=NULL;
        ListNode* forward=NULL;
        ListNode* curr=head;
        while(curr!=NULL){
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
        return prev;

    }
    ListNode* middle(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    void merge(ListNode* l1,ListNode* l2){
        while(l1!=NULL && l2!=NULL){
            ListNode* next1=l1->next;
            ListNode* next2=l2->next;
            l1->next=l2;
            if(next1 ==NULL) break;
            l2->next=next1;
            l1=next1;
            l2=next2;


        }
    }
    void reorderList(ListNode* head) {
        ListNode* mid=middle(head);
        //break into 2 list
        ListNode* left=head;
        ListNode* right=mid->next;
        mid->next=NULL;
        right=reverse(right);
        merge(left,right);
        
    }
};