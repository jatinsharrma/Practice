/**
 * 
 * @author : Jatin Sharma
 * @date : 19 June 2024
 * 
 * @problem : https://www.geeksforgeeks.org/problems/magical-box5306/1
 * 
 * @solution: 
 * Follow the below link, read the second reply (by user21467). 
 * There you will understand to get maximum volume, from length, breath, width 2 should be same.
 * And we are also given 2 values from that we can get 2 equations.
 * 
 * perimeter, P = 4(l + b + h)
 * area, A = 2(lb + bh + hl)
 * 
 * assume b == h then
 * perimeter = 4(l + 2b)
 * area = 2(2lb + bh)
 * 
 * upon solving both we can get
 * 
 * 6l^2 - Pb + 2A = 0 // quadratic equation, find read root that will be the value of b
 * b = (P/4) - 2l
 * 
 * @refrence : https://math.stackexchange.com/questions/756011/maximum-volume-of-a-box-given-perimeter-and-surface-area
 * 
 */


#include <iostream>
#include <cmath>

using namespace std;

/**
 * @class Solution
 * @brief A class that calculates the maximum volume of a box given the perimeter and area.
 */
class Solution{
public:
    /**
     * @brief Calculates the maximum volume of a box.
     * @param perimeter The perimeter of the box.
     * @param area The area of the box.
     * @return The maximum volume of the box.
     */
    double maxVolume(double perimeter, double area) {
        // code here
        double length = (perimeter - sqrt(perimeter * perimeter - (24 * area))) / 12;
        double Vol = length * (perimeter/4 - 2*length)*length;
        return Vol;
    }
};

int main()
{
    Solution sol;
    int perimeter = 22;
    int area = 15;
    cout << sol.maxVolume(perimeter,area) << endl;
    return 0;
}