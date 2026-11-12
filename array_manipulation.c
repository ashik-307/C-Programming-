
#include <stdio.h>

int main() {
    int arr1[100], arr2[100], arr3[100], arr4[100];
    int n, index, value, del, key;
    int i, j, temp, found, count;

    scanf("%d", &n);

    for(i = 0; i < n; i++)
        scanf("%d", &arr1[i]);

    scanf("%d %d", &index, &value);

    for(i = n; i > index; i--)
        arr1[i] = arr1[i - 1];

    arr1[index] = value;
    n++;

    scanf("%d", &del);

    for(i = 0; i < n; i++) {
        if(arr1[i] == del) {
            for(j = i; j < n - 1; j++)
                arr1[j] = arr1[j + 1];
            n--;
            break;
        }
    }

    printf("Updated Array: ");
    for(i = 0; i < n; i++)
        printf("%d ", arr1[i]);
    printf("\n");

    for(i = 0; i < n; i++)
        arr2[i] = arr3[i] = arr4[i] = arr1[i];

    for(i = 0; i < n - 1; i++) {
        for(j = 0; j < n - i - 1; j++) {
            if(arr2[j] > arr2[j + 1]) {
                temp = arr2[j];
                arr2[j] = arr2[j + 1];
                arr2[j + 1] = temp;
            }
        }
    }

    printf("Bubble Sort: ");
    for(i = 0; i < n; i++)
        printf("%d ", arr2[i]);
    printf("\n");

    for(i = 1; i < n; i++) {
        temp = arr3[i];
        j = i - 1;

        while(j >= 0 && arr3[j] > temp) {
            arr3[j + 1] = arr3[j];
            j--;
        }
        arr3[j + 1] = temp;
    }

    printf("Insertion Sort: ");
    for(i = 0; i < n; i++)
        printf("%d ", arr3[i]);
    printf("\n");

    for(i = 0; i < n - 1; i++) {
        found = i;

        for(j = i + 1; j < n; j++) {
            if(arr4[j] < arr4[found])
                found = j;
        }

        temp = arr4[i];
        arr4[i] = arr4[found];
        arr4[found] = temp;
    }

    printf("Selection Sort: ");
    for(i = 0; i < n; i++)
        printf("%d ", arr4[i]);
    printf("\n");

    scanf("%d", &key);
    count = 0;
    found = -1;

    for(i = 0; i < n; i++) {
        count++;

        if(arr1[i] == key) {
            found = i;
            break;
        }
    }

    if(found != -1)
        printf("Linear Search: Found at Index %d (Comparisons: %d)\n", found, count);
    else
        printf("Linear Search: Not Found (Comparisons: %d)\n", count);

    int low = 0, high = n - 1, mid;
    count = 0;
    found = -1;

    while(low <= high) {
        mid = (low + high) / 2;
        count++;

        if(arr2[mid] == key) {
            found = mid;
            break;
        }
        else if(key < arr2[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }

    if(found != -1)
        printf("Binary Search: Found at Index %d (Comparisons: %d)\n", found, count);
    else
        printf("Binary Search: Not Found (Comparisons: %d)\n", count);

    return 0;
}
