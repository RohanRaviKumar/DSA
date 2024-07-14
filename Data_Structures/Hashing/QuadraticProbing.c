#include <stdio.h>
#include <stdlib.h>

struct hash {
    int size;
    int *array;
};

void init(struct hash *H, int limit) {
    H->size = limit;
    H->array = (int *)malloc(sizeof(int) * H->size);

    for (int i = 0; i < H->size; i++) {
        H->array[i] = -1;
    }
}

int hashFunction(int key, int i, int size) {
    return (key + i * i) % size;
}

void insert(struct hash *H, int key) {
    int index = key % H->size;
    int i = 1;

    while (H->array[index] != -1) {
        index = hashFunction(key, i, H->size);
        i++;
    }

    H->array[index] = key;
}

void display(struct hash *H) {
    printf("Hash Table:\n");

    for (int i = 0; i < H->size; i++) {
        printf("%d : ", i);

        if (H->array[i] != -1) {
            printf("%d\n", H->array[i]);
        }
        
        else {
            printf("\n");
        }
    }
}

int main() {
    struct hash *H = (struct hash *)malloc(sizeof(struct hash));

    init(H, 10);

    int keys[] = {23, 45, 69, 87, 48, 67, 54, 66, 53};

    int n = sizeof(keys) / sizeof(keys[0]);

    for (int i = 0; i < n; i++) {
        insert(H, keys[i]);
    }

    display(H);

}