/*
Problem Description

Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.

Note: The test cases are generated in the following format (use the following format to use See Expected Output option):

First integer N is the number of nodes.

Then, N intgers follow denoting the label (or hash) of the N nodes.

Then, N2 integers following denoting the adjacency matrix of a graph, where Adj[i][j] = 1 denotes presence of an undirected edge between the ith and jth node, O otherwise.



Problem Constraints
1 <= Number of nodes <= 105



Input Format
First and only argument is a node A denoting the root of the undirected graph.



Output Format
Return the node denoting the root of the new clone graph.
*/

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
void clone(UndirectedGraphNode* &newNode, UndirectedGraphNode* oldNode, map<int, UndirectedGraphNode*> &mp)
{
    newNode = new UndirectedGraphNode(oldNode->label);
    mp[newNode->label] = newNode;

    for(auto next: oldNode->neighbors)
    {
        if(mp.find(next->label)==mp.end())
        {
            UndirectedGraphNode* newChild;
            clone(newChild, next, mp);
            newNode->neighbors.push_back(newChild);
        }
        else
        {
            newNode->neighbors.push_back(mp[next->label]);
        }
    }
}

UndirectedGraphNode *Solution::cloneGraph(UndirectedGraphNode *node) {
    UndirectedGraphNode* ans;
    map<int, UndirectedGraphNode*> mp;
    clone(ans, node, mp);
    return ans;
}
