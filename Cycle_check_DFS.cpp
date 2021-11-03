#include <bits/stdc++.h>
using namespace std;


cycle_check_dfs(int node,int parent,vector<int> adj[],vector<int> &visited)
{

    visited[node]=1;

    for(auto it: adj[node])
    {
        if(!visited[it])
        {
            if(cycle_check_dfs(it,node,adj,visited))
            {
                return true;
                break;
            }
            
        }
        else if(visited[it]==1 && parent!=it)
        {
            return true;
        }
    }
    return false;
}

bool is_cycle(int v,vector<int> adj[])
{
    vector<int> visited(v+1,0);

    for (int i = 1; i <=v; i++)
    {
        /* code */

        if(!visited[i])
        {
            if(cycle_check_dfs(i,v,adj,visited))
            {
                return true;
                break;
            }
        }
    }

    return false;
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
    
if(is_cycle(n,adj))
{
    cout<<"True";
}else
{
    cout<<"false";
}


   
return 0;
}

