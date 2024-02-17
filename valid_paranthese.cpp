#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        if (s.size()%2 !=0) return false;
        stack<char> stck;

        for(int i=0 ; i< s.size();i++)
        {
            if(s[i]== '('|| s[i] == '[' || s[i] == '{')
            {
                stck.push(s[i]);
            }
            else if (!stck.empty())
            {
                switch(s[i])
                {
                    case ')':
                        if (stck.top() != '(' ) return false;
                        break;
                    case ']':
                        if (stck.top() != '[') return false;
                        break;
                    case '}':
                        if(stck.top() != '{') return false;
                        break;
                    default:
                        continue;
                }
                stck.pop();
            }
            else return false;
        }
        if (stck.empty()) return true;
        return false;
    }
};

int test() {
    Solution solution;

    // Test case 1: Valid parentheses
    assert(solution.isValid("()") == true);

    // Test case 2: Valid parentheses with different types
    assert(solution.isValid("()[]{}") == true);

    // Test case 3: Invalid parentheses
    assert(solution.isValid("(]") == false);

    // Test case 4: Invalid parentheses with different types
    assert(solution.isValid("([)]") == false);

    // Test case 5: Valid parentheses with nested brackets
    assert(solution.isValid("{[]}") == true);

    // Test case 6: Invalid parentheses with extra closing bracket
    assert(solution.isValid("()[]{}]") == false);

    std::cout << "All test cases passed!" << std::endl;

    return 0;
}

int main()
{
    Solution sol;
    string s = "))";
    cout << sol.isValid(s) << "\n";
    test();
}