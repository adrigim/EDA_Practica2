#include <stdlib.h>

#include "../headers/board_static.h"

// TODO: Initializes the board, initializing also each square of it.

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
    return ERROR;
}

// TODO: Returns the number of rows of the board.

/**
 * Pre:
 * Post:
 *
 * Returns the number of rows of the board.
 *
 * @param board The board to be queried.
 * @return The number of rows of the board.
 */
int get_rows(Board* board) {
    return 0;
}

// TODO: Sets the number of rows of the board.

/**
 * Pre:
 * Post:
 *
 * Sets the number of rows of the board.
 *
 * @param board The board to be queried.
 */
void set_rows(Board* board, int rows) {
}

// TODO: Return the number of columns of the board.

/**
 * Pre:
 * Post:
 *
 * Returns the number of columns of the board.
 *
 * @param board The board to be queried.
 * @return The number of columns of the board.
 */
int get_columns(Board* board) {
    return 0;
}

// TODO: Sets the number of columns of the board.

/**
 * Pre:
 * Post:
 *
 * Sets the number of columns of the board.
 *
 * @param board The board to be queried.
 */
void set_columns(Board* board, int columns) {
}

// TODO: Returns the size of the board, it is, the total number of squares.

/**
 * Pre:
 * Post:
 *
 * Returns the size of the board, it is, the total number of squares.
 *
 * @param board The board to be queried.
 * @return The size of the board.
 */
int get_size(Board* board) {
    return 0;
}

// TODO: Returns the board square at the specific position.

/**
 * Pre:
 * Post:
 *
 * Returns the board square at the specific position.
 *
 * @param board The board from which the square should be retrieved.
 * @param position The position of the square.
 * @return The (reference to the) square of the board corresponding to the position if valid, NULL otherwise.
 */
Square* get_square_at(Board *board, int position) {
    return NULL;
}

// TODO: Given a board, a square type, a starting position and a reverse flag, search for the
//  next square starting from the starting position that has the required square type. If the
//  'reverse' flag is false, the search is incremental, if 'reverse' is true, the search is
//  decremental.

/**
 * Pre:
 * Post:
 *
 * Search for the next square in the board, starting from the starting position that has
 * the required square type.
 *
 * @param board The board to be searched.
 * @param type The square type to be searched.
 * @param starting_position The starting position.
 * @param reverse If the search is reverted, it is, decremental.
 * @return The index of the square, if exists, -1 otherwise.
 */
int find_square_by_type(Board *board, SquareType type, int starting_position, bool reverse) {
    return -1;
}

// TODO: Nothing.

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