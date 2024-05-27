// https://neetcode.io/problems/evaluate-reverse-polish-notation
// https://leetcode.com/problems/evaluate-reverse-polish-notation

// Solution:
// Use a stack to store the numbers. When we encounter an operator, pop the top two numbers from the stack, do the operation and push the result back to the stack.

#include <iostream>
#include <vector>
#include <ctype.h>
#include <stack>
#include <string>

using namespace std;

/**
 * @class Solution
 * @brief Class that evaluates reverse Polish notation expressions.
 */
class Solution {
public:
    /**
     * @brief Evaluates the given reverse Polish notation expression.
     * @param tokens The tokens representing the expression.
     * @return The result of the evaluation.
     */
    int evalRPN(vector<string>& tokens) 
    {
        stack<int> stack;
        int result = 0;
        for(string c : tokens)
        {
            if (isdigit(c[c.size()-1]))
                stack.push(stoi(c));
            else
            {
                int a = stack.top();
                stack.pop();
                int b = stack.top();
                stack.pop();
                if (c == "+")
                    stack.push(a+b);
                else if (c == "*")
                    stack.push(a*b);
                else if (c == "-")
                    stack.push(b-a);
                else if (c == "/")
                    stack.push(b/a);
            }
        }
        return stack.top();
    }	
};

int main()
{
	Solution s;
	vector<string> tokens {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
	cout << s.evalRPN(tokens) << endl;
	return 0;
}
