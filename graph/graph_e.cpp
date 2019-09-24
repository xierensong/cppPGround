#include <bits/stdc++.h>

using namespace std;

void BFS(unordered_map<string, unordered_map<string, double>> my_graph, string start, unordered_set<string> &visited, vector<string> &results)
{
    results.push_back(start);//后操作
    visited.insert(start);
    for(auto adj_pair:my_graph[start]) {
        string adj_node=adj_pair.first;
        if(!visited.count(adj_node)) {
            BFS(my_graph, adj_node, visited, results);
        }
    }
}

void BFSTraverse(unordered_map<string, unordered_map<string, double>> my_graph, vector<string> &results)
{
    unordered_set<string> visited;
    for(auto my_pair : my_graph) {
        string node = my_pair.first;
        if(!visited.count(node)) {  //先判断
            BFS(my_graph, node, visited, results);
        }
    }
}

void DFSTraverse(unordered_map<string, unordered_map<string,double>> my_graph, vector<string> &results)
{
    unordered_set<string> visited;
    queue<string> my_queue;
    for(auto my_pair : my_graph) {
        string node = my_pair.first;
        if(!visited.count(node)) {
            visited.insert(node);
            results.push_back(node);
            my_queue.push(node);
            while(!my_queue.empty()) {  //遍历子图
                cout << "we" << endl;
                string curr_node = my_queue.front();
                my_queue.pop();            
                for(auto adj_pair : my_graph[curr_node]) {
                    string adj_node = adj_pair.first;
                    if(!visited.count(adj_node)) {
                        visited.insert(adj_node);
                        results.push_back(adj_node);
                        my_queue.push(adj_node);
                    }
                }
            }
        }
    }
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
    vector<string> results;
    BFSTraverse(my_graph,results);
    for(auto result:results) {
        cout << result << ' ';
    }
    cout << endl;
    vector<string> dfs_results;
    DFSTraverse(my_graph, dfs_results);
    for(auto dfs_result:dfs_results) {
        cout << dfs_result << ' ';
    }
    cout << endl;
    return 0;

}