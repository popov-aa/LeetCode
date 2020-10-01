// https://leetcode.com/problems/add-two-numbers/

#include <iostream>

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return _addTwoNumbers(l1, l2, 0);
    }

    ListNode* _addTwoNumbers(ListNode* l1, ListNode* l2, int residual) {
        ListNode * l = new ListNode(residual);
        if (l1 != nullptr) {
            l->val += l1->val;
        }
        if (l2 != nullptr) {
            l->val += l2->val;
        }
        int _residual = 0;
        if (l->val > 9) {
            _residual = l->val / 10;
            l->val %= 10;
        }
        ListNode* l1Next = nullptr;
        if (l1) {
            l1Next = l1->next;
        }
        ListNode* l2Next = nullptr;
        if (l2) {
            l2Next = l2->next;
        }
        if (l1Next != nullptr || l2Next != nullptr || _residual != 0) {
            l->next = _addTwoNumbers(l1Next, l2Next, _residual);
        }
        return l;
    }
};

int main() {
    ListNode *l1 = new ListNode(2, new ListNode(4, new ListNode(3)));
    ListNode *l2 = new ListNode(5, new ListNode(6, new ListNode(4)));
    Solution s;
    ListNode * result = s.addTwoNumbers(l1, l2);
    while (result != nullptr) {
        std::cout << result->val << " ";
        result = result->next;
    }
    std::cout << std::endl;
}