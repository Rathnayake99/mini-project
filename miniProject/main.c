#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct node {
    int code;
    char name[45];
    int quantity;
    float price;
    float toatal;
    struct node *next;
};

struct node * newNode(int code,char name[],int quantity,float price){
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->code = code;
    strcpy(node->name, name);
    node->quantity = quantity;
    node->price = price;
    node->toatal = quantity*price;
    node->next = 0;
    return node;
}

struct node * insertNext(int code, char name[],int quantity,float price){
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->code = code;
    strcpy(node->name, name);
    node->quantity = quantity;
    node->price = price;
    node->toatal = quantity*price;
    node->next = 0;
    return node;
}

struct node *insertFront(int code, char name[],int quantity,float price){
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->code = code;
    strcpy(node->name, name);
    node->quantity = quantity;
    node->price = price;
    node->toatal = quantity*price;
    node->next = 0;
    return node;
};

struct node * insertRear(int code, char name[],int quantity,float price){
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->code = code;
    strcpy(node->name, name);
    node->quantity = quantity;
    node->price = price;
    node->toatal = quantity*price;
    node->next = 0;
    return node;
};

void Search(int code,int count,struct node *head){
    struct node * temp = head;
    while(count>0){
        if(temp->code==code){
            printf("\ncode : %d\n",temp->code);
            return;
        }
        temp = temp->next;
        count--;
    }
    printf("\nThis code is not exist...\n");
    return;
}

struct node * deleteNode(int code,int count,struct node *head){
    struct node * temp = head;
    struct node * prev =0;
    do{
        if(temp->code==code){
            if(prev==0){
                head = temp->next;
                count--;
                printf("\nDeleted...\n");
                return head;
            }
            prev->next = temp->next;
            count--;
            printf("\nDeleted...\n");
            return head;
        }
        prev = temp;
        temp = temp->next;
    }while(temp!=0);
    printf("\nThis code is not exist...");
    return head;
}

void display(int count,struct node *head){
    struct node * temp = head;
    if(count==0){
        printf("Empty list\n");
        return;
    }
    for(int i =0;i<count;i++){
        printf("%d  %s  %d  %.2f  %.2f\n",temp->code,temp->name,temp->quantity,temp->price,temp->toatal);
        temp = temp->next;
    }
    return;
};


int main()
{
    struct node *head,*tail,*temp;
    head = NULL;
    int manu,count,code,quantity;
    float price,total;
    char name[45];
    count = 0;
    bool program = true;

    printf("welcome to program...\n");

    while(program){

   printf("\nCreate new Node        press 1: \n");
   printf("Insert Node            press 2: \n");
   printf("Insert Node to front   press 3: \n");
   printf("Create Node to rear    press 4: \n");
   printf("Search Node using code press 5: \n");
   printf("Delete Node using code press 6: \n");
   printf("Display all Node       press 7: \n");
   printf("Exist the program      press 8: \n");

   scanf("%d", &manu);


    switch(manu){

     case 1:
        printf("Enter code:");      scanf("%d",&code);
        printf("Enter name:");      scanf("%s",&name);
        printf("Enter quantity:");  scanf("%d",&quantity);
        printf("Enter price:");     scanf("%f",&price);

        head = tail = newNode(code,name,quantity,price);
        head->next = 0;
        count = 1;
        break;

     case 2:
         if(head==NULL){
           printf("List is empty. first insert new Node...\n");
           break;
         }

         printf("Enter code:");      scanf("%d",&code);
         printf("Enter name:");      scanf("%s",&name);
         printf("Enter quantity:");  scanf("%d",&quantity);
         printf("Enter price:");     scanf("%f",&price);

         temp = insertNext(code,name,quantity,price);

         tail->next = temp;
         tail = temp;
         tail->next = 0;
         count++;
         break;

     case 3:
         printf("Enter code:");      scanf("%d",&code);
         printf("Enter name:");      scanf("%s",&name);
         printf("Enter quantity:");  scanf("%d",&quantity);
         printf("Enter price:");     scanf("%f",&price);

         temp = insertFront(code,name,quantity,price);
         if(head==NULL){
            head =tail = temp;
            head->next = 0;
            count = 1;
         }else{
             temp->next = head;
             head = temp;
             count++;
         }
        break;

     case 4:
         printf("Enter code:");      scanf("%d",&code);
         printf("Enter name:");      scanf("%s",&name);
         printf("Enter quantity:");  scanf("%d",&quantity);
         printf("Enter price:");     scanf("%f",&price);

         temp = insertRear(code,name,quantity,price);
         if(head==NULL){
            head =tail = temp;
            head->next = 0;
            count = 1;
         }else{
         tail->next = temp;
         tail = temp;
         tail->next = 0;
         count++;
         }
        break;

     case 5:
         printf("Enter code:");      scanf("%d",&code);

         Search(code,count,head);
         break;

     case 6:
         printf("Enter code:");      scanf("%d",&code);

         head = deleteNode(code,count,head);
         break;

     case 7:
         display(count,head);
         break;

     case 8:
         printf("\nBye....\n");
         return 0;
         break;

     default:
         break;
    }
  }
  return 0;
}
