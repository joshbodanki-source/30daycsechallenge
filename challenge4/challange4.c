#include<stdio.h>
int main(){
float expense, total = 0;
int low = 0, medium = 0, high = 0;
printf("LOOPLAB - analysis of daily expense\n");
printf("Enter expense:");
scanf("%f",&expense);
while (expense != 0)
{ if(expense > 0)
  { total = total + expense;
if(expense <= 100)
{ low++;
printf("low expense\n");
}
else if(expense <= 500)
{medium++;
printf("medium expense\n");
}else
{ high++;
printf("high expense\n");
 }
}
else
{ printf("invalid amount\n");
}
printf("Enter expense:");
scanf("%f",&expense);
}
printf("low expenses:%d\n",low);
printf("medium expenses:%d\n",medium);
printf("high expense:%d\n",high);
printf("total expense:%.2f\n",total);
return 0;
}
