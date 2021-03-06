/*
Link: https://leetcode.com/problems/reverse-linked-list/

Reverse a singly linked list.

Example:

Input: 1->2->3->4->5->NULL
Output: 5->4->3->2->1->NULL
Follow up:

A linked list can be reversed either iteratively or recursively. Could you implement both?

*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// iteratively
// The approach keeps the track of three pointers i.e. previous, current and next.
// Firstly save the next of current
// Then, in next of current save the previous
// Then make previous equal to current and move current to next
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
        ListNode *curr = head, *next = NULL, *prev = NULL;
        
        while(curr) {
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};

/*
TC = O(n)       where n is the length of the linked list
SC = O(1)
*/

===============================================================================================================

// recursively
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head -> next) {               // if head and next of head if null
            return head;
        }
        
        ListNode * temp = reverseList(head -> next);// calling reverseList on next of current node
        
        head -> next -> next = head;                // saving the current node in the next of next
        head -> next = NULL;                        // saving the null in current
        
        return temp;                                // return the new head
    }
};
/*
TC = O(n)       where n is the length of the linked list
SC = O(n)
*/