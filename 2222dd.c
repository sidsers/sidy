#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 20 // width of the screen
#define BLOCK_WIDTH 3 // width of the block

int main()
{
    int block_pos = WIDTH / 2; // starting position of the block
    int input; // variable to hold user input

    srand(time(NULL)); // seed the random number generator

    while (1) // loop forever
    {
        // generate a random block position
        int block_row = rand() % 5;
        
        // print the screen
        system("cls"); // clear the screen
        for (int row = 0; row < 5; row++)
        {
            for (int col = 0; col < WIDTH; col++)
            {
                if (row == block_row && col >= block_pos && col < block_pos + BLOCK_WIDTH)
                    printf("#");
                else
                    printf(" ");
            }
            printf("\n");
        }
        
        // get user input
        input = getch(); // read a character from the keyboard
        
        // move the block left or right
        if (input == 'a')
        {
            block_pos--;
            if (block_pos < 0)
                block_pos = WIDTH - BLOCK_WIDTH;
        }
        else if (input == 'd')
        {
            block_pos++;
            if (block_pos + BLOCK_WIDTH > WIDTH)
                block_pos = 0;
        }
    }

    return 0;
}

