// https://neetcode.io/problems/car-fleet

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
	int carFleet(int target, vector<int>& position, vector<int>& speed) 
	{
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
		vector<pair<int,double>> pair;
		int n = position.size();
		for( int i=0 ; i<n ; i++)
		{
			double time = (double)(target - position[i])/speed[i];
			pair.push_back({position[i],time});
		}
		sort(pair.begin(),pair.end());

		int result = 0;
		double max_time = 0.0;
		for( int i=n-1 ; i>=0 ; i-- )
		{
			double time = pair[i].second;
			if( time > max_time)
			{
				result ++;
				max_time = time;
			}
		}
		return result;
	}
};

int main()
{
	vector<int> position = {0,2,4};
	vector<int> speed = {4,2,1};
	int target = 100;
	Solution sol;
	cout << sol.carFleet(target, position, speed) << endl;
	return 0;
}
