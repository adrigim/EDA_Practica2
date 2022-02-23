#ifndef PLAYER_H
#define PLAYER_H

typedef struct {
    char symbol;
    int current_position;
} Player;

void init_player(Player* player, char symbol);

char get_symbol(Player* player);

int get_current_position(Player* state);
void set_current_position(Player* state, int position);

int get_blocked_turns(Player* state);
void set_blocked_turns(Player* state, int turns);

#endif //PLAYER_H
