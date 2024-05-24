// https://neetcode.io/problems/minimum-stack
// Solution
// each element in the stack will have a corresponding minimum value.

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

/**
 * @class MinStack
 * @brief A stack data structure that supports retrieving the minimum element in constant time.
 */
class MinStack {
private:
	vector<pair<int,int>> nums; /**< The stack to store the elements and their corresponding minimum values. */
public:
    /**
     * @brief Default constructor for the MinStack class.
     */
    MinStack() 
    {       
    }
    
    /**
     * @brief Pushes an element onto the stack.
     * @param val The value to be pushed onto the stack.
     */
    void push(int val) 
    {
	    if (nums.size())
		    nums.push_back({val,min(val,nums.back().second)});
        else
            nums.push_back({val,val});
    }
    
    /**
     * @brief Removes the top element from the stack.
     */
    void pop() 
    {
	    nums.pop_back();
    }
    
    /**
     * @brief Returns the top element of the stack.
     * @return The top element of the stack.
     */
    int top() 
    {
        return nums.back().first;
    }
    
    /**
     * @brief Returns the minimum element in the stack.
     * @return The minimum element in the stack.
     */
    int getMin() 
    {
        return nums.back().second;
    }
};

int main()
{
	MinStack m;
	m.push(1);
	m.push(2);
	m.push(0);
	cout << m.getMin() << endl;
	m.pop();
	cout << m.top() << endl;
	cout << m.getMin() << endl;
	return 0;
}
