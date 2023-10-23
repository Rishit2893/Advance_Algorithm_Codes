#include <bits/stdc++.h>

using namespace std;
const int n=6;

bool bfs(int rg[n][n],int s,int t,int parent[n]){
    int visited[n];
    for(int i=0;i<n;i++){
        visited[i]=0;
    }
    queue<int> q;
    q.push(s);
    visited[s]=1;
    parent[s]=-1;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int v=0;v<n;v++){
            if(visited[v]==0 && rg[u][v]>0){
                if(v==t){
                    parent[v]=u;
                    return true;
                }
                q.push(v);
                visited[v]=1;
                parent[v]=u;
            }
        }
    }
    return false;
    
}

int fordfulkerson(int g[n][n], int s,int t){
    int rg[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            rg[i][j]=g[i][j];
        }
    }
    int parent[n], max_flow=0;
    while(bfs(rg,s,t,parent)){
        int path_flow=1000;
        for(int v=t;v!=s;v=parent[v]){
            int u=parent[v];
            path_flow=min(path_flow,rg[u][v]);
        }
        for(int v=t;v!=s;v=parent[v]){
            int u= parent[v];
            rg[u][v]-=path_flow;
            rg[v][u]+=path_flow;
        }
        max_flow+=path_flow;
    }
    return max_flow;
}

int main()
{
    int g[n][n]={
        { 0, 16, 13, 0, 0, 0},
        { 0, 0, 10, 12,0, 0},
        { 0, 4, 0, 0, 14, 0},
        { 0, 0, 9, 0, 0, 20},
        { 0, 0, 0, 7, 0, 4},
        { 0, 0, 0, 0, 0, 0}
    };
    
    cout<<fordfulkerson(g, 0,5)<<endl;

    return 0;
}
