#include <iostream>
#include <bits/stdc++.h>
#include <queue>
#include <cmath>
using namespace std;

#define pi (3.141592653589)
//#define int long long int
#define mod 1e9+7
#define float double
#define pb push_back
#define mp make_pair
#define min3(a,b,c) min(c,min(a,b))
#define min4(a,b,c,d) min(d,min(c,min(a,b)))



void bfs_short_path_unit_wt(vector<int> adj[],int N,int src)
{
    int dist[N];
    for (int i = 0; i < N; ++i)
    {
        /* code */
        dist[i]=INT_MAX;
    }

    queue <int> q;

    dist[src] =0;
    q.push(src);

    while(q.empty()==false)
    {
        int node = q.front();
        q.pop();

        for(auto it: adj[node]){
            if (dist[node]+1<dist[it])
            {
                /* code */
                dist[it]=dist[node] +1;
                q.push(it);
            }

        }
    }

    for (int i = 0; i < N; ++i)
    {
        /* code */
        cout<<dist[i]<<" ";
    }
}


int main(){
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif


    int n,m;
    cin>>n>>m;
    vector<int> adj[n];

    for (int i = 0; i < m; ++i)
    {
        /* code */

        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }

    bfs_short_path_unit_wt(adj,n,0);



return 0;
}

