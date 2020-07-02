#include <bits/stdc++.h>

using namespace std;
typedef pair <int, int> pii;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int vertice, edge;
    cin >> vertice >> edge;
    vector < vector <pii> > graph(vertice+1);

    //taking graph values
    for(int i=0; i<edge; i++){
        int from, to, weight;
        cin >> from >> to >> weight;

        graph[from].push_back(pii(weight, to));
        graph[to].push_back(pii(weight, from));
    }
    int source;
    cin >> source;

    //Dijkstra
    vector <int> weightGraph(vertice+1, 999999);//initializing with big value
    weightGraph[source]=0;//initializing source with zero
    vector <bool> processed(vertice+1);
    priority_queue <pii, vector<pii>, greater<pii> > queueGraph;
    queueGraph.push(pii(weightGraph[source], source));//putting source at queue

    while(!queueGraph.empty()){
        int dad = queueGraph.top().second;
        queueGraph.pop();
        processed[dad]=true;

        for(auto son : graph[dad]){//visiting all adjacent node
            int weight = son.first;
            int node = son.second;

            if(weightGraph[node] > weightGraph[dad]+weight){
                weightGraph[node] = weightGraph[dad]+weight;//swap to least weigth

                if(!processed[node]){
                    queueGraph.push(pii(weightGraph[node], node));
                }
            }
        }
    }

    //showing least i-th graph weight
    for(auto dist : weightGraph){
        cout << dist << " ";
    }cout << endl;

    return 0;
}