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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1,s2;
        while(l1 != nullptr)
        {
            s1.push(l1->val);
            l1 = l1->next;
        }
        while(l2 != nullptr)
        {
            s2.push(l2->val);
            l2 = l2->next;
        }
        
        ListNode *res = new ListNode(0), *tmp = NULL;
        for(int sum = 0; !s1.empty() || !s2.empty(); sum/=10, tmp = new ListNode(sum), tmp->next = res,res =tmp)
        {
            if(!s1.empty())
            {
                sum += s1.top();
                s1.pop();
            }
            if(!s2.empty())
            {
                sum += s2.top();
                s2.pop();
            }
            res->val = sum%10;
        }
        return res->val ? res : res->next;
    }
};
