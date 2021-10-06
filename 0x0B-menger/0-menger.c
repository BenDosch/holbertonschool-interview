#include "menger.h"

/**
 * menger - A function that draws a 2D Menger Sponge.
 * 
 * @level: The level of the Menger Sponge to draw.
 */

void menger(int level){
	int hash, row, col, lvl, side_len = pow(3, level);

	if (level >= 0)
	    for (row = 0; row < side_len; ++row)
	    {
	    	for (col = 0; col < side_len; ++col)
	    	{
	    		hash = 1;
	    		for (lvl = 0; lvl < level; ++lvl)
	    			if ((row / (int)pow(3, lvl)) % 3 == 1 &&
                        (col / (int)pow(3, lvl)) % 3 == 1)
	    				hash = 0;
	    		if (hash)
	    			printf("#");
	    		else
	    			printf(" ");
	    	}
	    	printf("\n");
	    }
}