//1905622 - NITISH KUMAR SONTHALIA
//Linked list Merge Sort
#include<stdio.h>
#include <stdlib.h>



struct node
{
    int data;
    struct node *next;
};

void merg_2_sorted_list(struct node **,struct node **,struct node **);
void creat_list(struct node ** ,int n);
void display_list(struct node ** );

int main(){

    struct node *start = NULL;

    struct node *start1 = NULL;

    struct node *start2 = NULL;

    int t;

    int f=1;

    while(f){
    printf("\n MENU ");
    printf("\n 1. Enter An Element In List 1 ");
    printf("\n 2. Enter An Element In List 2 ");
    printf("\n 3. Display List ");
    printf("\n 4. Merge List ");
    printf("\n 5. Exit ");
    scanf("%d",&t);
    int e;

    switch (t)
    {

    case 1:
        printf("\n Enter The Element To Be Entered in list 1: ");
        scanf("%d",&e);
        creat_list(&start1,e);
        break;
    case 2:
        printf("\n Enter The Element To Be Entered in list 2: ");
        scanf("%d",&e);
        creat_list(&start2,e);
        break;
    case 3:
        printf("\n Enter The List You Want To Print: ");
        scanf("%d",&e);
        if(e==1)
        display_list(&start1);
        else if(e==2)
        display_list(&start2);
        else if(e==3)
        display_list(&start);
        else
        printf("\n Enter the Correct list number ");
        break;
    case 4:
        merg_2_sorted_list(&start1,&start2,&start);
        break;
    case 5:
        f=0;
        break;

    default:
        break;
    }
    }

}

void creat_list(struct node **st ,int n){

    struct node *temp;

    struct node *new1 = (struct node *)malloc(sizeof(struct node *));

    new1->data=n;

    new1->next=NULL;

    if(*st==NULL){
        *st=new1;
    }
    else{
        temp=*st;
        while(temp->next!=NULL){
            temp= temp->next;
        }
        temp->next = new1;
    }
}



void display_list(struct node **st){

    if (*st == NULL){ 
      printf("\n Empty List"); 
      return ;
    }

    struct node*temp=*st;
        printf("Elements in LIST are:");

    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}

void merg_2_sorted_list(struct node **st1,struct node **st2,struct node **st3){

    struct node *t1=*st1;

    struct node *t2=*st2;

    while(t1!=NULL&&t2!=NULL){
        if(t1->data>t2->data){
            creat_list(st3,t2->data);
            t2=t2->next;
        }
        else if(t1->data<t2->data){
            creat_list(st3,t1->data);
            t1=t1->next;
        }
        else{
            creat_list(st3,t1->data);
            t1=t1->next;
            t2=t2->next;
        }
    }
    while(t1!=NULL){
        creat_list(st3,t1->data);
        t1=t1->next;
    }
    while(t2!=NULL){
        creat_list(st3,t2->data);
        t2=t2->next;
    }
}
