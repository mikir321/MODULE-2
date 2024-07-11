#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100//максимальная длина поля 
#define MAX_CONTACTS 100//максимальное кол-во контактов


typedef struct
{
    char lastName[MAX_LENGTH];//фамилия
    char name[MAX_LENGTH];//имя
    char work[MAX_LENGTH];//место работы
    char position[MAX_LENGTH];//должность
    char phone[MAX_LENGTH];//телефон
    char email[MAX_LENGTH];//почта
    char social[MAX_LENGTH];//ссылка на страницу в соцсети
    char messenger[MAX_LENGTH];//мессенджер

} Person;

Person contacts[MAX_CONTACTS];
int contactCount = 0;

void addContact(){
    Person p;
    if(contactCount >= MAX_CONTACTS) {
        printf("List is full\n");
        return;
    }
 
     printf("Enter last name: ");
     scanf("%s",p.lastName);
     printf("Enter name: ");
     scanf("%s",p.name);

    for (int i = 0; i < contactCount; i++){
        if(strcmp(contacts[i].lastName, p.lastName) == 0 && strcmp(contacts[i].name, p.name) == 0)
        printf("\nError! This contact already exists\n");
        return;
    }

     int a;
     printf("Add more information(1 - yes, 0 - no): ");
     scanf("%d", &a);
    
     if(a){
     printf("Enter work place: ");
     scanf("%s",p.work);
     printf("Enter position on work: ");
     scanf("%s",p.position);
     printf("Enter phone number: ");
     scanf("%s",p.phone);
     printf("Enter email: ");
     scanf("%s",p.email);
     printf("Enter social media: ");
     scanf("%s",p.social);
     printf("Enter messenger: ");
     scanf("%s",p.messenger);
     }
    contacts[contactCount++] = p;

    printf("Contact added \n");

}

void editContact(){
    if(contactCount == 0){
        printf("Phone book empty\n");
        return;
    }

    char lastName[MAX_LENGTH];//фамилия
    char name[MAX_LENGTH];//имя
    printf("Enter last name of the contact to edit: ");
     scanf("%s",lastName);
     printf("Enter name of the contact to edit: ");
     scanf("%s",name);
    
    int contactFound = 0;
    for(int i = 0; i < contactCount; i++){
        if(strcmp(contacts[i].lastName, lastName) == 0 && strcmp(contacts[i].name, name) == 0){
            printf("Enter new work place: ");
            scanf("%s", contacts[i].work);
            printf("Enter new position on work: ");
            scanf("%s", contacts[i].position);
            printf("Enter new phone number: ");
            scanf("%s", contacts[i].phone);
            printf("Enter new email: ");
            scanf("%s", contacts[i].email);
            printf("Enter new social media: ");
            scanf("%s", contacts[i].social);
            printf("Enter new messenger: ");
            scanf("%s", contacts[i].messenger);
            
            printf("Contact updated\n");
            contactFound = 1;
            break;
        }
    }

    if (!contactFound) {
        printf("Contact not found\n");
    }

}

void deleteContact(){
     if(contactCount == 0){
        printf("Phone book empty\n");
        return;
    }
    char lastName[MAX_LENGTH];//фамилия
    char name[MAX_LENGTH];//имя
    printf("Enter last name of the contact to delete: ");
     scanf("%s",lastName);
     printf("Enter name of the contact to delete: ");
     scanf("%s",name);
    for (int i = 0; i < contactCount; i++){
        if(strcmp(contacts[i].lastName, lastName) == 0 && strcmp(contacts[i].name, name) == 0){
            for (int j = i; j < contactCount; j++){
                contacts[j] = contacts[j + 1];
            }
            contactCount--;
            printf("Contact deleted\n");
            return;
        }
    }

    printf("Contact not found\n");
}

void display(){
     if(contactCount == 0){
        printf("Phone book empty\n");
        return;
    }

    for(int i = 0; i < contactCount; i++){
        printf("Contact: %d \n", i + 1);
        printf("Last name: %s \n", contacts[i].lastName);
        printf("Name: %s \n", contacts[i].name);
        printf("Place of work: %s \n", contacts[i].work);
        printf("Position on work: %s \n", contacts[i].position);
        printf("Phone number: %s \n", contacts[i].phone);
        printf("E-mail: %s \n", contacts[i].email);
        printf("Social media: %s \n", contacts[i].social);
        printf("Messenger: %s \n\n", contacts[i].messenger);
        
    }
}


int main(){
    int choose;
    while(1){
    printf("\nMenu: \n");
    printf("1: Add contact \n");
    printf("2: Edit contact \n");
    printf("3: Delete contacts \n");
    printf("4: Display contact \n");
    printf("5: Exit  \n");
    printf("choose your point of menu: ");
    scanf("%d", &choose);
        
    switch (choose)
    {
    case 1:
        addContact();
        break;
    case 2:
        editContact();
        break;
    case 3:
        deleteContact();
        break;
    case 4:
        display();
        break;
    case 5:
        return 0;
    
    default:
        printf("Invalid choice! Please try again.\n");
    }
    }
    return 0;
}