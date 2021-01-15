#include <iostream>
#include <string>
#include <cstring>
#include <math.h>

//using namespace std;

int main(){
int employeeId;
char name[100];
double grossPay;
double tax;
double net;
double takeHome;

std::cout<<"Enter employee's number:";
std::cin>>employeeId;

std::cout<<"Enter employee's full name:";
getchar();
std::cin.getline(name,100);
//name[strlen(name)-1] = '\0';

std::cout<<"Enter gross salary for "<<name<<":";
std::cin>>grossPay;

std::cout<<"\nPaycheck for "<< name <<", employeeId "<<employeeId;

grossPay = round(grossPay*100.00)/100.00;
std::cout<<"\n\nGross Amount: ................ $ "<<grossPay;

std::cout<<"\n\nDeductions";

tax = (grossPay*.175);
tax = round(tax*100.00)/100.00;
std::cout<<"\nFederal Tax: ................. $ "<<tax;

tax = (grossPay*.091);
tax = round(tax*100.00)/100.00;
std::cout<<"\nState Tax: ................... $ "<<tax;

tax = (grossPay*.062);
tax = round(tax*100.00)/100.00;
std::cout<<"\nSocial Security Tax: ......... $ "<<tax;

tax = (grossPay*.0145);
tax = round(tax*100.00)/100.00;
std::cout<<"\nMedicare Tax: ................ $ "<<tax;

tax = (grossPay*.0929);
tax = round(tax*100.00)/100.00;
std::cout<<"\nRetirement Tax: .............. $ "<<tax;

tax = 51.48;
tax = round(tax*100.00)/100.00;
std::cout<<"\nHealth Insurance: ............ $ "<<tax;

tax = 3.71;
tax = round(tax*100.00)/100.00;
std::cout<<"\nLife insurance: .............. $ "<<tax;


net = grossPay - ((grossPay*.175)+(grossPay*.091)+(grossPay*.062)+(grossPay*.0145)+(grossPay*.0929)+(51.48)+(3.71));
net = round(net*100.00)/100.00;
std::cout<<"\n\nNet Pay: ..................... $ "<<net;

takeHome = net/grossPay;
takeHome = round(takeHome*10000)/100;
std::cout<<"\nPercent take home: ........... "<<"% "<<takeHome<<std::endl;
}


