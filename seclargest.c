#include <stdio.h>

void main() {
    int n, l, sl;
    printf("Enter the array size :");
    scanf("%d", &n);
    int a[n];
    printf("Enter the array :");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    l = a[0];
    sl = a[1];
    for (int i = 0; i < n; i++) {
        if (a[i] > l) {
            sl = l;
            l = a[i];
        }
        else if (a[i] > sl && a[i] < l) {
            sl = a[i];
        }
    }
    printf("The second largest number in the array is %d", sl);
}
