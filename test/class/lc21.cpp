/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
#include <iostream>
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) :val(x), next(nullptr) {}
};
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode* headNode = new ListNode(0);
    ListNode* tmpNode = headNode;
    while (nullptr != l1 || nullptr != l2)
    {
        tmpNode->next = new ListNode(0);
        tmpNode = tmpNode->next;
        if (nullptr == l1)
        {
            tmpNode->val = l2->val;
            l2 = l2->next;
        }
        else if (nullptr == l2)
        {
            tmpNode->val = l1->val;
            l1 = l1->next;
        }
        else if (l1->val > l2->val)
        {
            tmpNode->val = l2->val;
            l2 = l2->next;
        }
        else if (l1->val < l2->val)
        {
            tmpNode->val = l1->val;
            l1 = l1->next;
        }
        else
        {
            tmpNode->val = l1->val;
            tmpNode->next = new ListNode(l2->val);
            tmpNode = tmpNode->next;
            l1 = l1->next;
            l2 = l2->next;
        }
    }
    return headNode->next;
}

int main() {
    ListNode *t1 = new ListNode(-9);
    t1->next = new ListNode(5);
    //t1->next->next = new ListNode(3);

    ListNode *t2 = new ListNode(3);
    t2->next = new ListNode(7);
    //t2->next->next = new ListNode(3);

    mergeTwoLists(t1, t2);
    getchar();
    return 0;
}


