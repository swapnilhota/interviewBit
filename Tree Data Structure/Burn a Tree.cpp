/*
Problem Description

Given a binary tree denoted by root node A and a leaf node B from this tree.

 It is known that all nodes connected to a given node (left child, right child and parent) get burned in 1 second. Then all the nodes which are connected through one intermediate get burned in 2 seconds, and so on.

You need to find the minimum time required to burn the complete binary tree.



Problem Constraints
2 <= number of nodes <= 105

1 <= node value, B <= 105

node value will be distinct



Input Format
First argument is a root node of the binary tree, A.

Second argument is an integer B denoting the node value of leaf node.



Output Format
Return an integer denoting the minimum time required to burn the complete binary tree.



Example Input
Input 1:

 Tree :      1 
            / \ 
           2   3 
          /   / \
         4   5   6
 B = 4
Input 2:

 Tree :      1
            / \
           2   3
          /     \
         4       5 
 B = 5 

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
int depth_below(TreeNode* A, int B, int d)
{
    if(A==NULL)
    {
        return 0;
    }
    if(A->val==B)
    {
        return d;
    }
    return max(depth_below(A->left, B, d+1), depth_below(A->right, B, d+1));
}

int depth(TreeNode* A)
{
    if(A==NULL)
    {
        return 0;
    }
    return 1 + max(depth(A->left), depth(A->right));
}

bool find(TreeNode* A, int B, int &t, int d)
{
    if(A==NULL)
    {
        return false;
    }
    if(A->val==B)
    {
        return true;
    }
    if(find(A->left, B, t, d-1))
    {
        t = max(depth(A->right)+d, t);
        return true;
    }
    else if(find(A->right, B, t, d-1))
    {
        t = max(depth(A->left)+d, t);
        return true;
    }

    return false;
}

int Solution::solve(TreeNode* A, int B) {

    int d = depth_below(A, B, 0);
    int t=0;
    find(A, B, t, d);
    return t;

}
