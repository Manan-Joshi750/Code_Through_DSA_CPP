#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(NULL), right(NULL) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Definition for a linked list node.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    // Function to merge two BSTs
    TreeNode* mergeBSTs(TreeNode* root1, TreeNode* root2) {
        ListNode* head1 = bstToSortedLinkedList(root1);
        ListNode* head2 = bstToSortedLinkedList(root2);
        ListNode* mergedHead = mergeSortedLinkedLists(head1, head2);
        return sortedLinkedListToBST(mergedHead);
    }

private:
    // Function to convert BST to a sorted linked list
    ListNode* bstToSortedLinkedList(TreeNode* root) {
        if (!root) return NULL;

        ListNode* leftList = bstToSortedLinkedList(root->left);
        ListNode* currentNode = new ListNode(root->val);
        ListNode* rightList = bstToSortedLinkedList(root->right);

        // Merge left list, current node, and right list
        return mergeThreeLists(leftList, currentNode, rightList);
    }

    // Function to merge three parts into a single linked list
    ListNode* mergeThreeLists(ListNode* left, ListNode* middle, ListNode* right) {
        if (!left && !middle && !right) return NULL;

        ListNode* head = left;

        // If there is a left list, find its tail
        if (left) {
            while (left->next) {
                left = left->next;
            }
            left->next = middle; // Connect left list to middle node
        } else {
            head = middle; // No left list, head is the middle node
        }

        middle->next = right; // Connect middle node to right list
        return head;
    }

    // Function to merge two sorted linked lists
    ListNode* mergeSortedLinkedLists(ListNode* head1, ListNode* head2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (head1 && head2) {
            if (head1->val < head2->val) {
                tail->next = head1;
                head1 = head1->next;
            } else {
                tail->next = head2;
                head2 = head2->next;
            }
            tail = tail->next;
        }

        // Append remaining elements
        if (head1) tail->next = head1;
        if (head2) tail->next = head2;

        return dummy.next; // Return the merged linked list
    }

    // Function to convert sorted linked list to a balanced BST
    TreeNode* sortedLinkedListToBST(ListNode* head) {
        if (!head) return NULL;

        // Find the middle of the linked list
        ListNode* mid = findMiddle(head);
        TreeNode* root = new TreeNode(mid->val);

        if (head == mid) return root; // Only one element in the list

        // Recursively build the left and right subtrees
        root->left = sortedLinkedListToBST(head);
        root->right = sortedLinkedListToBST(mid->next);

        return root;
    }

    // Function to find the middle of the linked list
    ListNode* findMiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;

        // Move fast by two and slow by one
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};

// Helper function to print in-order traversal of the tree
void printInorder(TreeNode* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main() {
    // Example: Normal BST 1
    TreeNode* root1 = new TreeNode(3);
    root1->left = new TreeNode(1);
    root1->right = new TreeNode(5);

    // Example: Normal BST 2
    TreeNode* root2 = new TreeNode(4);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(6);

    Solution solution;
    TreeNode* mergedRoot = solution.mergeBSTs(root1, root2);

    // Print the in-order traversal of the merged BST
    cout << "In-order traversal of merged BST: ";
    printInorder(mergedRoot);
    cout << endl;

    return 0;
}