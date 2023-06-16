#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <windows.h>

struct node {
    int code;
    char name[45];
    char vType[45];
    int hours;
    float price;
    float toatal;
    struct node *next;
};

struct node *head = NULL;
struct node *tail = NULL;
struct node *temp = NULL;
int count = 0;

void newNode(int code,char name[],char vType[],int hours,float price){
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->code = code;
    strcpy(node->name, name);
    strcpy(node->vType, vType);
    node->hours = hours;
    node->price = price;
    node->toatal = hours*price;
    node->next = 0;
    head = tail = node;
    count = 1;

}

void insertNext(int code, char name[],char vType[],int hours,float price){
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->code = code;
    strcpy(node->name, name);
    strcpy(node->vType, vType);
    node->hours = hours;
    node->price = price;
    node->toatal = hours*price;
    node->next = 0;
    temp = node;
    tail->next = temp;
    tail = temp;
    count++;
}

void insertFront(int code, char name[],char vType[],int hours,float price){
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->code = code;
    strcpy(node->name, name);
    strcpy(node->vType, vType);
    node->hours = hours;
    node->price = price;
    node->toatal = hours*price;
    node->next = 0;
    temp = node;
         if(head==NULL){
            head =tail = temp;
            count = 1;
         }else{
             temp->next = head;
             head = temp;
             count++;
         }
};

void insertRear(int code, char name[],char vType[],int hours,float price){
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->code = code;
    strcpy(node->name, name);
    strcpy(node->vType, vType);
    node->hours = hours;
    node->price = price;
    node->toatal = hours*price;
    node->next = 0;
    temp = node;
         if(head==NULL){
            head =tail = temp;
            count = 1;
         }else{
         tail->next = temp;
         tail = temp;
         count++;
         }
};

void Search(int code){
    temp = head;
    int i = 0;
    while(count>i){
        if(temp->code==code){
            printf("%d  %s   %s   %d  %.2f  %.2f\n",temp->code,temp->name,temp->vType,temp->hours,temp->price,temp->toatal);
            return;
        }
        temp = temp->next;
        i++;
    }
    printf("\nThis code is not exist...\n");
}

void deleteNode(int code){
    temp = head;
    struct node * prev = 0;
    do{
        if(temp->code==code){
            if(prev==0){
                head = temp->next;
                count--;
                printf("\nDeleted...\n");
                return;
            }
            prev->next = temp->next;
            count--;
            printf("\nDeleted...\n");
            return;
        }
        prev = temp;
        temp = temp->next;
    }while(temp!=0);
    printf("\nThis code is not exist...");
    return;
}

void display(int count){
    temp = head;
    if(count==0){
        printf("Empty list\n");
        return;
    }
    for(int i =0;i<count;i++){
        printf("%d  %s   %s   %d  %.2f  %.2f\n",temp->code,temp->name,temp->vType,temp->hours,temp->price,temp->toatal);
        temp = temp->next;
    }
    return;
};

int main()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);  //color changer
    int manu,code,hours;
    float price,total;
    char name[45];
    char vType[45];
    bool program = true;

    SetConsoleTextAttribute(hConsole,FOREGROUND_RED);
    SetConsoleTextAttribute(hConsole,FOREGROUND_RED | FOREGROUND_RED | BACKGROUND_GREEN);
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
        printf("Enter vehicle type:");      scanf("%s",&vType);
        printf("Enter hours:");  scanf("%d",&hours);
        printf("Enter price:");     scanf("%f",&price);

        newNode(code,name,vType,hours,price);

        break;

     case 2:
         if(head==NULL){
           printf("List is empty. first insert new Node...\n");
           break;
         }
         printf("Enter code:");      scanf("%d",&code);
         printf("Enter name:");      scanf("%s",&name);
         printf("Enter v-number:");      scanf("%s",&vType);
         printf("Enter hours:");  scanf("%d",&hours);
         printf("Enter price:");     scanf("%f",&price);

         insertNext(code,name,vType,hours,price);

         break;

     case 3:
         printf("Enter code:");      scanf("%d",&code);
         printf("Enter name:");      scanf("%s",&name);
         printf("Enter v-number:");      scanf("%s",&vType);
         printf("Enter hours:");  scanf("%d",&hours);
         printf("Enter price:");     scanf("%f",&price);

         insertFront(code,name,vType,hours,price);
        break;

     case 4:
         printf("Enter code:");      scanf("%d",&code);
         printf("Enter name:");      scanf("%s",&name);
         printf("Enter v-number:");      scanf("%s",&vType);
         printf("Enter hours:");  scanf("%d",&hours);
         printf("Enter price:");     scanf("%f",&price);

         insertRear(code,name,vType,hours,price);

        break;

     case 5:
         printf("Enter code:");
         scanf("%d",&code);
         Search(code);
         break;

     case 6:
         printf("Enter code:");      scanf("%d",&code);

         deleteNode(code);
         break;

     case 7:
         display(count);
         break;

     case 8:
         printf("\nBye....\n");
         return 0;
         break;

     default:
         printf("\nWrong Input\n");
         break;
    }
  }
  return 0;
}
