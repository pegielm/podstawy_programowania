#include <stdio.h>

#define N 10

int front = 0, rear = 0;
int queue[N];

int Queue__push(int queue[], int number) {
    if ((rear + 1) % N == front) {
        printf("Kolejka jest pelna\n");
        return -1;
    }
    queue[rear] = number;
    rear = (rear + 1) % N;
    return 0;
}

int Queue__pop(int queue[]) {
    if (front == rear) {
        printf("Kolejka jest pusta\n");
        return -2;
    }
    int number = queue[front];
    front = (front + 1) % N;
    return number;
}

void Queue__print(int queue[]) {
    printf("Kolejka: ");
    int i;
    for (i = front; i != rear; i = (i + 1) % N) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    Queue__push(queue, 1);
    Queue__push(queue, 2);
    Queue__push(queue, 3);
    Queue__print(queue);
    printf("%d\n", Queue__pop(queue));
    Queue__push(queue, 4);
    Queue__push(queue, 5);
    Queue__push(queue, 6);
    Queue__print(queue);
    printf("%d\n", Queue__pop(queue));
    Queue__push(queue, 7);
    Queue__push(queue, 8);
    Queue__push(queue, 9);
    Queue__push(queue, 10);
    Queue__push(queue, 11);
    Queue__print(queue);
    printf("%d\n", Queue__pop(queue));
    printf("%d\n", Queue__pop(queue));
    printf("%d\n", Queue__pop(queue));
    printf("%d\n", Queue__pop(queue));
    printf("%d\n", Queue__pop(queue));
    printf("%d\n", Queue__pop(queue));
    printf("%d\n", Queue__pop(queue));
    printf("%d\n", Queue__pop(queue));
    printf("%d\n", Queue__pop(queue));
    printf("%d\n", Queue__pop(queue));
    Queue__print(queue);
    return 0;
}
