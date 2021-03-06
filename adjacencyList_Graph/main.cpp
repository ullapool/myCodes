#include <iostream>
#include <vector>
#include <queue> // BFS: BFS kann mit zirkulären Graphen umgehen.
#include <stack> // DFS: DFS hingegen nicht, darum muss einen die besuchten nodes geflagged werden
#include <set>

using namespace std;

int compare(const vector<vector<int>> &graph, int start, int end) {
    queue<int> q;
    q.push(start);
    int counterQueue = 0;
    int counterStack = 0;

    while(!q.empty()) {
        int node = q.front();
        if(node == end) {break;}
            q.pop();
        for(int edge : graph[node]) {
            q.push(edge);
        }
        counterQueue++;
    }

    stack<int> s;
    set<int> grassedNodes;
    s.push(start);
    while(!s.empty()) {
       int node = s.top();
       if(node == end) {break;}
          s.pop();
       grassedNodes.insert(node);
       for(int i = graph[node].size() -1; i >= 0; i-- ) {
           if(grassedNodes.find(graph[node][i]) == grassedNodes.end()) { //find gives back iterator if not found == end = false
              s.push(graph[node][i]);
           }
       }

       counterStack++;
       cout << "nodeS: "<< node <<" counter: " << counterStack << endl;
    }

    cout << "BFS: " <<counterQueue << endl;
    cout << "DFS: " <<counterStack << endl;

    if(counterQueue < counterStack) {
        return 1;
    }
    else if (counterQueue > counterStack){
        return 2;

    }
    else {
        return 3;
    }

}

int main()
{
    vector<vector<int>> graph({
       {1, 3},
       {0, 3},
       {0, 1},
       {0, 1, 2}
    });

    int result = compare(graph, 0, 2);
    cout << result << endl;

    return 0;
}
