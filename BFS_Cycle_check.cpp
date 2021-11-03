#include <bits/stdc++.h>
using namespace std;

bool cycle_check_bfs(int s,int v,vector<int> adj[],vector<int> &visited)
{
    queue<pair<int,int>> q;

    visited[s]=1;
    q.push({s,-1});

    while(!q.empty())
        {
            int node=q.front().first;
            int par = q.front().second;

            q.pop();

          for(auto it: adj[node])
          {
            if(!visited[it])
            {
                visited[it]=1;
                q.push({it,node});
            }
 // dekho hm intension tha ki koi aisa node jo adjacent aur phle sey visited ho
//toh cycle ho skta hai but ek twist hai
// jo parent node nikal rhe q.front.second krke
// toh parent node humesa adjacent hoga
// aur visited v, but uske wajh sey cycle thori banega
// esliye condition ye hoga ki koi aisa adjacent node it 
// jo phle sey visited ho aur wo it parent nhi ho node ka toh cycle hai
            // aise v likh skte else if(visited[i]==1 && it != par)

            else if(par != it)
            {
                return true;
            }
          }

          

        }

        return false;
}


bool is_cycle(int v,vector<int> adj[])
{
    vector<int> visited(v+1,0);
//disconnected graph ho skta input esliye aisa kr rhe
    for (int i = 1; i<=v; i++)
    {
        /* code */
        if(!visited[i])
        {
            
            if(cycle_check_bfs(i,v,adj,visited))
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
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;


   
return 0;
}

