#include<stdio.h>
#include<stdlib.h>
#define MAX_QUEUE_SIZE 100
typedef struct queue{
    int elements[MAX_QUEUE_SIZE];
    int front, rear;
}CQUEUE;

void init(CQUEUE *);
int insert_cqueue (int , CQUEUE *);
int delete_cqueue (int *, CQUEUE *);
void display(CQUEUE *)
int checkEmpty (CQUEUE);
int checkFull (CQUEUE);

void init(CQUEUE *aq){
    aq->front =-1;
    aq->rear =-1;
}

int checkFull (CQUEUE q){
    if((q.front == q.rear+1) || (q.front==0 && q.rear == MAX_QUEUE_SIZE-1))
        return 1;
    else
        return 0;
}

int checkEmpty(CQUEUE q){
    if (q.front == -1)
        return 1;
    else
        return 0;
}
int insert_cqueue (int item, CQUEUE *aq){
    /*There is no space in Queue for the new Item. Item can not be added in the Queue.*/
    if (checkFull (*aq)){
        printf("\nQueue Overflow");
        return 0; /* Unsuccessful Addition*/
    }
    /* Spaces are available in Queue for the new Item. */
    else{
        if (aq->front == -1)
            aq->front=0;
        aq->rear=(aq->rear+1)% MAX_QUEUE_SIZE;
        aq->elements [aq->rear]=item;
        return 1; /* Successful Addition*/
    }
}

int delete_cqueue (int *data, CQUEUE *aq){
    /* Empty Queue*/
    if (aq->front==-1){
        printf("\nEmpty Queue");
        data=NULL;
        return 0; /* Empty Queue*/
    }
    /* Non-empty Queue*/
    else{
        *data= aq->elements [aq->front];
        if (aq->front == aq->rear) 
            init(aq);
        else
            aq->front=(aq->front+1)% MAX_QUEUE_SIZE;
        return 1; /* Successful retrieval of data*/
    }
}

void display(CQUEUE *p){
    if(p->front==-1 && p->rear==-1){
        printf("UNDERFLOW\n");
    }
    else{
        int i=p->front;
        while(i<=p->rear){
            printf("%d\n",p->data[i]);
            i++;
        }
    }
}


void main( ){
    CQUEUE q;
    initi(&q);
    int choice,again=1,val,num;
    while(again){
        printf("Enter the number:\n0: Insert Queue \n1: Delete Queue \n2: Display \n ");
        scanf("%d",&choice);
        switch (choice)
        {                                                                            
        case 0:
            printf("Enter Element: ");
            scanf("%d",&val);
            insert_cqueue(&q,val);
            break;
        case 1:
            delete_cqueue(&q);
            break;
        case 2:
            display(&q);
            break;
        case 3:
            num = peak(&q);
            if(q.front!=-1 && q.rear!=-1)
                printf("%d\n",num);
            break;
        default:
            printf("ERROR: WRONG INDEX\n");
            break;
        }
        printf("Enter 1 for continue and 0 to exit: ");
        scanf("%d",&again);
    }

    return 0;
}
    
