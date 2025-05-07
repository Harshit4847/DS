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

void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;  
        return;
    }
    
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;  
    }
    
    temp->next = newNode;  
}

void deleteFromBeginning(struct Node** head) {
    if (*head == NULL) {
        printf("The list is already empty.\n");
        return;
    }
    
    struct Node* temp = *head;
    *head = temp->next;  
    free(temp);  
    printf("Node deleted from the beginning.\n");
}

void deleteFromEnd(struct Node** head) {
    if (*head == NULL) {
        printf("The list is already empty.\n");
        return;
    }
    
    if ((*head)->next == NULL) {  
        free(*head);
        *head = NULL;
        printf("Node deleted from the end.\n");
        return;
    }
    
    struct Node* temp = *head;
    while (temp->next != NULL && temp->next->next != NULL) {
        temp = temp->next;  
    }
    
    free(temp->next);  
    temp->next = NULL;  
    printf("Node deleted from the end.\n");
}

void deleteAtPosition(struct Node** head, int position) {
    if (*head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    
    if (position == 1) {
        deleteFromBeginning(head);  // Delete from beginning if position is 1
        return;
    }
    
    struct Node* temp = *head;
    int count = 1;
    
    while (temp != NULL && count < position - 1) {
        temp = temp->next;
        count++;
    }
    
    if (temp == NULL || temp->next == NULL) {
        printf("Position is greater than the number of nodes in the list.\n");
        return;
    }
    
    struct Node* nodeToDelete = temp->next;
    temp->next = temp->next->next;  
    free(nodeToDelete);  
    printf("Node deleted at position %d.\n", position);
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
    
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);
    insertAtEnd(&head, 50);
    
    printf("Original ");
    displayList(head);
    
    deleteFromBeginning(&head);  
    deleteFromEnd(&head);        
    deleteAtPosition(&head, 2);  
    
    printf("Updated ");
    displayList(head);
    
    return 0;
}
