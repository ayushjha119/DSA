#include <bits/stdc++.h>
using namespace std;


void dfs(int node,vector<int> &visited,vector<int> adj[],vector<int> &dfs_array)
{
    dfs_array.push_back(node);
    visited[node]=1;

    for(auto it: adj[node])
    {
        if(!visited[it])
        {
            dfs(it,visited,adj,dfs_array);
        }
    }
}

vector<int> dfs_of_graph(int v,vector<int> adj[],vector<int> &dfs_array)
{
    vector<int> visited(v+1,0);

    for (int i = 1; i <=v; i++)
    {
        /* code */
        if(!visited[i])
        {

            dfs(i,visited,adj,dfs_array);
        }
    }

    return dfs_array;
}

int main(){
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n,m;
    cin>>n>>m;


    vector<int> adj[n+1];

    for (int i = 0; i < m; i++)
    {
        /* code */
        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> dfs_array;

    dfs_of_graph(n,adj,dfs_array);

    for (int i = 0; i < dfs_array.size(); ++i)
    {
        /* code */
        cout<<dfs_array[i]<<" ";
    }


   
return 0;
}

