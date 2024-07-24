/**
* @author  : Jatin Sharma
* @date    : 23 Jul 2024
* @problem : New Students are arriving at college. Initially the students don't know each other, 
            and each has a circle of friends limited to themselves. As the semester progresses, 
            groups of friends form.

            As they arrive, each students gets an ID number, 1 to n.

            You'll receive three interconnected data sets: a query type (either "Friend" or "Total"), and two student ID numbers. If the query is "Friend," a friendship is established between the specified students. For a "Total" query, calculate and report the combined size of the friend groups for the given students.

* @solution : each one initial will have one set of friends. Initially the person id friend with him/herself. 
            later as friends are group they will point to a common list (saving time to update numerous list).
*/



#include <iostream>
#include <vector>
#include <set>
#include <string>

using namespace std;

class Solution{
    public:
    vector<int> grouping(int n, vector<string>cmd , vector<int>student_1,vector<int>student_2)
    {
        vector<int> ans;
        vector<set<int>*> frnd;
        for(int i=0 ; i<n+1 ;  i++)
        {
            set<int>* s1 = new set<int>;
            (*s1).insert(i);
            frnd.push_back(s1);

        }
        for(int i=0 ; i<n+1 ; i++)
        {
            for(int j : (*frnd[i]))
                cout << j << " ";
            cout << " | " << endl;
        }
        int index = 0;
        for(string i: cmd)
        {
            if(i == "Friend")
            {

                set<int>* frnd_1 = frnd[student_1[index]];
                set<int>* frnd_2 = frnd[student_2[index]];
                
                set<int> * temp = frnd_1;
                for(int i : *frnd_2)
                {
                    (*temp).insert(i);
                }
                
                (*temp).insert(student_1[index]);
                (*temp).insert(student_2[index]);
                for(int i : *frnd_2)
                {
                    frnd[i] = temp;
                }
                
            }
            else
            {
                ans.push_back((*frnd[student_1[index]]).size() + (*frnd[student_2[index]]).size());
            }
            index ++;
        }

        return ans;
    }
};

int main()
{
    Solution sol;
    int n = 5;
    vector<string> cmd {"Friend","Friend","Total","Friend","Total"};
    vector<int> students_1 {1,2,3,4,3};
    vector<int> students_2 {2,3,4,5,2};
    vector<int> ans = sol.grouping(n,cmd,students_1,students_2);
    for(int i : ans) cout << i << " ";
    cout << endl;
    return 0;
}