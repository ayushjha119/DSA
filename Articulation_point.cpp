#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void dfs(int node,int parent,vector<int>&visited,vector<int>&discovery_time,vector<int> &lower_time,int &timer,vector<int> adj[],vector<int> &isArticulation)
{

/*main function sey node bheje 1st aur  uska parent -1
     aate hi visited array mai us node position ko 1 kiye
     aur discovery aur low time ko timer++ ke initialize kiye
     ek child variable liye 0 sey initialize 
    individual child seperate dfs call pta lagane ke kaam aayega
    */


    visited[node]=1;
    discovery_time[node]=lower_time[node]=timer++;
    int child=0;

/*harr node ke adjacent pe jaoo niche garph pe dekho maan lo 1 sey 2 pe gye
     2 sey 3 gaye aur 3 sey 4 , mtlb dfs aise chala
    toh 4th ke pass 3 option hai , 3 type ka node hua
     3 sey 4 pe aaye toh 3 parent hua toh simple 3 ko ignore kro 
    i.e if it == parent coninue wala case
     ab maan lo 4 sey 5 gye toh 5 visited nhi hai toh simple dfs call kiye
     ab 5 pe aur 5 sey 6 pe 6 pr dfs kthm aur toh dfs ke just niche wla code 
     excute hoga ab*/
    

    /*
                1-------2
                |       |
                |       |
                4_______3
                |
                |
                |
                5-------6

    */

    for(auto it: adj[node])
    {
        if(it==parent) continue;
        if(!visited[it])
        {
            dfs(it,node,visited,discovery_time,lower_time,timer,adj,isArticulation);
            lower_time[node]=min(lower_time[node],lower_time[it]);
            child++;
            /*
            dfs ke niche wala code bolta hai uppar tum lower time aur discovery time
            ko timer++ krte hue aaye hai toh lower time of node kch hoga lekin
            usko update  kro
            lower_time[node]=min(lower_time[node],lower_time[it]);
            */

            if(lower_time[it]>=discovery_time[node] && parent != -1)
            {
                isArticulation[node]=1;
            }
        }
        else{

                lower_time[node]=min(lower_time[node],discovery_time[it]);

            }


    }
            if(parent==-1 && child>1)
            {
                isArticulation[node]=1;
            }
}



int main(){
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

   
   int n,m;
   cin>>n>>m;//no of nodes of edge input le liye
   vector<int> adj[n+1];//adjacency list  banaye 
   //vector banaye jismey harr block m size ke array ko point kr rha

   for (int i = 0; i < m; i++)
   {
       /* code */
    // undirected graph esliye adj u to v and adj v to u kr rhe
    //aur graph ka input le rhe u to v mtlb kis 2 node ke bich mai edge hai


    int u,v;
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
   }
   //n+1 size esliye qki adj[n+1] hai mtlb 1 based indexing kiye hai
   //agar 0 based indexing kiye hote toh n+1 size ka nahi n size ka initialize krte



   vector<int> discovery_time(n+1,-1);
   // n+1 size ka vector banaye jisko -1 sey initialize kiye
   // ye vector batayega kon sa node kb discover hua
   vector<int> lower_time(n+1,-1);
   //n+1 size ka vector banaye jisko -1 sey initialize kiye
   //ye vector batayega given node ka lowerest time of discovey
   vector<int> visited(n+1,0);
   //n+1 size ka vector banaye jisko 0 sey initialize kiye 
   // dfs call krne ke kaam aayega node visited hai ya nhi
   vector<int> isArticulation(n+1,0);
   // n+1 size ka vector banye jisko 0 sey initialize kiye
   // ye repeated count sey bachaega
   // mtlb maar lo node 8 artiluation point hai
   // toh agar dubara kahi sey pta chala node 8 articulation point hai usko
   // 2 baaar count naa kr le, esmay ye help krega


   int timer=0;

   for (int i = 1; i <= n; i++)
   {
       // simple harr node pe jake dfs call agar wo visited nhi hai toh
    if(!visited[i])
    {
    dfs(i,-1,visited,discovery_time,lower_time,timer,adj,isArticulation);

    }
   }

   for (int i = 0; i <n; i++)
   {
       /* code */
    if (isArticulation[i]==1)
    {
        /* code */
        cout<<i<<endl;
    }
   }

return 0;
}

