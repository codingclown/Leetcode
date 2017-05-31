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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode odd(0), even(0);
        ListNode* ptrOdd = &odd, *ptrEven =&even;
        
        while(head != NULL)
        {
            ptrOdd->next = head;
            head = head->next;
            ptrOdd = ptrOdd->next;
            
            if(head != NULL)
            {
                ptrEven->next = head;
                head = head->next;
                ptrEven = ptrEven->next;
            }
        }
        
        ptrOdd->next = even.next;
        ptrEven->next = NULL;
        return odd.next;
    }
};
