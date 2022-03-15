#include "../headers/square.h"

/**
 * Pre:
 * Post: Initializes the square's attributes with the provided and default values.
 *
 * @param square The square to be initialized.
 * @param position The position of the square.
 */
void init_square(Square* square, int position) {
    set_type(square, EMPTY);
    square->position = position;
}

/**
 * Pre:
 * Post: Returns the position of the square.
 *
 * @param square The square to be queried.
 * @return The position of the square.
 */
int get_position(Square* square) {
    return square->position;
}

/**
 * Pre:
 * Post: Returns the type of the square.
 *
 * @param square The square to be queried.
 * @return The type of the square.
 */
SquareType get_type(Square* square) {
    return square->type;
}

/**
 * Pre:
 * Post: Sets the type of the square.
 *
 * @param square The square to be queried.
 * @param type The type of square to be set.
 */
void set_type(Square* square, SquareType type) {
    square->type = type;
}
