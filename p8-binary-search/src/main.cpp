// Date: 2024-02-08
//https://leetcode.com/problems/binary-search/description/
// -------------------------------------------------------
#include <cassert>
#include <iostream>
#include <vector>


int binary_search(const std::vector<int> v, int t);
void test_binary_search();


int main(void) {
    test_binary_search();

    return 0;
}


int binary_search(const std::vector<int> v, int t) {
    int lower_bound = 0;
    int upper_bound = v.size() - 1;

    while (lower_bound <= upper_bound) {
        int midpoint = (lower_bound + (upper_bound - lower_bound) / 2);

        if (v[midpoint] == t) {
            return midpoint;  // Index of target in the vector
        } else
        if (v[midpoint] < t) {
            lower_bound = midpoint + 1;
        } else
        {
            upper_bound = midpoint - 1;
        }
    }
    return -1;  // Target not found in vector
}


void test_binary_search() {
    int test0 = binary_search(std::vector<int>{ -1, 0, 3, 5, 9, 12 }, 9);
    assert(test0 == 4);

    int test1 = binary_search(std::vector<int>{ -1, 0, 3, 5, 9, 12 }, 2);
    assert(test1 == -1);
}
