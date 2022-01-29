#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *next;
    int data; 
};

struct node *first = NULL;
struct node *q =NULL;

//insert a data at end...
void insertAtEnd(int givendata)
{
    struct node *new = (struct node*)malloc(sizeof(struct node));
    
    new->data = givendata;
    new->next = NULL;

    if(first == NULL){
        first = new;
    }
    else{
        q = first;
        while(q->next !=NULL){
            q = q->next;
        }
        q->next = new;
    }   
}
// insert a data at beginning...

void insertAtBeginning(int givendata){

    struct node *new = (struct node*)malloc(sizeof(struct node));

    new->data = givendata;

    if(first == NULL){
        first = new;
    }
    else{
        new->next = first;
        first = new;
    }
}

// deleting first node...

void deleteFirst(){
    struct node* second = (struct node*)malloc(sizeof(struct node));
    second = NULL;
     
    //checking is the list empty
    if(first == NULL){
        printf("this list is already empty!");
    }
    else{
       second = first->next;
       first = NULL;
       first = second;
    }
}

// deleting last node...

void deleteLast(){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp = NULL;
    
    if(first == NULL){
        printf("this list is already empty!");
    }
    else{
        q = first;
        while(q->next->next != NULL){
            q = q->next;
        }
        q->next = NULL;
    }


}



// printing list...
void displayList(){
 
    struct node* temp = (struct node*)malloc(sizeof(struct node));   
    temp = first;
    while(temp->next != NULL){
        printf("%d -- ",temp->data);
        temp = temp->next;
    } 
    printf("%d",temp->data);

}

//finding a node in linkedlist...

void find(int givendata){
    q = first;
    int x = 0;
    
    while(q->next !=NULL){
        if(q->data == givendata){
            printf("element found;");
            x =1;
            break;
        }
        q = q->next;
    }
    if(x==0){
        printf("element is not exist!");
    }

    

}


int main()
{
    int answer;
    while (answer != 5)
    {

        int input;
        int where;
        printf("---------------------------MENU-----------------------\n");
        printf("Insert the data : 1  \nDisplay : 2  \nSearch the data : 3 \nDelete the Data : 4  \nFor Exit : 5  ===>  ");
        scanf("%d", &answer);
        switch (answer)
        {
        case 1:
            
            printf("Dou you want where add to data - begin : 1 End : 2 \n ");
            scanf("%d", &where);
            printf("Enter a data =  ");
            scanf("%d", &input);
            if (where == 1)
            {
                insertAtBeginning(input);
            }
            else
            {
                insertAtEnd(input);
            }

            break;
        case 2:
            displayList();
            break;

        case 3:
            printf("Enter a Data ");
            scanf("%d", &input);
            find(input);
            break;
        case 4:
            printf("Dou you want where delete to data - begin : 1 End : 2 \n ");
            scanf("%d", &where);
            if (where == 1)
            {
                deleteFirst();
            }
            else
            {
                deleteLast();
            }
            break;
        default:
            exit(0);
            break;
        }
    }

    return 0;
}