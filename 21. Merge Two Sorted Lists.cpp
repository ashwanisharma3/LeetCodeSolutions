/*
Link: https://leetcode.com/problems/merge-two-sorted-lists/

Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

Example:

Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        ListNode *head = new ListNode(0), *p = NULL;    // head pointer for the next node
        p = head;                                       // p is moving pointer
        
        while(l1 && l2) {                               // if node from both the list exists
            if(l1 ->val < l2 -> val) {                  // when val of l1 is lesser
                p -> next = new ListNode(l1 -> val);    // save the value of l1 to new node and save it to next of p
                l1 = l1 -> next;                        // moving l1 to next node
            } else {
                p -> next = new ListNode(l2 -> val);    // same as above if
                l2 = l2 -> next;
            }
            p = p -> next;                              // moving p pointer to its next node
        }
        p -> next = (l1) ? l1 : l2;                     // if there exists node in any of the list
        return head -> next;                            // returning next of head, as first node is zero.
    }
};

/*
TC = O(m + n)
SC = O(m + n)   where m & n are the length of the linked list
*/

// in place - iteratively

class Solution {    
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1) {                              // if l1 is null
            return l2;
        } 
        
        if(!l2) {                               // if l2 is null
            return l1;
        }
        
        ListNode* head, *ptr;                   // head pointer to return and ptr to traverse
        if (l1 -> val < l2 -> val) {            // when first node of l1 is less than l2
            head = l1;
            l1 = l1 -> next;                    
        } else {
            head = l2;
            l2 = l2 -> next;
        }
        
        ptr = head;
        
        while (l1 && l2) {                      // both l1 and l2 should exists
            if (l1 -> val < l2 ->val) {
                ptr -> next = l1;               // assign l1 to the next of ptr
                l1 = l1 -> next;
            } else {
                ptr -> next = l2;               // assign l1 to the next of ptr
                l2 = l2 ->next;
            }
            ptr = ptr -> next;                  // moving ptr to next
        }
        
        if (l1) {                               // if there are nodes in l1 left
            ptr -> next = l1;
        } else {
            ptr -> next = l2;
        }
    
        return head;
    }
};
/*
TC = O(m + n)
SC = O(1)
*/

// in place recursively

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

        if (!l1 && !l2) {                               // if both the node are null
            return NULL;
        }
        
        if (!l1) {                                      // if l1 is null
            return l2;
        }
        
        if (!l2) {                                      // if l2 is null
            return l1;
        }
        
        if (l1 -> val < l2 -> val) {                    // if val of l1 is less than l2
            l1 -> next = mergeTwoLists(l1 -> next, l2); // saving the returned pointer of the recursive call
            return l1;                                  // return
        } else {
            l2 -> next = mergeTwoLists(l1, l2 -> next);
            return l2;
        }
    }
};
/*
TC = O(n + m)
SC = O(n + m)
*/
