#include<stdio.h>
int main(){
float purchase, distence, discountrate, discountamount, deliverycharge, finalamount;int customer;
printf("Enter purchase amount: ");
scanf("%f", &purchase);
printf("Enter customer type :");
scanf("%d", &customer);
printf("Enter delivery distence in km: ");
scanf("%f", &distence);
if(customer == 1)
{
   if(purchase >= 2000)
      discountrate = 15;
   else
      discountrate = 10;
}
else if(customer == 2)
{   if(purchase >= 3000)
       discountrate = 8;
    else
       discountrate = 0;}
else
{  printf("invalid customer type\n");
   return 0;}
discountamount = purchase * discountrate / 100;
if(distence <= 5)
   deliverycharge = 40;
else if (distence <= 15)
         deliverycharge = 70;
else
    deliverycharge = 100;
finalamount = purchase - discountamount + deliverycharge;
printf("purchase amount: rs. %.2f\n",purchase);
printf("discount amount: rs. %.2f\n",discountamount);
printf("delivery charge: rs. %.2f\n",deliverycharge);
printf("final amount: rs. %.2f\n",finalamount);
return 0;}
