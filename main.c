#include <stdio.h>

void mainInterface(){
    int selec1;
    printf("HI DEAR");
    printf("\n\n1.Create account\n2.Login account");
    printf("\n\nSelect your option:");
    scanf("%d", &selec1);
    system("clear || cls");

    if(selec1=1){
        createAcount();
    }
    else if(selec1=2){
        logAcc();
    }
}

void createAcount(){
    int age,phone;
    char name,pwd;
  printf("ACCOUNT CREATE\n\n");
  printf("Enter your user name:");
  scanf("%s", &name);
  printf("Enter new your password:");
  scanf("%d",&pwd);
  printf("");
  printf("Enter phone number:");
  scanf("%d",&phone);
}

void logAcc(){
  printf("WELLOCE!!");
  printf("Enter account number:");
  scanf("");
}

 int main() {
  mainInterface();
 return 0;
 }
