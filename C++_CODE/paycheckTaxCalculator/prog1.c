#include <stdio.h>
#include <string.h>
#include <math.h>

int main(){
 int employeeId = 0;
 char name[100];
 double grossPay = 0.00;
 double tax = 0.00;
 double net = 0.00;
 double takeHome = 0.00;

 printf("Enter employee's number:");
 scanf("%d",&employeeId);

 printf("Enter employee's full name:");
 fgets(name,5,stdin);
 fgets(name,100,stdin);
 name[strlen(name) - 1] = '\0';

 printf("Enter gross salary for %s:",name);
 scanf("%lf",&grossPay);

 printf("\nPaycheck for %s, employeeId %d",name,employeeId);

 //grossPay = round(grossPay*100.00)/100.00;
 printf("\n\nGross Amount: ................ $%6.2lf",grossPay);

 printf("\n\nDeductions");

 tax = (grossPay*.175);
 printf("\nFederal Tax: ................. $ %6.2lf",tax);

 tax = (grossPay*.091);
 printf("\nState Tax: ................... $ %6.2lf",tax);

 tax = (grossPay*.062);
 printf("\nSocial Security Tax: ......... $ %6.2lf",tax);

 tax = (grossPay*.0145);
 printf("\nMedicare Tax: ................ $ %6.2lf",tax);

 tax = (grossPay*.0929);
 printf("\nRetirement Tax: .............. $ %6.2lf",tax);

 tax = 51.48;
 printf("\nHealth Insurance: ............ $ %6.2lf",tax);

 tax = 3.71;
 printf("\nLife insurance: .............. $ %6.2lf",tax);

 net = grossPay - ((grossPay*.175)+(grossPay*.091)+(grossPay*.062)+(grossPay*.0145)+(grossPay*.0929)+(51.48)+(3.71));
 //net = round(net*100.00)/100.00;
 printf("\n\nNet Pay: ..................... $ %5.2lf",net);

 takeHome = net/grossPay;
 //takeHome = round(takeHome*1000)/10;
 printf("\nPercent take home: ........... %% %6.2lf\n",takeHome);
 }

