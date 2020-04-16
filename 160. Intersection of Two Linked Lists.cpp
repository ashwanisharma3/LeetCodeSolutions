/*
Link: https://leetcode.com/problems/intersection-of-two-linked-lists/

Write a program to find the node at which the intersection of two singly linked lists begins.

For example, the following two linked lists:


begin to intersect at node c1.

 

Example 1:


Input: intersectVal = 8, listA = [4,1,8,4,5], listB = [5,0,1,8,4,5], skipA = 2, skipB = 3
Output: Reference of the node with value = 8
Input Explanation: The intersected node's value is 8 (note that this must not be 0 if the two lists intersect). From the head of A, it reads as [4,1,8,4,5]. From the head of B, it reads as [5,0,1,8,4,5]. There are 2 nodes before the intersected node in A; There are 3 nodes before the intersected node in B.
 

Example 2:


Input: intersectVal = 2, listA = [0,9,1,2,4], listB = [3,2,4], skipA = 3, skipB = 1
Output: Reference of the node with value = 2
Input Explanation: The intersected node's value is 2 (note that this must not be 0 if the two lists intersect). From the head of A, it reads as [0,9,1,2,4]. From the head of B, it reads as [3,2,4]. There are 3 nodes before the intersected node in A; There are 1 node before the intersected node in B.
 

Example 3:


Input: intersectVal = 0, listA = [2,6,4], listB = [1,5], skipA = 3, skipB = 2
Output: null
Input Explanation: From the head of A, it reads as [2,6,4]. From the head of B, it reads as [1,5]. Since the two lists do not intersect, intersectVal must be 0, while skipA and skipB can be arbitrary values.
Explanation: The two lists do not intersect, so return null.
 

Notes:

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.

*/

//Solution 1
/*
TC = O(m + n)
SC = O(m + n) where m and n are the length of the strings
*/
// the solution uses stack
// we pus the pointer of both the linked lists in two seperate stacks
// then we pop them out until the pointer are not equal
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        stack <ListNode *> stA;
        stack <ListNode *> stB;
        
        ListNode *ptr = headA;
        
        while(ptr) {
            stA.push(ptr);
            ptr = ptr -> next;
        }
        
        ptr = headB;
        while(ptr) {
            stB.push(ptr);
            ptr = ptr -> next;
        }
        
        while (!stA.empty() && !stB.empty()) {
            if (stA.top() == stB.top()) {
                ptr = stA.top();
                stA.pop();
                stB.pop();
            } else {
                break;
            }
        }
        
        return ptr;
    }
};

//Solution 2
/*
TC = O(n)
SC = O(1)
*/
// The solution uses the length of the LL.
// then move the starting pointer of greater node by the difference of the lengths
// then iterate until the equal pointers are found
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = 0, lenB = 0;
        
        ListNode *ptr = headA;
        
        while(ptr) {
            lenA++;
            ptr = ptr -> next;
        }
        
        ptr = headB;
        
        while(ptr) {
            lenB++;
            ptr = ptr -> next;
        }
        
        if (lenA > lenB) {
            while(lenA - lenB) {
                headA = headA -> next;
                lenA--;
            }
        } else {
            while(lenB - lenA) {
                headB = headB -> next;
                lenB--;
            }
        }
        
        while(headA != headB) {
            headA = headA -> next;
            headB = headB -> next;
        }
        return headA;
    }
};

// Solution 3
/*
TC = O(n)
SC = O(1)
*/
// The solution uses a simple approach that if two pointer iterate both the LL
// doesn't matter from where they start, they will cover the same length.
// What we do, here is that we start two pointer from the respective head of LL.
// and when the end of the LL is reached, we assign the head of the other LL to 
// this pointer.
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode * ptrA = headA, *ptrB = headB;
        
        while (ptrA != ptrB) {
            ptrA = (ptrA) ? ptrA -> next : headB;
            ptrB = (ptrB) ? ptrB -> next : headA;
        }
        cout<<ptr -> val;
        return ptrA;
    }
};