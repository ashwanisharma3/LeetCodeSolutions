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
    ListNode* head1 = NULL;                     // declaring a global variable head1
    ListNode* reverse(ListNode *head) {
        if(!head -> next) {                     // if we are at the last node
            head1 = head;
            return head;
        }
        ListNode * p = head;
        ListNode *temp = reverse(p -> next);    // calling the reverse function on next of p
        temp -> next = p;                       // temp is the next node of p, hence saving p in the next of it
        p -> next = NULL;                       // making the next of p NULL
        return p;
    }
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next)                // if either list is empty or there is only one element
            return head;
        reverse(head);
        return head1;                           // returning head1, declared globally
    }
};

/*
TC = O(n)       where n is the length of the linked list
SC = O(n)
*/