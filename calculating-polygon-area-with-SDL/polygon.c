/* Bilal Özcan
 * polygon.c
 * kullanicidan aldigi noktalarla tanimli,
 * bir polygonun alanini rastgele N tane nokta uretip
 * bu noktalardan polygonun icerisine dusenlerin sayisini kullanarak
 * polygonun alanini hesaplar.
 */


#include <stdio.h>
#include <stdlib.h>

#define N 1000000        		/* alan hesabi icin kullanilacak nokta sayisi 			*/

double points[100][2];			/* polygonu tanimlamak icin kullanilacak noktalar		*/
int np = 0;						/* polygonun nokta sayisi. 								*/

/*y = mx +b icin
 * m[i], i.kenarin egimi m
 * m[i], i.kenarin b degerini tutacak.*/
double *m = NULL, *b = NULL;	/* kenarlar denklemleri icin m ve b degerlini tutacak	*/

/*points dizisine nokta ekler ve nokta sayisini bir arttirir*/
int addPoint(double x, double y);


 /*  bu fonksiyon m ve b icin alan ayirip her bir kenar icin bu degerleri hesaplayacak*/
int generateCoeffs();

/*verilen noktanin polygonun icerisinde olup olmadigini bulur*/
int isInside(double *point);

/*[0,a] ve [0, b] araliginda x,y degerleri ile rastgele nokta olusturur*/
int generateRandomPoint(double *point, double a, double b);

/*width, height araliginda rastgele N tane nokta uretip alani hesaplar */
double findArea(double width, double height);


/**
 * points[np]'ye bir nokta ekler ve np'nin degerini bir artirir
 * increases np by 1, and returns np
 */
int addPoint(double x, double y){
	points[np][0] = x;
	points[np][1] = y;
	printf("nokta:%d- x:%lf, y:%lf \n",np+1, x, y);
	np = np+1;
	/*TODO: points[np][0]'a x'n degerini points[np][1]'e de y nin degerini atayin.*/
	 /*TODO: Sonra np yi bir artirin*/
	return np;
}

/**
 * x [0,a] ve y [0, b] araliginda olacak sekilde bir nokta olusturur
 */
int generateRandomPoint(double *point, double a, double b) {
	point[0]= ((double)rand()/RAND_MAX)*a;
    point[1]= ((double)rand()/RAND_MAX)*b;
	/*TODO: [0, a] ve [0, b] araliginda iki tane double rastgele sayi ureterek
	 *  point[0] ve point[1]'e atayin*/
	return 0;
}

/**
 * m ve b degerleri icin alan ayirdiktan sonra
 * her bir i kenari icin m[i] ve b[i] degerlini bulur
 */
int generateCoeffs(){
	/*yine polygonun i. kenari (points[i][0],points[i][1])
	 * (points[i+1][0],points[i+1][1]) noktalariyla tanimlidir.
	 *
	 * Ayrica son kenar
	 * (points[0][0],points[0][1])
	 * (points[np-1][0],points[np-1][1]) noktalariyla tanimlidir. */
	 m = (double *) malloc (np* sizeof (double));
	 b = (double *) malloc (np* sizeof (double));
	/*TODO: b ve m pointerlari icin malloc kullanarak np tane double icin
	 * yer ayirin
	 */
	/*TODO her bir kenar icin m[i] ve b[i] degerlerini bulun
	 * burada m[i] = (y2-y1)/(x2-x1)
	 * b[i] = y2- m[i]*x2*/
		for(int i = 0; i < np-1; i++){
			m[i] = (points[i+1][1] - points[i][1])/(points[i+1][0]-points[i][0]);
			b[i] = points[i+1][1]- m[i]*points[i+1][0];
		}
    m[np-1]= (points[np-1][1] - points[0][1])/(points[np-1][0]-points[0][0]);
    b[np-1] = points[np-1][1] - m[np-1]*points[np-1][0];
	return 0;
}

/**
 * point ile verilen noktanin polygonun icerisinde olup olmadigini belirler
 */
int isInside(double *point) {
	/*x noktanin x, y noktanin y koordinati olsun*/
	/*polygonun i. kenari (points[i][0],points[i][1])
	 * (points[i+1][0],points[i+1][1]) noktalariyla tanimlidir.
	 *
	 * Ayrica son kenar
	 * (points[0][0],points[0][1])
	 * (points[np-1][0],points[np-1][1]) noktalariyla tanimlidir. */

	/*TODO: (x, y) noktasindan yukari dogru cizilen dogrunun,
	 *  kac tane kenari kestigini (kesenSayisi) bulmak icin bir dongu olusturun
	 * bu dongu tum kenarlari kapsamali*/
	int kesenSayisi = 0;
		for(int i = 0 ;i < np-1; i++){
		
			if(point[0] < points[i][0] && point[0] < points[i+1][0]){
				continue;
			}
			else if(point[0] > points[i][0] && point[0] > points[i+1][0]){
				continue;
			}
			else if(point[1] < points[i][1] && point[1] < points[i+1][1]){
				continue;
			}
			else{
				double ykesisim = m[i]*point[0] + b[i];
					if(ykesisim < point[1]){
						kesenSayisi++;
					}
			}
		}
		
		if(point[0] < points[0][0] && point[0] < points[np-1][0]){
			
		}
		else if(point[0] > points[0][0] && point[0] > points[np-1][0]){
			
		}
		else if(point[1] < points[0][1] && point[1] < points[np-1][1]){
		
		}
		else{
			double ykesisim = m[np-1]*point[0] + b[np-1];
				if(ykesisim < point[1]){
					kesenSayisi++;
				}
		}
	if(kesenSayisi%2==1){
		return 1;
	}
	else{
		return 0;
	}
	
	/*bu dongunun icerisinde*/

		/*TODO:eger noktanin x koordinati,
		 * i.kenarin her iki x koordinatinin da sagina dusuyorsa,
		 * bir sey yapmadan diger kenara gecin */

		/*TODO: eger noktanin x koordinati,
		 * i.kenarin her iki x koordinatinin da soluna dusuyorsa,
		 * diger kenara gecin */

		/*TODO: eger noktanin y koordinati,
		 * i.kenarin her iki y koordinatinin da uzerinde ise,
			 * diger kenara gecin */

		/*Yukaridaki durumlardan hic birisi degilse*/
		/*TODO kenar icin*/

    	/*TODO: noktadan cizilen dogrunun kenari hangi y noktasinda kestigini bulun:*/
		 /*ykesisim = m[i]xnokta + b[i]*/

    	/*TODO: eger ykesisim, ynokta dan buyukse ise
    	 * o zaman bu kenar bu noktadan cizilen dogruyu kesmektedir.
	     * kesenSayisini bir artirin*/

	/*TODO: donguden sonra
	 * eger kesen sayisi tek ise return 1, diger durumlarda return 0*/

	return 0;
}



/**
 * en: generates N random point and estimates the area of polygon
 * tr: generateRandomPoint fonksiyonunu kullanarak,
 * rastgele N nokta olusturur, isInside fonksiyonu ile
 * rastgele N noktadan kac tanesinin iceri dustugunu bulur ve alani hesaplar
 */
double findArea(double width, double height){
	/*TODO: bir tane rastgele noktayi tutmak icin iki elemanli bir dizi olusturun*/
	double rastgeleNokta[2];
	double icerdekinokta = 0;
	for(int j = 1; j <= N ; j++){
		/*TODO: generateRandomPoint fonksiyonunu bu dizi ve width ve height arguman degerleriyle
		 * cagirarak bir tane rastgele nokta elde edin*/
		generateRandomPoint(rastgeleNokta, width, height);
		/*TODO: isInside() fonksiyonunu bu nokta ile cagirarak bu noktanin icerde olup olmadigini belirleyin*/
		if(isInside(rastgeleNokta) == 1){
			icerdekinokta++;
		}
	}
	double cokgenalani;
	cokgenalani = (icerdekinokta/N)*width*height;
	/*TODO: eger nokta icerideyse, icerdeki noktalarin sayisini bir artirin*/

	/*TODO: yukarida yapilanlari N defa tekrar ettirin*/

	/*TODO height X width ve
	 * toplam  nokta sayisi ile iceri dusenlerin oranini kullanarak alani hesaplayip return edin*/

	return cokgenalani;
}



/**
 * frees allocated memory
 */
int resetAll(){
	free(m);
	free(b);
	np = 0;
	return np;
}


