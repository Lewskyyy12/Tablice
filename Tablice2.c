

#include "stdio.h"
#include "time.h"
#include "stdlib.h"

void wypisywanie2(int n,short tab[]){
    for(int i=0;i<n;i++) {
        printf("%d ",tab[i]);
    }
    printf("\n");
}

void generuj2(short tab[], int n, short minWartosc, short maxWartosc){
    for (int i = 0; i < n; i++) {
        tab[i] = rand() % (maxWartosc-minWartosc+1) + minWartosc;
    }
    wypisywanie2(n,tab);
}
int ileDodatnich(const short tab[], int n){
    int ile=0;
    for (int i = 0; i < n; i++) if(tab[i]>0) ile++;
    return ile;
}
int ileUjemnych(const short tab[], int n){
    int ile=0;
    for (int i = 0; i < n; i++) if(tab[i]<0) ile++;
    return ile;
}
int ileZerowych(const short tab[], int n){
    int ile=0;
    for (int i = 0; i < n; i++) if(tab[i]==0) ile++;
    return ile;
}
int sumaDodatnich(const short tab[], int n){
    int ile=0;
    for (int i = 0; i < n; i++) if(tab[i]>0) ile+=tab[i];
    return ile;
}
int sumaUjemnych(const short tab[], int n){
    int ile=0;
    for (int i = 0; i < n; i++) if(tab[i]<0) ile+=tab[i];
    return ile;
}
int dlugoscMaksymalnegoCiaguDodatnich(const short tab[], int n){
    int dl_akt=0,dl_Max=0;
    for(int i=0;i<n;i++) {
        if (tab[i] > 0) dl_akt++;
        if (tab[i] <= 0) {
            if(dl_akt>=dl_Max) dl_Max=dl_akt;
            dl_akt=0;
        }
    }
    return dl_Max;
}

int main() {
    int const N = 1000;
    int n;
    scanf("%d",&n);
    short tabik[N];
    generuj2(tabik, n,-99,99);
    printf("Ujemne - %d\n", ileUjemnych(tabik,n));
    printf("Zerowe - %d\n", ileZerowych(tabik,n));
    printf("Dodatnie - %d\n", ileDodatnich(tabik,n));
    printf("Suma dodatnie - %d\n", sumaDodatnich(tabik,n));
    printf("Suma ujemne - %d\n", sumaUjemnych(tabik,n));
    printf("Dlugosc maksymalnego ciagu: %d", dlugoscMaksymalnegoCiaguDodatnich(tabik,n));


}
