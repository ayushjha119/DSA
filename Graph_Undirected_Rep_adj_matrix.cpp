


/* 

1--------2
|`      | \
| `     |  \
|  `    |   4            
|   `   |  /
|     ` | /
5------ 3


Graph representation 
agar undirected graph toh sbse simple hai adjacency matrix mai rep krna.
adj[u][v]=1
adj[v][u]=1

trust me yrr itna simple hai ki es sey jyda kch simple ho hi nhi skta hai
itna v hard nhi hai graph.





*/




#include <bits/stdc++.h>
#include <iostream>
using namespace std;



int main(){
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n,m; 
    cin>>n>>m;

    
        //kya kiye kch kiye hai 2 number input liye user sey bass
    // n = kitna nodes hai total , m = kitna edge hai total




    // ek adj naam ka 2d matrix declare krte hai thik hai.
    // qki adjacency matrix hai toh store krne ke liye kch toh chahiye

    int adj[n+1][n+1]={0};

    // ab edge input lenge user sey edge kaha kaha hai
    // toh maan lo m edge hai
    //user ko pta hoga kitna edge hai hmko kya pta

    for (int i = 0; i < m; i++)
    {
        /* code */
        int u , v;
         // bhai mere, simple variable hai declaration hai
        // kis two nodes hai bich edge hai ye user sey input lene ke liye

        cin>>u>>v;

        adj[u][v]=1;
        adj[v][u]=1;

        /*ho gya bass bass kthm adjacency matrix mai yehi two lines hai bass
        phle bole the */


    }


    //output kra lete hai 

    for (int i = 1; i < n+1 ; i++)
    {
       
        for (int j = 1; j < n+1 ; j++)
        {
            /* code */

            cout<<adj[i][j]<<" "; 
        }
        cout<<endl;
    }


   // aa gya naa diagonal ke along symmetric 

return 0;
}

