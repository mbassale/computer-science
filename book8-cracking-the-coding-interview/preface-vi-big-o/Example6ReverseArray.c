#include <stdio.h>
#include <stdlib.h>

/*
 * Reverses the array in-place.
 * Time: O(n)
 * Memory: O(1)
 */
void reverse(int *arr, size_t n)
{
    int *p1 = arr;
    int *p2 = arr + n - 1;
    while (p1 < p2)
    {
        int tmp = *p2;
        *p2 = *p1;
        *p1 = tmp;
        p1++;
        p2--;
    }
}

void print_array(const char *prefix, int *arr, int n)
{
    printf("%s", prefix);
    int *p = arr;
    while (--n >= 0)
    {
        printf("%d ", *p++);
    }
    printf("\n");
}

int main(int argc, char *argv[])
{
    int *arr1 = calloc(10, sizeof(int));
    int *p = arr1;
    int i = 0;
    while (p < (arr1 + 10))
    {
        *p++ = i++;
    }
    print_array("Arr1: ", arr1, 10);
    reverse(arr1, 10);
    print_array("Arr1Reversed: ", arr1, 10);
    free(arr1);
    return EXIT_SUCCESS;
}