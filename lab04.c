#include "lab04.h"
#include <stdio.h>

/**
 * @brief Initialize the board with inputs.
 * Empty positions will be represented by hyphens.
 * 
 * @param board 
 * @param positions 
 */
void init_board(board_t board, char **argv) {
    int k = 0;
    for (int i = 0; i < BOARD_SZ; i++) {
        for (int j = 0; j < BOARD_SZ; j++) {
            board[i][j] = argv[k][0];
            k++;
        }
    }
}

void print_board(board_t board)
{
    for (int x = 0; x < BOARD_SZ; x++)
    {
        for (int o = 0; o < BOARD_SZ; o++)
        {
            printf("%c", board[x][o]);
            if (o < 2)
                printf(" | ");
        }
        printf("\n");
        if (x < 2)
            printf("---+---+---\n");
    }
}

int check_board(board_t board)
{
    // This loop checks each row, column, or diaganol for a win
    for (int x = 0; x < BOARD_SZ; x++)
    {
        // Check a column
        if (board[x][0] == board[x][1] && board[x][1] == board[x][2])
        {
            if (board[x][0] == 'X')
            {
                return 1; // X wins
            }
            else if (board[x][0] == 'O')
            {
                return -1; // O wins
            }
        }

        // Check a row
                if (board[0][x] == board[1][x] && board[1][x] == board[2][x])
                {
                    if (board[0][x] == 'X')
                    {
                        return 1; // X wins
                    }
                    else if (board[0][x] == 'O')
                    {
                        return -1; // O wins
                    }
                }
            }

            if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
                    (board[0][2] == board[1][1] && board[1][1] == board[2][0]))
                {
                    if (board[1][1] == 'X')
                    {
                        return 1; // X wins
                    }
                    else if (board[1][1] == 'O')
                    {
                        return -1; // O wins
                    }
                }

                // Game is ongoing if there is no definite result [win or draw]
                    for (int x = 0; x < BOARD_SZ; x++)
                    {
                        for (int o = 0; o < BOARD_SZ; o++)
                        {
                            if (board[x][o] == '-')
                            {
                                return 2; // Game is ongoing
                            }
                        }
                    }
                
                    return 0; // It's a draw
                }
                
