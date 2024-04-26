#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *info; //manage file

//Define a structure named 'userinfo' to hold information about a userinfo
struct userinfo{

char fname[20];
char username[60];
char password[50];
int actbals;
int actnb;
int mobile;
char new_pasword[50];

};





char tempuser3[60];
struct userinfo user;



//View user datails
void details(){

char loginuser[60];
char loginpw[50];

printf("Please login to view account details.\n");

printf("Enter your username: ");
scanf("%s", &loginuser);
printf("Enter your password: ");
scanf("%s", &loginpw);

char tempuser2[60];
strcpy(tempuser2, loginuser);

info = fopen(strcat(tempuser2, ".txt"), "r");

if(info == NULL){

    printf("Invalid login info. Try again!\n\n");
    details();

} else {

fread(&user, sizeof(struct userinfo), 1, info);

}

if(!strcmp(loginpw, user.password)){

    system("clear || cls");
    printf("Hi %s! \n", user.fname);
    printf("Here's your account details,\n\n");
    printf("Username: %s\n", user.username);
    printf("Password: %s\n", user.password);
    printf("Account balance: %d\n", user.actbals);
    printf("Mobile number: %d\n", user.mobile);
    printf("Account number: %d\n", user.actnb);

fclose(info);
goback();

} else {

printf("Wrong Password!\n");
details();

}
}







void goback(){

int gobackinput;

printf("\n1. Go Back \n0. Exit\n\n");
scanf("%d", &gobackinput);

switch(gobackinput){

case 0:

    break;

case 1:

    system("clear || cls");
    mainmenu();

}
}






void transfer(){

int reciever;
int transferamt;

printf("Enter reciever's account number: ");
scanf("%d", &reciever);
printf("Enter the amount to transfer: ");
scanf("%d", &transferamt);

if(transferamt > user.actbals){
  printf("Insufficient account balance!\n\n");
  goback();

} else {

user.actbals = user.actbals - transferamt;

strcpy(tempuser3, user.username);
//Save the account exchange on file
info = fopen(strcat(tempuser3, ".txt"), "w");
fwrite(&user, sizeof(struct userinfo), 1, info);
fclose(info);

system("clear || cls");
printf("%dLKR transfered successfully to %d\n", transferamt, reciever);
printf("Your account balance is %dLKR\n\n", user.actbals);
goback();

}

}






void billpay(){

int billnb;
int billamt;

printf("Enter bill payment number: ");
scanf("%d", &billnb);
printf("Enter the payment amount: ");
scanf("%d", &billamt);

if(billamt > user.actbals){

printf("Insufficient account balance!\n\n");
goback();

} else {

user.actbals = user.actbals - billamt;

strcpy(tempuser3, user.username);
info = fopen(strcat(tempuser3, ".txt"), "w");
fwrite(&user, sizeof(struct userinfo), 1, info);
fclose(info);

system("clear || cls");
printf("%dLKR payed successfully to bill number %d\n", billamt, billnb);
printf("Your account balance is %dLKR\n\n", user.actbals);
goback();

}

}







void bal_check(){

printf("Hi, %s!", user.fname);
printf("\nYour account balance is: %dLKR\n", user.actbals);
goback();

}






void withdraw(){

char tempuser3[60];
int withdraw_amt;

printf("\nEnter the amount to withdraw: ");
scanf("%d", &withdraw_amt);

if (withdraw_amt % 2 == 1){

system("clear || cls");
printf("Please enter an even number!\n\n");
withdraw();

} else if (user.actbals - withdraw_amt <= 1000) {

printf("Insufficient account balance!\nAccount balance should be more than 1000LKR to withdraw.\n");
goback();

} else {

user.actbals = user.actbals - withdraw_amt;

strcpy(tempuser3, user.username);

info = fopen(strcat(tempuser3, ".txt"), "w");
fwrite(&user, sizeof(struct userinfo), 1, info);
fclose(info);

printf("%dLKR withdrawn!\n", withdraw_amt);
printf("Your account balance is: %dLKR\n\n", user.actbals);

goback();

}
}






void deposit(){

int deposit_amt;
char tempuser4[60];

printf("\nEnter the amount to deposit: ");
scanf("%d", &deposit_amt);

if (deposit_amt % 2 == 1){

printf("Please enter an even number!\n\n");
deposit();

} else {

user.actbals = user.actbals + deposit_amt;

strcpy(tempuser4, user.username);

info = fopen(strcat(tempuser4, ".txt"), "w");
fwrite(&user, sizeof(struct userinfo), 1, info);
fclose(info);

printf("%dLKR deposited!\n", deposit_amt);
printf("Your account balance is: %dLKR\n\n", user.actbals);

goback();

}
}



//Change password and new password is save in file
void change_password() {
    char *username;
    char username22,tempuser2;
    char new_password[50];
    printf("PASSWORD CHANGE\n\n");
    printf("Enter your new password: ");
    scanf("%s", new_password);
    strcpy(user.password, new_password);
    strcpy(tempuser3, user.username);
    info = fopen(strcat(tempuser3, ".txt"), "w");
    fwrite(&user, sizeof(struct userinfo), 1, info);
    fclose(info);

    int choice;
    printf("Password changed successfully!\n\n");
    printf("1.Main menu\n2.Exit\n\nCHOICE :");
    scanf("%d" , &choice);
     if(choice==1){
        system("clear||cls");
        mainmenu();
     }
     else {}
    }







void mainmenu(){

int menuinput;

printf("Choose the function\n\n");
printf("1. Account Balance \n2. Withdraw Money \n3. Deposit Money \n4. Account Details \n5. Transfer Money \n6. Bill Payment\n7.Change password\n\n9. Sign Out \n0. Exit \n\n");
scanf("%d", &menuinput);
printf("\n");

switch(menuinput){

case 0:

    break;

case 1:

    system("clear || cls");
    bal_check();
    break;

case 2:

    system("clear || cls");
    withdraw();
    break;

case 3:

    system("clear || cls");
    deposit();
    break;

case 4:

    system("clear || cls");
    details();
    break;

case 5:

    system("clear || cls");
    transfer();
    break;

case 6:

    system("clear || cls");
    billpay();
    break;

case 7:

    system("clear||cls");
    change_password();
    break;

case 9:

    system("clear || cls");
    manageacc();
    break;

}
}





//User
void signup(){

printf("Enter your first name: ");
scanf("%s", &user.fname);
printf("Enter your username: ");
scanf("%s", &user.username);

char temptemp[60];
strcpy(temptemp, user.username);

info = fopen(strcat(temptemp, ".txt"), "r");
fclose(info);

while(info != NULL){

    system("clear || cls");
    printf("Username taken, Try again!\n\n");
    signup();
    break;

}

printf("Enter your password: ");
scanf("%s", &user.password);
printf("Enter your mobile number: ");
scanf("%d", &user.mobile);
printf("Enter the initial deposit amount: ");
scanf("%d", &user.actbals);

srand(time(NULL));
int randomnb = rand();
randomnb = randomnb * 100;

user.actnb = randomnb;

char tempuser[60];
strcpy(tempuser, user.username);

 // Save user information to file
info = fopen(strcat(tempuser, ".txt"), "w");
fwrite(&user, sizeof(struct userinfo), 1, info);
fclose(info);

if(fwrite != 0){

    system("clear || cls");
    printf("Account created successfully!\n\n");
    printf("Hi %s,", user.fname);
    printf("\nYour account number is: %d\n\n", user.actnb);
    mainmenu();

} else {

    printf("Error! Try Again.");
    signup();

}
}





//
void login(){

char loginuser[60];
char loginpw[50];
char tempuser2[60];

printf("Enter your username: ");
scanf("%s", &loginuser);
printf("Enter your password: ");
scanf("%s", &loginpw);
system("clear || cls");

strcpy(tempuser2, loginuser);
info = fopen(strcat(tempuser2, ".txt"), "r");

while(info == NULL){

    printf("Invalid username. Try again!\n\n");
    break;

}

fread(&user, sizeof(struct userinfo), 1, info);
fclose(info);

//create a new if and else statement
if  (!strcmp(loginuser, user.username)) {
    if(!strcmp(loginpw, user.password)){

      printf("Login Successful\n\n");
      printf("Hi %s, Welcome back!\n", user.fname);
      mainmenu();}

     else {printf("pasword invalid. \n\n"); }
     manageacc();
    }
//

else {

  printf("Error!\n\n");
  manageacc();

    }



}





void manageacc(){

int signinput;

printf("1. Login \n2. Signup \n0. Exit\n\n");
scanf("%d", &signinput);

switch(signinput){

case 0:

    break;

case 1:

    system("clear || cls");
    login();
    break;

case 2:

    system("clear || cls");
    signup();
    break;

}
}





int main()
{
    printf("====WELCOME TO E-BANK====\n\n");

    manageacc();

    return 0;
}





