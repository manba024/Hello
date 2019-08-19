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
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode *fistNode = head;
    ListNode *secondNode = head;
    ListNode *lastNode = head;
    int count = 0;
    while (true)
    {
        if (count == n)
        {
            lastNode = secondNode;
            secondNode = secondNode->next;
        }
        else
            count++;
        if (nullptr == fistNode)
            break;
        fistNode = fistNode->next;
    }
    if (nullptr == lastNode->next)
        return lastNode->next;
    else
        lastNode->next = secondNode->next;
    return head;
}

int main() {
    ListNode* listTest = new ListNode(1);
    listTest->next = new ListNode(2);
    removeNthFromEnd(listTest, 2);
    getchar();
    return 0;
}


