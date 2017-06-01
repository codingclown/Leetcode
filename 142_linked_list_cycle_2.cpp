/**
 * Definition for single-linked list.
 * Struct ListNode {
 *      int val;
 *      ListNode* next;
 *      ListNode(int x) : val(x), next(NULL) {}
 *};
*/

//首先判断是否有环。方法很简单，使用快慢指针，如果两个指针相遇，则证明有环，如果快指针等于NULL，则没有环
//其次，如何求出环的起始位置。当快慢指针第一次相遇之后，将快指针移到链表起点，然后快慢指针同时移动，每次只走一步，相遇的位置就是换的起始点。
//解释：假设环的长度为L,从开始到两个指针第一次相遇，Slow指针一共走了m步，Fast指针一共走了2m步，Fast比Slow夺走了x圈，则 m = x*L, 那么将Fast指针移到起点，
//Fast和Slow同时走，每次走一步，m步以后，Fast和Slow会在停留在相同的位置，去掉重合的区域，相遇的位置就是环的起始点。



class Solution{
public:
    ListNode* detectCycle(List *head)
    {
        if(head == NULL || head->next == NULL || head->next->next == NULL) return NULL;
        
        
        ListNode *fast = head, *slow = head;
        while(fast != nullptr)
        {
            fast = fast->next;
            slow = slow->next;
            
            if(fast == nullptr) return NULL;
            
            fast = fast->next;
            if(fast == slow)
            {
                fast = head;
                while(fast != slow)
                {
                    fast = fast->next;
                    slow = slow->next;
                }
                return fast;
            }
        }
        
        
        return NULL;
    }
};
