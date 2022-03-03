#include <stdlib.h>

#include "../headers/board_static.h"

/**
 * Pre:
 * Post:
 *
 * Initializes the board, initializing also each square of it.
 *
 * @param board The board to be initialized.
 * @param rows The number of rows of the board.
 * @param columns The number of columns of the board.
 * @return SUCCESS code if the initialization was successful, ERROR code if rows are less than 1 or more than MAX_ROWS
 * or if columns is less than 2 or more than MAX_COLUMNS.
 */
int init_board(Board* board, int rows, int columns) {
    set_rows(board, rows);
    set_columns(board, columns);

    for(int i = 0; i < get_size(board); i++) {
        init_square(&board->squares[i], i);
    }
    return SUCCESS;
}

/**
 * Pre:
 * Post: Returns the number of rows of the board.
 *
 * @param board The board to be queried.
 * @return The number of rows of the board.
 */
int get_rows(Board* board) {
    return board->rows;
}

/**
 * Pre:
 * Post: Sets the number of rows of the board.
 *
 * @param board The board to be queried.
 */
void set_rows(Board* board, int rows) {
    board->rows = rows;
}

/**
 * Pre:
 * Post: Returns the number of columns of the board.
 *
 * @param board The board to be queried.
 * @return The number of columns of the board.
 */
int get_columns(Board* board) {
    return board->columns;
}

/**
 * Pre:
 * Post: Sets the number of columns of the board.
 *
 * @param board The board to be queried.
 */
void set_columns(Board* board, int columns) {
    board->columns = columns;
}

/**
 * Pre:
 * Post: Returns the size of the board, it is, the total number of squares.
 *
 * @param board The board to be queried.
 * @return The size of the board.
 */
int get_size(Board* board) {
    int size = board->rows * board->columns;
    return size;
}

/**
 * Pre:
 * Post: Returns the board square at the specific position.
 *
 * @param board The board from which the square should be retrieved.
 * @param position The position of the square.
 * @return The (reference to the) square of the board corresponding to the position if valid, NULL otherwise.
 */
Square* get_square_at(Board *board, int position) {
    return &board->squares[position];
}

/**
 * Pre:
 * Post: Search for the next square in the board, starting from the starting position that has
 * the required square type.
 *
 * @param board The board to be searched.
 * @param type The square type to be searched.
 * @param starting_position The starting position.
 * @param reverse If the search is reverted, it is, decremental.
 * @return The index of the square, if exists, -1 otherwise.
 */
int find_square_by_type(Board *board, SquareType type, int starting_position, bool reverse) {
    if(reverse == false) {
        for(int i = starting_position; i < get_size(board); i++) {
            if(get_type(&board->squares[i]) == type) {
                return i;
            }
        }
    } else {
        for(int i = starting_position; i >= 0; i--){
            if(get_type(&board->squares[i]) == type) {
                return i;
            }
        }
    }
    return -1;
}

/**
 * Pre: -
 * Post: -
 *
 * Frees the allocated resources. Since this is the static implementation,
 * this is managed automatically.
 *
 * @param board The board to be freed.
 */
void free_board(Board* board) {
    // Nothing to do here for the static version
}