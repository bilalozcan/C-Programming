/* Bilal Özcan
 * 18120205035
 * PiSayisi.c 
 * Kare icine teget bir daireden olusan sekılde
 * rastgele nokta ureterek alanları oranından
 * yaklasık pi degerini bulma
 */
	
	
	#include <stdio.h>
	#include <stdlib.h>
	#include <math.h>

	int main (){
		
		double L = 37, N = 9998; /*Kenae uzunlugunu tutan L degiskeni ve Tekrar sayisini tutan N degiskeni */
		double x = 0, y = 0, n_daire = 0, fark = 0, pi = 0; /*x degerini tutan x degiskeni,
															y degerini tutany degiskeni, 
															2 nokta arasi uzakligi tutan fark degiskeni ve
															pi degerini tutan pi degiskeni */
			for (int i = 1 ; i<=N ; i++){  /*1 den N ye kadar N defa adimlarin tekrar etmesini saglayan for dongusu */
				
				x = (rand()/(double )RAND_MAX)*L; /*rastgele bir [0-L] noktasi uretip x degiskenine atayan ifade*/
				y = (rand()/(double )RAND_MAX)*L; /*rastgele bir [0-L] noktasi uretip y degiskenine atayan ifade*/
				
				fark = ((x-L/2)*(x-L/2))+((y-L/2)*(y-L/2)); /*iki nokta arasi uzakligi bulan formulun karekok ici*/
				fark = sqrt(fark);				/*fark ifadesinin kokunu alan ifade*/
					
					if(fark<=L/2){    /*eger uretilen nokta yaricapdan kucukse dairenin icinde bir nokta oldugunu tespit eden ifade*/
						n_daire++;
					}
								
			}
		
		pi = (4*n_daire)/N;  /*Alanlar oranindanyaklasik pi degerini bulan ifade*/
		printf("hesaplanan pi degeri:%lf",pi);
		
			
	}
