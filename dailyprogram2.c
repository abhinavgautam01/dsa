#include <stdio.h>

typedef struct {
    int day;
    int month;
    int year;
} Date;

// Function to swap two dates
void swap(Date *a, Date *b) {
    Date temp = *a;
    *a = *b;
    *b = temp;
}

// Function to compare two dates
int compareDates(Date d1, Date d2) {
    if (d1.year != d2.year)
        return d1.year - d2.year;
    if (d1.month != d2.month)
        return d1.month - d2.month;
    return d1.day - d2.day;
}

// Bubble Sort for sorting dates
void sortDates(Date arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (compareDates(arr[j], arr[j + 1]) > 0) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

// Function to print dates
void printDates(Date arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%02d-%02d-%d\n", arr[i].day, arr[i].month, arr[i].year);
    }
}

int main() {
    Date dates[] = {
        {15, 8, 1995}, {23, 5, 2000}, {10, 12, 1992},
        {1, 1, 2010}, {5, 11, 1998}
    };

    int n = sizeof(dates) / sizeof(dates[0]);

    printf("Before Sorting:\n");
    printDates(dates, n);

    sortDates(dates, n);

    printf("\nAfter Sorting:\n");
    printDates(dates, n);

    return 0;
}
