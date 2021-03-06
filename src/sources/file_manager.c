#include <stdio.h>
#include <string.h>

#include "../headers/file_manager.h"

// TODO: Reads and loads the data line for the GOOSE by:
// - Reads each integer and checks it.
// - If valid, sets the square type to GOOSE
/**
 * Pre:
 * Post: Reads and loads the data line for the GOOSE type.
 *
 * @param board The board to be configured.
 * @param fd The opened board file.
 * @return INVALID_SQUARE_POSITION if a position is invalid, SUCCESS otherwise.
 */
int is_valid(Board* board, position, SquareType type) {
    if (position < get_size(board) - 1) {
        Square *square = get_square_at(board, position);
        set_type(square, type);
        return SUCCESS;
    }
    return INVALID_SQUARE_POSITION;
}
int read_goose_type(Board* board, FILE* fd) {
    int p1 = -1;
    char line[MAX_STRING];
    fgets(line, MAX_LOADING_BUFFER, fd);

    int match = 1;
    while(match == 1){
        match = sscanf(line, "%d", &p1);
        if(p1 > MAX_ROWS*MAX_COLUMNS || p1 < 0){
            return INVALID_SQUARE_POSITION;
        }
        is_valid(board, p1, GOOSE);
    }
    return SUCCESS;
}

// TODO: Reads and loads the data line for the DEATH type by:
// - Reads each integer and checks it. (More than one?)
// - If valid, sets the square type to DEATH
/**
 * Pre:
 * Post: Reads and loads the data line for the DEATH type.
 *
 * @param board The board to be configured.
 * @param fd The opened board file.
 * @return INVALID_SQUARE_POSITION if a position is invalid, SUCCESS otherwise.
 */
int read_death_type(Board* board, FILE* fd) {
    int p;
    fscanf(fd, "%d", &p);
    is_valid(board, p, DEATH);
}

// TODO: Reads the two lines that define all the squares of a type and treats them by:
//  - Reading the square type line and checking it.
//  - Depending on the type of squares, call the specific function to treat them (i. e. GOOSE -> read_goose_type)
/**
 * Pre:
 * Post: Reads the two lines that define all the squares of a type and treats them according to the type.
 *
 * @param board The board to be configured.
 * @param fd The opened board file.
 * @return The status of the action:
 *      - SUCCESS if the file was loaded successfully.
 *      - INVALID_SQUARE_LINE if an invalid square line is found (if the line could not be read, mainly).
 *      - INVALID_SQUARE_DATA if an invalid square data is found (if the data does not match the format).
 *      - INVALID_SQUARE_TYPE if an invalid square type is found.
 *      - INVALID_SQUARE_POSITION if an invalid square position is found.
 *      - INVALID_SQUARE_TYPE_DATA if invalid data for a type is found.
 */
int read_square_type(Board* board, FILE* fd) {
    char line[MAX_STRING];

    while (!feof(fd)) {
        fgets(line, MAX_LOADING_BUFFER, fd);

        if (line == "GOOSE") {
            read_goose_type(board, fd);
        } else if (line == "DEATH") {
            read_death_type(board, fd);
        } else {
            return INVALID_SQUARE_TYPE;
        }
    }
}

// TODO: Loads a board from a file configuration by:
//  - Reading and checking the dimensions line
//  - Reading each of the square lines and treating each one by calling to read_square_type
/**
 * Pre:
 * Post: Loads a board from a file configuration.
 *
 * @param board The board to be configured.
 * @param fd The opened board file.
 * @return The status of the action:
 *      - SUCCESS if the file was loaded successfully.
 *      - INVALID_BOARD_DIMENSIONS if the board dimensions are invalid (wrong format, invalid values, etc.)
 *      - INVALID_SQUARE_LINE if an invalid square line is found (if the line could not be read, mainly).
 *      - INVALID_SQUARE_DATA if an invalid square data is found (if the data does not match the format).
 *      - INVALID_SQUARE_TYPE if an invalid square type is found.
 *      - INVALID_SQUARE_POSITION if an invalid square position is found.
 *      - INVALID_SQUARE_TYPE_DATA if invalid data for a type is found.
 */
int load_board_file(Board* board, FILE* fd) {
    int rows;
    int cols;

    while (!feof(fd)) {
        int matches = fscanf(fd, "%dx%d", &rows, &cols);

        if (matches != 2) {
            return INVALID_BOARD_DIMENSIONS;
        }else if(rows > MAX_ROWS || rows < 0){
            return INVALID_SQUARE_POSITION;
        }else if(cols > MAX_COLUMNS || cols < 0){
            return INVALID_SQUARE_POSITION;
        }
        set_rows(board, rows);
        set_columns(board, cols);
        read_square_type(board, fd);
    }
    return SUCCESS;
}

// TODO: Loads a board stored into the file at the specified path by:
//  - Opening the file in the path and checking it.
//  - If opened properly, tries to read the board configuration from it by calling load_board_file.

/**
 * Pre:
 * Post: Loads a board stored into the file at the specified path.
 *
 * @param board The board to be initialized with the contents of the file in path.
 * @param path The path to the file containing a board configuration encoded as a text file.
 * @return The status of the load action, SUCCESS if the action was completed successfully,
 * other specific error code otherwise.
 */
int load_board(Board* board, char* path) {
    FILE* file = fopen(path, "r");

    if (file != NULL) {
        load_board_file(board, file);
        return SUCCESS;
    }

    return FILE_NOT_FOUND;
}
