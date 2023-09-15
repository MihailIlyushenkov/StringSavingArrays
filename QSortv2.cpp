#include <stdio.h>
#include <stddef.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

void Sort(int *Data, size_t size);
size_t Partition(int data[], size_t left, size_t right);
void swap(int* a, int* b);
void ArrayOutp(const char ** Data, size_t size);

void qsort(void *base, size_t num, size_t size, int (*compare) (const void *, const void *));



int comparator(const void* a, const void* b)
{
    // if (*(int*)a > *(int*)b)
    // printf("%p %p\n"); // &Data[i]

    const char* s1 = *(const char**)a;
    const char* s2 = *(const char**)b;

    return strcmp(s1, s2);
}

// void swap(void* a, void* b, size_t size)
// {
//     char* tmp = malloc(size);
//     memcpy(tmp, a);
//
//
//     int t = *a;
//     *a = *b;
//     *b = t;
// }

int main(void)
{
    const char* Data[] = {"sdjgw", "ogjwog", "epgiw", "wrogwe", "agekmbe", "ageambe"};

    size_t size = 4;
    ArrayOutp(Data, size);

    qsort(Data, size, sizeof(const char*), comparator);

    ArrayOutp(Data, size);
}
/*
void Sort(int* Data, size_t size)
{
    printf("---NEW SORT ITERATION---\n");

    int left = 0;
    int right = size-1;

    int mid = Data[size/2];

    printf("mid value is %d, mid pos is %d\n", Data[size/2], size/2);
    ArrayOutp(Data, size);

    do
    {
        while (Data[left] < mid)
        {
            left++;
        }

        while (Data[right] > mid)
        {
            right--;
        }
        if (left <=right)
        {
        swap(&Data[left], &Data[right]);
        left++;
        right--;
        }

    } while(left <= right);

    ArrayOutp(Data, size);

    if (right > 0)
    {
        Sort(Data, right + 1);
    }

    // printf("gotoright\n");
    if (left < size)
    {
        Sort(&Data[left], size - left);
    }
}

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
*/

void ArrayOutp(const char** Data, size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        printf("%s ", Data[i]);
    }
    printf("\n");
}
