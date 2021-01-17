#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <malloc.h>

struct node {//Ana düðüm yapýmýz
 
    char req[100];
    struct node *next;
    struct node *prev;
};

struct node* start = NULL;
 

struct node* dugumOlustur(char veri[100]) //Düðümün oluþmasýný saðlayan fonksiyonumuz
{
    struct node* yeniDugum = (struct node*)malloc(sizeof(struct node));//Bellek üzerinde düðümümüz için alan açýyoruz
    strcpy(yeniDugum->req,veri);//düðüme gireceðimiz site adresini düðümün gerekli alanýna atýyoruz
    yeniDugum->next = NULL;
    yeniDugum->prev = NULL;
 
    return yeniDugum;
}

void sonaEkle(char veri[100])//En sona yeni bir düðüm eklemek için kullanýðýmýz fonksiyon
{
    struct node* sonaEklenecek = dugumOlustur(veri);
 
    
    if (start == NULL)//Listemizin içerisinde hiç eleman yoksa ilk elemanýmýzý ekliyoruz
    {
        start = sonaEklenecek;
    }
 
    else//Eðer liste içerisinde eleman varsa
    {
    	
	    struct node* temp = start;//Start deðerini kaybetmemek için temp deðerine kopyalýyoruz   
	    while (temp->next != NULL)//Son düðümün next deðerini buluyoruz
	    {
	       temp = temp->next;
	    }  
	    sonaEklenecek->prev = temp;//Sona ekleyeceðimiz düðümün prev deðerine liste içerisindeki var olan son deðeri ekliyoruz 
	    temp->next = sonaEklenecek;	//Listede var olan son düðümün next deðerine yeni ekleyeceðimiz düðümü iþaret ediyoruz
    }
}

void basaEkle(char veri[100])//Eðer hiç düðümümüz yoksa ilk olarak bu fonksiyonla ilk düðümü ekleyeceðiz
{
    struct node* basaEklenecek = dugumOlustur(veri);
 
    if (start == NULL)
    {
        start = basaEklenecek;
        return;
    }
 
    start->prev = basaEklenecek;
    basaEklenecek->next = start;
    start = basaEklenecek;
}

void sondanSil()//Eðer kullanýcýnýn girdiði maksimum istek sayýsýna ulaþýldýysa sondaki düðümü silmek için bu fonksiyonu kullanacaðýz
{
    if (start == NULL)
    {
        printf("\n Liste zaten bos ....");
        return;
    }

    struct node* temp = start;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
 
    struct node* onceki = temp->prev;
    free(temp);
    onceki->next = NULL;
}

void yazdir()//Düðümlerimizi yazdýrmak için bu fonksiyonu kullanýyoruz
{
    struct node* temp = start;
 
    while (temp != NULL)
    {
        printf("Veri: %s\n", temp->req);
        temp = temp->next;
    }
}

int main(){
	
	sonaEkle("burak");
	sonaEkle("batu");
	sonaEkle("ayberk");
	basaEkle("caner");
	yazdir();
	printf("\n\n----------------\n\n");
	
	
	basaEkle("kamil");
	sonaEkle("osman");
	sonaEkle("kamil");
	yazdir();

}
