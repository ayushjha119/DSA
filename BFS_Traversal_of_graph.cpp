#include <bits/stdc++.h>
using namespace std;

vector<int> bfs_of_graph(int v,vector<int> adj[],vector<int> &bfs)
{
queue<int> q;
vector<int> visited(v+1,0);

    /* code */
 for (int i = 1; i<=v; i++)
 {
     /* code */

    // Time complexity O(N+E)
    // for loop ke ander while uske ander for loop but phir v O(N+E)
    // qki harr node pe call nhi ho rha phle check kr rhe visited hai ya nhi
    if(!visited[i]){
 
        
        q.push(i);
        visited[i]=1;

        while(!q.empty()){
            int node=q.front();
            q.pop();
            bfs.push_back(node);


            for(auto it: adj[node])
            {
                if(!visited[it])
                {
                    q.push(it);
                    visited[it]=1;
                }
            }
        }
    }

    }

        return bfs;


    

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
    vector<int> bfs;

bfs_of_graph(n,adj,bfs);

 for (int i = 0; i < bfs.size(); ++i)
 {
     /* code */
    cout<<bfs[i]<<" ";
 }

   
return 0;
}

