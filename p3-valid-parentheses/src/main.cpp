// Date: 2024-02-06
// Problem: https://leetcode.com/problems/valid-parentheses/description/
// ---------------------------------------------------------------------
#include <cassert>
#include <unordered_map>
#include <iostream>


bool is_valid_parenthese(const std::string s);
void test_is_valid_parenthese();


int main(void) {
    test_is_valid_parenthese();

    return 0;
}


bool is_valid_parenthese(const std::string s) {
    std::unordered_map<char, char> parentheses;
    parentheses['('] = ')';
    parentheses['['] = ']';
    parentheses['{'] = '}';

    std::vector<char> stack;

    for (char c: s) {
        // If c is an opening parens, push to stack
        if (parentheses.count(c) > 0) {
            stack.push_back(c);
        }
        else  // c is a closing parens
        {
            if (stack.empty()) {
                return false;  // because a closing parens will be in first and remain unclosed
            }
            char top_element = stack.back(); // Get the top element
            if (parentheses[top_element] != c) {
                return false;  // If top_element is for e.g. ( and c is ], it's an invalid pair
            }
            stack.pop_back();  // Matching pair - pop top element off stack
        }
    }
    return stack.empty();;
}


void test_is_valid_parenthese() {
    bool test0 = is_valid_parenthese("()");
    assert(test0 == true);

    bool test1 = is_valid_parenthese("()[]{}");
    assert(test1 == true);

    bool test2 = is_valid_parenthese("(]");
    assert(test2 == false);

    bool test3 = is_valid_parenthese("{([])}");
    assert(test3 == true);

    bool test4 = is_valid_parenthese("(((()())))");
    assert(test4 == true);

    bool test5 = is_valid_parenthese("(((()))))");
    assert(test5 == false);

    bool test6 = is_valid_parenthese("(])");
    assert(test6 == false);
}
