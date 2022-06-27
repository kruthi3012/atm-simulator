#include "header.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int auth_cardnumber(struct accinfo *p[],int n)
    {
        int flag=0;
        int ipcardnumber; //input cardnumber
        printf("\nenter 8-digit cardnumber: ");
        scanf("%d",&ipcardnumber);

        for(int j=0;j<n;j++)
        {
            if((p[j]->cardnumber)==ipcardnumber)
            {
                printf("\ncardnumber verified\n");
                flag=-1;
                return j;
            }
        }
        
        if(flag==0)
        {
            printf("\ncardnumber not found\n Please try again");
            return -1;
        }
    }


int auth_pin(struct accinfo *p[],int now)
{
    int flag=0;
    int ippin; //input pin
    printf("\nenter 4-digit pin: ");
    scanf("%d",&ippin);

    if((p[now]->pin)==ippin)
    {
        printf("\npin verified\n");
        flag=-1;
        return 0;
    }

    if(flag==0)
    {
        printf("\nincorrect pin\n Please try again");
        return -1;
    }
}

void checkbalance(struct accinfo *p[],int now)
{
    printf("\n****************************************");
    printf("\nYour account balance is: %.2f",p[now]->balance);
}

void deposit(struct accinfo *p[],int now)
{
    float depositrs;
    printf("\n****************************************");
    printf("\nYour account balance is: %.2f",p[now]->balance);
    printf("\nEnter amount you want to deposit: ");
    scanf("%f",&depositrs);
    p[now]->balance+=depositrs;
    printf("\nYour new balance is: %.2f",p[now]->balance);
}


void withdraw(struct accinfo *p[],int now)
{
    float withdrawrs;

    printf("\n****************************************");
    printf("\nYour account balance is: %.2f",p[now]->balance);
    printf("\nEnter amount you want to withdraw: ");
    scanf("%f",&withdrawrs);

    if(withdrawrs<=(p[now]->balance))
    {
        p[now]->balance-=withdrawrs;
        printf("\nYour new balance is: %.2f",p[now]->balance);
    }
    else
    {
        printf("You can't withdraw more than the balance");
    }

}


void changepin(struct accinfo *p[],int now)
{
    int old_pin,new_pin1,new_pin2;

    printf("\n****************************************");
    printf("\nConfirm your previous pin: ");
    scanf("%d",&old_pin);

    if((p[now]->pin)==old_pin)
    {
        printf("Enter new PIN number: ");
        scanf("%d",&new_pin1);
        printf("Confirm new PIN again: ");
        scanf("%d",&new_pin2);
        
        if(new_pin1==new_pin2)
        {
            p[now]->pin=new_pin1;
            printf("Your PIN has been changed successfully");
        }

        else
        {
            printf("Entries not matching. Please try again");
        }
    }

    else
    {
        printf("Incorrect PIN. Please try again");
    }
}