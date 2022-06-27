#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "header.h"
int main()
{
    printf("\n*************************");
    printf("\nWelcome to ATM SIMULATOR\n");
    printf("***************************\n");

    FILE *fp=fopen("new.csv","r");

    char a[200];
    fgets(a,200,fp);
    char *buffer;

    struct accinfo s[250];
    int i=0;

    while(fgets(a,200,fp))
    {
        buffer=strtok(a,",");
        //printf("%s\t",buffer);
        s[i].cardnumber=atoi(buffer); //atoi to convert string to integer
        buffer=strtok(NULL,",");
        //printf("%s\t",buffer);
        s[i].pin=atoi(buffer);
        buffer=strtok(NULL,",");
        //printf("%s",buffer);
        s[i].balance=atof(buffer); //atof to convert string to integer
        i++;
    }

    fclose(fp);

    int n=i;

    struct accinfo *p[100];

    for(int j=0;j<n;j++)
    {
        p[j]=&s[j];
    }
    int nowforcred=0;
    int nowforpin=0;
    //disp(p,n);
      int x=1;
      int ch;
      char c='c';
      int lock=0;
      int now;
    while(lock!=3)
    {
      printf("Before starting lets verify its you.\n");
      nowforcred=auth_cardnumber(p,n);//index of record of current user
      //printf("\nnow=%d\n",nowforcred);
      if(nowforcred >=0)
      {
	nowforpin=auth_pin(p,nowforcred);
        //printf("\nnow=%d\n",nowforpin);
      }


       if(nowforcred==-1||nowforpin==-1)
      {
            printf("\n Wrong credentials\n");
            lock++;
            continue;
      }
      else
	  break;
      }

     if(lock==3) exit (0);
     printf("\nCorrect credentials \n");
            choices:
            printf("\n*******************************************************\nEnter your choice:\n");
            //printf("\n 1.Check balance \n 2.Deposit \n 3.Withdraw \n 4.Changepin \n 5.authorise pin(Verify)\n\n   0 to exit\n *******************************************************\n");
            printf("\n 1.Check balance \n 2.Deposit \n 3.Withdraw \n 4.Changepin \n\nPress 0 to exit\n *******************************************************\n");
            scanf("%d",&ch );
            switch(ch)
            {
                  case 1: checkbalance(p,nowforcred);
                          printf("\nDo you wanna choose another option:(Y/N): ");
                          scanf("%s",&ch);
			  if(ch=='Y'||ch=='y')
                              goto choices;
                          else break;
                  case 2: deposit(p,nowforcred);
                          printf("\nDo you wanna choose another option:(Y/N): ");
                          scanf("%s",&ch);
                          if(ch=='Y'||ch=='y')
                              goto choices;
                         else break;
                  case 3: withdraw(p,nowforcred);
                          printf("\nDo you wanna choose another option:(Y/N): ");
                          scanf("%s",&ch);
                          if(ch=='Y'||ch=='y')
                              goto choices;
                          else break;
                  case 4:changepin(p,nowforcred);
                          printf("\nDo you wanna choose another option:(Y/N): ");
                          scanf("%s",&ch);
                          if(ch=='Y'||ch=='y')
                              goto choices;
                          else break;
                  case 5: auth_pin(p,nowforcred);
                          printf("\nDo you wanna choose another option:(Y/N): ");
                          scanf("%s",&ch);
                          if(ch=='Y'||ch=='y')
                              goto choices;
                          else break;
                  case 0: exit(0);
            }
    

    //this section is to update all changes made during this transaction
    FILE *fw=fopen("new.csv","w");
    fprintf(fw,"cardnumber,pin,balance\n");

    i=0;
    while(i<n)
    {
        fprintf(fw,"%d,%d,%.2f\n",p[i]->cardnumber,p[i]->pin,p[i]->balance);
        i++;
    }

    fclose(fw);

    printf("\nRECORDS have been SAVED\n");
    printf("THANK YOU FOR BANKING WITH US");



}
