#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;  
    *head = newNode;        
    printf("%d inserted at the beginning.\n", data);
}

void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;  
        printf("%d inserted at the end.\n", data);
        return;
    }
    
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;  
    }
    
    temp->next = newNode;  
    printf("%d inserted at the end.\n", data);
}

void insertAtPosition(struct Node** head, int data, int position) {
    if (position < 1) {
        printf("Position must be greater than or equal to 1.\n");
        return;
    }
    
    struct Node* newNode = createNode(data);
    if (position == 1) {
        insertAtBeginning(head, data);  
        return;
    }
    
    struct Node* temp = *head;
    int count = 1;
    
    while (temp != NULL && count < position - 1) {
        temp = temp->next;
        count++;
    }
    
    if (temp == NULL) {
        printf("Position is greater than the number of nodes in the list.\n");
        free(newNode);
        return;
    }
    
    newNode->next = temp->next;  
    temp->next = newNode;        
    printf("%d inserted at position %d.\n", data, position);
}

void displayList(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    
    struct Node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    
    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 20);
    insertAtBeginning(&head, 30);
    
    insertAtEnd(&head, 40);
    insertAtEnd(&head, 50);
    
    insertAtPosition(&head, 25, 3);
    
    displayList(head);
    
    return 0;
}
