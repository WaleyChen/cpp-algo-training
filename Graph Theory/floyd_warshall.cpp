#include <iostream>
#include <queue>
#include <sstream>
#include <vector>
using namespace std;

// strings
string to_s(int num);
// graphs
struct edge {
  int id;
  int edge_count;
  string name;
  struct edge *next;
  vector<int> weights;
};
struct graph {
   bool directed;
   vector<edge*> edges;
};
struct v_info {
    edge* parent; // creates a tree of shortest paths from root to other nodes
    			  // which reduces cost of finding the shortest path from x to node
    			  // from O(|V| + |E|) to O(|V|)
	string state;
};
void delete_graph(graph* g);
void friends(edge* friend_1, edge* friend_2, graph* g, int weight, int** shortest_paths);
void print_graph(graph *g);
// vectors
string vprint(vector<edge*> vec);
vector<int> subset(vector<int>& vec, int start, int end);
void floyd_warshall(int** shortest_paths, vector<edge*> vec);
void two_d_array_print(int** arr, int size);

int main() {
    graph* g = new graph;
    g->directed = false;
    
    edge* waley = new edge;
    waley->id = 0;
    waley->name = "Waley";
    waley->edge_count = 0;
    edge* wilson = new edge;
    wilson->id = 1;
    wilson->name = "Wilson";
    wilson->edge_count = 0;
    edge* jay = new edge;
    jay->id = 2;
    jay->name = "Jay";
    jay->edge_count = 0;
    edge* michael = new edge;
    michael->id = 3;
    michael->name = "Michael";
    michael->edge_count = 0;
    edge* edward = new edge;
    edward->id = 4;
    edward->name = "Edward";
    edward->edge_count = 0;
    edge* ju = new edge;
    ju->id = 5;
    ju->name = "Ju";
    ju->edge_count = 0;
    edge* juu = new edge;
    juu->id = 6;
    juu->name = "Juu";
    juu->edge_count = 0;
    
    g->edges.push_back(waley);
    g->edges.push_back(wilson);
    g->edges.push_back(jay);
    g->edges.push_back(michael);
    g->edges.push_back(edward);
    g->edges.push_back(ju);
    g->edges.push_back(juu);
    
    int *shortest_paths[g->edges.size()];
    for(int i = 0; i < g->edges.size(); i++) {
     shortest_paths[i] = new int[g->edges.size()];   
    }
    
    for(int i = 0; i < g->edges.size(); i++) {
        for(int i2 = 0; i2 < g->edges.size(); i2++) {
            if(i != i2)
                shortest_paths[i][i2] = 10000;
        }
    }
    
    friends(waley, wilson, g, 100, shortest_paths);
    friends(waley, jay, g, 56, shortest_paths);
    friends(waley, michael, g, 22, shortest_paths);
    friends(jay, michael, g, 2000, shortest_paths);
    friends(edward, michael, g, 1, shortest_paths);
    friends(edward, wilson, g, 88, shortest_paths);
    friends(edward, waley, g, 100, shortest_paths);
    friends(jay, ju, g, 2100, shortest_paths);
    friends(juu, ju, g, 222, shortest_paths);
    
    print_graph(g);
    two_d_array_print(shortest_paths, g->edges.size());
    floyd_warshall(shortest_paths, g->edges);
    cout << endl;
    two_d_array_print(shortest_paths, g->edges.size());
    
    delete_graph(g);
}

void floyd_warshall(int** shortest_paths, vector<edge*> vec) {        
    for(int i = 0; i < vec.size(); i++) {
    	for(int x = 0; x < vec.size(); x++) {
        	for(int y = 0; y < vec.size(); y++) {
                if(shortest_paths[x][i] == 10000 || shortest_paths[i][y] == 10000)
                    continue;
                
                if(shortest_paths[x][i] + shortest_paths[i][y] < shortest_paths[x][y]) {
                    shortest_paths[x][y] = shortest_paths[x][i] + shortest_paths[i][y];
                }
    		}
    	}
    }
}

// integers
string to_s(int num) {
   stringstream ss;
   ss << num;
   return ss.str();
}

// 2-d array
void two_d_array_print(int** arr, int size) {
    for(int i = 0; i < size; i++) {
        for(int i2 = 0; i2 < size; i2++) {
            cout << arr[i][i2] << " ";
        }
        cout << endl;
    }
}

// vectors
string vprint(vector<edge*> vec) {
    string str;
	for (int i = 0; i < vec.size(); i++) {
        str += vec[i]->name + " -> ";
    }
    return str;
}

vector<int> subset(vector<int>& vec, int start, int end) {
    vector<int> subset;
    for (int i = 0; i < end - start; i++) {
        subset.push_back(vec[start + i]);
    }
    return subset;
}

// graphs
void delete_graph(graph* g) {
	for (int i = 0; i < g->edges.size(); i++) {
        delete g->edges[i];
    }
    delete g;
}

void print_graph(graph *g) {
    edge* next;
    for (int i = 0; i < g->edges.size(); i++) {
		cout << g->edges[i]->name << " " << to_s(g->edges[i]->id);
        for (int i2 = 0; i2 < g->edges[i]->edge_count; i2++) {
            if (i2 == 0) {
                next = g->edges[i]->next;
                cout << ": ";
            } else {
                next = next->next;
            }
            cout << " " << next->name << " " << next->id << " " << next->weights[i2];
        }
        cout << " count: " << to_s(g->edges[i]->edge_count);
        cout << endl;
    }
}

void friends(edge* friend_1, edge* friend_2, graph* g, int weight, int** shortest_paths) {
    shortest_paths[friend_1->id][friend_2->id] = weight;
    shortest_paths[friend_2->id][friend_1->id] = weight;
    
    edge* temp = friend_1->next;
	edge* copy = new edge;
    copy->name = friend_2->name;
    copy->id = friend_2->id;
    copy->next = friend_2->next;
    copy->edge_count = friend_2->edge_count;
    copy->weights.push_back(weight);
    friend_1->next = copy;
    friend_1->edge_count = ++friend_1->edge_count;
    copy->next = temp;
   
    if (!g->directed) {
    	temp = friend_2->next;
        copy = new edge;
    	copy->name = friend_1->name;
        copy->id = friend_1->id;
        copy->next = friend_1->next;
        copy->edge_count = friend_1->edge_count;
        copy->weights.push_back(weight);
    	friend_2->next = copy;
        friend_2->edge_count = ++friend_2->edge_count;
    	copy->next = temp;
    }
}