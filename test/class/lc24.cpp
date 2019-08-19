/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) :val(x), next(nullptr) {}
};
ListNode* mergeKLists(vector<ListNode*>& lists) {
    vector<int> arr;
    for (auto l : lists)
    {
        while (nullptr != l)
        {
            arr.push_back(l->val);
            l = l->next;
        }
    }
    sort(arr.begin(), arr.end());
    if (0 == arr.size())
        return nullptr;
    ListNode* headNode = new ListNode(0);
    ListNode* node = headNode;
    for (auto l : arr)
    {
        node->next = new ListNode(l);
        node = node->next;
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

    //mergeTwoLists(t1, t2);
    getchar();
    return 0;
}


