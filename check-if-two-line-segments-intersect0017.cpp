// https://www.geeksforgeeks.org/problems/check-if-two-line-segments-intersect0017/1

#include <iostream>

using namespace std;

class Solution{
private:
    int orientation(int p[], int q[], int r[]){
        int val = (q[1] - p[1]) * (r[0] - q[0]) - (q[0] - p[0]) * (r[1] - q[1]);
        if (val == 0) return 0;
        return (val>0)?1:2;
    }

    bool onSegment(int p[], int q[], int r[]) 
    { 
        if (q[0] <= max(p[0], r[0]) && q[0] >= min(p[0], r[0]) && 
            q[1] <= max(p[1], r[1]) && q[1] >= min(p[1], r[1])) 
        return true; 

        return false; 
    }

public:
    string doIntersect(int p1[], int q1[], int p2[], int q2[]) {
        int p1q1_p2 = orientation(p1,q1,p2);
        int p1q1_q2 = orientation(p1,q1,q2);

        int p2q2_p1 = orientation(p2,q2,p1);
        int p2q2_q1 = orientation(p2,q2,q1);

        if ((p1q1_p2 != p1q1_q2) && (p2q2_p1 != p2q2_q1)) return "true";

        if(p1q1_p2 == 0 && onSegment(p1,p2,q1)) return "true";
        if(p1q1_q2 == 0 && onSegment(p1,q2,q1)) return "true";
        if(p2q2_p1 == 0 && onSegment(p2,p1,q2)) return "true";
        if(p2q2_q1 == 0 && onSegment(p2,q1,q2)) return "true";
        return "false";
    }
};

int main()
{
    Solution sol;
    int p1[] = {-4, -3 };
    int q1[] = {12,12};
    int p2[] = {10,5};
    int q2[] = {2,2};
    cout << sol.doIntersect(p1,q1,p2,q2) << endl;
    return 0;
}