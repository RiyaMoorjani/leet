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
    ListNode* partition(ListNode* head, int x) {
        ListNode* smallhead=new ListNode(0);
        ListNode* largehead=new ListNode(0);
        ListNode* ptr1=smallhead;
        ListNode* ptr2=largehead;
        ListNode* temp=head;
        while(temp!=NULL){
            if(temp->val<x){
                ptr1->next=temp;
                ptr1=ptr1->next;
            }
            else{
                ptr2->next=temp;
                ptr2=ptr2->next;
            }
            temp=temp->next;
        }
        ptr2->next=NULL;
        ptr1->next=largehead->next;
        return smallhead->next;
        
        
    }
};