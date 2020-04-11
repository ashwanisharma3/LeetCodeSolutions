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


// Recursive Solution
// The approaches uses the concept that once we reach that last node of the list, we hace acces to first and last node.
// Then, we compare them and if they are equal, we compare the next of first and second last from the last.

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(!head || !head -> next)                      // if there either no node or signle node
            return true;
        
        return checkPalin(&head, head->next);           
    }
    
    bool checkPalin (ListNode **first, ListNode *last) {
        if(!last) {                                     // when we have reached the last node of the list
            return true;
        }
        
        bool isPalin = checkPalin (first, last -> next);// calling for the next of last
        
        if (!isPalin) { 
            return false;
        }
        
        isPalin = (*first) -> val == last -> val;       // checking for the value of
        
        *first = (*first) -> next;
            
        return isPalin;
    }
};

/*
TC = O(n)
SC = O(n)
*/

// In place by reversing the second half of the list
// The approach uses the concept of reversing the second half of the list and then comparing its first element
// to first element of original list and so on.
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head -> next)
            return true;
        if (!head -> next -> next) {
            return head -> val == head -> next -> val;
        }
        
        ListNode *ptr = head, *fast = head, *slow = NULL;
        
        while(fast && fast -> next) {
            fast = fast -> next -> next;
            if (!slow)
                slow = head;
            else
                slow = slow -> next;
        }
        if (fast) {
            slow = slow -> next;
        }
        slow -> next = reverse(slow -> next);
        slow = slow -> next;
        while (slow) {
            if (ptr -> val != slow -> val)
                return false;
            slow = slow -> next;
            ptr = ptr -> next;
        }
        
        return true;
        
    }
    
    ListNode* reverse (ListNode* head) {
        ListNode *prev = NULL, *curr = head, *next = NULL;
        
        while(curr) {
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};