// https://leetcode.com/problems/transform-to-chessboard/discuss/234984/C%2B%2B-solution-with-very-detailed-comments-especially-the-swap-counting-part
// Don't understand
class Solution {
public:
    int movesToChessboard(vector<vector<int>>& board) {
        /**** Two important facts ****
        1. Take rows for example, for any 2 rows, look at their items in the same column, e.g. b[r1][c], b[r2][c], 
           no matter how the rows or columns swap, the relationship between the 2 items never change:
           if they are the same, they will always be the same, if they are inverted, they will always be inverted.
        2. For a chess board, any two rows are either the same, or inverted.
        *******************************/
        
        // Hence we have:
        // Rule 1. If the board can be transformed to a chess board, for any two rows in the board, they must be either both the same, or inverted, if not. 
		//         i.e. some items are inverted and some items are the same, they can't form a chess board by swapping.
        // Rule 2. The difference of two types of rows/columns cannot > 1,
		//         otherwise there must be >= 2 same type of rows/columns arranged together.
        
        // Now, validate our board by these 2 rules.
        int n = board.size();
        int row_counter = 0, col_counter = 0;
        for(int r = 0; r < n; r++){
            row_counter += board[r][0] ? 1 : -1;
            for(int c = 0; c < n; c++){
                if(r == 0) col_counter += board[r][c] ? 1 : -1;
                // Check rule 1.
                // The relationship of items in current column between current row and first row should be consistent with the relationship of first items between current row and first row (i.e. the 2 pair of items should be either both the same or both inverted).
                if((board[r][0] ^ board[0][0]) ^ (board[r][c] ^ board[0][c])) return -1;
                // Since XOR operator is associative and commutative, we don't have to verify columns again (i.e. (board[0][c] ^ board[0][0]) ^ (board[r][c] ^ board[r][0]) )
            }
        }
        
        // Check rule 2.
        if(abs(row_counter) > 1 || abs(col_counter) > 1) return -1;
        
        // Count possible swap count, we only need care about the swap count of odd positions, since when we swap, we always swap an odd position with an even position.
        int row_swap_count = 0, col_swap_count = 0, row_0_count = 0, col_0_count = 0;
        // When n is odd, we need ensure the item who is more stay on even position and item who's less stay on odd position, because even position is more than odd position.
        // E.g. 
        // 0,1,0,1,1, then 0s must stay on odd positions so that 1s stay on even positions: 1,0,1,0,1.
        // 1,0,1,0,0, then 1s must stay on odd positions so that 0s stay on even positions: 0,1,0,1,0.
        for(int i = 0; i < n; i++){
            if(i & 1){ // When i is odd
                // Assume 0 is less and should stay on odd position, so we swap 1 away from odd position.
                row_swap_count += board[i][0];
                col_swap_count += board[0][i];
            }
            // Count 0.
            row_0_count += board[i][0] == 0, col_0_count += board[0][i] == 0;            
        }
        
        int odd_position_count = n/2; // Odd position count is always less than or equal with even position count.
        if(n & 1){ // When n is odd.
            // Count of 0 == odd_position_count means 0 is less, so we're right on swapping 1 away, the current swap count is correct. 
			// Otherwise we should keep 1 on the odd position and swap 0 away, so the swap count becomes odd_position_count - row_swap_count.
            row_swap_count = row_0_count == odd_position_count ? row_swap_count : (odd_position_count - row_swap_count);
            col_swap_count = col_0_count == odd_position_count ? col_swap_count : (odd_position_count - col_swap_count);
        }
        else{
            // If n is even, odd position's count is the same with even position's count, choose whichever swap count is smaller.
            row_swap_count = min(row_swap_count, odd_position_count - row_swap_count);
            col_swap_count = min(col_swap_count, odd_position_count - col_swap_count);            
        }
        
        return row_swap_count + col_swap_count;
    }
};
