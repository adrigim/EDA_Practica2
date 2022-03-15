#include "../headers/player.h"

/**
 * Pre:
 * Post: Initializes the player's attributes with the provided and default values.
 *
 * @param player The player to be initialized.
 * @param symbol The symbol representing the player.
 */
void init_player(Player* player, char symbol) {
    set_current_position(player, 0);
    player->symbol = symbol;
    player->prison = 0;
}

/**
 * Pre:
 * Post: Returns the symbol associated with the player.
 *
 * @param player The player from which the symbol is required.
 * @return The symbol representing the player.
 */
char get_symbol(Player* player) {
    return player->symbol;
}

/**
 * Pre:
 * Post: Sets the current position.
 *
 * @param player The player to be updated.
 * @param position The current position.
 */
void set_current_position(Player* player, int position) {
    player->current_position = position;
}

/**
 * Pre:
 * Post: Retrieves the current position.
 *
 * @param player The player that stores the current position.
 * @return The current position.
 */
int get_current_position(Player* player) {
    return player->current_position;
}
