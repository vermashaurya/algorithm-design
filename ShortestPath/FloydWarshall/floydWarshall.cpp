#include <iostream>
#include <vector>
using namespace std;
const int INF = 1e9;
void floydWarshall(vector<vector<int> >& graph, int n) {
    vector<vector<int> > dist = graph;
    for(int k = 0; k < n; ++k) {
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            if(dist[i][j] == INF) {
                cout<<"INF ";
            }
            else {
                cout<<" "<<dist[i][j]<<"  ";
            }
        }
        cout<<endl;
    }
}
int main() {
    int n,m;
    cout<<"Enter the vertices(n): ";
    cin>>n;
    cout<<"Enter the edges(m): ";
    cin>>m;
    
    vector<vector<int> > graph(n,vector<int>(n,INF));
    cout<<"Enter the edges and the weights: \n";
    for(int i = 0; i < m; ++i) {
        int u,v,weight;
        cin>>u>>v>>weight;
        graph[u][v] = weight;
    }
    floydWarshall(graph,n);
    return 0;
}
