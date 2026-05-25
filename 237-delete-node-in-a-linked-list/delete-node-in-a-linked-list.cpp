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
    void deleteNode(ListNode* node) {
        // Step 1: Copy the value of the next node into the current node
        // Example: If current node's value = 5 and next node's value = 7
        //          after this step, current node's value becomes 7.
        node->val = node->next->val;

        // Step 2: Store the next node in a temporary pointer
        // We do this so we can delete it later without losing access to it.
        
        // Step 3: Point the current node's next to the node after temp
        // This effectively skips the node we are going to delete.
        node->next = node->next->next;

        // Step 4: Free the memory of the skipped node
        
    }
};

