#include <stdio.h>
#include <stddef.h>
#include <assert.h>
#include <stdlib.h>

void Sort(int *Data, size_t size);
size_t Partition(int data[], size_t left, size_t right);
void swap(int* a, int* b);
void ArrayOutp(int *Data, size_t size);

void qsort(void *base, size_t num, size_t size, int (*compare) (const void *, const void *));

int comparator(const void* a, const void* b)
{
    if ( *(int*)a > *(int*)b)
        return 1;z
    else if ( *(int*)a < *(int*)b)
        return -1;
    else
        return 0;
}

int main(void)
{
    int Data[] = {5, 5, 5, 5, 5, 16, 10, 5, 10, 3, 4, 12, 6, 6, 22, 20};
    size_t size = 16;
    ArrayOutp(Data, size);

    qsort(Data, size, sizeof(int), comparator);

    ArrayOutp(Data, size);
}

void Sort(int* Data, size_t size)
{
    printf("---NEW SORT ITERATION---\n");

    int left = 0;
    int right = size-1;

    // comparator(left, right);
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


void ArrayOutp(int *Data, size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        printf("%3d", Data[i]);
    }
    printf("\n");
}
