//this code is kinda bad
//get starting non terminal
//get no of pdns
//get pdns individually into separate arrays and compare them
//as long as equal values put it into new array, when not equal break loop
//add S' to the end
//put remaining pdns in new array with epsilon with non-ter S'
//use print statements and do something idk any other way
//S->iEtS|iEtSeS|a
//use strings in cpp if uk its much easier

#include <stdio.h>
#include <string.h>

int main () {
    char gram[20], part1[20], part2[20], modifiedGram[20], newGram[20], tempGram[20];
    int i, j = 0, k = 0, l = 0, pos;
    printf ("Enter Production : S->");
    fgets (gram, sizeof (gram), stdin);	// Safely read input
    gram[strcspn (gram, "\n")] = 0;	// Remove newline character added by fgets

    for (i = 0; gram[i] != '|' && gram[i] != '\0'; i++, j++) {
      part1[j] = gram[i];
    }
    part1[j] = '\0';
    for (j = ++i, i = 0; gram[j] != '\0'; j++, i++) {
	    part2[i] = gram[j];
	}
    part2[i] = '\0';

    for (i = 0; i < strlen (part1) && i < strlen (part2); i++) {
	    if (part1[i] == part2[i]) {
	        modifiedGram[k] = part1[i];
		    k++;
		    pos = i + 1;
		}
    }

    for (i = pos, j = 0; part1[i] != '\0'; i++, j++) {
	    newGram[j] = part1[i];
	}
    newGram[j++] = '|';
    for (i = pos; part2[i] != '\0'; i++, j++) {
	    newGram[j] = part2[i];
	}
    newGram[j] = '\0';

    modifiedGram[k] = 'X';
    modifiedGram[++k] = '\0';
    
    printf ("\nGrammar Without Left Factoring :\n");
    printf (" A->%s", modifiedGram);
    printf ("\n X->%s\n", newGram);
    return 0;
}
