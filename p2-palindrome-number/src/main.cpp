// Date: 2024-02-06
// Problem: https://leetcode.com/problems/palindrome-number/description/
// ---------------------------------------------------------------------
#include <cassert>
#include <cmath>
#include <iostream>


bool is_palindrome(int number);
void test_is_palindrome();


int main(void) {
    test_is_palindrome();

    return 0;
}


bool is_palindrome(int number) {
    // Return true if number is a palindrome

    // Handle negative numbers (non-palindrome) and single-digit numbers (inherently palindrome)
    if (number < 0 || number < 10) {
        return number >= 0;
    }

    int num_digits = 0;
    int original_num = number;
    // Calculate number of digits (avoid string conversion)
    while (original_num > 0) {
        original_num /= 10;
        num_digits++;
    }

    // Compare digits from both ends
    for (int i = 0; i < num_digits / 2; ++i) {
        int left_digit = (number / (int)pow(10, num_digits - i*2 - 1)) % 10;
        int right_digit = number % 10;
        if (left_digit != right_digit) {
            return false;
        }
        // Remove right digit
        number /= 10;
    }

    return true;
}


void test_is_palindrome() {
    // Execute test cases against function `is_palindrome`.
    bool test0 = is_palindrome(12021);
    assert(test0 == true);

    bool test1 = is_palindrome(121);
    assert(test1 == true);

    bool test2 = is_palindrome(-121);
    assert(test2 == false);

    bool test3 = is_palindrome(10);
    assert(test3 == false);

    bool test4 = is_palindrome(1012101);
    assert(test4 == true);

    bool test5 = is_palindrome(0);
    assert(test5 == true);
}
