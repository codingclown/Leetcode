/**
 * Definition for singly-linked list.
 * struct ListNode {
 *        int val;
 *        ListNode * next;
 *        ListNode(int x) : val(x), next(NULL) {}
 * };
*/


class Solution
{
public:
    ListNode* removeElements(ListNode *head, int val)
    {
        ListNode newHead(0);
        
        ListNode * prev = &newHead;
        prev->next = head;
        ListNode * curr = head;
        while(curr != NULL)
        {
            if(curr->val == val)
            {
                prev->next = curr->next;
                curr = curr->next;
            }else
            {
                prev = curr;
                curr = curr->next;
            }
        }
        
        return newHead.next;
    }
};
