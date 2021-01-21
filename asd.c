#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include <wincon.h>
#include <processenv.h>
#include <stdlib.h>
 
/*
 
Random sayı belirlemede kullanılan <time.h> kütüphanesi öğesi.
 
srand(time(NULL));
int iAmRaiDeiN=0+rand()%9;
 
*/
 
 
void clrscr(){
	system("CLS"); 
}
 
struct calisanBilgisi{
	
	char isim[20];
	char soyIsim[20];
	int maas;
	
};
 
void gotoxy(short d,short y){
	COORD pos = {d,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
 
void hg(){
	
	printf("\n\n\n\t\t\t\tPersonel Bilgileri Kayitlama Programina HOSGELDINIZ..(version 0,1-7.12.2019)[Created By RaiDeiN]");
}
 
int giris(char admIdData[15],char admPwData[15]){
	char admId[15],admPw[15];
	int hata=0;
	while(hata==0)
	{
	printf("\n\n-------------Admin Giris Paneli-------------");
	printf("\n|                                          |");
	printf("\n| Kullanici Adi :                          |");
	printf("\n|                                          |");
	printf("\n| Sifre         :                          |");
	printf("\n|                                          |");
	printf("\n--------------------------------------------");
	printf("\n");
	gotoxy(18,7);scanf("%s",&admId);
	gotoxy(18,9);scanf("%s",&admPw);
	printf("\n");
	if(strcmp(admId,admIdData)==0 && strcmp(admPw,admPwData)==0)
		{
			printf("\n\n=========================================");
			printf("\n\tGiris Isleminiz Basarili..");
			printf("\n=========================================\n");
			hata=1;
		}
	else if(strcmp(admId,admIdData)!=0 || strcmp(admPw,admPwData)!=0)
		{
			printf("\n\n=========================================");
			printf("\n\tHatali Giris Yaptiniz..");
			printf("\n=========================================\n");
			printf("\n ------> Yeniden denemek icin bir tusa basiniz."); getch(); clrscr(); hg();
		}
	}
}
 
int personelBilgiGiris(int j){
	int i,sira;
	struct calisanBilgisi prsnlBlgGrs[j];
	for(i=1;i<=j;++i){
		printf("\n|-----------------------------------------|");
		printf("\n|                                         |");
		printf("\n| %d. Personelin bilgilerini giriniz !     |",i);
		printf("\n|                                         |");
		printf("\n| Personelin ismi    :                    |");
		printf("\n|                                         |");
		printf("\n| Personelin Soyismi :                    |");
		printf("\n|                                         |");
		printf("\n| Personelin Maasi   :                    |");
		printf("\n|                                         |");
		printf("\n|-----------------------------------------|\n\n");
		printf("\n");
		sira=i*10;
		gotoxy(23,16+sira); scanf("%s",&prsnlBlgGrs[i].isim);
		gotoxy(23,18+sira); scanf("%s",&prsnlBlgGrs[i].soyIsim);
		gotoxy(23,20+sira); scanf("%d",&prsnlBlgGrs[i].maas);	
	}
}
 
int personelAdet(){
	int prsnlAdt;
	printf("\nKac personelin bilgisini girmek istiyorsunuz ? \n\n ---------->  : ");
	scanf("%d",&prsnlAdt);
	personelBilgiGiris(prsnlAdt);
}
 
int main(){
	char admIdData[15]="RaiDeiN";
	char admPwData[15]="Rai123.";
	hg();
	giris(admIdData,admPwData);
	personelAdet();
		
	return 0;
}
