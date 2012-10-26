/*
Quick Sort
O(n log n)
worst case: n^2 (although it's rare, choosing the last element to be the pivot on already sorted lists or lists of identical elements)
is often faster in practice that other O(n log n) algorithms
can be implemented with an in-place partitioning algorithm so the entire sort can be done with only O(log n) space

Quicksort is a divide and conquer algorithm. Quicksort first divides a large list into two smaller sub-lists: the low elements and the high elements. Quicksort can then recursively sort the sub-lists.
The steps are:
Pick an element, called a pivot, from the list.
Reorder the list so that all elements with values less than the pivot come before the pivot, while all elements with values greater than the pivot come after it (equal values can go either way). After this partitioning, the pivot is in its final position. This is called the partition operation.
Recursively sort the sub-list of lesser elements and the sub-list of greater elements.
The base case of the recursion are lists of size zero or one, which never need to be sorted.
*/

/*
Pivot Choice
The problem was easily solved by choosing either a random index for the pivot, choosing the middle index of the partition or 
(especially for longer partitions) choosing the median of the first, middle and last element of the partition for the pivot 
(as recommended by R. Sedgewick).
*/

/*
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

void quick_sort(vector<int>* vec, int left, int right);
int median_of_three(vector<int>* vec, int left_index, int right_index);
int partition(vector<int>* vec, int pivot_index, int left, int right);
int manual_sort(vector<int>* vec, int left, int right);
void swap(vector<int>* vec, int index_1, int index_2);
vector<int> subset(vector<int>& vec, int start, int end);
string to_s(int num);
void vprint(vector<int> vec);
void vprint(vector<int> vec, int left, int right);

int main() {
    int unsorted_arr[13] = {5, 9, 1, 2, 3, 4, 11, 12, 100, -9, 0, 9, 0};
    vector<int> vec(unsorted_arr, unsorted_arr + 13);
    quick_sort(&vec, 0, 12);
    vprint(vec);
    
    int unsorted_arr[8] = {-100, 1, 2 -100, -200, -101, 3 ,4};
    vector<int> vec(unsorted_arr, unsorted_arr + 8);
    quick_sort(&vec, 0, 7);
    vprint(vec);
}

*/

/*
  function quicksort(array, 'left', 'right')
 
      // If the list has 2 or more items
      if 'left' < 'right'
 
          // See "Choice of pivot" section below for possible choices
          choose any 'pivotIndex' such that 'left' â¤ 'pivotIndex' â¤ 'right'
 
          // Get lists of bigger and smaller items and final position of pivot
          'pivotNewIndex' := partition(array, 'left', 'right', 'pivotIndex')
 
          // Recursively sort elements smaller than the pivot
          quicksort(array, 'left', 'pivotNewIndex' - 1)
 
          // Recursively sort elements at least as big as the pivot
          quicksort(array, 'pivotNewIndex' + 1, 'right')
*/
/*
void quick_sort(vector<int>* vec, int left, int right) {  
    if (right > left) {
        if (right - left >= 2) {
            int pivot_index = median_of_three(vec, left, right);
            pivot_index = partition(vec, pivot_index, left, right);
            cout << "pivot_index: " << to_s(pivot_index) << endl; 
            cout << "pivot_vab: " << to_s(vec->at(pivot_index)) << endl; 
            vprint(*vec);
            cout << "left: " << to_s(left) << " right: " << to_s(right) << endl;
            quick_sort(vec, left, pivot_index - 1);
            quick_sort(vec, pivot_index + 1, right);
        } else {
            manual_sort(vec, left, right);
        }
	}
}

int median_of_three(vector<int>* vec, int first_index, int last_index) {
    int first_val = vec->at(first_index);
    int mid_index = (first_index + last_index)/2;
    int mid_val = vec->at(mid_index);
    int last_val = vec->at(last_index);
        
    if(first_val < mid_val && mid_val < last_val) {
    } else if(last_val < mid_val && mid_val < first_val) {
        swap(vec, first_index, last_index);
    } else if(last_val < first_val && first_val < mid_val) {
     	swap(vec, last_index, mid_index);
        swap(vec, mid_index, first_index);
    } else if(mid_val < first_val && first_val < last_val) {
     	swap(vec, first_index, mid_index);
    } else if(first_val < last_val && last_val < mid_val) {
     	swap(vec, last_index, mid_index);
    } else { // mid_val < last_val && last_val < first_val
        swap(vec, last_index, first_index);
        swap(vec, first_index, mid_index);
    }
    
    return mid_index;
}

int partition(vector<int>* vec, int pivot_index, int left, int right) {
    int pivot_val = vec->at(pivot_index);
    int temp_pivot_index = left;
    
    swap(vec, pivot_index, right);
    
    for(int i = left; i < right; i++) {
        if (vec->at(i) < pivot_val) {
            swap(vec, temp_pivot_index, i);
            temp_pivot_index = temp_pivot_index + 1;
        }
    }
    
    swap(vec, temp_pivot_index, right);
    return temp_pivot_index;
}

void swap(vector<int>* vec, int index_1, int index_2) {
    if (index_1 == index_2) {
		return;
    }
    int tmp = vec->at(index_1);
    vec->at(index_1) = vec->at(index_2);
    vec->at(index_2) = tmp;
}

int manual_sort(vector<int>* vec, int left, int right) {
    if(left == right) {
    } else {
        if(vec->at(left) > vec->at(right)) {
            swap(vec, left, right);
        }
    }
}

string to_s(int num) {
   stringstream ss;
   ss << num;
   return ss.str();
}

void vprint(vector<int> vec) {
   string str = "";
	for (int i = 0; i < vec.size(); i++) {
        str += to_s(vec[i]) + " ";
    }
    cout << str << endl; 
}

void vprint(vector<int> vec, int left, int right) {
    string str = "";
	for (int i = left; i <= right; i++) {
        str += to_s(vec[i]) + " ";
    }
    cout << str << endl;
}

vector<int> subset(vector<int>& vec, int start, int end) {
    vector<int> subset;
    for (int i = 0; i < end - start; i++) {
        subset.push_back(vec[start + i]);
    }
    return subset;
}
*/