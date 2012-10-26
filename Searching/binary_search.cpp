/*
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int bin_search(int ele, vector<int>& vec, int low, int high);
string to_s(int num);
string vprint(vector<int>& vec);
vector<int> subset(vector<int>& vec, int start, int end);

int main() {
    int sorted_arr[11] = {-5, 0, 1, 2, 3, 4, 5, 1000, 2000, 3000, 1000000};
    vector<int> sorted(sorted_arr, sorted_arr + 11);
    int search_bool;
}

// best: O(1)
// worst: O(log n)
// space: O(1)
int bin_search(int ele, vector<int>& vec, int low, int high) {
    int mid = (low + high) / 2;
    
    // cout << to_s(mid) << ' ' << ele << ' ' << vec[low] << ' ' << vec[mid] << ' ' << vec[high] << endl;

    if (ele == vec[mid]) {
        return mid;
    } else if (low > high) {
		return -1;
    } else if (ele < vec[mid]) {
        return bin_search(ele, vec, low, mid - 1);
    } else {
     	return bin_search(ele, vec, mid + 1, high);   
    }
}

string to_s(int num) {
   stringstream ss;
   ss << num;
   return ss.str();
}

vector<int> subset(vector<int>& vec, int start, int end) {
    vector<int> subset;
    for (int i = 0; i < end - start; i++) {
        subset.push_back(vec[start + i]);
    }
    return subset;
}
*/