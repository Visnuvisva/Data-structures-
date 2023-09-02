#include <stdio.h>

// Function to display the elements of the array
void displayArray(int arr[], int size) {
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to insert an element into the array at a given index
void insertElement(int arr[], int *size, int index, int element) {
    if (*size == 0 || index >= *size) {
        // Insert at the end if the array is empty or index is out of bounds
        arr[*size] = element;
    } else {
        // Shift elements to the right to make space for the new element
        for (int i = *size; i > index; i--) {
            arr[i] = arr[i - 1];
        }
        arr[index] = element;
    }

    (*size)++;
}

// Function to delete an element from the array at a given index
void deleteElement(int arr[], int *size, int index) {
    if (index >= 0 && index < *size) {
        // Shift elements to the left to fill the gap left by the deleted element
        for (int i = index; i < *size - 1; i++) {
            arr[i] = arr[i + 1];
        }

        (*size)--;
    } else {
        printf("Invalid index. Cannot delete element.\n");
    }
}

int main() {
    int arr[100]; // Assuming a maximum size of 100
    int size = 0;
    int choice, index, element;

    while (1) {
        printf("\nArray Operations:\n");
        printf("1. Insert an element\n");
        printf("2. Delete an element\n");
        printf("3. Display the array\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the index where you want to insert the element: ");
                scanf("%d", &index);
                printf("Enter the element to be inserted: ");
                scanf("%d", &element);
                insertElement(arr, &size, index, element);
                break;
            case 2:
                printf("Enter the index of the element to be deleted: ");
                scanf("%d", &index);
                deleteElement(arr, &size, index);
                break;
            case 3:
                displayArray(arr, size);
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

