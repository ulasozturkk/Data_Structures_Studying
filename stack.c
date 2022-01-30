#include <stdio.h>
#include <stdlib.h>

struct node{

    struct node* link;
    int data;
};

struct node* top;
struct node* q;

void push(int givendata){

    struct node* temp =(struct node*)malloc(sizeof(struct node));
    temp->data = givendata;
    temp->link = NULL;
    if(top!=NULL){
        temp->link = top;
    }
    top = temp;
}

void pop(){
    struct node* temp =(struct node*)malloc(sizeof(struct node));

    if(top==NULL){
        printf("stack is already empty!");
    }
    else{
        temp = top;
        top = top->link;
        temp = NULL;
    }

}

struct node* peek(){
    return top;
}

void displayStack(){
   struct node* q = (struct node*)malloc(sizeof(struct node));
   q = top;
   while(q!=NULL){
       printf("%d\n",q->data);
       q = q->link;
   }
}

int main(){

    int a1 = 3, a2= 5, a3= 7, a4= 9, a5= 11;
    push(a1);
    push(a2);
    push(a3);   
    push(a4);
    displayStack();
    printf("\n\n");
    pop();
    pop();
    displayStack();
    return 0;
}