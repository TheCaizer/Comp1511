// Assignment 1 19T3 COMP1511: CS Paint
// paint.c
//
// This program was written by Jackie Cai (z5259449)
// on 9/10/2019
//
// Version 1.0.0 (2019-10-08): Assignment released.

/* USEFUL INFORMATION
This program makes a canvas for the user to draw on, that the user can give
commands to draw shapes and lines as well as changing the color.
This program can draw straight, diagonal, squares, copy and paste colors. 
STAGE 1,2 and half of stage 3 has been complete the only problems are stage 4
and drawing ellipse would be the limitation of this code as stage 3 copy paste 
works and has been tested.
There won't be any functions in this code other than from the ellipse as I
started the assignment before learning it. Attempted to convert code to
functions but failed to do so
*/

#include <stdio.h>

// Note: you may find the square root function (sqrt) from the math
// library useful for drawing ellipses in Stage 3 and Stage 4.
#include <math.h>

// The dimensions of the canvas (20 rows x 36 columns).
#define N_ROWS 20
#define N_COLS 36

// Shades (assuming your terminal has a black background).
#define BLACK 0
#define DARK 1
#define GREY 2
#define LIGHT 3
#define WHITE 4

// IF YOU NEED MORE #defines ADD THEM HERE


// Provided helper functions:
// Display the canvas.
void displayCanvas(int canvas[N_ROWS][N_COLS]);

// Clear the canvas by setting every pixel to be white.
void clearCanvas(int canvas[N_ROWS][N_COLS]);

// Calculate the distance between two points.
// Note: you will only need this function for the Draw Ellipse command
// in Stages 3 and 4.
double distance(int row1, int col1, int row2, int col2);


// ADD PROTOTYPES FOR YOUR FUNCTIONS HERE


int main(void) {
    int canvas[N_ROWS][N_COLS];

    clearCanvas(canvas);
//SHADE of color variables
    int SHADE = 0;
//default SHADE BLACK = 0
    int new_shade;
//line and square variables
    int instruction;
    int start_row;
    int start_col;
    int length;
    int direction;
//made new varible col so col value can be changed without changing start_col
//Do the same for row and start_row or else infinite loop with inequality
    int col = 0;
    int row = 0;
//start target col and row for copy paste 
    int st_col;
    int st_row;
    int target_row;
    int target_col;
//ellipse variables
    int focus1_row;
    int focus1_col;
    int focus2_row;
    int focus2_col;
    int fill;
    double e_length;

//added the variables needed for the scans and other variables that are needed
//such as col and row allows movement in the canvas to draw
    while (scanf("%d",&instruction) == 1){
//add a while loop to keep scanning or until CTRL + D is pressed
        if (instruction == 1){
//start with the instuctions checks it
            scanf ("%d %d %d %d" ,&start_row ,&start_col ,&length,&direction);
//then scan for the other variables
            if (start_col >= 0 && start_col <= 35 && start_row >=0 
            && start_row <= 19){
//checks the pixel to be inside the array for invalid inputs
                if (length < 0){
                    length = length * (-1);
//handles negative distance by making it positive to compute and goes in the
//negative direction (180 degrees)
                    direction = direction + 180;
                }
                col = start_col;
                row = start_row;
                if (direction >= 360){
                    direction = direction % 360;
//If direction is greater than 360 it changes it back to valid direction
                }
                if (direction%90 == 0){
//start with direction to determine the way the color moves make sure
//divisible by 90
                    if (direction == 90 && start_col + length <= 36){
//when the direction is 90 it draws to the right meaning colum increases and
//checks if the line is out of bounds as it only increase right
                        while (col < (start_col + length)){
//the equation draws the right length (tested)
                            canvas[start_row][col] = SHADE;
                            col++;
//add to start row until it is equal to length plus the start row to get length
// since increasing to right would only increse column
                        }
                    }
                    if (direction == 180 && start_row + length <= 20){
//Do the same for 180 degree but row increases instead and check bounds
                        while (row < (start_row + length)){
                            canvas[row][start_col] = SHADE;
                            row++;
                        }
                    }
                    if (direction == 0 && start_row - length >= -1){
//Now do the negatives direction so 0 makes row go up
                        while (row > start_row - length){
                            canvas[row][start_col] = SHADE;
                            row--;
                        }
                    }
                    if (direction == 270 && start_col - length >= -1){
//do the same for the negative direction of columns
                        while (col > start_col - length){
                            canvas[start_row][col] = SHADE;
                            col--;
                        }
                    }
                }
                else if (direction % 45 == 0){
// checks for direction of 90 then 45 to draw diagonals same as instruction 2
//make a new variable that identifies when its diagonal as the diagonal is only
//the difference between row and col are equal to diagonal variable
                    if (direction == 135 && start_col + length <= 36 && 
                    start_row + length <= 20){
//same as line but has to check for both row and column
                        int diagonal = start_row - start_col;
                        while (row < start_row + length){
                            while (col < start_col + length){
                                if (row - col == diagonal){
//now this loop checks if the diagonal variable is equal to the row and col
//difference which then draws a diagonal line
                                    canvas[row][col] = SHADE;
                                }
                                col++;
                            }
                            row++;
                            col = start_col + 1;
                            col = start_col;
                        }
                    }
                    else if (direction == 315 && start_row - length >= -1 && 
                    start_col - length >= -1){
//greater than equal to -1 since size of grid is 0 to N_ROWN_COL - 1 meaning
//the col minus length can potentially be -1 which is the 0th location
//same as the first diagonal but change signs for direction and check bounds
//do the same for all directions
                        int diagonal = start_col - start_row;
                        while (row > start_row - length){
                            while (col > start_col - length){
                                if (col - row == diagonal){
                                    canvas[row][col] = SHADE;
                                }
                                col--;
                            }
                            row--;
                            col = start_col - 1;
                            col = start_col;
                        }
                    }
                    else if (direction == 45 && start_col <= 36 && 
                    start_row >= 0){
                        int diagonal = start_row + start_col;
                        while (row > start_row - length){
                            while (col < start_col + length){
                                if (row + col == diagonal){
                                    canvas[row][col] = SHADE;
                                }
                                col++;
                            }
                            row--;
                            col = start_col + 1;
                            col = start_col;
                        }
                    }
                    else if (direction == 225 && start_col >= 0 && 
                    start_row <= 20){
                        int diagonal = start_row + start_col;
                        while (row < start_row + length){
                            while (col > start_col - length){
                                if (row + col == diagonal){
                                    canvas[row][col] = SHADE;
                                }
                                col--;
                            }
                            row++;
                            col = start_col - 1;
                            col = start_col;
                        }
                    }
                }
            }
        }
        if (instruction == 2){
            scanf("%d %d %d %d" ,&start_row ,&start_col ,&length,&direction);
            if (start_col >= 0 && start_col <= 35 && start_row >=0 && 
            start_row <= 19){
//same as instruction 1
                if (length < 0){
                    length = length * (-1);
//handles negative distance by making it positive to compute and goes in the
//negative direction (180 degrees)
                    direction = direction + 180;
                }
                col = start_col;
                row = start_row;
                if (direction >= 360){
//same as insturction one 
                    direction = direction % 360;
                }
//copy pasted the same code from instuction 1 as the horizontal and vertical
//draw line is the same refer to instruction 1 to look for comments
                if (direction%90 == 0){
                    if (direction >= 360){
                        direction = direction % 360;
                    }
                    if (direction == 90 && start_col + length <= 36){
                        while (col < (start_col + length)){
                            canvas[start_row][col] = SHADE;
                            col++;
                        }
                    }
                    if (direction == 180 && start_row + length <= 20){
                        while (row < (start_row + length)){
                            canvas[row][start_col] = SHADE;
                            row++;
                        }
                    }
                    if (direction == 0 && start_row - length >= -1){
                        while (row > start_row - length){
                            canvas[row][start_col] = SHADE;
                            row--;
                        }
                    }
                    if (direction == 270 && start_col - length >= -1){
                        while (col > start_col - length){
                            canvas[start_row][col] = SHADE;
                            col--;
                        }
                    }
                }
                else if (direction%45 == 0){
//same as the instruction 1 instead 45 for the different degrees now and the 
//same for starting row and columns
                    if (direction == 135 && start_col + length <= 36 && 
                    start_row + length <= 20){
//checking bounds and direction, do the same for all direction/bounds
                        while (row < start_row + length){
                            while (col < start_col + length){
                                canvas[row][col] = SHADE;
                                col++;
                            }
//loops so it draws a line up and then after it reaches the length given,
//it moves to the next column and loops until the length of both sides are
//equal to make a square
                            row++;
                            col = start_col + 1;
                            col = start_col;
                        }
                    }
//copy paste the same code but change the signs around to match direction given
                    else if (direction == 315 && start_row - length >= -1 && 
                    start_col - length >= -1){
                        while (row > start_row - length){
                            while (col > start_col - length){
                                canvas[row][col] = SHADE;
                                col--;
                            }
                            row--;
                            col = start_col - 1;
                            col = start_col;
                        }
                    }
                    else if (direction == 225 && start_col - length >= -1 && 
                    start_row + length <= 20){
                        while (row < start_row + length){
                            while (col > start_col - length){
                                canvas[row][col] = SHADE;
                                col--;
                            }
                            row++;
                            col = start_col - 1;
                            col = start_col;
                        }
                    }
                    else if (direction == 45 && start_col + length <= 36 
                    && start_row - length >= -1){
                        while (row > start_row - length){
                            while (col < start_col + length){
                                canvas[row][col] = SHADE;
                                col++;
                            }
                            row--;
                            col = start_col + 1;
                            col = start_col;
                        }
                    }
                }
            }
        }
        if (instruction == 3){
//changed the scanf function at the start to only scan insturction first then
//when instruction are found it runs and finds other varible to run the function
//made new variable shade for color variable and new_shade that applys changes
            scanf("%d",&new_shade);
            if (SHADE + new_shade >= 0 && SHADE + new_shade <= 4){
//the if statement is there to check if the shade if valid to change color if
//its between 0 and 4 (valid) if not it is ignored
                SHADE = SHADE + new_shade;
            }
        }
        if (instruction == 4){
            scanf("%d %d %d %d %d %d",&start_row ,&start_col ,&length 
            ,&direction ,&target_row ,&target_col);
//new variables targets added and then same as other insturction checks bounds
            if (start_col >= 0 && start_col <= 35 && start_row >=0 && 
            start_row <= 19){
                if (length < 0){
                    length = length * (-1);
                    direction = direction + 180;
                }
                col = start_col;
                st_col = target_col;
                row = start_row;
                st_row = target_row;
                if (direction >= 360){
                    direction = direction % 360;
                }
                if (direction % 90 == 0){
//for striaght line copy as the hint said it may be given 90 degrees etc.
                    if (direction == 90 && start_col + length <= 36 && 
                    target_col + length <= 36){
//draw line but instead of drawing copying the shade given through target
                        while (target_col < st_col + length){
                            canvas[target_row][target_col] = canvas[row][col];
                            target_col++;
                            col++;
                        }
                    }
                    if (direction == 0 && start_row - length >= -1 && target_row
                    - length >= -1){
//copy paste the first command but change the signs
                        while (target_row > st_row - length){
                            canvas[target_row][target_col] = canvas[row][col];
                            target_row--;
                            row--;
                        }
                    }
                    if (direction == 270 && start_col - length >= -1 
                    && target_col - length >= -1){
                        while (target_col > st_col - length){
                            canvas[target_row][target_col] = canvas[row][col];
                            target_col--;
                            col--;
                        }
                    }
                    if (direction == 180 && start_row + length <= 20 && 
                    target_row + length <= 20){
                        while (target_row < st_row + length){
                            canvas[target_row][target_col] = canvas[row][col];
                            target_row++;
                            row++;
                        }
                    }
                }
                else if (direction % 45 == 0){
//start with 135 degree since it positive in row and column (easier)
                    if (direction == 135  && start_col + length <= 36 && 
                    start_row + length <= 20){
                        if (target_row + length <= 20 
                        && target_col + length <= 36){
//checking for bounds for both start pixel and the target pixel 
                            while (target_row < st_row + length){
//should be same condition as the size of both square are the same
//this part is just drawing a square from a square 
                                while (target_col < st_col + length){
                                    canvas[target_row][target_col] = 
                                    canvas[row][col];
//make the target row and col equal to shade of row and col to copy
                                    target_col++;
                                    col++;
                                }
                                row++;
                                target_row++;
                                col = start_col + 1;
                                col = start_col;
                                target_col = st_col + 1;
                                target_col = st_col;
//just did the same as draw square but added in the targets to move the square
                            }
                        }
                    }
                    if (direction == 45 && start_col + length <= 36 && 
                    start_row - length >= -1){
//copy paste the first direction that works then change the signs to suit the 
//direction given to us
                        if (target_row - length >= -1 
                        && target_col + length <= 36){
                            while (target_row > st_row - length){
                                while (target_col < st_col + length){
                                    canvas[target_row][target_col] = 
                                    canvas[row][col];
                                    target_col++;
                                    col++;
/* Idea for overlay is when the target row is withing the start row + length 
puth the the start row + length into an array[] and then copy it in example:
                            if (target_row <= start_row + length || target_col <=
                            start_col + length){
                                int array[20][36];
                                while (row <= start_row + length){
                                    while (col <= start_col + length){
                                        array[row][col]= canvas[row][col];
                                        col++;
                                    }
                                    row++
                                    col = start_col + 1;
then copy the array into canvas[target_row][target_col] (attempt)
                                }
                            }
*/
                                }
                                row--;
                                target_row--;
                                col = start_col + 1;
                                col = start_col;
                                target_col = st_col + 1;
                                target_col = st_col;
                            }
                        }
                    }
                    if (direction == 225  && start_col - length >= -1 && 
                    start_row + length <= 20){
                        if (target_row + length <= 20 
                        && target_col - length >= -1){
                            while (target_row < st_row + length){
                                while (target_col > st_col - length){
                                    canvas[target_row][target_col] = 
                                    canvas[row][col];
                                    target_col--;
                                    col--;
                                }
                                row++;
                                target_row++;
                                col = start_col - 1;
                                col = start_col;
                                target_col = st_col - 1;
                                target_col = st_col;
                            }
                        }
                    }
                    if (direction == 315  && start_col - length >= -1 && 
                    start_row - length >= -1){
                        if (target_row - length >= -1 
                        && target_col - length >= -1){
                            while (target_row > st_row - length){
                                while (target_col > st_col - length){
                                    canvas[target_row][target_col] = 
                                    canvas[row][col];
                                    target_col--;
                                    col--;
                                }
                                row--;
                                target_row--;
                                col = start_col - 1;
                                col = start_col;
                                target_col = st_col - 1;
                                target_col = st_col;
                            }
                        }
                    }
                }
            }
        }
//Was unable to solve how to draw an ellipse function
        if (instruction == 0){
            scanf("%d %d %d %d %lf %d",&focus1_row ,&focus1_col ,&focus2_row 
            ,&focus2_col ,&e_length ,&fill);
//scan the values
            row = focus1_row;
            col = focus1_col;
            double distance1 = distance(focus1_row, focus1_col
            , focus1_row - e_length ,focus1_row - e_length);
            double distance2 = distance(focus2_row + e_length, 
            focus2_row + e_length, focus2_row,focus2_col);
//finding the distance from the focus to the pixel 
            if (fill != 0){
                while (distance1 + distance2 <= 2 * e_length){
//formula given to color in the pixel of the ellipse
                    canvas[row][col] = SHADE;
                    row++;
                }
            }
            if (fill == 0){
//This part would be to do Stage 4 hollow ellipse
                while (distance1 + distance2 <= 2 * e_length){
                    if (row == distance1 + distance2){
//would only print at pixel which is at the edge (attempt)
                        canvas[row][col] = SHADE;
                        row++;
                    }
                }
            }
        }
    }
    displayCanvas(canvas);
    return 0;
}

// ADD CODE FOR YOUR FUNCTIONS HERE



// Displays the canvas, by printing the integer value stored in
// each element of the 2-dimensional canvas array.
//
// You should not need to change the displayCanvas function.
void displayCanvas(int canvas[N_ROWS][N_COLS]) {
    int row = 0;
    while (row < N_ROWS) {
        int col = 0;
        while (col < N_COLS) {
            printf("%d ", canvas[row][col]);
            col++;
        }
        row++;
        printf("\n");
    }
}


// Sets the entire canvas to be blank, by setting each element in the
// 2-dimensional canvas array to be WHITE (which is #defined at the top
// of the file).
//
// You should not need to change the clearCanvas function.
void clearCanvas(int canvas[N_ROWS][N_COLS]) {
    int row = 0;
    while (row < N_ROWS) {
        int col = 0;
        while (col < N_COLS) {
            canvas[row][col] = WHITE;
            col++;
        }
        row++;
    }
}

// Calculate the distance between two points (row1, col1) and (row2, col2).
// Note: you will only need this function for the Draw Ellipse command
// in Stages 3 and 4.
double distance(int row1, int col1, int row2, int col2) {
    int row_dist = row2 - row1;
    int col_dist = col2 - col1;
    return sqrt((row_dist * row_dist) + (col_dist * col_dist));
}
