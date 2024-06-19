/**
 * This code checks if two line segments intersect. It provides two different implementations to solve the problem.
 * 
 * The first implementation uses the concept of orientation of points. It determines the orientation of three points in a 2D plane and checks if the orientations of the endpoints of the line segments are different. If they are, it checks if any of the endpoints lies on the other line segment. If any of these conditions are satisfied, it returns "true", indicating that the line segments intersect. Otherwise, it returns "false".
 * 
 * The second implementation uses the concept of vector equations of lines. It checks if the two line segments intersect at a common point. It calculates the values of 'a' and 'b' using the vector equations of the line segments and checks if they are within the range [0, 1]. If they are, it returns "true", indicating that the line segments intersect. Otherwise, it returns "false".
 * 
 * The code includes helper functions to calculate the orientation of points and check if a point lies on a line segment.
 * 
 * References:
 * - Problem: https://www.geeksforgeeks.org/problems/check-if-two-line-segments-intersect0017/1
 * - Orientation of points: https://www.youtube.com/watch?v=bbTqI0oqL5U
 * - Vector equations of lines: https://www.youtube.com/watch?v=bvlIYX9cgls
 */

#include <iostream>

using namespace std;

class Solution{
private:
    /**
     * Determines the orientation of three points in a 2D plane.
     * 
     * @param p The coordinates of the first point.
     * @param q The coordinates of the second point.
     * @param r The coordinates of the third point.
     * @return 0 if the points are collinear, 1 if they are clockwise, 2 if they are counterclockwise.
     */
    int orientation(int p[], int q[], int r[]){
        long long val = (long long)(q[1] - p[1]) * (r[0] - q[0]) - (long long)(q[0] - p[0]) * (r[1] - q[1]);
        if (val == 0) return 0;
        return (val>0)?1:2;
    }

    /**
     * Checks if a point q lies on the line segment defined by points p and r.
     *
     * @param p The coordinates of the first point of the line segment.
     * @param q The coordinates of the point to be checked.
     * @param r The coordinates of the second point of the line segment.
     * @return true if the point q lies on the line segment, false otherwise.
     */
    bool onSegment(int p[], int q[], int r[]){ 
        if (q[0] <= max(p[0], r[0]) && q[0] >= min(p[0], r[0]) && 
            q[1] <= max(p[1], r[1]) && q[1] >= min(p[1], r[1])) 
        return true; 

        return false; 
    }

public:
    /**
     * Determines if two line segments intersect.
     * 
     * Concept : https://www.youtube.com/watch?v=bbTqI0oqL5U
     * 
     * Checking orientation of points of on line with other line. 
     * If one point is in clockwise and other is anticlockwise, intersection is there (check for both lines).
     * If collinear check if point of one line lies on the other line.
     *
     * @param p1 The coordinates of the first endpoint of the first line segment.
     * @param q1 The coordinates of the second endpoint of the first line segment.
     * @param p2 The coordinates of the first endpoint of the second line segment.
     * @param q2 The coordinates of the second endpoint of the second line segment.
     * @return "true" if the line segments intersect, "false" otherwise.
     */
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

    /**
     * Checks if two line segments intersect.
     * 
     * Concept : https://www.youtube.com/watch?v=bvlIYX9cgls
     * 
     * If there are 2 point A and B (both are vectors from origin). A + aAB = X. If a = 0 A = A, if a = 1 A + AB = B, if 0<a<1 there it at some mid point.
     * If there are 2 line AB and CD. They intersect at point P. We can say A + aAB = P and C + bCD = P. So, A + aAB = C + bCD.
     * 
     * @param p1 The starting point of the first line segment.
     * @param q1 The ending point of the first line segment.
     * @param p2 The starting point of the second line segment.
     * @param q2 The ending point of the second line segment.
     * @return "true" if the line segments intersect, "false" otherwise.
     */
    string doIntersect2(int p1[], int q1[], int p2[], int q2[]) {
        long long a = (long long)(q2[0] - p2[0])*(p2[1] - p1[1]) - (long long)(q2[1] - p2[1])*(p2[0] - p1[0]);
        long long b = (long long)(q2[0] - p2[0])*(q1[1] - p1[1]) - (long long)(q2[1] - p2[1])*(q1[0] - p1[0]);
        long long c = (long long)(q1[0] - p1[0])*(p2[1] - p1[1]) - (long long)(q1[1] - p1[1])*(p2[0] - p1[0]);
        
        if(b==0)
        {
            if(a == 0 && onSegment(p1,p2,q1)) return "true";
            else if(a == 0 && onSegment(p1,q2,q1)) return "true";
            else if(c == 0 && onSegment(p2,p1,q2)) return "true";
            else if(c == 0 && onSegment(p2,q1,q2)) return "true";
            else return "false";
        }
        else
        {
            double x = (double) a/b;
            double y = (double) c/b;
            if(x>=0 && x<=1 && y>=0 && y<=1) return "true";
            return "false";
        }
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