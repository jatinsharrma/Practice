// https://neetcode.io/problems/daily-temperatures

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution 
{
public:
	vector<int> dailyTemperatures(vector<int>& temperatures) 
	{
	ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int n = temperatures.size();
		vector<int> result(n,0);
		stack<int> stack;
		stack.push(0);
		for(int i=1 ; i<n; i++)
		{
			while(!stack.empty() && temperatures[i] > temperatures[stack.top()])
			{
				result[stack.top()] = i - stack.top();
				stack.pop();
			}
			stack.push(i);
		}
		return result;
        }
};

int main()
{
	vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
	Solution sol;
	vector<int> result = sol.dailyTemperatures(temperatures);
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << " ";
	}
	cout << endl;
	return 0;
}
