#include <stdio.h>

int main() {
    char grid[9] = {'1','2','3','4','5','6','7','8','9'};
    int currentPlayer = 1;
    char symbol;
    int position;
    int gameActive = 1;

    while (gameActive) {
        printf("\n");
        printf(" %c | %c | %c \n", grid[0], grid[1], grid[2]);
        printf("---+---+---\n");
        printf(" %c | %c | %c \n", grid[3], grid[4], grid[5]);
        printf("---+---+---\n");
        printf(" %c | %c | %c \n", grid[6], grid[7], grid[8]);
        printf("\n");

        if (currentPlayer == 1)
            symbol = 'X';
        else
            symbol = 'O';

        printf("Player %d (%c), enter a position on the board: ", currentPlayer, symbol);
        scanf("%d", &position);

        if (position >= 1 && position <= 9) {
            grid[position-1] = symbol;
        } else {
            printf("Invalid move\n");
            continue;
        }

        int winner = 0;

        if (grid[0] == grid[1] && grid[1] == grid[2])
            winner = 1;
        else if (grid[3] == grid[4] && grid[4] == grid[5])
            winner = 1;
        else if (grid[6] == grid[7] && grid[7] == grid[8])
            winner = 1;
        else if (grid[0] == grid[3] && grid[3] == grid[6])
            winner = 1;
        else if (grid[1] == grid[4] && grid[4] == grid[7])
            winner = 1;
        else if (grid[2] == grid[5] && grid[5] == grid[8])
            winner = 1;

        if (winner) {
            printf("\n");
            printf(" %c | %c | %c \n", grid[0], grid[1], grid[2]);
            printf("---+---+---\n");
            printf(" %c | %c | %c \n", grid[3], grid[4], grid[5]);
            printf("---+---+---\n");
            printf(" %c | %c | %c \n", grid[6], grid[7], grid[8]);
            printf("\n");
            printf("Player %d wins the game and isn't a loser\n", currentPlayer);
            gameActive = 0;
        } else {
            int tie = 1;
            for (int i = 0; i < 9; i++) {
                if (grid[i] >= '1' && grid[i] <= '9') {
                    tie = 0;
                    break;
                }
            }
            if (tie) {
                printf("\nIt's a tie, you both suck!!!\n");
                gameActive = 0;
            } else {
                if (currentPlayer == 1)
                    currentPlayer = 2;
                else
                    currentPlayer = 1;
            }
        }
    }

    return 0;
}
