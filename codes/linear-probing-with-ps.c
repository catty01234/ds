// 21.Write a C program to demonstrate insertion and collision resolution using linear
// probingTake hash function H(key) = key % 10.
// ● Example keys: 23, 22, 21, 25, 24
// ● Handle collision using Linear Probing (e.g., if Key2 = 34 collides with Key1
// = 24 at index 4, shift to index 9)


#include <stdio.h>

#define SIZE 10

int table[SIZE];

void insert(int key) {
    int index = key % SIZE;
    int probes = 0;

    while (table[index] != -1 && probes < SIZE) {
        printf("Collision at index %d for key %d\n", index, key);
        index = (index + 1) % SIZE;
        probes++;
    }

    if (probes == SIZE) {
        printf("Hash Table is Full, key %d not inserted\n", key);
        return;
    }

    table[index] = key;
    printf("Key %d inserted at index %d\n", key, index);
}

void display() {
    int i;

    printf("\nHash Table:\n");

    for (i = 0; i < SIZE; i++) {
        if (table[i] == -1)
            printf("%d: Empty\n", i);
        else
            printf("%d: %d\n", i, table[i]);
    }
}


int main() {
    int keys[] = {23, 22, 21, 25, 24, 34};
    int i, n;

    n = sizeof(keys) / sizeof(keys[0]);

    for (i = 0; i < SIZE; i++)
        table[i] = -1;

    printf("Inserting elements using Linear Probing:\n");

    for (i = 0; i < n; i++)
        insert(keys[i]);

    display();

    return 0;
}