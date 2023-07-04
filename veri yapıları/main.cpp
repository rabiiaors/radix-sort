#include<iostream> 
using namespace std; 
  //�RNEK D�Z� : 22 43 123 768 3 32
// dizinin max de�erinin bulunmas�=768
int maxdeger(int dizi[], int boyut) 
{ 
    int max = dizi[0]; 
    for (int i = 1; i < boyut; i++) 
        if (dizi[i] > max) 
            max = dizi[i]; 
    return max; 
} 

void CountingSort(int dizi[], int boyut, int basamak) 
{   
    int cikis[boyut];  // max fonfiyonundan belirlenen boyut ile olu�turulmu� ��kt�dizisi
    int count[10] = {0}; //rakamlar�n say�ld��� bo� dizi(0-9)
  
    for (int i = 0; i < boyut; i++) 
        count[ (dizi[i]/basamak)%10 ]++;  //elaman� basma�a b�l�p 10'a g�re mod al�n�p s�ralar.
  // 1'ler bas. rakamlara bak�l�r
    
	
	for (int i = 1; i < 10; i++) 
        count[i] = count[i]+count[i - 1]; // caunt dizisinde k�m�latif toplama yaparak dizinin elman say�s�na ula��r.
  
   
   
    for (int i = boyut - 1; i >= 0; i--) //Eleman sayisi diziden azlarak devam eder
    { 
        cikis[count[ (dizi[i]/basamak)%10 ] - 1] = dizi[i]; 
        count[ (dizi[i]/basamak)%10 ]--; 
        // �rne�in say� 768 olsun basamak 1 olsun 768/1=768%10=8   ��k��[ count[8]-1 ] count[2]olsun ��k��[1] kutucu�una konur 
    } 
  
    for (int i = 0; i < boyut; i++) 
        dizi[i] = cikis[i]; 
} 
  
 //getmax ile dizinin en b�y�k elam�n� al�r m ye e�itler. basamak de�i�keni ile basamklara ay�r�r ka� kez k�yas yap�lac�a�� belirlenir.
void RadixSort(int dizi[], int boyut) 
{ // max dizi eleman� bulunan get max algoritmas�ndaki sayi M de tutulur m=768
    int m = maxdeger(dizi, boyut); 
    // her basamak i�in sayma s�ralama yap�l�r
//1.ad�m M/div 768/1>0 do�ru yeni div=1*10 768/10>0 do�ru yeni div=10*10 768/100>0  div;1,10,100 3 kez s�ralama yap�l�cak
    for (int basamak = 1; m/basamak> 0; basamak= basamak*10) 
        CountingSort(dizi, boyut, basamak);
} 
  

int main() 
{    //kullan�c�dan boyutunu isteyip diziyi yazd�rma
	int boyut;
	cout<<"Dizinin boyutu:"<<endl;
	cin>>boyut;
	int dizi[boyut];
	cout<<" Rastgele sayi girin"<<endl;
	for(int i=0;i<boyut;i++)
	{
		cin>>dizi[i];
	}
	
   cout<<endl<<"Yazdiginiz dizi: "<<endl;
   for(int i=0;i<boyut;i++)
	{
		cout<<dizi[i]<<" ";
	}
	
	RadixSort(dizi, boyut); 
   
	cout<<endl<<"radix sort ile siralanmis hali: "<<endl;
   for(int i=0;i<boyut;i++)
	{
		cout<<dizi[i]<<" ";
	} 
    
    return 0; 
}
