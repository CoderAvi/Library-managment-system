
//list of header files

#include "general_functions.h"
#include "core_functions.h"
//#include<general_functions.h>
//#include<core_functions.h>

int main(){
    login = fopen("password.dat","rb");
    if(login == NULL){
        gotoxy(10,9);
        printf("Database Do not exits. Be an adminstrator. Sign Up");
        adminsignup();
    }else{
        adminsignin();
    }
    mainmenu();
    return 0;
}

void mainmenu()
{
    while(1){
        system("cls");
        gotoxy(20,3);
        printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
        gotoxy(20,5);
        printf("\xDB\xDB\xDB\xDB\xB2 1. Add Books   ");
        gotoxy(20,7);
        printf("\xDB\xDB\xDB\xDB\xB2 2. Delete Book");
        gotoxy(20,9);
        printf("\xDB\xDB\xDB\xDB\xB2 3. Search Book");
        gotoxy(20,11);
        printf("\xDB\xDB\xDB\xDB\xB2 4. View Book List");
        gotoxy(20,13);
        printf("\xDB\xDB\xDB\xDB\xB2 5. Edit Book Record ");
        gotoxy(20,15);
        printf("\xDB\xDB\xDB\xDB\xB2 6. Change Password");
        gotoxy(20,17);
        printf("\xDB\xDB\xDB\xDB\xB2 7. Close Application");
        gotoxy(20,19);
        printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
        gotoxy(20,21);
        printf("Enter your choice:");
        switch(getch()){
            case '1':
                addbooks();
                break;
            case '2':
                deletebooks();
                break;
            case '3':
                searchbooks();
                break;
            case '4':
                viewbooks();
                break;
            case '5':
                editbooks();
                break;
            case '6':
                change_password();
                gotoxy(10,13);
                printf("press any key to continue....");
                getch();
                break;
            case '7':
                creditNclose();
            default:
                gotoxy(10,23);
                printf("\aWrong Entry!!Please re-entered correct option");
                getch(); //holds the screen until a key is pressed
        }
    }
}
void addbooks(void){    //funtion that add books
	system("cls");
	FILE *fp;
	int i, choice;
	add_window();
	gotoxy(20,22);
	printf("Enter your choice:");
	scanf("%d", &choice);
	if(choice==7)
        mainmenu() ;
	system("cls");
	fp = fopen("Record.dat","ab+");
	if(getdata(choice) == 1){
        book.cat=catagories[choice-1];
        fseek(fp,0,SEEK_END);
        fwrite(&book,sizeof(book),1,fp);
        fclose(fp);
        gotoxy(21,14);
        printf("The record is sucessfully saved");
        gotoxy(21,15);
        printf("Save any more?(Y / N):");
        if(getch()=='n')
            mainmenu();
        else{
            system("cls");
            addbooks();
        }
    }
    fclose(fp);
}
void deletebooks(){    //function that delete items from file Record.dat
    FILE *ft,*fp;
    system("cls");
    int d,findBook = 0;
    char another='y';
    while(another=='y'){  //infinite loop
        system("cls");
        gotoxy(10,5);
        printf("Enter the Book ID to  delete:");
        scanf("%d",&d);
        fp = fopen("Record.dat","rb+");
        while(fread(&book,sizeof(book),1,fp)==1){
            if(book.id==d){
                gotoxy(10,7);
                printf("The book record is available");
                gotoxy(10,8);
                printf("Book name is %s",book.name);
                gotoxy(10,9);
                printf("Rack No. is %d",book.rackno);
                findBook = 1;
                gotoxy(10,10);
                printf("Do you want to delete it?(Y/N):");
                if(getch()=='y'){
                    ft=fopen("test.dat","wb");  //temporary file for delete
                    rewind(fp);
                    while(fread(&book,sizeof(book),1,fp)==1){
                        if(book.id!=d){
                            fwrite(&book,sizeof(book),1,ft); //write all in tempory file except that
                        }                              //we want to delete
                    }
                    fclose(fp);
                    fclose(ft);
                    remove("Record.dat");
                    rename("test.dat","Record.dat"); //copy all item from temporary file to fp except that
                                        //we want to delete
                    gotoxy(10,11);
                    printf("The record is sucessfully deleted");
                }
            }
        }
        if(findBook == 0){
            gotoxy(10,10);
            printf("No record is found");
            getch();
        }
        gotoxy(10,12);
        printf("Delete another record?(Y/N)");
        fflush(stdin);
        another=getch();
    }
}


void searchbooks()
{
    system("cls");
    printf("*****************************Search Books*********************************");
    gotoxy(20,10);
    printf("\xDB\xDB\xDB\xB2 1. Search By ID");
    gotoxy(20,14);
    printf("\xDB\xDB\xDB\xB2 2. Search By Name");
    gotoxy( 15,20);
    printf("Enter Your Choice");
    switch(getch())
    {
        case '1':
            searchByID();
            break;
        break;
        case '2':
            searchByName();
            break;
        default :
            getch();
            searchbooks();
    }
}

void viewbooks(void)  //show the list of book persists in library
{
    int j;
    FILE *fp;
    system("cls");
    gotoxy(1,1);
    printf("*********************************Book List*****************************");
    gotoxy(2,2);
    printf(" CATEGORY     ID    BOOK NAME     AUTHOR       QTY     PRICE     RackNo ");
    j=4;
    fp=fopen("Record.dat","rb");
    while(fread(&book,sizeof(book),1,fp)==1){
        gotoxy(3,j);
        printf("%s",book.cat);
        gotoxy(16,j);
        printf("%d",book.id);
        gotoxy(22,j);
        printf("%s",book.name);
        gotoxy(36,j);
        printf("%s",book.Author);
        gotoxy(50,j);
        printf("%d",book.quantity);
        gotoxy(57,j);
        printf("%.2f",book.Price);
        gotoxy(69,j);
        printf("%d",book.rackno);
        printf("\n\n");
        j++;
    }
    fclose(fp);
    gotoxy(35,25);
    returnfunc();
}


void editbooks(void)  //edit information about book
{
	system("cls");
	FILE *fp;
	int c=0,d;
	gotoxy(20,4);
	printf("****Edit Books Section****");
	char another='y';
	while(another=='y')
	{
		system("cls");
		gotoxy(15,6);
		printf("Enter Book Id to be edited:");
		scanf("%d",&d);
		fp=fopen("Record.dat","rb+");
		while(fread(&book,sizeof(book),1,fp)==1)
		{
			if(checkid(d)==0)
			{
				gotoxy(15,7);
				printf("The book is availble");
				gotoxy(15,8);
				printf("The Book ID:%d",book.id);
				gotoxy(15,9);
				printf("Enter new name:");scanf("%s",book.name);
				gotoxy(15,10);
				printf("Enter new Author:");scanf("%s",book.Author);
				gotoxy(15,11);
				printf("Enter new quantity:");scanf("%d",&book.quantity);
				gotoxy(15,12);
				printf("Enter new price:");scanf("%f",&book.Price);
				gotoxy(15,13);
				printf("Enter new rackno:");scanf("%d",&book.rackno);
				gotoxy(15,14);
				printf("The record is modified");
				fseek(fp,ftell(fp)-sizeof(book),0);
				fwrite(&book,sizeof(book),1,fp);
				fclose(fp);
				c=1;
			}
			if(c==0)
			{
				gotoxy(15,9);
				printf("No record found");
			}
		}
		gotoxy(15,16);
		printf("Modify another Record?(Y/N)");
		fflush(stdin);
		another=getch() ;
	}
		returnfunc();
}



