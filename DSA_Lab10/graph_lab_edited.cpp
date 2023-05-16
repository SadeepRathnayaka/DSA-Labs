#include <iostream>
#include <list>
using namespace std;

struct Node{
    int label;          
    list<int> neighbors; };

struct Graph{
    int n = 9;
    Node* nodes = new Node[n]; 

    void initializeNodes(){
        //iterate through the nodes and assign labels
        for(int i = 1; i < n; i++){
            nodes[i].label = i;        
    }
    }

    void addEdge(int u, int v){
        nodes[u].neighbors.push_back(v); 
         }

    void print(){
        for(int i = 1; i < n; i++){
            cout << "Node " << nodes[i].label << " connected with : ";
            for(auto neighbor : nodes[i].neighbors){
                cout << neighbor << " ";
            }
            cout << endl;}}};

int main() {
    Graph* g = new Graph;
    g->initializeNodes();
    
    // Add edges for the graph
    g->addEdge(1,2);
    g->addEdge(1,4);
    g->addEdge(1,3);
    g->addEdge(1,5);
    g->addEdge(2,3);
    g->addEdge(2,6);
    g->addEdge(4,6);
    g->addEdge(4,8);
    g->addEdge(4,7);
    g->addEdge(5,6);
    g->addEdge(5,8);
    g->addEdge(5,7);
    
    
    // Print the graph adjacency list
    g->print();
    return 0;
}
