//#define PATH "E:\ClemCfiles\test\CallibData\IC1_MCP3208\CH0\DUAL"
char debugFilePath[100];
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void trim(char *s)
{
    int i;

    while (isspace(*s))
        s++; // skip left side white spaces
    for (i = strlen(s) - 1; (isspace(s[i])); i--)
        ; // skip right side white spaces
    s[i + 1] = '\0';
    // printf ("%s\n", s);
}
bool isNumericAndFloatingPoint(const char *str)
{
    trim(str);
    while (*str != '\0')
    {
        if (*str < '0' || *str > '9')
        {
            if (*str != '.')
                return false;
        }
        str++;
    }
    return true;
}
#define __DEBUG_FILE_PATH_INDEX__ 1
int main(int argc, char **argv)
{
    int ch = 0;
    char str[100];
    unsigned int l=0;

    for (ch = 0; ch < 100; ch++)
    {
        if (argv[__DEBUG_FILE_PATH_INDEX__][ch] == '\0')
            break;
        debugFilePath[ch] = argv[__DEBUG_FILE_PATH_INDEX__][ch]; //
    }
    fclose(fopen(debugFilePath, "w"));
    FILE *fPtr = fopen(debugFilePath, "a");
    while (1)
    {
        memset(str, '\0', 100);
        printf("Enter a value :");
        gets(str);

        printf("\nYou entered: ");
        puts(str);
        if (isNumericAndFloatingPoint(str))
        {

            if (fPtr == NULL)
            {
                /* Unable to open file hence exit */
                printf("\nUnable to open '%s' file.\n", debugFilePath);
                printf("Please check whether file exists and you have write privilege.\n");
                exit(EXIT_FAILURE);
            }
            fprintf(fPtr, "%u=%s\n", l, str);
            l++;
        }
        else
        {
            printf("\nExiting from Callibration");
            break;
        }
    }

    fclose(fPtr);
}