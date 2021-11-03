#include <bits/stdc++.h>
#include <iostream>
using namespace std;



void dfs(int node,int parent,vector<int> &visited,vector<int> &discovery_time,vector<int> &lower_time,int &timer,vector<int> adj[])
{
    visited[node]=1;
    discovery_time[node]=lower_time[node]=timer++;

    for (auto it: adj[node])
    {
        /* code */

        if(it==parent)
            continue;
        if(!visited[it])
        {
            dfs(it,node,visited,discovery_time,lower_time,timer,adj);
            lower_time[node]=min(lower_time[node],lower_time[it]);
            if (lower_time[it]>discovery_time[node])
            {
                /* code */
                cout<<node<<" "<<it<<endl;
            }
        }else
        {
            // dfs backtrack krte time
            lower_time[node] = min(lower_time[node],discovery_time[it]);
        }
    }
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

    vector<int> discovery_time(n+1,-1);
    vector<int> lower_time(n+1,-1);
    vector<int> visited(n+1,0);

    int timer=0;
    for (int i = 1; i <= n; i++)
    {
        /* code */
        if(!visited[i])
        {
            dfs(i,-1,visited,discovery_time,lower_time,timer,adj);
        }
    }

   

return 0;
}

