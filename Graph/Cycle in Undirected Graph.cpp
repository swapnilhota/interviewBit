/*
Given an undirected graph having A nodes labelled from 1 to A with M edges given in a form of matrix B of size M x 2 where (B[i][0], B[i][1]) represents two nodes B[i][0] and B[i][1] connected by an edge.

Find whether the graph contains a cycle or not, return 1 if cycle is present else return 0.

NOTE:

The cycle must contain atleast three nodes.
There are no self-loops in the graph.
There are no multiple edges between two nodes.
The graph may or may not be connected.
Nodes are numbered from 1 to A.
Your solution will run on multiple test cases. If you are using global variables make sure to clear them.


Problem Constraints
1 <= A, M <= 3105

1 <= B[i][0], B[i][1] <= A



Input Format
The first argument given is an integer A representing the number of nodes in the graph.

The second argument given is an matrix B of size M x 2 which represents the M edges such that there is a edge between node B[i][0] and node B[i][1].



Output Format
Return 1 if cycle is present else return 0.
*/

void dfs(map<int, vector<int>> &adj, int curr, int prev, vector<bool> &visited, int &ans)
{
    visited[curr]=true;
    for(auto next: adj[curr])
    {
        if(visited[next] && next!=prev)
        {
            ans=1;
            return;
        }
        if(!visited[next])
        {
            dfs(adj, next, curr, visited, ans);
        }        
    }
    visited[curr]=false;
}

int Solution::solve(int A, vector<vector<int> > &B) {
    map<int, vector<int>> adj;
    for(auto e: B)
    {
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }

    int ans=0;
    vector<bool> visited(A+1, false);
    for(int i=1; i<=A; i++)
    {
        if(!visited[i])
        {
            for(auto next: adj[i])
            {
                dfs(adj, next, i, visited, ans);
            }
        }
    }
    return ans;
}
