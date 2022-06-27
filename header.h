struct accinfo
{
    int cardnumber;
    int pin;
    float balance;
}a;
int auth_cardnumber(struct accinfo *p[],int n);
int auth_pin(struct accinfo *p[],int now);
void checkbalance(struct accinfo *p[],int now);
void deposit(struct accinfo *p[],int now);
void withdraw(struct accinfo *p[],int now);
void changepin(struct accinfo *p[],int now);