#include "slide_line.h"

/**
 * slide_line: Function that slides and merges an array of integers.
 * 
 * @line: Pointer to an array of integers.
 * @size: Number of elements in the array pointed to by line.
 * @direction: Direction to slide and merge, either SLIDE_Left or SLIDE_RIGHT.
 * 
 * return: 1 on sucess or 0 on failure. 
 */

int slide_line(int *line, size_t size, int direction){

    if (line){
        if (direction == SLIDE_RIGHT){
            return (slide_right(line, size));
        }
        else if (direction == SLIDE_LEFT){
            return (slide_right(line, size));
        }
    }
    return (0);
}

/**
 * slide_right - Slides the array to the right.
 *
 * @line: Pointer to an array of integers.
 * @size: Number of elements in the array pointed to by line.
 * @direction: Direction to slide and merge, either SLIDE_Left or SLIDE_RIGHT.
 * 
 * returns: 1 on success.
 */

int slide_right(int *line, size_t size){
    size_t final_index = size - 1, i, j;

    for (i = final_index; i > 0; i--){
        j = i - 1;
        while (!line[j])
            j--;
        if (!line[i]){
            line[i] = line[j];
            line[j] = 0;
            i++;
        }
        else if (line[i]){
            if (line[i] == line[j]){
                line[i] *= 2;
                line[j] = 0;
            }
            else
                line[i - 1] = line[j];
        }
        else
            break;
    }
    return (1);
}

/**
 * slide_left - Slides the array to the left.
 *
 * @line: Pointer to an array of integers.
 * @size: Number of elements in the array pointed to by line.
 * @direction: Direction to slide and merge, either SLIDE_Left or SLIDE_RIGHT.
 * 
 * returns: 1 on success.
 */

int slide_left(int *line, size_t size){
    size_t final_index = size - 1, i, j;

    for (i = 0; i < final_index; i++){
        j = i + 1;
        while (!line[j] && j <= final_index)
            j++;
        if (j > final_index)
            break;
        if (!line[i]){
            line[i] = line[j];
            line[j] = 0;
            i--;
        }
        else if (line[i]){
            if (line[i] == line[j]){
                line[i] *= 2;
                line[j] = 0;
            }
            else
                line[i + 1] = line[j];
        }
        else
            break;
    }
    return (1);
}