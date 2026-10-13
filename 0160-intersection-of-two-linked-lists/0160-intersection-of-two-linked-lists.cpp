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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return nullptr;

        ListNode* ptrA = headA;
        ListNode* ptrB = headB;

        // Traverse both lists. When ptrA reaches the end of list A, redirect it to headB.
        // When ptrB reaches the end of list B, redirect it to headA.
        while (ptrA != ptrB) {
            ptrA = (ptrA == nullptr) ? headB : ptrA->next;
            ptrB = (ptrB == nullptr) ? headA : ptrB->next;
        }

        // Returns either the intersection node or nullptr if no intersection exists
        return ptrA;
    }
};