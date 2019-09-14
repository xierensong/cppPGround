#include<bits/stdc++.h>

using namespace std;

void DFS(unordered_map<string, unordered_map<string,int>> graph, string start, vector<string> &results, unordered_set<string> &visited)
{
    visited.insert(start);
    results.push_back(start);
    for(auto my_pair:graph[start]) {
        string my_node=my_pair.first;
        if(!visited.count(my_pair.first)) {
            DFS(graph, my_node, results, visited);
        }
    }
}

void DFSTraverse(unordered_map<string,unordered_map<string, int>> my_graph)
{
    vector<string> results;
    unordered_set<string> visited;
    for(auto my_pair : my_graph) {
        string my_node=my_pair.first;
        if(!visited.count(my_node)) {
            DFS(my_graph, my_node, results, visited);
        }
    }
    for(auto result : results) {
        cout << result << ' ';
    }
    cout << endl;
}

void BFSTraverse(unordered_map<string, unordered_map<string, int>> graph)
{
    vector<string> results;
    unordered_set<string> visited;
    queue<string> my_queue;
    for(auto my_pair:graph) {
        string node=my_pair.first;
        if(!visited.count(node)) {  //未访问
            visited.insert(node);   //标记访问
            results.push_back(node);    //访问
            my_queue.push(node);    //加入队列
            while(!my_queue.empty()) {  //队列不空
                node=my_queue.front();  //取队首
                my_queue.pop();     //弹走队首
                for(auto adj_pair:graph[node]) {    //邻接点
                    string adj_node=adj_pair.first; 
                    if(!visited.count(adj_node)) {  //未访问
                        visited.insert(adj_node);   //标记访问
                        results.push_back(adj_node);    //访问
                        my_queue.push(adj_node);    //入队列
                    }
                }
            }
        }
    }
    for(auto result :results) {
        cout << result << ' ';
    }
    cout << endl;
}

int main()
{
    unordered_map<string, unordered_map<string,int>> my_graph;
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