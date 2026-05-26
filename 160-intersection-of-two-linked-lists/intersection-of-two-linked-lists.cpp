/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        ListNode* a=headA;
        ListNode* b=headB;
        while(a!=NULL && b!=NULL && a!=b){
            a=a->next;
            b=b->next;
            if(a==b){
                return b;
            }
            if(a==NULL){
                a= headA;
            }
            if(b==NULL){
                b= headB;
            }
            
            
        }
    return b;   
        
    }
};