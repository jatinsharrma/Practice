/*
    Given a number n, print a n x n spiral pattern matrix.
    The pattern matrix is a matrix of size n x n, where the values of the matrix are printed in a spiral manner.
    
    example for n = 4

        4 4 4 4 4 4 4 
        4 3 3 3 3 3 4 
        4 3 2 2 2 3 4 
        4 3 2 1 2 3 4 
        4 3 2 2 2 3 4 
        4 3 3 3 3 3 4 
        4 4 4 4 4 4 4 
        
*/


#include <iostream>

using namespace std;

/**
 * Prints a spiral pattern of numbers.
 * 
 * @param n The size of the pattern.
 */
void pattern(int n)
{
    int condition = 0;
    int t = n +1;

    for (int i=0 ; i<2*n-1 ; i++)
    {
        if (i<n) // condition for printing the first half of the pattern
        {
            condition = n-i-1;
            t -= 1;
        }
        else // condition for printing the second half of the pattern
        {
            condition = i-n + 1;
            t +=1;
        }

        // printing left corner elements
        for(int j=n ; j > condition; j--)
        {
            cout << j << " ";
        }

        // printing middle elements
        for (int j=1 ; j<= 2*(t-1)-1; j++)
        {
            cout << t << " ";
        }

        // printing right corner elements
        for (int j=condition+1 ; j < n+1; j++)
        {
            if(j==1) continue; // preventing this loop from printing 1 as it is already printed by first for loop
            cout << j << " ";
        }
        cout << "\n";
    }
}

int main()
{
    int n = 4;
    pattern(n);
    return 0;
}