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

struct node *head = 0;
struct node *tail = 0;
struct node *temp = 0;

struct node * newNode(int code,char name[],char vType[],int hours,float price){
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->code = code;
    strcpy(node->name, name);
    strcpy(node->vType, vType);
    node->hours = hours;
    node->price = price;
    node->toatal = hours*price;
    node->next = 0;
    return node;
}

void insertNext(int code, struct node *node){
    temp = head;
    if(head==0){
        head=tail=node;
    }else{
        while(temp->code!=code&&temp->next!=0){
            temp = temp->next;
        }
        if(temp->code==code){
                if(tail==temp){
                    tail==node;
                }
            node->next=temp->next;
            temp->next=node;
        }else{
            node->next=head;
            head=node;
        }
    }
}

void insertFront(struct node *node){
    temp = node;
         if(head==0){
            head =tail = temp;
         }else{
             temp->next = head;
             head = temp;
         }
}

void insertRear(struct node *node){
    temp = node;
         if(head==0){
            head =tail = temp;
         }else{
         tail->next = temp;
         tail = temp;
         }
}

void Search(int code){
    temp = head;
    int i = 0;
    while(temp->next!=0){
        if(temp->code==code){
            break;
        }
        temp = temp->next;
    }
    if(temp->code==code){
            printf("%d  %s   %s   %d  %.2f  %.2f\n",temp->code,temp->name,temp->vType,temp->hours,temp->price,temp->toatal);
            return;
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
                printf("\nDeleted...\n");
                return;
            }
            prev->next = temp->next;
            if(tail==temp){
                tail=prev;
            }
            printf("\nDeleted...\n");
            return;
        }
        prev = temp;
        temp = temp->next;
    }while(temp!=0);
    printf("\nThis code is not exist...");
    return;
}
void changeHours(int newHours,int code){
    temp = head;
    while(temp!=0){
        if(temp->code==code){
            temp->hours=newHours;
            temp->toatal=newHours*temp->price;
            printf("\nUpdated..");
            return;
        }
        temp=temp->next;
    }
    printf("\nThis code is not exist...");

}

void display(){
    temp = head;
    if(head==0){
        printf("Empty list\n");
    }else{
        while(temp!=0){
        printf("%d  %s   %s   %d  %.2f  %.2f\n",temp->code,temp->name,temp->vType,temp->hours,temp->price,temp->toatal);
        temp = temp->next;
      }

    }
}

int main()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);  //color changer
    int manu,code,hours,position,newHours;
    float price,total;
    char name[45];
    char vType[45];
    bool program = true;

    SetConsoleTextAttribute(hConsole,FOREGROUND_RED);
    SetConsoleTextAttribute(hConsole,FOREGROUND_RED | FOREGROUND_RED | BACKGROUND_GREEN);
    printf("welcome to program...\n");

    while(program){

   printf("\nInsert next vehicle(Node)       press 1: \n");
   printf("Insert vehicle to front         press 2: \n");
   printf("Create vehicle to rear          press 3: \n");
   printf("Search vehicle using code       press 4: \n");
   printf("Delete vehicle using code       press 5: \n");
   printf("Display all vehicle             press 6: \n");
   printf("Change hours in vehicle         press 7: \n");
   printf("Exist the program               press 8: \n");
   scanf("%d", &manu);

    switch(manu){
     case 1:
         printf("Enter position(code):");      scanf("%d",&position);   //after position park new car...
         printf("Enter vehicle code:");      scanf("%d",&code);
         printf("Enter name:");      scanf("%s",&name);
         printf("Enter vehicle type:");      scanf("%s",&vType);
         printf("Enter hours:");  scanf("%d",&hours);
         printf("Enter price:");     scanf("%f",&price);
         insertNext(position,newNode(code,name,vType,hours,price));
        break;

     case 2:
         printf("Enter vehicle code:");      scanf("%d",&code);
         printf("Enter name:");      scanf("%s",&name);
         printf("Enter vehicle type:");      scanf("%s",&vType);
         printf("Enter hours:");  scanf("%d",&hours);
         printf("Enter price:");     scanf("%f",&price);
         insertFront(newNode(code,name,vType,hours,price));
         break;

     case 3:
         printf("Enter vehicle code:");      scanf("%d",&code);
         printf("Enter name:");      scanf("%s",&name);
         printf("Enter vehicle type:");      scanf("%s",&vType);
         printf("Enter hours:");  scanf("%d",&hours);
         printf("Enter price:");     scanf("%f",&price);
         insertRear(newNode(code,name,vType,hours,price));
         break;

     case 4:
         printf("Enter vehicle code:");
         scanf("%d",&code);
         Search(code);
         break;

     case 5:
         printf("Enter vehicle code:");      scanf("%d",&code);
         deleteNode(code);
         break;

     case 6:
         display();
         break;

     case 7:
         printf("Enter vehicle code:");      scanf("%d",&code);
         printf("Enter new Hours:");      scanf("%d",&newHours);
         changeHours(newHours,code);
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
