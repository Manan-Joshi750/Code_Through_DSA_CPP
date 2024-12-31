#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    // Helper function to merge two sorted lists
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);  // Dummy node to start the merged list
        ListNode* tail = &dummy;

        while (l1 && l2) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }

        // Append the remaining nodes of l1 or l2
        if (l1) tail->next = l1;
        else tail->next = l2;

        return dummy.next;
    }

    // Helper function to find the middle of the linked list
    ListNode* getMiddle(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    // Main function to sort the linked list
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        // Split the list into two halves
        ListNode* middle = getMiddle(head);
        ListNode* left = head;
        ListNode* right = middle->next;
        middle->next = nullptr;

        // Recursively sort the left and right halves
        left = sortList(left);
        right = sortList(right);

        // Merge the sorted halves
        return merge(left, right);
    }
};

// Helper function to print the linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Create an unsorted linked list: 2 -> 3 -> 1 -> 4 -> 0 -> 5
    ListNode* head = new ListNode(2);
    head->next = new ListNode(3);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(0);
    head->next->next->next->next->next = new ListNode(5);

    cout << "Original list : ";
    printList(head);

    Solution solution;
    head = solution.sortList(head);

    cout << "List after sorting : ";
    printList(head);

    // Clean up memory
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}