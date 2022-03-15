#include <stdio.h>
#include "../headers/state.h"

/**
 * Pre:
 * Post: Initializes the state's attributes with the provided
 * and default values.
 *
 * @param state The state to be initialized.
 * @param board The playing board.
 */
void init_state(State* state, Board* board) {
    state->board = board;
    state->player_count = 0;
    state->turn = 0;
    set_finished(state,0);
}

/**
 * Pre:
 * Post: Returns the player count.
 *
 * @param state The state to be queried.
 * @return The player count.
 */
int get_player_count(State* state) {
    return state->player_count;
}

/**
 * Pre:
 * Post: Adds a player to the state
 *
 * @param state The state to be modified.
 * @param symbol The symbol of the new player.
 * @return SUCCESS if the player was added, ERROR otherwise.
 */
int add_player(State* state, char symbol) {
    int n = get_player_count(state);

    if (n < MAX_PLAYERS) {
        init_player(get_player(state, n), symbol);
        state->player_count++;
        return SUCCESS;
    }
    return ERROR;
}

/**
 * Pre:
 * Post: Returns the corresponding player.
 *
 * @param state The state to be queried.
 * @param idx The index of the player.
 * @return The player at idx index.
 */
Player* get_player(State* state, int idx) {
    return &state->players[idx];
}

/**
 * Pre:
 * Post: Returns the current player, according to the turn.
 *
 * @param state The state to be queried.
 * @return The player holding the turn.
 */
Player* get_current_player(State* state) {
    int i = state->turn;
    i = i % state->player_count;
    return &state->players[i];
}

/**
 * Pre:
 * Post: Sets the finished flag to finished value (true or false).
 *
 * @param state The state to be updated.
 * @param is_finished The value marking the game as finished or not.
 */
void set_finished(State* state, bool finished) {
        state->finished = finished;
}

/**
 * Pre:
 * Post: Returns the value of is_finished flag (true or false), marking a game as finished.
 *
 * @param state The state to be updated.
 */
bool is_finished(State* state) {
    if (state->finished == true) {
        return true;
    }

    return false;
}

/**
 * Pre:
 * Post: Moves the current player a number of steps in the board, updating the state's current position.
 *
 * @param state The current state of the game.
 * @param dice_value The number of steps to move.
 * @param print_actions Flag to enable/disable printing messages.
 * @return ERROR if the move ends in an invalid state, SUCCESS otherwise.
 */
int move(State* state, int dice_value, bool print_actions) {
    Player* player = get_current_player(state);
    int new_position = get_current_position(player) + dice_value;
    int final_square = get_size(state->board) - 1;

    if (new_position < final_square) {
        set_current_position(player, get_current_position(player) + dice_value);
    } else if (new_position > final_square) {
        int back = dice_value - (final_square - get_current_position(player));
        set_current_position(player, final_square - back);
    } else {
        set_current_position(player, get_current_position(player) + dice_value);
        set_finished(state, true);
        return SUCCESS;
    }

    Square* square = get_square_at(state->board, player->current_position);

    if (get_type(square) == GOOSE) {
        set_current_position(player, find_next_position(state, player, GOOSE));
        return SUCCESS;
    } else if (get_type(square) == DEATH) {
        set_current_position(player, 0);
    }

    state->turn++;
    return SUCCESS;
}

int find_next_position(State* state, Player* player, SquareType type) {
    int i = find_square_by_type(state->board, type, player->current_position, false);

    if (i == -1){
    i = find_square_by_type(state->board, type, player->current_position, true);
    }

    return i;
}