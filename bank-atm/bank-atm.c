/*atm.c
*Bilal Ozcan
*Tek bir kullanicinin banka hesabini tutan atm programi
*/

#include <stdio.h>

	int main (){
	
		printf("Merhaba bankaniza hosgeldiniz!\n");
		
		int sifre = 1234;		/*Degiskenler*/
		int bakiye = 100;
		int a, islem, tutar;
		
		printf("Lutfen sifrenizi giriniz:\n");
		
		scanf("%d",&a);
		
		if (a==sifre) {  /*Kullanicinin girdigi sifreyi kontrol etme*/
			printf("Sifreniz dogru!\nLutfen yapacaginiz islemi seciniz:\n");
			printf("Para yatirmak icin 1\nPara cekmek icin 2\nHesap bakiyenizi gormek icin 3 giriniz\n>");
			
			scanf("%d",&islem);
		}
			
		else {
			printf("Girdiginiz sifre yanlis!");	
			return 0;
			}	
		
		switch(islem) {  /*Kullanicinin girdigi degere gore islem yaptiran switch-case fonksiyonu*/
			
			case 1:
			
				printf("Bakiyeniz:%d\n",bakiye);
			
				printf("Lutfen yatirmak istediginiz miktari giriniz>\n");
					
				scanf("%d",&tutar);	
					
				if(tutar > 0 ) {
					 bakiye = bakiye+tutar;
					printf("Paraniz yatirilmistir\n");
					printf("Yeni bakiyeniz:%d",bakiye); 
				}
				
				else {
					printf("Gecersiz islem!\n");
				}
				break;
				
			case 2:
				
				printf("Bakiyeniz:%d\n",bakiye);
					
				printf("Lutfen cekmek istediginiz tutari giriniz>\n");
					
				scanf("%d",&tutar);
					
					if((tutar > 0)&&(tutar<bakiye)) {
				
						bakiye = bakiye-tutar;
						
						printf("Para cekme isleminiz gerceklesmistir!\n");
						printf("Lutfen paranizi para cekme bolgesinden aliniz.\n");
						printf("Kalan bakiyeniz:%d\n",bakiye); 
						}
					else {
						printf("Yetersiz bakiye!\n");
					}		
		
				break;
					
			case 3:
				
				printf("Bakiyeniz:%d",bakiye);
				
				break;
					
			default:
				
				printf("Gecersiz Islem!");
			
		}
 }
