
int getdata(int choice)
{
	int bookID;
	gotoxy(20,3);printf("Enter the Information Below");
	gotoxy(20,4);printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	gotoxy(20,5);
	printf("\xB2");gotoxy(46,5);printf("\xB2");
	gotoxy(20,6);
	printf("\xB2");gotoxy(46,6);printf("\xB2");
	gotoxy(20,7);
	printf("\xB2");gotoxy(46,7);printf("\xB2");
	gotoxy(20,8);
	printf("\xB2");gotoxy(46,8);printf("\xB2");
	gotoxy(20,9);
	printf("\xB2");gotoxy(46,9);printf("\xB2");
	gotoxy(20,10);
	printf("\xB2");gotoxy(46,10);printf("\xB2");
	gotoxy(20,11);
	printf("\xB2");gotoxy(46,11);printf("\xB2");
	gotoxy(20,12);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	gotoxy(21,5);
	printf("Category:");
	gotoxy(31,5);
	printf("%s",catagories[choice-1]);
	gotoxy(21,6);
	printf("Book ID:");
	gotoxy(30,6);
	scanf("%d",&bookID);
	if(checkid(bookID) == 0)
	{
		gotoxy(21,13);
		printf("The book id already exists");
		getch();
		addbooks();
		return 0;
	}
	book.id=bookID;
	gotoxy(21,7);
	printf("Book Name:");gotoxy(33,7);
	scanf("%s",book.name);
	gotoxy(21,8);
	printf("Author:");gotoxy(30,8);
	scanf("%s",book.Author);
	gotoxy(21,9);
	printf("Quantity:");gotoxy(31,9);
	scanf("%d",&book.quantity);
	gotoxy(21,10);
	printf("Price:");gotoxy(28,10);
	scanf("%f",&book.Price);
	gotoxy(21,11);
	printf("Rack No:");gotoxy(30,11);
	scanf("%d",&book.rackno);
	return 1;
}

int checkid(int t)  //check whether the book is exist in library or not
{
    FILE *temp;
	temp = fopen("Record.dat","rb+");
	while(fread(&book,sizeof(book),1,temp)==1)
        if(book.id == t){
            fclose(temp);
            return 0;
        }
        fclose(temp);
        return 1;

}

void searchByID(){
    system("cls");
    int id; FILE *fp;
    gotoxy(25,4);
    printf("****Search Books By Id****");
    gotoxy(20,5);
    printf("Enter the book id:");
    scanf("%d",&id);
    int findBook = 0;
    fp = fopen("Record.dat","rb");
    while(fread(&book,sizeof(book),1,fp)==1){
        if(book.id==id){
            Sleep(2);
            gotoxy(20,7);
            printf("The Book is available");
            gotoxy(20,8);
            printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
            gotoxy(20,9);
            printf("\xB2 ID:%d",book.id);gotoxy(47,9);printf("\xB2");
            gotoxy(20,10);
            printf("\xB2 Name:%s",book.name);gotoxy(47,10);printf("\xB2");
            gotoxy(20,11);
            printf("\xB2 Author:%s ",book.Author);gotoxy(47,11);printf("\xB2");
            gotoxy(20,12);
            printf("\xB2 Qantity:%d ",book.quantity);gotoxy(47,12);printf("\xB2"); gotoxy(47,11);printf("\xB2");
            gotoxy(20,13);
            printf("\xB2 Price:Rs.%.2f",book.Price);gotoxy(47,13);printf("\xB2");
            gotoxy(20,14);
            printf("\xB2 Rack No:%d ",book.rackno);gotoxy(47,14);printf("\xB2");
            gotoxy(20,15);
            printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
            findBook = 1;
        }
    }
    if(findBook == 0){  //checks whether conditiion enters inside loop or not
        gotoxy(20,8);
        printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
        gotoxy(20,9);printf("\xB2");  gotoxy(38,9);printf("\xB2");
        gotoxy(20,10);
        printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
        gotoxy(22,9);printf("\aNo Record Found");
    }
    fclose(fp);
    gotoxy(20,17);
    printf("Try another search?(Y/N)");
    if(getch()=='y')
        searchByID();
    else
        mainmenu();
}

void searchByName(){
    system("cls");
    char s[15];
    int d=0;
    FILE *fp;
    gotoxy(25,4);
    printf("****Search Books By Name****");
    gotoxy(20,5);
    printf("Enter Book Name:");
    scanf("%s",s);
    fp = fopen("Record.dat","rb");
    while(fread(&book,sizeof(book),1,fp)==1){
        if(strcmp(book.name,(s))==0){ //checks whether book.name is equal to s or not
            gotoxy(20,7);
            printf("The Book is available");
            gotoxy(20,8);
            printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
            gotoxy(20,9);
            printf("\xB2 ID:%d",book.id);gotoxy(47,9);printf("\xB2");
            gotoxy(20,10);
            printf("\xB2 Name:%s",book.name);gotoxy(47,10);printf("\xB2");
            gotoxy(20,11);
            printf("\xB2 Author:%s",book.Author);gotoxy(47,11);printf("\xB2");
            gotoxy(20,12);
            printf("\xB2 Qantity:%d",book.quantity);gotoxy(47,12);printf("\xB2");
            gotoxy(20,13);
            printf("\xB2 Price:Rs.%.2f",book.Price);gotoxy(47,13);printf("\xB2");
            gotoxy(20,14);
            printf("\xB2 Rack No:%d ",book.rackno);gotoxy(47,14);printf("\xB2");
            gotoxy(20,15);
            printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
            d++;
        }
    }
    if(d==0){
        gotoxy(20,8);
        printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
        gotoxy(20,9);printf("\xB2");  gotoxy(38,9);printf("\xB2");
        gotoxy(20,10);
        printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
        gotoxy(22,9);printf("\aNo Record Found");
    }
    fclose(fp);
    gotoxy(20,17);
    printf("Try another search?(Y/N)");
    if(getch()=='y')
        searchByName();
    else
        mainmenu();
}

