// An introduction to malloc() and free()

#include <stdlib.h>		// Libraries which may be needed
#include <stdio.h>

//------------------------------------------------------------------------------
// ** Code starts here **

int
main (int argc, char *argv[])	// The 'root' programme; execution start
{
char *pString;			// Create a pointer to a character
				// (... or, later a -string- of characters.)

pString = malloc(10);		// Get 10 bytes of memory
pString[0] = 'H';
pString[1] = 'e';
pString[2] = 'l';
pString[3] = 'l';
pString[4] = 'o';
pString[5] = '\0';		// Remember a string terminator



printf("before free %04X\n", &pString);	// Print the string + a line-feed
printf("%s\n", pString);	// Print the string + a line-feed
free(pString);			// Give the memory back


printf("after free %04X\n", &pString);	// Print the string + a line-feed
printf("%s\n", pString);	// Print the string + a line-feed

 exit(0);			// ... and relax.

}

//==============================================================================
