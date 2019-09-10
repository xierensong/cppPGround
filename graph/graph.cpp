#include<bits/stdc++.h>

using namespace std;

void DFS(unordered_map<string,unordered_map<string,double>> my_graph, string root, unordered_set<string> &visited, vector<string> &res) 
{
    res.push_back(root);
    visited.insert(root);
    for(auto my_pair : my_graph[root]) {
        string node=my_pair.first;
        if(!visited.count(node)) {
            DFS(my_graph, node, visited, res);
        }
    }

}

void DFSTraverse(unordered_map<string,unordered_map<string,double>> my_graph) 
{
    vector<string> res;
    unordered_set<string> visited;
    for(auto my_pair : my_graph) {
        string node=my_pair.first;
        if(!visited.count(node)) {
            DFS(my_graph, node, visited, res);
        }
    }
    for(auto a : res) {
        cout << a << " ";
    }
    cout << endl;
}

void BFSTraverse(unordered_map<string, unordered_map<string, double>> my_graph)
{
    vector<string> res;
    unordered_set<string> visited;
    queue<string> my_queue;
    for(auto my_pair : my_graph) {
        string node = my_pair.first;
        if (!visited.count(node)) {
            visited.insert(node);
            res.push_back(node);
            my_queue.push(node);
            while(!my_queue.empty()) {
                node = my_queue.front();
                my_queue.pop();
                for(auto adjent_pair : my_graph[node]) {
                    string adjacent_node = adjent_pair.first;
                    if(!visited.count(adjacent_node)) {
                        visited.insert(adjacent_node);
                        res.push_back(adjacent_node);
                        my_queue.push(adjacent_node);
                    }    
                }
            }
        }
    }
    for(auto a : res) {
        cout << a << ' ';
    }
    cout << endl;
}

int main()
{
    unordered_map<string, unordered_map<string, double>> my_graph;
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
    BFSTraverse(my_graph);
}