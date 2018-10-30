#include <stdio.h>

int main(void)
{
    int i1, i2, i3, i4, large_1, small_1, large_2, small_2, largest, smallest;

    printf("Enter four integers: ");
    scanf("%d %d %d %d", &i1, &i2, &i3, &i4);

    if (i1 < i2) {
        small_1 = i1;
        large_1 = i2;
    } else {
        small_1 = i2;
        large_1 = i1;
    }

    if (i3 < i4) {
        small_2 = i3;
        large_2 = i4;
    } else {
        small_2 = i4;
        large_2 = i3;
    }

    if (large_1 < large_2)
        largest = large_2;
    else
        largest = large_1;

    if (small_1 < small_2)
        smallest = small_1;
    else
        smallest = small_2;

    printf("Largest: %d\n", largest);
    printf("Smallest: %d\n\n", smallest);      

    return 0;
}