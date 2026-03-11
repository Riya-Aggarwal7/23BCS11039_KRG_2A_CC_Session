#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100001];
bool visited[100001];

void dfs(int node){
    visited[node] = true;
    for(int nei : adj[node]){
        if(!visited[nei]){
            dfs(nei);
        }
    }
}

int main(){
    int n,m;
    cin>>n>>m;

    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> comp;

    for(int i=1;i<=n;i++){
        if(!visited[i]){
            comp.push_back(i);
            dfs(i);
        }
    }

    cout<<comp.size()-1<<endl;

    for(int i=1;i<comp.size();i++){
        cout<<comp[i-1]<<" "<<comp[i]<<endl;
    }
}
