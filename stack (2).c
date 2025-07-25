#include <stdio.h>
#define MAX 100

int top = -1;
int stack[MAX];

void push(){
    int item;
    printf("Enter the item to be added: ");
    scanf("%d", &item);
    if(top == MAX-1){
        printf("Overflow, cannot push more elements!");
        return;
    }
    top++;
    stack[top] = item;

}

void display(){
    if(top == -1){
        printf("Underflow, stack is empty!");
        return;
    }

    int i;
     for(i=top; i>=0; i--){
        printf("%d\n", stack[i]);
     }
}


void pop(){
    if(top == -1){
        printf("Underflow, stack is empty!");
        return;
    }
 
    top--;
    int i;
    for(i=top; i>=0; i--){
        printf("%d\n", stack[i]);
 
    }
 }


void main(){

    int ch;
    char op;

    do{
        printf("// STACK MENU // \n");
        printf("1.Push \n");
        printf("2.Pop \n");
        printf("3.Display \n");
        printf("4.Exit \n");

        printf("Select the operation to be performed: ");
        scanf("%d", &ch);

        switch(ch){
            case 1:
            push();
            break;

            case 2:
            pop();
            break;

            case 3:
            display();
            break;
           
            case 4:
            break;

            default:
            printf("Invalid input! \n");
        }

        printf("Do you wish to continue? ");
        scanf(" %c", &op);

    }while(op == 'Y' || op == 'y');

}