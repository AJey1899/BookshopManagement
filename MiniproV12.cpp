#include<windows.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<dos.h>
#include<time.h>
#define RETURNTIME 15
struct books
{
    char stname[20];
    char name[20];
    char Author[20];
    int quantity;
    float price;
    int count;
    int edition;
    int billno;
    char cust_name[50];
    float total_amt;
};
struct books a,c,e,m;
void check_availability(void);
void returnfunc(void);
void mainmenu(void);
void addbooks(void);
void search_bills(void);
void Password();
void issuerecord();
void search_by_book_name();
void search_by_author_name();
void billing(struct books);
void loaderanim();
void viewbooks(void);
void viewstock(void);
void view_billing(void);
int getdata();
int checkid(int);
COORD coord = {0, 0};
COORD max_res,cursor_size;
void gotoxy (int x, int y)
{
        coord.X = x; coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}
int i;
FILE *fp,*ft,*fs,*fg,*fz;
int s;
char dat_file[20];
char findbook;
char password[15]={"fbiopenup"};
int main()
{
      Password();
      _getch();
      return 0;
}
void mainmenu()
{
    system("cls");
    int i;
	gotoxy(20,3);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(20,5);
	printf("\xDB\xDB\xDB\xDB\xB2 1. Add Books");
	gotoxy(20,7);
	printf("\xDB\xDB\xDB\xDB\xB2 2. Check Availability");
	gotoxy(20,9);
	printf("\xDB\xDB\xDB\xDB\xB2 3. Billing List");
	gotoxy(20,11);
	printf("\xDB\xDB\xDB\xDB\xB2 4. Search Bills");
	gotoxy(20,13);
	printf("\xDB\xDB\xDB\xDB\xB2 5. Stock List");
	gotoxy(20,15);
	printf("\xDB\xDB\xDB\xDB\xB2 6. Purchase List");
	gotoxy(20,17);
	printf("\xDB\xDB\xDB\xDB\xB2 7. Close Application");
	gotoxy(20,19);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	gotoxy(20,21);
	printf("Enter your choice:");
	switch(_getch())
	{
		case '1':
		addbooks();
		break;
		case '2':
        check_availability();
		break;
		case '3':
        view_billing();
        break;
        case '4':
		search_bills();
	    break;
        case '5':
		viewstock();
		case '6':
		viewbooks();
		case '7':
	    {
		system("cls");
		gotoxy(16,3);
		printf("Created by\n\t\tRoll numbers");
		gotoxy(16,4);
		printf("\n\t\t01,07,10,18 ");
		gotoxy(16,5);
		printf("\n\nExiting\n");
		for(i=0;i<5;i++)
        {
            printf(".\n");
            delay(300);
        }
		exit(0);
	    }
	    default:
		{
		gotoxy(10,23);
		printf("\aWrong Entry!!Please re-entered correct option");
		if(_getch())
		mainmenu();
		}
    }
}
void addbooks(void)
{
	system("cls");
	int i;
	system("cls");
	fz=fopen("stock.dat","ab+");
	fp=fopen("database.dat","ab+");
	if(getdata()==1)
	{
	fseek(fp,0,SEEK_END);
	fseek(fp,0,SEEK_END);
	fwrite(&a,sizeof(a),1,fz);
	fclose(fz);
	fwrite(&a,sizeof(a),1,fp);
	fclose(fp);
	gotoxy(21,14);
	printf("The record is sucessfully saved");
	gotoxy(21,15);
	printf("Save any more?(Y / N):");
	if(_getch()=='n')
	    mainmenu();
	else
	    system("cls");
	    addbooks();
	}
}
void check_availability()
{
    system("cls");
    int d;
    char s[100];
    printf("*****************************Search Books*****************************");
    gotoxy(20,10);
    printf("\xDB\xDB\xDB\xB2 1. Search By Name");
    gotoxy(20,12);
    printf("\xDB\xDB\xDB\xB2 2. Search by Author Name");
    gotoxy(15,20);
    printf("Enter Your Choice");

    switch(_getch())
    {
	case '1':
                search_by_book_name();
                break;


	case '2':   search_by_author_name();
                break;
	default :
	_getch();
	check_availability();
    }
    fclose(fp);
}
void search_by_book_name(void)
{
        char s[15];
	    system("cls");
	    gotoxy(25,4);
	    fp=fopen("stock.dat","rb+");
        rewind(fp);
	    printf("****Search Books By Name****");
	    gotoxy(20,5);
	    printf("Enter Book Name:");
	    scanf("%s",s);
	    int d=0;
	    while(fread(&a,sizeof(a),1,fp)==1)
	    {
		if(strcmp(a.name,(s))==0)
		{
		    gotoxy(20,7);
		    printf("Book Details");
	        gotoxy(20,10);
		    printf("Name:%s",a.name);
		    gotoxy(20,11);
		    printf("Author:%s",a.Author);
		    gotoxy(20,12);
		    printf("Quantity:%d",a.quantity);
		    gotoxy(20,13);
		    printf("Price:Rs.%.2f",a.price);
		    gotoxy(20,14);
            printf("Edition:%d",a.edition);
            gotoxy(20,15);
		    d++;
            printf("Do you want to buy?(Y/N)");
	    if(_getch()=='y')
        {
            if(a.quantity <= 0)
            {
                gotoxy(20,16);
                printf("Sorry...... This Book is currently out of stock\n");
                break;
            }
            else
            {
                c=a;
                m=c;
                system("cls");
                fseek(fp,ftell(fp)-sizeof(a),0);
                printf("Quantity?");
                scanf("%d",&c.quantity);
                c.price=c.price*c.quantity;
                a.quantity=a.quantity-c.quantity;
                fwrite(&a,sizeof(a),1,fp);
                fclose(fp);
                billing(c);
            }
        }
		}
	    }
	    if(d==0)
	    {
            gotoxy(20,8);
            gotoxy(22,9);
            printf("\aNo Record Found");
	    }
	    gotoxy(20,20);
	    printf("Try another search?(Y/N)");
	    if(_getch()=='y')
            check_availability();
	    else
            mainmenu();
}
void search_by_author_name(void)
{
    int i=0,j;
    char aut[100];
    system("cls");
    gotoxy(1,1);
    j=4;
    fp=fopen("stock.dat","rb");
    rewind(fp);
    printf("Enter Author Name:");
    scanf("%s",aut);
    int d=0;
    system("cls");
    gotoxy(1,1);
    printf("*****************************Book List*****************************");
    gotoxy(2,2);
    printf("BOOK NAME               AUTHOR                 EDITION     QTY     PRICE");
    while(fread(&a,sizeof(a),1,fp)==1)
    {
    if(strcmp(a.Author,aut)==0)
    {
        gotoxy(2,j);
        printf("%s",a.name);
        gotoxy(26,j);
        printf("%s",a.Author);
        gotoxy(52,j);
        printf("%d",a.edition);
        gotoxy(62,j);
        printf("%d",a.quantity);
        gotoxy(69,j);
        printf("%.2f",a.price);
        printf("\n\n");
        j++;
        d++;
        i=i+a.quantity;
     }
}
    gotoxy(3,25);
    printf("Total Books =%d\n",i);
    fclose(fp);
    fseek(fp,0,SEEK_SET);
    printf("Want to buy any of these?(Y/N)\n");
    if(_getch()=='y')
    {
        search_by_book_name();
    }
    else
    mainmenu();
    gotoxy(35,25);
    returnfunc();
}
void search_bills()
{
    system("cls");
    int d;

    printf("*****************************Search Bills*****************************");
    gotoxy(20,10);
    printf("\xDB\xDB\xDB\xB2 1. Search By Name");
    gotoxy(20,12);
    printf("\xDB\xDB\xDB\xB2 2. Search by Author Name");
    gotoxy(20,14);
    printf("\xDB\xDB\xDB\xB2 3. Search by Bill no.");
    gotoxy(15,25);
    printf("Enter Your Choice:");
    switch(_getch())
    {
	case '1':
	{
	    char s[15];
	    system("cls");
	    int i=0,j;
        fz=fopen("billing.dat","rb+");
        rewind(fz);
	    printf("Enter Book Name:");
	    scanf("%s",s);
        system("cls");
        gotoxy(1,1);
        printf("******************************Book List*****************************");
        gotoxy(2,2);
        printf("BOOK NAME               AUTHOR                 EDITION     QTY     PRICE     BILL NO.");
        j=4;

        while(fread(&m,sizeof(m),1,fz)==1)
        {
        if(strcmp(m.name,s)==0)
            {
            gotoxy(2,j);
            printf("%s",m.name);
            gotoxy(26,j);
            printf("%s",m.Author);
            gotoxy(52,j);
            printf("%d",m.edition);
            gotoxy(62,j);
            printf("%d",m.quantity);
            gotoxy(69,j);
            printf("%.2f",m.total_amt);
            gotoxy(79,j);
            printf("%d",m.billno);
            printf("\n\n");
            j++;
            i=i+m.quantity;
          }
          }
          gotoxy(3,25);
          printf("Total Books =%d",i);
          fclose(fz);
          fseek(fz,0,SEEK_SET);
          gotoxy(35,25);
          returnfunc();
    }
	break;
	case '2':
	    {
        char aut[100];
	    system("cls");
	    int i=0,j;
	    printf("Enter Author Name:");
	    scanf("%s",aut);
        system("cls");
        gotoxy(1,1);
        printf("*****************************Bill List*****************************");
        gotoxy(2,2);
        printf("BOOK NAME               AUTHOR                 EDITION     QTY     PRICE     BILL NO.");
        j=4;
        fg=fopen("billing.dat","rb+");
        rewind(fg);
        while(fread(&c,sizeof(c),1,fg)==1)
        {
         if(strcmp(c.Author,aut)==0)
            {
            gotoxy(2,j);
            printf("%s",c.name);
            gotoxy(26,j);
            printf("%s",c.Author);
            gotoxy(52,j);
            printf("%d",c.edition);
            gotoxy(62,j);
            printf("%d",c.quantity);
            gotoxy(69,j);
            printf("%.2f",c.total_amt);
            gotoxy(79,j);
            printf("%d",c.billno);
            printf("\n\n");
            j++;
            i=i+c.quantity;
          }
        }
          gotoxy(3,25);
          printf("Total Books =%d",i);
          fclose(fg);
          gotoxy(35,25);
          returnfunc();
            break;
	    }
    case '3':
            {
            int bill;
            system("cls");
            gotoxy(25,4);
            printf("****Search Books By Bill no****");
            gotoxy(20,5);
            printf("Enter Bill no:");
            scanf("%d",&bill);
            int d=0;
            fp=fopen("billing.dat","rb+");
            rewind(fp);
            while(fread(&c,sizeof(c),1,fp)==1)
            {
            if(c.billno==bill)
            {
                gotoxy(20,7);
                printf("The Book is available");
                gotoxy(20,10);
                printf("Name:%s",c.name);
                gotoxy(20,11);
                printf("Author:%s",c.Author);
                gotoxy(20,12);
                printf("Bill no:%d",c.billno);
                gotoxy(20,13);
                printf("Quantity:%d",c.quantity);
                gotoxy(20,14);
                printf("Price:Rs.%.2f",c.total_amt);
                gotoxy(20,15);
                printf("Edition:%d",c.edition);
                gotoxy(20,16);
                d++;
            }
	    }
	    if(d==0)
	    {
	    gotoxy(20,8);
	    gotoxy(22,9);printf("\aNo Record Found");
	    }
	    gotoxy(20,17);
	    printf("Try another search?(Y/N)");
	    if(_getch()=='y')
	    search_bills();
	    else
	    returnfunc();

            }
	default :
	_getch();
	search_bills();
    }
    //fclose(fp);
}


void Password(void)
{
    system("cls");
    char d[25]=" Password Protected";
    char ch,pass[10];
    int i=0,j;
    gotoxy(10,4);
    for(j=0;j<20;j++)
    {
        delay(50);
        printf("*");
    }
    for(j=0;j<20;j++)
    {
        delay(50);
        printf("%c",d[j]);
    }
    for(j=0;j<20;j++)
    {
        delay(50);
        printf("*");
    }
    gotoxy(10,10);
    gotoxy(15,7);
    printf("Enter Password:");
    while(ch!=13)
    {
        ch=_getch();
        if(ch!=13 && ch!=8)
        {
            putch('*');
            pass[i] = ch;
            i++;
        }
    }
    pass[i] = '\0';
    if(strcmp(pass,password)==0)
    {
        gotoxy(15,9);
        printf("Password match");
        gotoxy(17,10);
        printf("Press any key to countinue.....");
        _getch();
        mainmenu();
    }
    else
    {
        gotoxy(15,16);
        printf("\aWarning!! Incorrect Password");
        _getch();
        Password();
    }
}
int getdata()
{
	gotoxy(21,7);
	printf("Book Name:");gotoxy(33,7);
	scanf("%s",a.name);
	gotoxy(21,8);
	printf("Author:");gotoxy(30,8);
	scanf("%s",a.Author);
	gotoxy(21,9);
	printf("Quantity:");gotoxy(31,9);
	scanf("%d",&a.quantity);
	gotoxy(21,10);
	printf("Price:");gotoxy(28,10);
	scanf("%f",&a.price);
	gotoxy(21,11);
	printf("Edition:");gotoxy(31,11);
	scanf("%d",&a.edition);
    return 1;
}
void viewstock(void)  //show the list of books remaining in Bookshop
{
    int i=0,j;
    system("cls");
    gotoxy(1,1);
    printf("******************************Stock List*****************************");
    gotoxy(2,2);
    printf("BOOK NAME               AUTHOR                 EDITION     QTY     PRICE");
    j=4;
    fp=fopen("stock.dat","rb");
    while(fread(&a,sizeof(a),1,fp)==1)
    {
        gotoxy(2,j);
        printf("%s",a.name);
        gotoxy(26,j);
        printf("%s",a.Author);
        gotoxy(52,j);
        printf("%d",a.edition);
        gotoxy(62,j);
        printf("%d",a.quantity);
        gotoxy(69,j);
        printf("%.2f",a.price);
        printf("\n\n");
        j++;
        i=i+a.quantity;
    }
    gotoxy(3,25);
    printf("Total Books =%d",i);
    fclose(fp);
    gotoxy(35,25);
    returnfunc();
}
void viewbooks(void)  //show the list of purchase of books by bookshop
{
    int i=0,j;
    system("cls");
    gotoxy(1,1);
    printf("*****************************Purchase List*****************************");
    gotoxy(2,2);
    printf("BOOK NAME               AUTHOR                 EDITION     QTY     PRICE");
    j=4;
    fp=fopen("database.dat","rb");
    while(fread(&a,sizeof(a),1,fp)==1)
    {
        gotoxy(2,j);
        printf("%s",a.name);
        gotoxy(26,j);
        printf("%s",a.Author);
        gotoxy(52,j);
        printf("%d",a.edition);
        gotoxy(62,j);
        printf("%d",a.quantity);
        gotoxy(69,j);
        printf("%.2f",a.price);
        printf("\n\n");
        j++;
        i=i+a.quantity;
      }
      gotoxy(3,25);
      printf("Total Books =%d",i);
      fclose(fp);
      gotoxy(35,25);
      returnfunc();
}
void returnfunc(void)
{
    {
	printf(" Press ENTER to return to main menu");
    }
    a:
    if(_getch()==13)
    mainmenu();
    else
    goto a;
}
void view_billing()
{
   int i=0,j;
    system("cls");
    gotoxy(1,1);
    printf("*****************************Bill List*****************************");
    gotoxy(2,2);
    printf("BOOK NAME               AUTHOR                 EDITION     QTY     PRICE     BILL NO.");
    j=4;
    fg=fopen("billing.dat","rb");
    while(fread(&c,sizeof(c),1,fg)==1)
    {
        gotoxy(2,j);
        printf("%s",c.name);
        gotoxy(26,j);
        printf("%s",c.Author);
        gotoxy(52,j);
        printf("%d",c.edition);
        gotoxy(62,j);
        printf("%d",c.quantity);
        gotoxy(69,j);
        printf("%.2f",c.total_amt);
        gotoxy(79,j);
        printf("%d",c.billno);
        printf("\n\n");
        j++;
        i=i+c.quantity;
      }
      gotoxy(3,25);
      printf("Total Books =%d",i);
      fclose(fg);
      gotoxy(35,25);
      returnfunc();
}

void billing(struct books b)
{
            system("cls");
            printf("Enter bill no.\n");
            gotoxy(20,6);
            printf("Bill no:");
            gotoxy(20,7);
            scanf("%d",&b.billno);
            gotoxy(20,8);
            printf("Enter customer name\n");
            gotoxy(20,9);
            scanf("%s",b.cust_name);
            system("cls");
            gotoxy(20,9);
		    printf("Customer Name:%s",b.cust_name);
	        gotoxy(20,10);
		    printf("Book Name:%s",b.name);
		    gotoxy(20,11);
		    printf("Author:%s",b.Author);
		    gotoxy(20,12);
		    printf("Bill no.:%d",b.billno);
            gotoxy(20,13);
		    printf("Quantity:%d",b.quantity);
		    gotoxy(20,14);
		    printf("Price:Rs.%.2f",b.price);
		    gotoxy(20,15);
            printf("Edition:%d",b.edition);
            gotoxy(20,16);
            printf("GST:18 Percent");
            gotoxy(20,17);
            b.total_amt=b.price+(0.18*b.price);
            printf("Total Amount Including Taxes:Rs.%.2f",b.total_amt);
            gotoxy(20,19);
            fg=fopen("billing.dat","ab+");
            fseek(fg,0,SEEK_END);
            fwrite(&b,sizeof(b),1,fg);
            fclose(fg);
            //view_billing();
}
