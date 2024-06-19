/** 
 * @Author : Jatin Sharma
 * @Date : Jan 18 2024
 * @Problem : Given a circular sheet of radius, r. Find the total number of rectangles with integral length and width that can be cut from the sheet that can fit on the circle, one at a time.
 * 
 * 
 * References
 * idea : https://www.youtube.com/watch?v=-gqSFdOEpQ4
 * Problem : https://www.geeksforgeeks.org/problems/rectangles-in-a-circle0457/1
*/


#include <iostream>
#include <cmath>

using namespace std;

/**
 * @class Solution
 * @brief Class that calculates the number of rectangles that can fit inside a circle.
 */
class Solution {
private:
    /**
     * @brief Checks if a rectangle with given dimensions can fit inside the circle.
     * @param r The radius of the circle.
     * @param x The width of the rectangle.
     * @param y The height of the rectangle.
     * @return True if the rectangle can fit inside the circle, false otherwise.
     */
    bool willRectangleFit(int r, int x, int y)
    {
        return (((x/2.0)*(x/2.0) + (y/2.0)*(y/2.0)) <= r*r) ? true : false;
    }
public:
    /**
     * 
     * Time complexity  = O(r^2)
     * 
     * This solution find all the pairs.
     * 
     * @brief Calculates the number of rectangles that can fit inside the circle.
     * @param r The radius of the circle.
     * @return The number of rectangles that can fit inside the circle.
     */
    int rectanglesInCircle(int r) {
        int sum = 0;
        for(int i = 1; i < 2*r; i++){
            for(int j = 1; j < 2*r; j++)
            {
                if(willRectangleFit(r, i, j)) sum++;
            }
        }
        return sum;
    }

    /**
     * 
     * Time Complexity O(r)
     * This solution only give how many rectangles can fit the circle but can not print the dimensions of all rectangles.
     * 
     * @brief the number of rectangles that can fit inside a circle with radius r.
     * @param r The radius of the circle.
     * @return The total number of rectangles that can fit inside the circle.
     */
    int rectanglesInCircle2(int r) {
        int sum=0;
        for(int i=1;i<2*r;i++){
            float a=2*sqrt(r*r*1LL-(i/2.0)*(i/2.0));
            sum+=(int)a;
        }
        return sum;
    }
};
class Solution {
private:
    bool willRectangleFit(int r,int x, int y)
    {
        return (((x/2.0)*(x/2.0) + (y/2.0)*(y/2.0)) <= r*r) ? true:false;
    }
public:
    int rectanglesInCircle(int r) {
        int sum=0;
        for(int i=1;i<2*r;i++){
            for(int j=1;j<2*r;j++)
            {
                if(willRectangleFit(r,i,j)) sum++;
            }
        }
        return sum;
    }
};

int main()
{
    Solution sol;
    int r = 5;
    cout << sol.rectanglesInCircle(r) << endl ;
    return 0;
}