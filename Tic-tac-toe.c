//Game: Tic Tac Toe

#include <stdio.h>
#include <ctype.h>

int main()
{
int player = 0;   //current player 1 or 2
int winner = 0;   //Winning player number
int choice = 0;   //Chosen square
unsigned int row = 0;  //squares' row index
unsigned int column = 0;  //squares' column index
char indicator = 0;
do
{
char board[3][3] = {    //Playing board with digits 1-9 to identify the squares
{'1','2','3'},
{'4','5','6'},
{'7','8','9'}
};


//main game loop. The game continues for up to 9 turns if there is no winner

for(unsigned int i = 0; i < 9 && winner == 0; ++i)
{
//Display the board
printf("\n");
printf(" %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
printf("...+...+...\n");
printf(" %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
printf("...+...+...\n");
printf(" %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);

player = i % 2 + 1;   //Select player

// Get a valid player square selection
do
{
printf("Player %d, please enter your valid square number for where you want to place your %c:",
player, (player == 1)? 'x':'0');
scanf("%d", &choice);
choice -= 1;
row = choice / 3;
column = choice % 3;
}while(choice < 0 || choice > 8 || board[row][column] > '9');

//Insert player symbol
board[row][column] = (player == 1)? 'x':'0';

//Code to check for winner
//check for a winning line - diagonals first
if((board[0][0] == board[1][1] && board[0][0] == board[2][2]) ||
(board[0][2]==board[1][1] && board[0][2]==board[2][0]))

winner = player;
else
{
//Check rows and columns for a winning line
for(unsigned int line = 0; line <= 2; ++line)
{
if((board[line][0] == board[line][1] && board[line][0] == board[line][2])||
(board[0][line] == board[1][line] && board[0][line] == board[2][line]))

winner = player;
}
}
}
//Code to output the results
//Game is over so display the final board
printf("\n");
printf(" %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
printf("...+...+...\n");
printf(" %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
printf("...+...+...\n");
printf(" %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);

//Display result message
if(winner)
printf("\nCongratulations, player %d, YOU ARE THE WINNER!\n",winner);
else
printf("\nHow boring, its a draw\n");
printf("Do you wanna play again (y/n)?\n");
scanf(" %c", &indicator);

}while(tolower(indicator) == 'y');
printf("\nGoodbye\n");
return 0;
}
