/*
Problem Description

Given a Binary Tree A consisting of N nodes.

You need to find all the cousins of node B.

NOTE:

Siblings should not be considered as cousins.
Try to do it in single traversal.
You can assume that Node B is there in the tree A.
Order doesn't matter in the output.


Problem Constraints
 1 <= N <= 105 

 1 <= B <= N



Input Format
First Argument represents the root of binary tree A.

Second Argument is an integer B denoting the node number.



Output Format
Return an integer array denoting the cousins of node B.

NOTE: Order doesn't matter.



Example Input
Input 1:

 A =

           1
         /   \
        2     3
       / \   / \
      4   5 6   7 


B = 5

Input 2:

 A = 
            1
          /   \
         2     3
        / \ .   \
       4   5 .   6


B = 1




Example Output
Output 1:

 [6, 7]
Output 2:

 []
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
struct Node
{
    int val;
    TreeNode* parent;
};

void helper(TreeNode* node, int B, TreeNode* parent, map<int, vector<Node>> &mp, int lvl, int &level, TreeNode* &B_parent)
{
    if(node==NULL)
    {
        return;
    }
    Node tmp;
    tmp.val = node->val;
    tmp.parent = parent;
    mp[lvl].push_back(tmp);
    if(node->val == B)
    {
        level = lvl;
        B_parent = parent;
    }
    helper(node->left, B, node, mp, lvl+1, level, B_parent);
    helper(node->right, B, node, mp, lvl+1, level, B_parent);
}

vector<int> Solution::solve(TreeNode* A, int B) {

    map<int, vector<Node>> mp;
    int level=0;
    TreeNode* B_parent=NULL;

    helper(A, B, NULL, mp, 0, level, B_parent);

    vector<int> ans;

    if(B_parent==NULL)
    {
        return ans;
    }

    for(auto node: mp[level])
    {
        if(node.parent!=B_parent)
        {
            ans.push_back(node.val);
        }
    }

    return ans;

}
