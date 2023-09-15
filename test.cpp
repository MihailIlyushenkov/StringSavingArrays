#include <stdio.h>

int main(void)
{
   int arr1[9] = {5, 13, 37, 3, 5, 53, 3, 30, 3};
   int arr2[9] = {13, 3, 5, 37, 5, 53, 3, 3, 30};

    for (int i = 0; i < 9; i++)
   {
        printf("%3d ", arr1[i]);
   }
   printf("\n");
    for (int i = 0; i < 9; i++)
   {
        printf("%3d ", arr2[i]);
   }

   return 0;
}
