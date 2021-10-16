/*
Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

A height balanced BST : a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Example :


Given A : 1 -> 2 -> 3
A height balanced BST  :

      2
    /   \
   1     3
*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

void helper(vector<int> &v, int left, int right, TreeNode* &root)
{
    if(left>right)
    {
        return;
    }

    int mid = (right-left)/2+left;

    root = new TreeNode(v[mid]);

    helper(v, left, mid-1, root->left);
    helper(v, mid+1, right, root->right);
}

TreeNode* Solution::sortedListToBST(ListNode* A) {
    vector<int> v;
    ListNode* temp = A;
    while(temp)
    {
        v.push_back(temp->val);
        temp=temp->next;
    }

    int n = v.size();

    int left = 0;
    int right = n-1;

    TreeNode* root = NULL;

    helper(v, left, right, root);

    return root;
}
