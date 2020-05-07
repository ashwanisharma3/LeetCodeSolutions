/*
Link: https://leetcode.com/problems/design-tic-tac-toe

Design a Tic-tac-toe game that is played between two players on a n x n grid.
You may assume the following rules:
A move is guaranteed to be valid and is placed on an empty block.
Once a winning condition is reached, no more moves is allowed.
A player who succeeds in placing n of their marks in a horizontal, vertical, or diagonal row wins the game.
Example:
Given n = 3, assume that player 1 is "X" and player 2 is "O" in the board.

TicTacToe toe = new TicTacToe(3);

toe.move(0, 0, 1); -> Returns 0 (no one wins)
|X| | |
| | | |    // Player 1 makes a move at (0, 0).
| | | |

toe.move(0, 2, 2); -> Returns 0 (no one wins)
|X| |O|
| | | |    // Player 2 makes a move at (0, 2).
| | | |

toe.move(2, 2, 1); -> Returns 0 (no one wins)
|X| |O|
| | | |    // Player 1 makes a move at (2, 2).
| | |X|

toe.move(1, 1, 2); -> Returns 0 (no one wins)
|X| |O|
| |O| |    // Player 2 makes a move at (1, 1).
| | |X|

toe.move(2, 0, 1); -> Returns 0 (no one wins)
|X| |O|
| |O| |    // Player 1 makes a move at (2, 0).
|X| |X|

toe.move(1, 0, 2); -> Returns 0 (no one wins)
|X| |O|
|O|O| |    // Player 2 makes a move at (1, 0).
|X| |X|

toe.move(2, 1, 1); -> Returns 1 (player 1 wins)
|X| |O|
|O|O| |    // Player 1 makes a move at (2, 1).
|X|X|X|
Follow up:
Could you do better than O(n2) per move() operation?
Hint:
Could you trade extra space such that move() operation can be done in O(1)?
You need two arrays: int rows[n], int cols[n], plus two variables: diagonal, anti_diagonal.
*/

// Solution
// In tic tac toe  player wins if he get his mark in any of these
// - a row
// - a column
// - back diagonal
// - forward diagonal
// In other word we can also say that if the count of a players move in any of the above becomes
// equal to the side of the matrix. We have used this approach here.

/*
TC = O(n)       n is the number of moves
SC = O(n)       for row and column, in brute force approach SC is O(n ^ 2)
*/
class TicTacToe {
public:
    vector<int> rows;
    vector<int> cols;
    int dig = 0;
    int fDiag = 0;
    /** Initialize your data structure here. */
    public TicTacToe(int n) {
        vector<int> v(n);
        row = v;
        col = v;
    }
     
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    public int move(int row, int col, int player) {
        int count = player == 1 ? 1 : -1;
         
        rows[row] += count;
        cols[col] += count;
         
        if (row == col) {
            diag += count;
        }
             
        // X-diagonal
        if (row + col == n - 1) {
            xdiag += count;
        }
             
        // If any of them equals to n, return 1
        if (Math.abs(rows[row]) == n || 
            Math.abs(cols[col]) == n || 
            Math.abs(diag) == n || 
            Math.abs(xdiag) == n) {
            return count > 0 ? 1 : 2;
        }
         
        return 0;
    }
};
