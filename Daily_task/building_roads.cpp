#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100005];
bool visited[100005];

void dfs(int node){
    visited[node] = true;
    
    for(int neigh : adj[node]){
        if(!visited[neigh]){
            dfs(neigh);
        }
    }
}

int main(){
    
    int n, m;
    cin >> n >> m;
    
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    vector<int> reps;
    
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            reps.push_back(i);
            dfs(i);
        }
    }
    
    cout << reps.size()-1 << endl;
    
    for(int i=1;i<reps.size();i++){
        cout << reps[i-1] << " " << reps[i] << endl;
    }
}
