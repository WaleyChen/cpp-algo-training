/*
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

vector<int> merge_sort(vector<int> vec);
vector<int> merge(vector<int> left, vector<int> right);
vector<int> subset(vector<int>& vec, int start, int end);
string to_s(int num);
string vprint(vector<int>& vec);

int main() {
    int unsorted_arr[13] = {5, 9, 1, 2, 3, 4, 11, 12, 100, -9, 0, 9, 0};
    vector<int> merged;
    vector<int> unsorted(unsorted_arr, unsorted_arr + 13);
    merged = merge_sort(unsorted);
    cout << vprint(merged);
}

// Comparison Based Sorting Algorithms
// uses a comparison operation that determines which of two elements should appear first
// in a final sorted list

// Merge Sort
// O(n log n) time
// O(n) space
// stable
// 1. Divide the list into n sublists.
// 2. Merge sublists until there is only 1 sublist remaining.
vector<int> merge_sort(vector<int> vec) {
    int mid;
    vector<int> left;
    vector<int> right;
    vector<int> merged;
    
    if(vec.size() > 1) {
    	mid = vec.size() / 2;
        left = subset(vec, 0, mid);
        right = subset(vec, mid, vec.size());
        return merge(merge_sort(left), merge_sort(right));
    }
    return vec;
}

vector<int> merge(vector<int> left, vector<int> right) {
    int size = left.size() + right.size();
    vector<int> merged;
    
    for (int i = 0; i < size; i++) {
        if (left.size() > 0 && right.size() > 0) {
        	if (left[0] <= right[0]) {
            	merged.push_back(left[0]);
            	left.erase(left.begin());
			} else {
            	merged.push_back(right[0]);
           		right.erase(right.begin());
        	}
    	} else if (left.size() > 0) {
            merged.push_back(left[0]);
           	left.erase(left.begin());
        } else {
            merged.push_back(right[0]);
           	right.erase(right.begin());
        }
    }
    
    return merged;
}

string to_s(int num) {
   stringstream ss;
   ss << num;
   return ss.str();
}

string vprint(vector<int>& vec) {
    string str = "";
	for (int i = 0; i < vec.size(); i++) {
        str += to_s(vec[i]) + " ";
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
*/