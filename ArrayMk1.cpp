#define _GNU_SOURCE

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>

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
    file = fopen("TextFileMk1.txt", "r");

    size_t nline = 0, maxlen = 0;
    // printf("%p\n", &nline);
    fscanf(file, "%zu %d\n", &nline, &maxlen);

    // printf("%zu\n", nline);

    char ** LineArray = (char **) calloc(nline, sizeof(char*));
    assert(LineArray);
    char * Buff = (char *) calloc(maxlen + 1, sizeof(char));

    for (int i = 0; i < nline; i++)
    {

        MyGetline(&Buff, &maxlen, file);
        // printf("%p", LineArray);
        LineArray[i] = strdup(Buff);


    }

    for (int i = 0; i < nline; i++)
    {
        printf("%s\n", LineArray[i]);
    }

    for (int i = 0; i < nline; i++)
    {
        free(LineArray[i]);
    }
    free(LineArray);

    return 0;
}
