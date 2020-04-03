/*
Link: https://leetcode.com/problems/remove-nth-node-from-end-of-list/

Given a linked list, remove the n-th node from the end of list and return its head.

Example:

Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:

Given n will always be valid.

Follow up:

Could you do this in one pass?
*/


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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head, *slow = NULL;            // taking two pointer fast and slow, at the end fast will point to NULL
                                                        // and slow will point to the previous of the target node.
                                                        
        while(n--) {                                    // Moving the fast pointer n nodes ahead of slow.        
            fast = fast -> next;
        }
        
        if (!fast) {                                    // fast has reached null it means the head is to removed.
            return head->next;
        }
        
        while(fast) {                                   // iterating until fast become NULL
            fast = fast -> next;
            
            if(!slow) {                                 // if slow is NULL
                slow = head;
            } else {
                slow = slow -> next;
            }
        }
        
        slow -> next = slow->next->next;                // as slow points to the previous node of the target node.
                                                        // we save the next of target node to the next of the current node.
                                                        // Hence removing the current node.
        return head;
    }
};

/*
Time Complexity = O(L) where L is the length of the list.
Space Complexity = O(1)
*/
