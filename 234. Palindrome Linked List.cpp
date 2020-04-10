/*
Link: https://leetcode.com/problems/palindrome-linked-list/

Given a singly linked list, determine if it is a palindrome.

Example 1:

Input: 1->2
Output: false
Example 2:

Input: 1->2->2->1
Output: true
Follow up:
Could you do it in O(n) time and O(1) space?
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// Using Stack

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(!head)
            return true;
        
        stack<int> st;
        
        ListNode *p = head;
        
        while(p) {
            st.push(p->val);
            p = p -> next;
        }
        
        p = head;
        
        while(p) {
            if (p -> val == st.top()) {
                st.pop();
                p = p -> next;
            } else {
                return false;
            }
        }
        return true;
    }
};


// Using reverse of Linked List

