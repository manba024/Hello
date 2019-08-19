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
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *handNode = new ListNode(0);       //头节点   
    ListNode *currentNode = handNode;           //当前节点
    bool isCarry = false;                       //是否需要进位
    while (nullptr != l1 || nullptr != l2)
    {
        if (nullptr == l1)
        {
            currentNode->val += l2->val;
        }
        else if (nullptr == l2)
        {
            currentNode->val += l1->val;
        }
        else
            currentNode->val += l1->val + l2->val;
        
        if (currentNode->val > 9)
        {
            currentNode->val = currentNode->val % 10;
            isCarry = true;
        }
        l1 = l1 == nullptr ? nullptr : l1->next;
        l2 = l2 == nullptr ? nullptr : l2->next;
        
        if (nullptr != l1 || nullptr != l2 || isCarry)
        {
            currentNode->next = new ListNode(0);
            currentNode = currentNode->next;
            if (isCarry)
                currentNode->val++;
            isCarry = false;
        }
        else
            break;
    }
    return handNode;
}
ListNode* test()
{
    ListNode *handNode = new ListNode(0);
    ListNode *currNode = handNode;
    for (int i = 0; i < 3; ++i)
    {
        currNode->val = i;
        if (i< 2)
        {
            currNode->next = new ListNode(0);
            currNode = currNode->next;
        }
    }
    return handNode;
}
ListNode* test1(ListNode *l1, ListNode *l2) {
    ListNode* pre = new ListNode(0);
    ListNode* cur = pre;
    int carry = 0;
    while (l1 != nullptr || l2 != nullptr) {
        int x = l1 == nullptr ? 0 : l1->val;
        int y = l2 == nullptr ? 0 : l2->val;
        int sum = x + y + carry;

        carry = sum / 10;
        sum = sum % 10;
        cur->next = new ListNode(sum);

        cur = cur->next;
        if (l1 != nullptr)
            l1 = l1->next;
        if (l2 != nullptr)
            l2 = l2->next;
    }
    if (carry == 1) {
        cur->next = new ListNode(carry);
    }
    return pre->next;
}
int main() {
    //243 564
    ListNode *node1 = test();//new ListNode(5);
    ListNode *node2 = test();//new ListNode(5);
    node1->val = 1;
    node1->next = nullptr;
    //node1->next->next->val = 3;
    node2->val = 9;
    node2->next->val = 9;
    node2->next->next = nullptr;// = 4;
    ListNode *node3 = addTwoNumbers(node1, node2);
    while (nullptr != node3)
    {
        std::cout << node3->val << std::endl;
        node3 = node3->next;
    }
    int a = 9 / 10;
    int b = 11 % 10;
    int c = 1;
    /*ListNode *test = node2->next->next->next;
    if (nullptr == test)
    {
        std::cout << "asdf" << std::endl;
    }*/
    getchar();
    return 0;
}

//class Solution {
//public:
//    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//
//    }
//};