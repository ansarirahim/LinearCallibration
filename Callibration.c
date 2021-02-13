//A. R. Ansari listed code to read line by line
//gcc readFileLinebyLine.c -o readFileLinebyLine.c
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#define LENGTH_OF_ARRAY (4096)
float xCallibData[LENGTH_OF_ARRAY];
float yCallibdata[LENGTH_OF_ARRAY];
unsigned int lineNumber = 0;

void splitCallibLine(char *str) //,unsigned int index)
{
    int k = 0;
    char delim[] = "=";
    //hexASCII_adress[8];
    //har hexAscc
    char *ptr = strtok(str, delim);
    //printf("\nx=");
    while (ptr != NULL)
    {
        switch (k)
        {
        case 0:
            xCallibData[lineNumber] = atof(ptr);
            break;
        case 1:
            yCallibdata[lineNumber] = atof(ptr);
            break;
        }
        ptr = strtok(NULL, delim);
        k++;
    }
}
char *readline(FILE *fp, char *buffer)
{
    int ch;
    int i = 0;
    size_t buff_len = 0;

    buffer = malloc(buff_len + 1);
    if (!buffer)
        return NULL; // Out of memory

    while ((ch = fgetc(fp)) != '\n' && ch != EOF)
    {
        buff_len++;
        void *tmp = realloc(buffer, buff_len + 1);
        if (tmp == NULL)
        {
            free(buffer);
            return NULL; // Out of memory
        }
        buffer = tmp;

        buffer[i] = (char)ch;
        i++;
    }
    buffer[i] = '\0';

    // Detect end
    if (ch == EOF && (i == 0 || ferror(fp)))
    {
        free(buffer);
        return NULL;
    }

    //////////////////////
    if ((buffer[0] == ';') || (buffer[0] == '#'))
    {
        //	buffer++;//=buffer+1;
        //splitLine(buffer,i);
    }
    else

    {
        ////////  printf("\nbuffer=%s", buffer);
        splitCallibLine(buffer);
        lineNumber++;
    }
    /////////////////////
    return buffer;
}

void lineByline(FILE *file)
{
    char *s;
    while ((s = readline(file, 0)) != NULL)
    {
        ///// puts(s);
        free(s);

        ////printf("\n");
    }
}
#include <stdio.h>

// function to calculate m and c that best fit points
// represented by x[] and y[]
void bestApproximate(float x[], float y[], unsigned int n)
{
    int i, j;
    double m, c, sum_x = 0, sum_y = 0, sum_xy = 0, sum_x2 = 0;
    for (i = 0; i < n; i++)
    {
        sum_x += x[i];
        sum_y += y[i];
        sum_xy += (double)x[i] * (double)y[i];
        sum_x2 += ((double)x[i] * (double)x[i]);
    }

    m = (n * sum_xy - sum_x * sum_y) / (n * sum_x2 - (sum_x * sum_x));
    c = (sum_y - m * sum_x) / n;

    printf("m =% f", m);
    printf("\nc =% f", c);
}

// Driver main function
// int main1()
// {
//     int x[] = { 1, 2, 3, 4, 5 };
//     int y[] = { 14, 27, 40, 55, 68 };
//     int n = sizeof(x) / sizeof(x[0]);
//     bestApproximate(x, y, n);
//     return 0;
// }

int main(int argc, char **argv)
{
    unsigned int i = 0;
    //char *fileName ="/root/CLEM_Files/test.txt";// "input-1.txt";
    FILE *file = fopen(argv[1], "r");
    lineByline(file);
    printf("\nArrayLength=%u\n", lineNumber);
    for (i = 0; i < lineNumber; i++)
        printf("\nxCallibData[%u]=%f,yCallibData[%u]=%f", i, xCallibData[i], i, yCallibdata[i]);
    printf("\n*****\n");
    bestApproximate(xCallibData, yCallibdata, lineNumber);
    return 0;
}
