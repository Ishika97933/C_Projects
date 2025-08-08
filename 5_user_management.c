#include<stdio.h>
#include<string.h>
#include<unistd.h>

#define MAX_USERS 10
#define CREDENTIAL_LENGTH 30

typedef struct {
    char username[CREDENTIAL_LENGTH];
    char password[CREDENTIAL_LENGTH];
} User;

User users[MAX_USERS];
int user_count = 0;

void register_user();
int login_user();
void fix_fgets_input(char*);
void input_credential(char* username, char* password);

int main(){
    int option;
    int user_index;
    while(1){
        printf("\nWelcome to User Management");
        printf("\n1. Register");
        printf("\n2. Login");
        printf("\n3. Exit");
        printf("\nSelect an option: ");
        scanf("%d", &option);
        getchar();

        switch(option){
            case 1:
             register_user();
             break;
            case 2:
             user_index = login_user();
             if(user_index >= 0){
                printf("\nLogin successful! Welcome, %s!\n", users[user_index].username);
             }else{
                printf("\nLogin failed! Incorrect username or password.\n");
             }
             break;
            case 3:
             printf("\nExisting Program.\n");
             return 0;
             break;
            default:
             printf("\nInvalid option. Please try again.\n");
             break;
        }
    }
    
    return 0;
}

void register_user(){
    if(user_count == MAX_USERS){
        printf("\nMaximum %d users are supported! No more registrations Allowed!!!!\n", MAX_USERS);
        return;
    }
    int new_index = user_count;
    printf("\nRegister a new user");
    input_credential(users[new_index].username, users[new_index].password);
    user_count++;
    printf("\nRegistration sucessfully!\n");
    // printf("-%s-%s-", users[new_index].username, users[new_index].password);
}

int login_user(){
    char username[CREDENTIAL_LENGTH];
    char password[CREDENTIAL_LENGTH];

    input_credential(username, password);
    // printf("-%s-%s-", username, password);

    for(int i=0; i<user_count; i++){
        if(strcmp(username, users[i].username)==0 && strcmp(password, users[i].password)==0){
            return i;
        }
    }

    return -1;
}

void input_credential(char* username, char* password){
    printf("\nEnter username: ");
    fgets(username, CREDENTIAL_LENGTH, stdin);
    fix_fgets_input(username);

    printf("Enter password: ");
    fgets(password, CREDENTIAL_LENGTH, stdin);
    fix_fgets_input(password);
}

void fix_fgets_input(char* string){
    int index = strcspn(string, "\n");
    string[index] = '\0';
}