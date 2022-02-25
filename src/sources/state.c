#include <stdio.h>
#include "../headers/state.h"

// TODO: Initializes the state, setting the provided playing board and
//  sets the default values for player count, turn and finished.
/**
 * Pre:
 * Post:
 *
 * Initializes the state's attributes with the provided
 * and default values.
 *
 * @param state The state to be initialized.
 * @param board The playing board.
 */
void init_state(State* state, Board* board) {
    state->board = board;
    state->player_count = 0;
    state->turn = 0;
    state->finished = 0;
}
// TODO: Returns the player count.
/**
 * Pre:
 * Post:
 *
 * Returns the player count.
 *
 * @param state The state to be queried.
 * @return The player count.
 */
int get_player_count(State* state) {
    return state->player_count;
}

// TODO: Adds a player to the state by:
//  - Checking if it is possible.
//  - If it is, initializing the next available player.
//  - Incrementing the player count.
/**
 * Pre:
 * Post:
 *
 * Adds a player to the state
 *
 * @param state The state to be modified.
 * @param symbol The symbol of the new player.
 * @return SUCCESS if the player was added, ERROR otherwise.
 */
int add_player(State* state, char symbol) {
    return ERROR;
}

// TODO: Returns the corresponding player.
/**
 * Pre:
 * Post:
 *
 * Returns the corresponding player.
 *
 * @param state The state to be queried.
 * @param idx The index of the player.
 * @return The player at idx index.
 */
Player* get_player(State* state, int idx) {
    return NULL;
}

// TODO: Returns the current player, according to the turn.
/**
 * Pre:
 * Post:
 *
 * Returns the current player, according to the turn.
 *
 * @param state The state to be queried.
 * @return The player holding the turn.
 */
Player* get_current_player(State* state) {
    return NULL;
}

// TODO: Sets the finished flag to finished value (true or false).

/**
 * Pre:
 * Post:
 *
 * Sets the finished flag to finished value (true or false).
 *
 * @param state The state to be updated.
 * @param is_finished The value marking the game as finished or not.
 */
void set_finished(State* state, bool finished) {
}

// TODO: Returns the value of is_finished flag (true or false),
//  marking a game as finished.


/**
 * Pre:
 * Post:
 *
 * Returns the value of is_finished flag (true or false),
 * marking a game as finished.
 *
 * @param state The state to be updated.
 */
bool is_finished(State* state) {
    return true;
}

// TODO: Moves the current player a number of steps in the board, updating the state's current
//  position.
//  If the player ends up in an empty square, it just updates the player's current position and
//  advances the turn. But if they end up in a non-empty square, it applies the corresponding effect,
//  i. e. if the square is a goose, jumps to the next goose square, if any, and keeps the turn so the
//  player can throw the dice again.
//  Also, sets the state as finished if it moves to the last square exactly. If the final position is
//  beyond the final square, it bounces back.

/**
 * Pre:
 * Post:
 *
 * Moves the current player a number of steps in the board, updating the state's current
 * position.
 *
 * @param state The current state of the game.
 * @param dice_value The number of steps to move.
 * @param print_actions Flag to enable/disable printing messages.
 * @return ERROR if the move ends in an invalid state, SUCCESS otherwise.
 */
int move(State* state, int dice_value, bool print_actions) {
    return ERROR;
}
