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
    bool isPalindrome(ListNode* head) {
        ListNode *fast = head, *slow = head;
        while(fast != NULL && fast->next != NULL) //这种写法其实slow会指向第 n/2 +1 个节点
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        
        //翻转后半段链表
        ListNode* prev = NULL;
        while (slow != NULL) {
            ListNode * tmp = slow;
            slow = slow->next;
            tmp->next = prev;
            prev = tmp;
        }
        
        //进行比对
        fast = head;
        while(prev != NULL)
        {
            if(fast->val == prev->val)
            {
                fast =fast->next;
                prev = prev->next;
            }else
            {
                return false;
            }
        }
        
        return true;
    }
};
