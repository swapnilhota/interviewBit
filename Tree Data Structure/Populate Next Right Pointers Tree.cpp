/*
Given a binary tree

    struct TreeLinkNode {
      TreeLinkNode *left;
      TreeLinkNode *right;
      TreeLinkNode *next;
    }
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Note:

You may only use constant extra space.
Example :

Given the following binary tree,

         1
       /  \
      2    3
     / \  / \
    4  5  6  7
After calling your function, the tree should look like:

         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \  / \
    4->5->6->7 -> NULL
Note 1:  that using recursion has memory overhead and does not qualify for constant space.

Note 2: The tree need not be a perfect binary tree.
*/

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
void Solution::connect(TreeLinkNode* A) {

    queue<pair<TreeLinkNode*, int>> q;
    pair<TreeLinkNode*, int> prev={NULL, 0};
    q.push({A, 0});
    while(!q.empty())
    {
        auto curr_pair = q.front();
        q.pop();

        TreeLinkNode* curr_node = curr_pair.first;
        int curr_lvl = curr_pair.second;

        if(curr_node->left)
        {
            q.push({curr_node->left, curr_lvl+1});
        }
        if(curr_node->right)
        {
            q.push({curr_node->right, curr_lvl+1});
        }
        if((prev.first)==NULL)
        {
            prev={curr_node, curr_lvl};
            continue;
        }
        else
        {
            if(curr_lvl==(prev.second))
            {
                (prev.first)->next = curr_node;
            }
            prev = {curr_node, curr_lvl};
        }
    }

}
