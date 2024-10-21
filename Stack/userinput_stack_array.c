#include<stdio.h>


struct stack 
{
    int top;
    int *arr;
    int size;
};

int isEmpty(struct stack *ptr)
{
    if(ptr->top==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct stack *ptr)
{
    if(ptr->top==ptr->size-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// push
void push(struct stack *ptr)
{
    int num;
    printf("enter the data: \n");
    scanf("%d",&num);
    if(isFull(ptr))
    {
        printf("stack overflow!!!\n");
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top]=num;
    }
}


// pop
int pop(struct stack *ptr)
{
    if(isEmpty(ptr))
    {
        printf("Stack Underflow!!!!\n");
    }
    else
    {
        int value=ptr->arr[ptr->top];
        ptr->top--;
        return value;
    }
}

// display all the element in this stack
void display(struct stack *ptr)
{
    if(isEmpty(ptr))
    {
        printf("Stack underflow!!!\n");
    }
    else
    {
        printf("Element present in the stack::-->>>\n");
        for(int i=ptr->top;i>=0;i--)
        {
            printf("%d\n",ptr->arr[i]);
        }
    }
}
// top most element
int stacktop(struct stack *ptr)
{
    return ptr->arr[ptr->top];
}
// Bottom most element
int stackBottom(struct stack *ptr)
{
    return ptr->arr[0];
}


int main(){
    int ch;
    struct stack *sp = (struct stack *) malloc(sizeof(struct stack));
    sp->size = 50;
    sp->top = -1;
    sp->arr = (int *) malloc(sp->size * sizeof(int));

    while(1)
    {
        printf("-----------------------MENU-----------------------\n");
        printf("press 1 to push the element\n");
        printf("press 2 to pop the element\n");
        printf("press 3 to display the element\n");
        printf("press 4 to display the top most element of this stack\n");
        printf("press 5 to display the bottom most element of this stack\n");
        printf("press 0 to exit\n");
        printf("enter your choice: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                    push(sp);
                    break;
            case 2:
                    pop(sp);
                    break;
            case 3:
                    display(sp);
                    break;
            case 4:
                    stacktop(sp);
                    break;
            case 5:
                    stackBottom(sp);
                    break;
            case 0:
                    exit(0);
                    break;
            default:
                    printf("Invalid choice\n");

        }
    }

return 0;
}