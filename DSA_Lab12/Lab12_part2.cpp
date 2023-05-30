#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

#define INF INT_MAX 

struct Vertex {
    int ind;
    int Time;

    Vertex(int i, int d) : ind(i), Time(d) {}
};

struct CompareVertex {
    bool operator()(const Vertex& v1, const Vertex& v2) {
        return v1.Time > v2.Time;
    }
};

void dijkstraShortest(std::vector<std::vector<int>>& graph, int source) {
    int V = graph.size(); 
    std::vector<int> Time(V, INF); 
    std::vector<bool> visited(V, false); 

    Time[source] = 0; 

    std::priority_queue<Vertex, std::vector<Vertex>, CompareVertex> pq;
    pq.push(Vertex(source, 0));

    while (pq.empty() == 0) {
        int u = pq.top().ind;
        pq.pop();

        if (visited[u])
            continue;

        visited[u] = true;

        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] != INF &&
                Time[u] + graph[u][v] < Time[v]) {
                Time[v] = Time[u] + graph[u][v];
                pq.push(Vertex(v, Time[v]));
            }
        }
    }

    int total=0;
    std::cout << "Shortest time from the Source:\n";
    
    for (int v = 0; v < V; v++) {
        total+=Time[v];
        std::cout << "City " << v << ": " << Time[v] << "\n";
    }
    float average= total / 5.0;
    std::cout<< "Average  "<<average<< "\n";
    
}

int main() {
    std::vector<std::vector<int>> graph = {
        {0, 10,INF, INF,15,5},
        {10, 0,10, 30, INF, INF},
        {INF,10, 0, 12, 5, INF},
        {INF, 30, 12, 0, INF, 20},
        {15, INF, 5, INF, 0, INF},
        {5, INF, INF, 20, INF, 0}
    };

    int source;
    std::cout << "Enter the source city: ";
    std::cin >> source;

    dijkstraShortest(graph, source);

return 0;
}