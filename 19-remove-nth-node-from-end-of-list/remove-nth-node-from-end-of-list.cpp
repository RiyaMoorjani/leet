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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp =head;
        int cnt =0;
        while(temp!=NULL ){
            temp=temp->next;
            cnt++;
        }
        if(cnt==n){//first node is to be deleted 
            return head->next;
        }
        temp=head;
        int res=cnt -n;
        while ( res >1){//temp lies just before the node that is to be deleted 
            temp=temp->next;
            res--;
        }
        //delete node 
        temp->next=temp->next->next;
        return head;

        



        
    }
};