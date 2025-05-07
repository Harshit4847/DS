#include <stdio.h>
#include <stdlib.h>

#define MAX 5  

struct Queue {
    int arr[MAX];
    int front;
    int rear;
};

void initializeQueue(struct Queue* q) {
    q->front = -1;
    q->rear = -1;
}

int isEmpty(struct Queue* q) {
    if (q->front == -1) {
        return 1;
    }
    return 0;
}

int isFull(struct Queue* q) {
    if ((q->rear + 1) % MAX == q->front) {
        return 1;
    }
    return 0;
}

void enqueue(struct Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full. Cannot enqueue %d.\n", value);
    } else {
        if (q->front == -1) {
            q->front = 0; 
        }
        q->rear = (q->rear + 1) % MAX;  
        q->arr[q->rear] = value;
        printf("%d enqueued to the queue.\n", value);
    }
}

int dequeue(struct Queue* q) {
    int item;
    if (isEmpty(q)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    } else {
        item = q->arr[q->front];
        if (q->front == q->rear) {
            q->front = -1;
            q->rear = -1;
        } else {
            q->front = (q->front + 1) % MAX;  
        }
        printf("%d dequeued from the queue.\n", item);
        return item;
    }
}

void displayQueue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements: ");
        int i = q->front;
        while (i != q->rear) {
            printf("%d ", q->arr[i]);
            i = (i + 1) % MAX;  
        }
        printf("%d\n", q->arr[q->rear]);
    }
}

int main() {
    struct Queue q;
    initializeQueue(&q);
    
    int choice, value;
    
    while (1) {
        printf("\nCircular Queue Operations Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter the value to enqueue: ");
                scanf("%d", &value);
                enqueue(&q, value);
                break;
            case 2:
                dequeue(&q);
                break;
            case 3:
                displayQueue(&q);
                break;
            case 4:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}
