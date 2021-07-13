/*
Given an undirected tree with an even number of nodes. Consider each connection between a parent and child node to be an edge.

You need to remove maximum number of these edges, such that the disconnected subtrees that remain each have an even number of nodes.

Return the maximum number of edges you can remove.
*/

int DFS(map<int, vector<int>> &mp, int curr_node, map<int, int> &node_cnt, vector<bool> &visited)
{
    visited[curr_node]=true;
    int cnt=0;
    for(auto child: mp[curr_node])
    {
        if(visited[child])
        {
            continue;
        }
        cnt += DFS(mp, child, node_cnt, visited);
    }
    node_cnt[curr_node]+=cnt;
    return node_cnt[curr_node];
}

int Solution::solve(int A, vector<vector<int> > &B) {

    if(A<=2)
    {
        return 0;
    }

    map<int, vector<int>> mp;
    map<int, int> node_cnt;

    for(int i=0; i<A-1; i++)
    {
        mp[B[i][0]].push_back(B[i][1]);
    }

    for(int i=1; i<=A; i++)
    {
        node_cnt[i]=1;
    }

    vector<bool> visited(A+1, false);

    DFS(mp, 1, node_cnt, visited);

    int ans=0;

    for(int i=1; i<=A; i++)
    {
        //cout<<"node-> "<<i<<endl;
        vector<int> childs = mp[i];
        if(childs.size()==0)
        {
            continue;
        }
        for(auto child: childs)
        {
            if(node_cnt[child]%2==0)
            {
                ans++;
            }
        }
    }

    return ans;

}
