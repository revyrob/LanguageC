/* COMP 2131
   Kayle Robson
   Winter 2022
   Tic Tac Toe game in C Language*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

/* constants */
char board[3][3]; // constant for our 2 dimensional board
const char PLAYER = 'X';
const char COMPUTER = 'Y';

// give all functions
void userName();
void resetBoard();
void printBoard();
int checkFreeSpaces();
void playerMove();
char checkWinner();
void computerMove();
void printWinner(char);

int main()
{
    char winner = ' ';
    char response;

    do
    {
        // Intro
        printf("*****************************************\n");
        printf("Tic Tac Toe\n");
        printf("COMP 2131 - Winter 2022\n");
        printf("You will be play against the computer.\n");
        printf("*****************************************\n");
        printf("\n");

        // reset variables
        winner = ' ';
        response = ' ';

        resetBoard();
        userName();

        // while there is no winner and no free spaces the while loop continues
        while (winner == ' ' && checkFreeSpaces() != 0)
        {
            printBoard();

            // player moves
            playerMove();
            winner = checkWinner();
            if (winner != ' ' || checkFreeSpaces() == 0)
            {
                break;
            }

            // computer moves
            computerMove();
            winner = checkWinner();
            if (winner != ' ' || checkFreeSpaces() == 0)
            {
                break;
            }
        }
        printBoard();
        // out of the wild loop and there is a winner
        // announce winner
        printWinner(winner);

        // play again, I tried to make this a function but I had
        // trouble doing so and decided to leave it in the main
        printf("\nWould you like to play again? ('Y' for yes, 'N' for no)\n");
        scanf("%s", &response);
        response = toupper(response); // change to upper case incase the user puts lowercase

    } while (response == 'Y');

    // out of loop since the user responded no or not 'Y'
    printf("Thanks for playing!");
    return 0;
}

void userName()
{
    char name[10]; // up to 10 characters no space for name
    printf("What is your first name (no spaces and less than 10 characters)? \n");
    scanf("%s", name);
    printf("Hello %s ... Let's have fun!!! You = X | Computer = Y\n", name);
}

void resetBoard()
{
    for (int i = 0; i < 3; i++) /* for the columns to reset*/
    {
        for (int j = 0; j < 3; j++) /* for the rows to reset */
        {
            board[i][j] = ' ';
        }
    }
}

void printBoard()
{
    printf("\n");
    printf(" %c | %c | %c ", board[0][0], board[0][1], board[0][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", board[1][0], board[1][1], board[1][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}

int checkFreeSpaces()
{
    int freeSpaces = 9;
    for (int i = 0; i < 3; i++) /*itereates over rows*/
    {
        for (int j = 0; j < 3; j++) /*itereates over columns*/
        {
            if (board[i][j] != ' ')
            {
                freeSpaces--;
            }
        }
    }
    return freeSpaces;
}

void playerMove()
{
    int x; /* rows */
    int y; /* columns */

    do
    {
        printf("\nEnter X, Y coordinates (between 1-3) for your move: \n");
        scanf("%d, %d", &x, &y);
        x--;
        y--;

        if (x > 3 || y > 3)
        {
            printf("Your entry is invalid please choose between 1 and 3 for X and Y coordinates.\n");
        }
        else if (x < 0 || y < 0)
        {
            printf("Your entry is invalid please choose between 1 and 3 for X and Y coordinates.\n");
        }
        else if (board[y][x] != ' ')
        {
            printf("Invalid move\n");
        }
        else
        {
            board[y][x] = PLAYER; /* y and x are flipped since the user enters in columns and rows
            and this program writes rows and columns */
            break;
        }
    } while (board[y][x] != ' ');
}

void computerMove()
{
    // need a seed
    srand(time(0));
    int x;
    int y;

    if (checkFreeSpaces() > 0)
    {
        do
        {
            x = rand() % 3;
            y = rand() % 3;
        } while (board[x][y] != ' ');

        board[x][y] = COMPUTER;
    }
    else
    {
        printWinner(' ');
    }
}

char checkWinner()
{
    // check rows
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2])
        {
            return board[i][0];
        }
    }
    // check columns
    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] == board[1][i] && board[0][i] == board[2][i])
        {
            return board[0][i];
        }
    }
    // check diagnols
    for (int i = 0; i < 3; i++)
    {
        if (board[0][0] == board[1][1] && board[0][0] == board[2][2])
        {
            return board[0][0];
        }
        if (board[2][0] == board[1][1] && board[2][0] == board[0][2])
        {
            return board[2][0];
        }
    }
    return ' ';
}

void printWinner(char winner)
{
    if (winner == PLAYER)
    {
        printf("\n********\n");
        printf("YOU WIN!\n");
        printf("********\n");
    }
    else if (winner == COMPUTER)
    {
        printf("\n********\n");
        printf("YOU LOSE!\n");
        printf("********\n");
    }
    else
    {
        printf("\n********\n");
        printf("It is a tie!\n");
        printf("********\n");
    }
}
