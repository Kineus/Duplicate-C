#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define max_line 100
#define max_length 100

int isDuplicate(char *currentCharacter)
{
    int isDuplicate = 0;

    currentCharacter[strcspn(currentCharacter, "\n")] = 0;
}

int main()
{
    char number[max_line][max_length];

    char eachfile[max_length];

    FILE *duplicate_file = fopen("duplicate.txt", "r");

    if (duplicate_file == NULL) /* check to be sure the file exist */
    {
        printf("Error opening file \n");
        return 1;
    }

    int line = 0;

    while (!feof(duplicate_file) && !ferror(duplicate_file))
    {
        if (fgets(eachfile, max_length, duplicate_file) != NULL)
        {
            // store all the lines inside a string array

            strcpy(number[line], eachfile);
            line++;
        }
    }

    // Loop through that universal array. If you detect a number, 
    // Use that number with the current index of the number to slice that unversal array.
    // Then that slice is what we are going to work on.
    
     

    for (int i = 1; i < line; i++)
    {
           printf("%s", number[i]);
    }

    fclose(duplicate_file);

    return 0;
}