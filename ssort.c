#include <stdio.h>

void main() {
    int n, A[20], small, temp;

    printf("Enter array size: ");
    scanf("%d", &n);
    printf("Enter the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    for (int i = 0; i < n - 1; i++) {
        int m_pos = i;
        for (int j = i + 1; j < n; j++) {
            if (A[j] < A[m_pos]) {
                m_pos = j;
            }
        }
        if (m_pos != i) {
            temp = A[m_pos];
            A[m_pos] = A[i];
            A[i] = temp;
        }
        printf("Iteration %d : ", i + 1);
        for (int i = 0; i < n; i++) {
            printf("%d ", A[i]);
        } 
        printf("\n");
    }

    printf("The sorted array is: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
}