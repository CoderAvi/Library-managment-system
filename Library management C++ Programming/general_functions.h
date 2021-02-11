#include "variables.h"

void gotoxy (int x, int y)
{
        coord.X = x; coord.Y = y; // X and Y coordinates
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void returnfunc()
{
	printf(" \nPress ENTER to return to main menu");
    a:
        if(getch()==13) //allow only use of enter
            mainmenu();
        else
        goto a;
}

void get_password(char* pass)
{
    char temp_passP[25];
    int i=0;
     while(1)
    {
            temp_passP[i]=getch();
            if(temp_passP[i]==13){break;}
            else if(temp_passP[i]==8)
            {
                if(i!=0) {
                printf("\b \b");
                i--;
                } else {printf("\a");}
            }
            else
            {
                printf("*");
                *(pass+i) = temp_passP[i];
                i++;
            }
             *(pass+i)='\0';
     }
}



void creditNclose(){
    system("cls");
    gotoxy(16,3);
    printf("Programmer....");
    gotoxy(16,6);
    printf("Bibek Subedi");
    gotoxy(16,8);
    printf("E-mail:subedi_bibek@yahoo.co.in");
    gotoxy(16,10);
    printf("Department of Computer Enginnering");
    gotoxy(16,11);
    printf("Tribhuvan University, Nepal");
    gotoxy(10,17);
    printf("Exiting in 3 second...........>");
    Sleep(3000);
    exit(0);
}

int t(void) //for time
{
    time_t t;
    time(&t);
    printf("Date and time:%s\n",ctime(&t));
}

void adminsignup(){
    char temp[10];
    login = fopen("password.dat","wb");
    gotoxy(10,10);
    printf("Enter password: ");
    get_password(password);
    gotoxy(10,11);
    printf("Re Enter Password: ");
    get_password(temp);
    while(strcmp(password,temp)!=0){
        gotoxy(10,10);
        printf("Password did not matched! Enter again");
        gotoxy(10,11);
        printf("Enter password: ");
        get_password(password);
        gotoxy(10,12);
        printf("Re Enter Password: ");
        get_password(temp);
        system("cls");
    }
    fwrite(&password,sizeof(password),1,login);
    fclose(login);
}

void adminsignin(){
    char temp[10];
    login = fopen("password.dat","rb");
    gotoxy(10,10);
    printf("Enter password: ");
    get_password(temp);
    while(fread(&password, sizeof(password),1,login)==1){
        while(strcmp(temp,password)!=0){
            system("cls");
            gotoxy(10,10);
            printf("Password did not match! ");
            printf("Enter Again: ");
            get_password(temp);
        }
        gotoxy(10,11);
        printf("Password Match");
        break;
    }
    fclose(login);
    gotoxy(10,12);
    printf("Press any key...");
    getch();
}

void add_window(){
    gotoxy(20,5);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2SELECT CATEGOIES\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	gotoxy(20,7);
	printf("\xDB\xDB\xDB\xDB\xB2 1. Computer");
	gotoxy(20,9);
	printf("\xDB\xDB\xDB\xDB\xB2 2. Electronics");
	gotoxy(20,11);
	printf("\xDB\xDB\xDB\xDB\xB2 3. Electrical");
	gotoxy(20,13);
	printf("\xDB\xDB\xDB\xDB\xB2 4. Civil");
	gotoxy(20,15);
	printf("\xDB\xDB\xDB\xDB\xB2 5. Mechanical");
	gotoxy(20,17);
	printf("\xDB\xDB\xDB\xDB\xB2 6. Architecture");
	gotoxy(20,19);
	printf("\xDB\xDB\xDB\xDB\xB2 7. Back to main menu");
	gotoxy(20,21);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

}

int change_password(){
    system("cls");
    FILE *login;
    char old_pass[10], new_pass[10];
    gotoxy(10,10);
    printf("Enter Old password: ");
    get_password(old_pass);
    gotoxy(10,11);
    printf("Enter New password: ");
    get_password(new_pass);
    login = fopen("password.dat","rb+");
    while(fread(&password,sizeof(password),1,login)==1){
        if(strcmp(old_pass,password)==0){
            strcpy(password,new_pass);
            fseek(login,-sizeof(password),SEEK_CUR);
            fwrite(&password,sizeof(password),1,login);
            fclose(login);
            gotoxy(10,12);
            printf("Password sucessfully changed! ");
            return 1;
        }else{
            gotoxy(10,12);
            printf("Password changing process failed!");
            return 0;
        }

    }

}
