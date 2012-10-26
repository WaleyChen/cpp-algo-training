/*
#include <iostream>
#include <queue>
#include <sstream>
#include <vector>
using namespace std;

struct edge {
  int id;
  struct edge *next;  
};
void print_edges(edge* list);
void reverse_non_recursive(edge* list);
edge* reverse_recursive_in_place(edge* old_list, edge* new_list);
    
int main() {
	edge* edge_1 = new edge;
    edge* edge_2 = new edge;
    edge* edge_3 = new edge;
    edge* edge_4 = new edge;
    
    edge_1->id = 1;
    edge_2->id = 2;
    edge_3->id = 3;
    edge_4->id = 4;
    
    edge_1->next = edge_2;
    edge_2->next = edge_3;
    edge_3->next = edge_4;
    
    edge* reversed = reverse_recursive_in_place(edge_1, NULL);
    print_edges(reversed);
}

void reverse_non_recursive(edge* list) {
}

edge* reverse_recursive_in_place(edge* old_list, edge* new_list) {
    edge* temp;
        
    if (old_list->next == NULL) {
        old_list->next = new_list;
        return old_list;
    } else {
		temp = reverse_recursive_in_place(old_list->next, old_list);
        old_list->next = new_list;
        return temp;
    }
}

void print_edges(edge* list) {
    while (list != NULL) {
        cout << list->id << ' ';
        list = list->next;
    }
    cout << endl;
}
*/