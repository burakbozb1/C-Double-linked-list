#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <malloc.h>

struct node {//Ana d���m yap�m�z
 
    char req[100];
    struct node *next;
    struct node *prev;
};

struct node* start = NULL;
 

struct node* dugumOlustur(char veri[100]) //D���m�n olu�mas�n� sa�layan fonksiyonumuz
{
    struct node* yeniDugum = (struct node*)malloc(sizeof(struct node));//Bellek �zerinde d���m�m�z i�in alan a��yoruz
    strcpy(yeniDugum->req,veri);//d���me girece�imiz site adresini d���m�n gerekli alan�na at�yoruz
    yeniDugum->next = NULL;
    yeniDugum->prev = NULL;
 
    return yeniDugum;
}

void sonaEkle(char veri[100])//En sona yeni bir d���m eklemek i�in kullan���m�z fonksiyon
{
    struct node* sonaEklenecek = dugumOlustur(veri);
 
    
    if (start == NULL)//Listemizin i�erisinde hi� eleman yoksa ilk eleman�m�z� ekliyoruz
    {
        start = sonaEklenecek;
    }
 
    else//E�er liste i�erisinde eleman varsa
    {
    	
	    struct node* temp = start;//Start de�erini kaybetmemek i�in temp de�erine kopyal�yoruz   
	    while (temp->next != NULL)//Son d���m�n next de�erini buluyoruz
	    {
	       temp = temp->next;
	    }  
	    sonaEklenecek->prev = temp;//Sona ekleyece�imiz d���m�n prev de�erine liste i�erisindeki var olan son de�eri ekliyoruz 
	    temp->next = sonaEklenecek;	//Listede var olan son d���m�n next de�erine yeni ekleyece�imiz d���m� i�aret ediyoruz
    }
}

void basaEkle(char veri[100])//E�er hi� d���m�m�z yoksa ilk olarak bu fonksiyonla ilk d���m� ekleyece�iz
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

void sondanSil()//E�er kullan�c�n�n girdi�i maksimum istek say�s�na ula��ld�ysa sondaki d���m� silmek i�in bu fonksiyonu kullanaca��z
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

void yazdir()//D���mlerimizi yazd�rmak i�in bu fonksiyonu kullan�yoruz
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
