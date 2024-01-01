#include <stdio.h>
#include <cs50.h>
#include <string.h>

int sayi_bulma(long number);
string basamak(long card_number);
int main(void)
{
int total=0,sayi=0,sayac=0;
string card_model="tanımsız";
long card_number;
do
{
card_number=get_long("Enter your card number : ");
}while(card_number<=0||card_number/1!=card_number);
do
{
 //sondan 1.basamak başlangıcı
sayi=sayi_bulma(card_number);
total+=sayi;
if(card_number!=0)
{
if(strcmp(card_model,"tanımsız")==0)
card_model=basamak(card_number);
card_number/=10; // diğer basamağa geçiş
sayac++;
}
//sondan 1.basamak sonu
//sondan 2.basamak başlangıcı
sayi=sayi_bulma(card_number);
sayi*=2;
if(sayi>10)
{
total+=sayi_bulma(sayi);
sayi/=10;
total+=sayi;
}
else if(sayi==10)
{
total+=1;
}
else
{
total+=sayi;
}
// dier basamağa geçiş
if(card_number!=0)
{
if(strcmp(card_model,"tanımsız")==0)
card_model=basamak(card_number);
card_number/=10; // diğer basamağa geçiş
sayac++;
}
//sondan 2.basamak
}while(card_number!=0);
if(total%10==0)
{
if(sayac==15&&strcmp(card_model,"American Express")==0)
{
printf("AMEX\n");
}
else if(sayac==16 && strcmp(card_model,"Master Card")==0)
printf("MASTERCARD\n");
else if((sayac==13||sayac==16)&&strcmp(card_model,"Visa")==0)
printf("VISA\n");
else
printf("INVALID\n");
}
else
{
printf("INVALID\n");
}
}
//son basamaktaki sayının kaç olduğunu bulan fonksiyon
int sayi_bulma(long number)
{
int sayis=0;
while(number%10!=0)
{
number--;
sayis++;
}
return sayis;
}
string basamak(long card_number)
{
string model="tanımsız";
if(card_number==34||card_number==37)
model="American Express";
else if(card_number==4)
model="Visa";
else if(card_number==51||card_number==52||card_number==53||card_number==54||card_number==55)
model="Master Card";
return model;
}
