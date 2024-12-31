#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* sortList1(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }

        int zeroCount = 0;
        int oneCount = 0;
        int twoCount = 0;

        ListNode* temp = head;
        while(temp != NULL){
            if(temp -> val == 0){
                zeroCount++;
            } else if(temp -> val == 1){
                oneCount++;
            } else {
                twoCount++;
            }

            temp = temp -> next;
        }

        temp = head;
        while(temp != NULL){
            if(zeroCount != 0){
                temp -> val = 0;
                zeroCount--;
            } else if(oneCount != 0){
                temp -> val = 1;
                oneCount--;
            } else if(twoCount != 0){
                temp -> val = 2;
                twoCount--;
            }

            temp = temp -> next;
        }

        return head;
    }

    //Now data replacement is not allowed......
    
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
    ListNode* sortList2(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        // Split the list into two halves
        ListNode* middle = getMiddle(head);
        ListNode* left = head;
        ListNode* right = middle->next;
        middle->next = nullptr;

        // Recursively sort the left and right halves
        left = sortList2(left);
        right = sortList2(right);

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
    // Create an unsorted linked list: 2 -> 2 -> 1 -> 2 -> 0 -> 1
    ListNode* head = new ListNode(2);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(0);
    head->next->next->next->next->next = new ListNode(1);

    cout << "Original list : ";
    printList(head);

    //using function 1
    Solution solution;
    head = solution.sortList1(head);

    cout << "List after sorting 0's 1's and 2's is : ";
    printList(head);

    //using function 2
    head = solution.sortList2(head);

    cout << "List after sorting 0's 1's and 2's is : ";
    printList(head);

    // Clean up memory
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}