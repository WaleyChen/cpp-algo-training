// implement:
// BFS & DFS

// DFS versus BFS
// O(|V| + |E|)
// DFS 
// less memory, only need to record vertices on current path
// good when many possible solutions & you don't care about a specific solution
// may get stuck exploring long and potentially infinite alleyways
// less appropriate when there's one soln & you only want the shortest one
// BFS
// whilst, BFS records vertices on an entire level
// will not get stuck in blind alleyways
// will always find the shortest path first
// more appropriate when depth of solution is short or interested in all the solns

// Implementation
// each vertex exists in one of three states
// undiscovered - initial virgin state
// discovered - vertex has been found but we have not checked out all of its descendents
// processed - visted all the vertex's descendents

// Implementation tips
// neighbour edges != actual edge since neighbour edges point to the next neighbour of an actual edge
// while actual edge points to its own neighbours
// e.g. 1->(2->3->4), 2->(5), notice how 2->3 and 2->(5) differ

// BFS
// Enqueue the root node
// Dequeue a node and examine it
// If the element sought is found in this node, quit the search and return a result.
// Otherwise enqueue any successors (the direct child nodes) that have not yet been discovered.
// If the queue is empty, every node on the graph has been examined â quit the search and return "not found".
// If the queue is not empty, repeat from Step 2.
// Note: Using a stack instead of a queue would turn this algorithm into a depth-first search.

/*
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
void friends(edge* friend_1, edge* friend_2, graph* g);
void print_graph(graph *g);
// vectors
string vprint(vector<edge*> vec);
vector<int> subset(vector<int>& vec, int start, int end);
// soln
vector<edge*> first_search(string type, graph* g, int start, string name);
void root_to_x(int id, vector<v_info*> vertex_info, graph* g, vector<edge*>& path);

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
    
    friends(waley, wilson, g);
    friends(waley, jay, g);
    friends(waley, michael, g);
    friends(jay, michael, g);
    friends(edward, michael, g);
    friends(edward, wilson, g);
    friends(edward, waley, g);
    friends(jay, ju, g);
    friends(juu, ju, g);
    
    
    print_graph(g);
    vector<edge*> path;
    
    path = first_search("breadth", g, 6, "Waley");
    cout << path.size();
    cout << vprint(path) << endl;
    
    // cout << vprint(first_search("breadth", g, 0, "Jay")) << endl;
    cout << vprint(first_search("breadth", g, 0, "Edward")) << endl;
    cout << vprint(first_search("breadth", g, 0, "Michael")) << endl;
    cout << vprint(first_search("breadth", g, 0, "Wilson")) << endl;
    cout << vprint(first_search("breadth", g, 0, "Tim")) << endl;
    
    delete_graph(g);
}

// BFS solution
vector<edge*> first_search(string type, graph* g, int start, string name) {
    edge* current_edge;
    edge* next_edge;
    queue<int> q;
    vector<edge*> path;
    vector<v_info*> vertex_info;
    
    for (int i = 0; i < g->edges.size(); i++) {
        v_info* temp = new v_info;
        temp->parent = 0;
        temp->state = "undiscovered";
        vertex_info.push_back(temp);
    }
    
    q.push(start);
    vertex_info[start]->state = "discovered";
    
    while(q.size() != 0) {
        current_edge = g->edges[q.front()];
        cout << "current_edge: " << current_edge->name << " " << current_edge->edge_count << endl;
        
        if (current_edge->name == name) {
			root_to_x(current_edge->id, vertex_info, g, path);
            return path;
        } else {
            next_edge = current_edge->next;
       		for (int i = 0; i < current_edge->edge_count; i++) {
                cout << "next edge: " << next_edge->name << endl;
                if (vertex_info[next_edge->id]->state == "undiscovered") {
               		q.push(next_edge->id);
                   	vertex_info[next_edge->id]->parent = current_edge;
                   	vertex_info[next_edge->id]->state = "discovered";
           		}
                if (next_edge->name == name) {
					root_to_x(next_edge->id, vertex_info, g, path);
                    return path;
       			}
                cout << "just before" << endl;
                next_edge = next_edge->next;
                cout << "not after" << endl;
        	}
    	}

        q.pop();
        vertex_info[current_edge->id]->state = "processed";
    }
    
    for (int i = 0; i < vertex_info.size(); i++) {
        delete vertex_info[i];
    }
}

void root_to_x(int id, vector<v_info*> vertex_info, graph* g, vector<edge*>& path) {
	edge* cur_edge = g->edges[id];
    
    if (vertex_info[cur_edge->id]->parent != 0) {
        root_to_x(vertex_info[cur_edge->id]->parent->id, vertex_info, g, path);
    }
    path.push_back(cur_edge);
    
    return;
}

// integers
string to_s(int num) {
   stringstream ss;
   ss << num;
   return ss.str();
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
            cout << " " << next->name << " " << next->id;
        }
        cout << " count: " << to_s(g->edges[i]->edge_count);
        cout << endl;
    }
}

void friends(edge* friend_1, edge* friend_2, graph* g) {
    edge* temp = friend_1->next;
	edge* copy = new edge;
    copy->name = friend_2->name;
    copy->id = friend_2->id;
    copy->next = friend_2->next;
    copy->edge_count = friend_2->edge_count;
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
    	friend_2->next = copy;
        friend_2->edge_count = ++friend_2->edge_count;
    	copy->next = temp;
    }
}
*/