#include <stdio.h>
#include <stdlib.h>
typedef struct ll {
    int data;
    struct ll *next;
} Node;

void InsertBeg(Node **head, int data){
    Node *New_Node = NULL;
    New_Node = (Node*)malloc(sizeof(Node));
    New_Node->data = data;
    New_Node->next = NULL;
    if (*head == NULL)
    {
        *head = New_Node;
        return;
    }
    New_Node->next = *head;
    *head = New_Node;
};

void InsertEnd(Node **head,int data){
    Node *New_Node = (Node*)malloc(sizeof(Node));
    New_Node->data = data;
    New_Node->next = NULL;
    if (*head == NULL){
        *head = New_Node;
        return;
    }
    Node *temp = *head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = New_Node;
};
void Traverse(Node *head){
    Node *temp = head;
    while (temp != NULL)
    {   
        printf("%d -> ", temp->data);
        temp=temp->next;
    }
    printf("NULL");
    
}




int main ()
{
    Node *head = NULL;
    int a = 1, ch, data;
    while (a == 1){
        printf("\n1. Add a number at beggining \n2. Add a number at the end \n3. Delete a number\n4. Traverse\n5. Searching \n0. Exit\nChoose a operation..: ");
        scanf("%d",&ch);
        switch (ch)
        {
            case 1:
                printf("Enter a data to insert (Beg)..: ");
                scanf("%d", &data);
                InsertBeg(&head, data);
                break;
            case 2:
                printf("Enter a data to insert (End)..: ");
                scanf("%d", &data);
                InsertEnd(&head, data);
                break;
            case 3: 
                break;
            case 4: 
                Traverse(head);
                break;
            case 5: 
                break;
            case 0:
                a = 3; 
                break;
            default:
                printf("Invalid input");
                break;
        }

    };


    return 0;
};

