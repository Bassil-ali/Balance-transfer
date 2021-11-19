#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>
struct customer
{
int id;
char name[40];
int balance;
}x;
char ans;
char name[40];
int id,balance;
void arow()
{
  printf("\n\n\t\t");
  for(int i=1;i<=5;i++)
      {
      printf(">");
      sleep(1);
      }
}
void load()
{
  clrscr();
  printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t LOADING.");
  for(int i=1;i<=3;i++)
  {
    sleep(1);
    printf(".");
  }
  clrscr();
}
//void again();

void main()
{
int selec,y;
int lable=0;
FILE *ptr,*ptr2;
again:
;
load();
textbackground(0);
textcolor(7);
clrscr();
printf("\n\n\n\n\n\n\n\t\t 1. Add customer");
printf("\n\t\t 2. View customers");
printf("\n\t\t 3. Search customer");
printf("\n\t\t 4. Modify customer");
printf("\n\t\t 5. Delete customer");
printf("\n\t\t 6. Transfer balance");
printf("\n\t\t 7. Exit");
printf("\n\n\t    Enter your selection : ");
scanf("%d",&selec);
if(selec<0||selec>7)
{
printf("\n\n  Out of range please reinter your choise \n");
goto again;
}
else
   if(selec==1)
   {
      clrscr();
      ptr=fopen("customer.txt","a+b");
      if(ptr==0)
      {
	textcolor(140);
	cprintf("\n\n\n\tEror in opining the file!");
	getch();
	exit(0);
      }
      do
      {

	printf("\n\n\n\n\t\tinter customer ID : ");
	id:;
	scanf("%d",&id);
	rewind(ptr);
	while(1)
	{
	  y=fread(&x,sizeof(x),1,ptr);
	  if(y==0)break;
	  if(id==x.id)
	  {
	    printf("\n\n\t ID already exsist, inter another ID : ");
	    goto id;
	  }
	  else
	    x.id=id;
	}
	fflush(stdin);
	printf("\n\t\tinter name: ");gets(x.name);
	printf("\n\t\tinter balance : ");scanf("%d",&x.balance);
	fwrite(&x,sizeof(x),1,ptr);
	printf("\n\n\tAdd another customer(y\\n)? : ");
	ans=getch();
	if(ans=='n'||ans=='N')
	break;

      }while(ans=='y');
      fclose(ptr);
      printf("\n\n\t\t");
      arow();
      textcolor(130);
      cprintf(" saved!");
      printf("\n\n\t Select again(y\\n)? : ");
      ans:
      ;
      ans=getch();
      if(ans=='y'||ans=='Y')
      {
      goto again;
      }
      else
      if(ans=='n'||ans=='N')
      exit(0);
      else
      {
      printf("\n\n\t Unexpected anser! ,Pleas select y or n : ");
      goto ans;
      }

   }
   else
   if(selec==2)
   {
      clrscr();
      ptr=fopen("customer.txt","rb");
      if(ptr==0)
      {
      textcolor(140);
      cprintf("Eror in opining the file!");
      getch();
      exit(0);
      }
      load();
      printf("\n\n\n\n\n\n\t\tId\tName\t\tbalance");
      printf("\n\t     ---------------------------------------");
      //int count=1;
      while(1)
      {
      y=fread(&x,sizeof(x),1,ptr);
      if(y==0)break;
       //if(x.id==count)
       //{
	printf("\n\t\t%d\t%s\t\t%d",x.id,x.name,x.balance);
       //	rewind(ptr);
       //	count++;
       //d}

      }
      fclose(ptr);
      printf("\n\n\t Select again(y\\n)? : ");
      ans2:
      ;
      ans=getch();
      if(ans=='y'||ans=='Y')
      goto again;
      else
      if(ans=='n'||ans=='N')
      exit(0);
      else
      {
      printf("Unexpected anser! ,Pleas select y or n : ");
      goto ans2;
      }

   }
   else
   if(selec==3)
   {
      clrscr();
      ptr=fopen("customer.txt","rb");
      if(ptr==0)
      {
	textcolor(140);
	cprintf("\n\n\n\tEror in opining the file!");
	getch();
	exit(0);
      }
      printf("\n\n\n\t\tSearch by ID : ");
      scanf("%d",&id);
      printf("\n\n\t\tSearching.");
      for(int i=1;i<=2;i++)
      {
      sleep(1);
      printf(".");
      }
      printf("\n\n");
      rewind(ptr);
      while(1)
      {
	 y=fread(&x,sizeof(x),1,ptr);
	 if(y==0)break;
	 if(id==x.id)
	 {
	 printf("\n\t\tId\tName\t\tbalance");
	 printf("\n\t   -------------------------------------------");
	 printf("\n\t\t%d\t%s\t\t%d",x.id,x.name,x.balance);
	 lable=1;
	 }
      }
      if(lable==0)
      {
      printf("\n\t\t");
      textcolor(140);
      cprintf("Not found!");
      }
      fclose(ptr);
      printf("\n\n\n\t Select again(y\\n)? : ");
      ans3:
      ;
      ans=getch();
      if(ans=='y'||ans=='Y')
      goto again;
      else
      if(ans=='n'||ans=='N')
      exit(0);
      else
      {
      printf("Unexpected anser! ,Pleas select y or n : ");
      goto ans3;
      }
   }
   else
   if(selec==4)
   {
     clrscr();
     ptr2=fopen("tempr.txt","wb");
     ptr=fopen("customer.txt","rb");
      if(ptr==0)
      {
      textcolor(140);
      cprintf("Eror in opining the file!");
      getch();
      exit(0);
      }
      printf("\n\n\t\tID of customer you want to modify : ");scanf("%d",&id);
      lable=0;
      rewind(ptr);
      while(1)
      {

	y=fread(&x,sizeof(x),1,ptr);
	if(y==0)break;
	if(x.id==id)
	{
	  printf("\n\n\t\tReinter Information");
	  printf("\n\n\t\t New ID : ");scanf("%d",&x.id);
	  printf("\n\t\t New name : ");fflush(stdin);gets(x.name);
	  printf("\n\t\t New balance : ");scanf("%d",&x.balance);
	  lable=1;
	}
	fwrite(&x,sizeof(x),1,ptr2);
     }
      if(lable==0)
      {
	arow();
	textcolor(140);
	cprintf("Can't find customer!");
      }
      else
      {
	arow();
	textcolor(130);
	cprintf(" Modified!");
      }
      fclose(ptr2);
      fclose(ptr);
      remove("customer.txt");
      rename("tempr.txt","customer.txt");
      printf("\n\n\t Select again(y\\n)? : ");
      ans10:
      ;
      ans=getch();
      if(ans=='y'||ans=='Y')
      goto again;
      else
      if(ans=='n'||ans=='N')
      exit(0);
      else
      {
      printf("Unexpected anser! ,Pleas select y or n : ");
      goto ans10;
      }
   }
   else
   if(selec==5)
   {
       clrscr();
       ptr2=fopen("Temp.txt","wb");
       ptr=fopen("customer.txt","rb");

	    printf("\n\n\n\tEnter ID of customer to delete: ");
	    scanf("%d",&id);
	    lable=0;
	    rewind(ptr);
	    while(1)
	    {
		y=fread(&x,sizeof(x),1,ptr);
		if(y==0)break;
		if(x.id==id)
		  lable=1;
		if(id!=x.id)
		  fwrite(&x,sizeof(x),1,ptr2);
	    }
	    if(lable==0)
	    {
	      arow();
	      textcolor(140);
	      cprintf("Cant find customer!");
	    }
	    else
	    {
	      arow();
	      textcolor(130);
	      cprintf(" Deleted! ");
	    }
	    fclose(ptr);
	    fclose(ptr2);
	    remove("customer.txt");
	    rename("Temp.txt","customer.txt");
	    printf("\n\n\t Select again(y\\n)? : ");
	    ans11:
	    ;
	    ans=getch();
	    if(ans=='y'||ans=='Y')
	    goto again;
	    else
	    if(ans=='n'||ans=='N')
	    exit(0);
	    else
	    {
	    printf("Unexpected anser! ,Pleas select y or n : ");
	    goto ans11;
	    }
   }
   else
   if(selec==6)
   {
   clrscr();
   int idFrom,idTo,balance;
   ptr2=fopen("tempr.txt","wb");
   ptr=fopen("customer.txt","rb");
      if(ptr==0)
      {
	textcolor(140);
	cprintf("\n\n\n\tEror in opining the file!");
	getch();
	exit(0);
      }
      printf("\n\n\n\t\t ID you want to transfer from : ");
      scanf("%d",&idFrom);

      printf("\n\t\t ID you want to transfer to : ");
      scanf("%d",&idTo);

      printf("\n\t\t balance you want to transfer : ");
      scanf("%d",&balance);
      rewind(ptr);
      int b1=0,b2=0;
      while(1)
      {
	 y=fread(&x,sizeof(x),1,ptr);
	 if(y==0)break;

	 if(x.id==idFrom)
	 {
	   if(x.balance>balance)
	   {
	     x.balance=x.balance-balance;
	   }
	    else
	   {
	     printf("\n\t Unable to transfer!,pleas check you balance and try again ");
	     printf("\n\n\t\t Check your balance(y\\n)? : ");
	     ans=getch();
	     if(ans=='y')
	     {
		printf("\n\n\t\tId\tName\t\tbalance");
		printf("\n\t   -------------------------------------------");
		printf("\n\t\t%d\t%s\t\t%d",x.id,x.name,x.balance);
	     }
	   }
	   b1=1;
	 }
	 if(idTo==x.id&&x.balance>balance)
	 {
	 x.balance=x.balance+balance;
	 b2=1;
	 }
	 fwrite(&x,sizeof(x),1,ptr2);
      }
      if(b1==0||b2==0)
      {
	arow();
	textcolor(140);
	cprintf("One of the IDs is valid!");
      }
      else
      {
	arow();
	textcolor(130);
	cprintf("Transfer completed! ");
      }
      fclose(ptr);
      fclose(ptr2);
      remove("customer.txt");
      rename("tempr.txt","customer.txt");
      printf("\n\n\t Select again(y\\n)? : ");
      ans5:
      ;
      ans=getch();
      if(ans=='y'||ans=='Y')
      goto again;
      else
      if(ans=='n'||ans=='N')
      exit(0);
      else
      {
      printf("Unexpected anser! ,Pleas select y or n : ");
      goto ans5;
      }
   }
   else
   if(selec==7)
   {
   exit(0);
   }
getch();
}
/*void again()
{
      printf("\n\n\t Select again(y\\n)? : ");
      ans:
      ;
      ans=getch();
      if(ans=='y'||ans=='Y')
      goto again;
      else
      if(ans=='n'||ans=='N')
      exit(0);
      else
      {
      printf("\n\n\t Unexpected anser! ,Pleas select y or n : ");
      goto ans;
      }

} */
