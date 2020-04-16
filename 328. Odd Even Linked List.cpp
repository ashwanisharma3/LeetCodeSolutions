/*
Link: https://leetcode.com/problems/odd-even-linked-list/

Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.

You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.

Example 1:

Input: 1->2->3->4->5->NULL
Output: 1->3->5->2->4->NULL
Example 2:

Input: 2->1->3->5->6->4->7->NULL
Output: 2->3->6->7->1->5->4->NULL
Note:

The relative order inside both the even and odd groups should remain as it was in the input.
The first node is considered odd, the second node even and so on ...
*/

//Solution 1
/*
TC = O(n)
SC = O(1)
*/
// The approach here is to bring all the odd to node to the beginning of the the LL.
// We will do this in O(n) by taking pointer, one at the end of the current odd node 
// at the beginning and other iterating the node. But basically it would be pointing 
// to the end of the last even node.

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head){
            return head;
        }
        
        ListNode *odd = head, *even = head  -> next, *temp;    
        while (even && even -> next) {                          // while there exists even node and its next node
            temp = odd -> next;                                 // storing the next of current odd node
            odd -> next = even -> next;                         // storing the next of next of current even to current odd node next
            odd = odd -> next;                                  // moving ptr to next
            even -> next = odd -> next;
            odd -> next = temp;                                 
            even = even -> next;
        }
        return head;
    }
};

//Solution 2
/*
TC = O(n)
SC = O(1)
*/

// The approach here to seperate the odd node and even node and then save the head of even node
// to the last of the odd node.

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head){
            return head;
        }
        
        ListNode *odd = head, *even = head  -> next, *even_Head = head  -> next;
        
        while (even && even -> next) {
            odd -> next = even -> next;
            odd = odd -> next;
            even -> next = odd -> next;
            even = even -> next;
        }
        
        odd -> next = even_Head;
        return head;
    }
};