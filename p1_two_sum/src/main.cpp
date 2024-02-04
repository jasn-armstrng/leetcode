// Date: 2024-02-04
// Problem: https://leetcode.com/problems/two-sum/description/
// -----------------------------------------------------------
#include <cassert>
#include <iostream>
#include <vector>

#include "../headers/phmap.h"


// Function declarations
// ---------------------
std::vector<int> two_sum(const std::vector<int> v, int t);
void test_two_sum();


int main(void) {
    void test_two_sum();

    return 0;
}


// Function definitions
// --------------------
std::vector<int> two_sum(const std::vector<int> nums, int target) {
    // Return a vector with the positions of the first 2 elements in nums whose
    // sum is the target. If no 2 elements found, return an empty vector.
    phmap::flat_hash_map<int, int> num_position;
    int input_size = nums.size();

    for (int i = 0; i < input_size; ++i) {
        num_position[nums[i]] = i;
    }

    for (int j = 0; j < input_size; ++j) {
        int test = target - nums[j];
        if (num_position.count(test) > 0 && num_position[test] != j) {
            return std::vector<int>{ j, num_position[target - nums[j]] };
        }
    }

    return std::vector<int>{};
}


void test_two_sum() {
    // Execute test cases against function `two_sum`.
    std::vector<int> test1 = two_sum(std::vector<int>{ 2, 7, 11, 15 }, 9);
    std::vector<int> expected1 = { 0, 1 };
    assert(test1 == expected1);

    std::vector<int> test2 = two_sum(std::vector<int>{ 3, 2, 4 }, 6);
    std::vector<int> expected2 = { 1, 2 };
    assert(test2 == expected2);

    std::vector<int> test3 = two_sum(std::vector<int>{ 3, 3 }, 6);
    std::vector<int> expected3 = { 0, 1 };
    assert(test3 == expected3);

    std::vector<int> test4 = two_sum(std::vector<int>{ 0, 3, 4, 0 }, 0);
    std::vector<int> expected4 = { 0, 3 };
    assert(test4 == expected4);

    std::vector<int> test5 = two_sum(std::vector<int>{ -1, -2, -3, -4, -5 }, - 8);
    std::vector<int> expected5 = { 2, 4 };
    assert(test5 == expected5);
}
