#include<bits/stdc++.h>

using namespace std;

void DFS(unordered_map<string, unordered_map<string, int>> graph, string root, 
         unordered_set<string> &visited, vector<string> &results)
{
    visited.insert(root);
    results.push_back(root);
    for(auto my_pair : graph[root]) {
        string node = my_pair.first;
        if(!visited.count(node)) {
            DFS(graph, node, visited, results);
        }
    }
}

void DFSTraverse(unordered_map<string, unordered_map<string, int>> graph)
{
    vector<string> results;
    unordered_set<string> visited;
    for(auto my_pair : graph) {
        string node=my_pair.first;
        if(!visited.count(node)) {
            DFS(graph, node, visited, results);
        }
    }
    for(auto result : results) {
        cout << result << ' ';
    }
    cout << endl;
}

int main()
{
    unordered_map<string, unordered_map<string, int>> my_graph;
    my_graph["v1"]["v3"]=3;    my_graph["v1"]["v2"]=5;
    my_graph["v2"]["v4"]=4;    my_graph["v2"]["v5"]=5;
    my_graph["v5"]["v8"]=1;    my_graph["v4"]["v8"]=2;
    my_graph["v3"]["v6"]=2;    my_graph["v3"]["v7"]=1;
    my_graph["v6"]["v7"]=3;    my_graph["v3"]["v1"]=3;
    my_graph["v2"]["v1"]=5;    my_graph["v4"]["v2"]=4;
    my_graph["v5"]["v2"]=5;    my_graph["v8"]["v5"]=1;
    my_graph["v8"]["v4"]=2;    my_graph["v6"]["v3"]=2;
    my_graph["v7"]["v3"]=1;    my_graph["v7"]["v6"]=3;
    DFSTraverse(my_graph);
}