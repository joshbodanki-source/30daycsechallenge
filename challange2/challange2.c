                                                           challange2.c
#include<stdio.h>
int main(){
float distance, mileage, fuelprice, fuelrequired, totalcost;

printf("Enter total distance(km) : ");
scanf("%f",&distance);

printf("Enter vechile mileage(km/l) : ");
scanf("%f",&mileage);

printf("Enter fuel price : ");
scanf("%f",&fuelprice);

fuelrequired =  distance/mileage;
totalcost = fuelrequired * fuelprice;

printf("total fuel required : %f litres\n",fuelrequired);
printf("total fuel cost : %f\n",totalcost);

return 0;
}
