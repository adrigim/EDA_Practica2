#ifndef SQUARE_H
#define SQUARE_H

#include "common.h"

// TODO: Create the struct and add the corresponding attributes.

enum square_type {
    EMPTY,
    GOOSE,
    BRIDGE,
    PRISON,
    DEATH,
};
typedef enum square_type SquareType;

typedef struct {
    int position;
    SquareType type;
} Square;

void init_square(Square* square, int position);

int get_position(Square* square);

SquareType get_type(Square* square);
void set_type(Square* square, SquareType type);

#endif //SQUARE_H
