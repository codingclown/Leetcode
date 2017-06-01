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
    ListNode* reverseList(ListNode* head) {
        ListNode * newHead = NULL;
        ListNode * curr = head;
        ListNode * temp = NULL;
        while (curr != NULL) {
            temp = curr;
            curr = curr->next;
            temp->next = newHead;
            newHead = temp;
        }
        
        return newHead;
    }
};
