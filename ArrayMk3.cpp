#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
#include <sys\stat.h>
#define FILENAME "TextFileMk2.txt"

ssize_t MyGetline(char **lineptr, size_t *n, FILE *stream)
{
    size_t size = 128;
    char *subbuf_p;
    subbuf_p = (char *)calloc(size, sizeof(char));
    if (subbuf_p == NULL)
    {
        return -1;
    }

    char Readedchar = getc(stream);
    size_t counter = 0;

    while (Readedchar != '\n')
    {
        subbuf_p[counter] = Readedchar;
        counter += 1;
        Readedchar = getc(stream);

        if (counter > size-1)
        {
            size += 128;
            subbuf_p = (char *)realloc(subbuf_p, size);

            if (subbuf_p == NULL)
            {
                return -1;
            }
        }
    }

    if ((*lineptr == NULL))
    {
        *n = counter + 1;
        *lineptr = (char*)calloc(counter + 1, sizeof(char));

        if (lineptr == NULL)
        {
            return -1;
        }

        for (int i = 0; i < counter; i++)
        {
            (*lineptr)[i] = subbuf_p[i];
        }
        (*lineptr)[counter] = '\0';
    }
    else
    {
        if (*n < size)
        {
            *n = counter;
            *lineptr = (char*)realloc(*lineptr, counter);

            if (lineptr == NULL)
            {
                return -1;
            }

        }
        for (int i = 0; i < counter; i++)
        {
            (*lineptr)[i] = subbuf_p[i];
        }
    }

    (*lineptr)[counter] = '\0';
    return counter;

}

char *strdup(const char *str)
{
    int Stringlen = 0;
    while (str[Stringlen] != '\0')
    {
        Stringlen += 1;
    }

    char *NewString = (char*)calloc(Stringlen + 1, sizeof(char));

    if (NewString == NULL)
    {
        return NULL;
    }

    for (int i = 0; i < Stringlen; i++)
    {
        NewString[i] = str[i];
    }

    return NewString;
}

int main(void)
{
    FILE *file;
    file = fopen(FILENAME, "r");

    size_t nline = 0, nchar = 0, maxlen = 0;

    struct stat FileData;
    stat(FILENAME,&FileData);

    char ReadedChar = '0';

    nchar = FileData.st_size;


    char * Buff = (char *) calloc(nchar, sizeof(char));

    fread(Buff, sizeof(char), nchar, file);
    fclose(file);

    for (int i = 0; i < nchar; i++)
    {
        if (Buff[i] == '\n')
        {
            nline += 1;
        }
    }

    char ** LineArray = (char **) calloc(nline, sizeof(char*));
    LineArray[0] = Buff;

    int StringNum = 1;
    for (int i = 0; i < nchar; i++)
    {
        if (Buff[i] == '\n')
        {
            // printf("now i am at symbol %d, it is %d, gonna put pointer %p in LineArray[%d]",
                // i, Buff[i],  &Buff[i+1], StringNum);
            LineArray[StringNum] = &Buff[i+1];
            StringNum += 1;
            Buff[i] = '\0';
        }
    }

    // printf("%d", nline);
    // printf("%d", nchar);

    for (int i = 0; i < nline; i++)
    {
        printf("<%s>\n", LineArray[i]);
    }

    free(LineArray);
    free(Buff);

    return 0;
}
