#include<iostream> 
using namespace std; 
  //ÖRNEK DÝZÝ : 22 43 123 768 3 32
// dizinin max deðerinin bulunmasý=768
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
    int cikis[boyut];  // max fonfiyonundan belirlenen boyut ile oluþturulmuþ çýktýdizisi
    int count[10] = {0}; //rakamlarýn sayýldýðý boþ dizi(0-9)
  
    for (int i = 0; i < boyut; i++) 
        count[ (dizi[i]/basamak)%10 ]++;  //elamaný basmaða bölüp 10'a göre mod alýnýp sýralar.
  // 1'ler bas. rakamlara bakýlýr
    
	
	for (int i = 1; i < 10; i++) 
        count[i] = count[i]+count[i - 1]; // caunt dizisinde kümülatif toplama yaparak dizinin elman sayýsýna ulaþýr.
  
   
   
    for (int i = boyut - 1; i >= 0; i--) //Eleman sayisi diziden azlarak devam eder
    { 
        cikis[count[ (dizi[i]/basamak)%10 ] - 1] = dizi[i]; 
        count[ (dizi[i]/basamak)%10 ]--; 
        // örneðin sayý 768 olsun basamak 1 olsun 768/1=768%10=8   Çýkýþ[ count[8]-1 ] count[2]olsun çýkýþ[1] kutucuðuna konur 
    } 
  
    for (int i = 0; i < boyut; i++) 
        dizi[i] = cikis[i]; 
} 
  
 //getmax ile dizinin en büyük elamýný alýr m ye eþitler. basamak deðiþkeni ile basamklara ayýrýr kaç kez kýyas yapýlacýaðý belirlenir.
void RadixSort(int dizi[], int boyut) 
{ // max dizi elemaný bulunan get max algoritmasýndaki sayi M de tutulur m=768
    int m = maxdeger(dizi, boyut); 
    // her basamak için sayma sýralama yapýlýr
//1.adým M/div 768/1>0 doðru yeni div=1*10 768/10>0 doðru yeni div=10*10 768/100>0  div;1,10,100 3 kez sýralama yapýlýcak
    for (int basamak = 1; m/basamak> 0; basamak= basamak*10) 
        CountingSort(dizi, boyut, basamak);
} 
  

int main() 
{    //kullanýcýdan boyutunu isteyip diziyi yazdýrma
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
