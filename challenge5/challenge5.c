#include<stdio.h>
#include<math.h>

int main(){
int option, number, step, answer;
float a, b, c, x, d, firstroot, secondroot;

for(option = 0; option !=4;){
printf("1.linear equation\n");
printf("2.factorial\n");
printf("3.quadratic equation\n");
printf("4.exit\n");
printf("choose an option: ");
scanf("%d",&option);

if(option == 1){
printf("enter a and b for ax + b = 0: ");
scanf("%f %f",&a,&b);

if(a == 0){
if(b==0){
printf("infinitely many solutions\n");
} else {
 printf("no solution\n");}
} else {
x = -b / a;
printf("x = %.2f\n",x);
}
}else if(option == 2){
printf("enter an integer from 0 to 12: ");
scanf("%d",&number);
if (number < 0 || number > 12){
printf("enter a number from 0 to 12\n");
} else{
answer = 1;

for(step = 1; step <= number; step++){
answer = answer * step;}

printf("%d! = %d\n", number, answer);}
}else if (option == 3){
printf("enter a, b, and c for ax^2 + bx +c = 0: ");
scanf("%f %f %f",&a ,&b ,&c);
if (a == 0){
printf("not a quadratic equation\n");
} else {
d = b * b - 4 * a * c;
if (d > 0){
firstroot = (-b + sqrt(d)) / (2 * a);
secondroot = (-b - sqrt(d)) / (2 * a);
printf("two real roots : %.2f and %.2f\n",firstroot ,secondroot);
} else if (d == 0){
firstroot = -b / (2 * a);
printf("one repeated root: %.2f\n", firstroot);
} else {
printf("no real root\n");
}
}
} else if (option == 4){
printf("good bye!\n");
} else {
printf("invalid choice. try again\n");
}
}
return 0;
}
