//------------------------------------------------------------------------------
// A simplified demonstration of signal handling; part 2

#include <stdlib.h>			// Libraries which may be needed
#include <stdio.h>
#include <signal.h>

struct sigaction sigaction_structure;	// A data structure, filled in below

void escape();				// Declaration only - definition below

//------------------------------------------------------------------------------

long int num1, num2;				// Two global variables
// (Even long ints might 'wrap around' here.)

//------------------------------------------------------------------------------

int main (int argc, char *argv[])		// Start here
{

  // Set three fields in a predefined 'struct'
  sigaction_structure.sa_handler = &escape;	// Pointer to a -function-
  sigemptyset(&sigaction_structure.sa_mask);	// Call defines 'empty' field
  sigaction_structure.sa_flags   = 0;		// No flags

  // Link the structure to signal "SIGINT" (as generated by ^C)
  sigaction(SIGINT, &sigaction_structure, NULL);// Link

  num1 = 0;
  num2 = 0;					// Count escape attempts

  while (num2 < 5) num1++;			// Everlasting loop?

  printf("You got out!\n");
  exit(0);
}

//------------------------------------------------------------------------------

void escape(int signum)
{
  printf("\nAttempted escape at count %d\n", num1); num2++;
  return;
}

//------------------------------------------------------------------------------
