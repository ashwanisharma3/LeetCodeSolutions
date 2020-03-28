/*
Link: https://leetcode.com/problems/add-two-numbers/

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
*/

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* head = new ListNode(0);           // new node to return the sum
    ListNode* ptr = head;                       // pointer to traverse
    int carry=0, sm, n1, n2;              
    
    while (l1 || l2) {                          // traverse while both of the linked lists are not null
        n1 = (l1) ? l1->val : 0;                // in case one l1 become null its value will be treated as 0
        n2 = (l2) ? l2->val : 0;
        
        sm = n1 + n2 + carry;
        
        ptr->next = new ListNode(sm % 10);      // creating a new node with the ones place of the sum and assigning it to next of ptr
        ptr = ptr->next;                        // moving ptr to its next
        
        carry = sm / 10;                        // carry
        
        if (l1) {
            l1 = l1->next;
        }
        
        if (l2) {
            l2 = l2->next;
        }
    }
    
    if(carry) {                                 // when both the list are null but there is a carry left 
        ptr->next = new ListNode(carry);        // create a new node and assign it the next of current ptr.
    }
    
    return head->next;                          // return next of head as there a node at the begining containing 0.
}
    
    
/*
Time Complexity: O(max(m,n)) m & n are the length of the lists.
Space Complexity: O(max(m,n))
*/
