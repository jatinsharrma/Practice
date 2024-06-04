// https://leetcode.com/problems/longest-palindrome/?envType=daily-question&envId=2024-06-04

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
	int longestPalindrome(string s) 
	{
		unordered_map<char,int> map;
		for(char i:s)
		{
			if(!map.contains(i))
				map[i] = 1;
			else
				map[i] ++;
		}
		int max = 0;
		int result = 0;
		
		for(pair i:map)
		{
			if(i.second % 2 ==0)
				result += i.second;
			else
				if(i.second > max)
				{
					if(max > 0) result += max - 1;
					max = i.second;
				}
				else
				{
					result += i.second - 1;
				}
		}
		return result + max;
	}	
};

int main()
{
	Solution sol;
	string s = "civilwartestingwhetherthatnaptionoranynartionsoconceivedandsodedicatedcanlongendureWeareqmetonagreatbattlefiemldoftzhatwarWehavecometodedicpateaportionofthatfieldasafinalrestingplaceforthosewhoheregavetheirlivesthatthatnationmightliveItisaltogetherfangandproperthatweshoulddothisButinalargersensewecannotdedicatewecannotconsecratewecannothallowthisgroundThebravelmenlivinganddeadwhostruggledherehaveconsecrateditfaraboveourpoorponwertoaddordetractTgheworldadswfilllittlenotlenorlongrememberwhatwesayherebutitcanneverforgetwhattheydidhereItisforusthelivingrathertobededicatedheretotheulnfinishedworkwhichtheywhofoughtherehavethusfarsonoblyadvancedItisratherforustobeherededicatedtothegreattdafskremainingbeforeusthatfromthesehonoreddeadwetakeincreaseddevotiontothatcauseforwhichtheygavethelastpfullmeasureofdevotionthatweherehighlyresolvethatthesedeadshallnothavediedinvainthatthisnationunsderGodshallhaveanewbirthoffreedomandthatgovernmentofthepeoplebythepeopleforthepeopleshallnotperishfromtheearth";
	cout << sol.longestPalindrome(s) << endl;
	return 0;
}
