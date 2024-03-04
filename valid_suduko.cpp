// https://leetcode.com/problems/valid-sudoku/description/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

/**
 * @class Solution
 * @brief Class that checks the validity of a Sudoku board.
 */
class Solution
{
public:
	/**
	 * @brief Checks if the given Sudoku board is valid.
	 * @param board The Sudoku board represented as a 2D vector of characters.
	 * @return True if the board is valid, false otherwise.
	 */
	bool isValidSudoku(vector<vector<char>>& board)
	{
		// Check rows and columns
		for(int i=0 ; i<9 ; i++)
		{
			int row[10] = {0,0,0,0,0,0,0,0,0,0};
			int column[10] = {0,0,0,0,0,0,0,0,0,0};
			for (int j=0 ; j<9 ; j++)
			{
				if(board[i][j] != '.')
				{
					if(row[int(board[i][j])-48]) return false;
					row[int(board[i][j])] = 1;
				}
				if(board[j][i] != '.')
				{
					if(column[int(board[j][i])-48]) return false;
					column[int(board[j][i])] = 1;
				}
			}
		}
		
		// Check 3x3 sub-grids
		for(int i=0 ; i<=2 ; i++)
		{
			for (int j=0 ; j<=2 ; j++)
			{
				int small[10] = {0,0,0,0,0,0,0,0,0,0};
				for (int k=0; k<=2; k++)
				{
					for (int l=0; l<=2; l++)
					{
						if(board[3*(i%3)+k][3*(j%3)+l] != '.')
						{
							if(small[int(board[3*(i%3)+k][3*(j%3)+l])-48]!=0) return false;
							else small[int(board[3*(i%3)+k][3*(j%3)+l])-48] = 1;
						}
					}
				}
			}
		} 
		
		return true;
	}
};

void tests()
{
    Solution solution;

    // Test case 1: Valid Sudoku board
    vector<vector<char>> board1 = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };
    bool result1 = solution.isValidSudoku(board1);
    cout << "Test case 1: " << (result1 ? "Passed" : "Failed") << endl;

    // Test case 2: Invalid Sudoku board with duplicate number in a row
    vector<vector<char>> board2 = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '8'} // Duplicate '8' in the last row
    };
    bool result2 = solution.isValidSudoku(board2);
    cout << "Test case 2: " << (!result2 ? "Passed" : "Failed") << endl;

    // Test case 3: Invalid Sudoku board with duplicate number in a column
    vector<vector<char>> board3 = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '9'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'} // Duplicate '9' in the last column
    };
    bool result3 = solution.isValidSudoku(board3);
    cout << "Test case 3: " << (!result3 ? "Passed" : "Failed") << endl;

    // Add more test cases here...
}


int main()
{
	Solution s;
	vector<vector<char>> board {
		{'5','3','.','.','7','.','.','.','.'},
		{'6','.','.','1','9','5','.','.','.'},
		{'.','5','8','.','.','.','.','6','.'},
		{'8','.','.','.','6','.','.','.','3'},
		{'4','.','.','8','.','3','.','.','1'},
		{'7','.','.','.','2','.','.','.','6'},
		{'.','6','.','.','.','.','2','8','.'},
		{'.','.','.','4','1','9','.','.','5'},
		{'.','.','.','.','8','.','.','7','9'}};
	cout << s.isValidSudoku(board) << '\n';
	tests();
	return 0;
}
