#include <bits/stdc++.h>
using namespace std;

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

    for (int i = 0; i <n+1; i++)
    {
        /* code */
        cout<<i;
        for (int j = 0; j < adj[i].size(); j++)
        {
            /* code */
            cout<<"->"<<adj[i][j];
        }
        cout<<endl;
    }

   
return 0;
}

