/* program to check if a number in a file is self describing */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define max_line 100
#define max_length 100

int count(int element, char *number)
{
    number[strcspn(number, "\n")] = 0; /* calculate the length of the number of characters in the array number excluding newline character*/

    int counter = 0;
    for (int i = 0; i < strlen(number); i++) /* loop through the length of number while incrementing i*/
    {
        char currentElement = number[i] - '0'; /* assign a new variable currentChar to store the character in each position*/

        if (currentElement == element) /* check if currentElement is the same as the first argument 'element' received then we increment ou counter*/
        {
            counter++;
        }
    }

    return counter;
}

int isSelfDescribing(char *currentNumber) /* create a function to check if a number is self describing receiving one argument which is the array of the content of the file stored */
{
    int isSelfDescribing = 0;

    currentNumber[strcspn(currentNumber, "\n")] = 0; /* calculate the length of the number of characters in the array excluding newline character*/
    for (int i = 0; i < strlen(currentNumber); i++) /* loop through the length of current number while incrementing i*/
    {
        char currentChar = currentNumber[i] - '0'; /* assign a new variable currentChar to store the character in each position*/
        int charCount = count(i, currentNumber); /* call our count function to count and check the occurence of the character in the position of the curent loop*/
        if (charCount == currentChar) /* if charCountis the same as the argument currentNumber then the number is self describing else it is not */
        {
            isSelfDescribing = 1;
        }
        else
        {
            return 0;
        }
    }
    return isSelfDescribing;
}

int main()
{
    char number[max_line][max_length];

    char eachLine[max_length];

    FILE *self_describing = fopen("Self.txt", "r"); /* Open the file */

    if (self_describing == NULL) /* check to be sure the file exist */
    {
        printf("Error opening file \n");
        return 1;
    }

    int line = 0;

    while (!feof(self_describing) && !ferror(self_describing)) /* wwhile the file exists continue to the next step*/
    {
        if (fgets(eachLine, max_length, self_describing) != NULL) /* Assigning the contents in the file to the variable each line*/
        {
            strcpy(number[line], eachLine); /* converts the string in eachline and store in the array number*/
            line++;
        }
    }

    for (int i = 1; i < line; i++) /* Create a loop to loop through each line to perform the isSelfDescribing function*/
    {
        int _isSelfDescribing = isSelfDescribing(number[i]);

        if (_isSelfDescribing == 1) /* Then check if the number is self describing and print self describing else print is not self describing*/
        {
            printf("\n%s is self describing", number[i]);
        }
        else
        {
            printf("\n%s is not self describing", number[i]);
        }
    }

    fclose(self_describing); /* close file when done */
    return 0;
}