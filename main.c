#include "time.h"
#include "stdlib.h"
#include "stdio.h"

void wypisywanie(int n,short tab[]){
    for(int i=0;i<n;i++) {
        printf("%d ",tab[i]);
    }
    printf("\n");
}

void generuj(int n , short tab[]){
    srand( time( NULL ) );
    for (int i = 0; i < n; i++) {
        tab[i] = rand() % 100 + 1;
    }
    wypisywanie(n,tab);
}

void collatz(short tab[], int n){
    for (int i = 0; i < n; i++) {
        if (tab[i] % 2 != 0) tab[i] = 3 * tab[i] + 1;
        else if (tab[i] % 2 == 0 && tab[i] >= 0) {
            for (int z = (tab[i] / 2) - 1; z > 0; z--) {
                if (z % 2 != 0 && tab[i] % z == 0) {
                    tab[i] = z;
                    break;
                }
            }
        }
    }
    wypisywanie(n, tab);
}

void zmien(short tab[], int n) {
    for (int i = 0; i < n; i++) {
        if (tab[i] % 2 != 0) tab[i] = 2 * tab[i];
        else if (tab[i] % 2 == 0) tab[i] = -1 * tab[i];
    }
    wypisywanie(n, tab);
}
void signum(short tab[], int n){
    for (int i = 0; i < n; i++) {
        if (tab[i] > 0) tab[i]=1;
        else if (tab[i] < 0) tab[i]=-1;

    }
    wypisywanie(n, tab);
}
void odwroc(short tab[], int lewy, int prawy){
    for(int i=0;i<(prawy-lewy)/2+1;i++){
        int z =tab[prawy-i];
        tab[prawy-i]=tab[lewy+i];
        tab[lewy+i]= z;
    }
}
int ileNieparzystych(const short tab[], int n){
    int zlicz=0;
    for(int i = 0; i < n; i++) {
        if (tab[i] % 2 != 0) zlicz++;
    }
    return zlicz;
}
int ileParzystych(const short tab[], int n){
    int zlicz=0;
    for(int i = 0; i < n; i++) {
        if (tab[i] % 2 == 0) zlicz++;
    }
    return zlicz;
}
int ileMaksymalnych(const short tab[], int n){
    int maks = tab[0];
    int zlicz=1;
    for(int i = 1; i < n; i++) {
        if (maks ==tab[i]) zlicz++;
        if (tab[i]>maks){
            maks = tab[i];
            zlicz=1;
        }
    }
    return zlicz;
}
void generuj2(short tab[], int n, short minWartosc, short maxWartosc){
    for (int i = 0; i < n; i++) {
        tab[i] = rand() % (maxWartosc-minWartosc+1) + minWartosc;
    }
    wypisywanie(n,tab);
}

int main() {
    int lewy, prawy, n;
    scanf("%d", &n);
    int const N = 1000;
    short tab[N];
    generuj(n, tab);
    printf("Tyle nieparzystych: %d\n", ileNieparzystych(tab, n));
    printf("Tyle parzystych: %d\n", ileParzystych(tab, n));
    printf("Tyle maksymalnych: %d\n", ileMaksymalnych(tab, n));
    collatz(tab, n);
    zmien(tab, n);
    signum(tab, n);
    scanf("%d", &lewy);
    scanf("%d", &prawy);
    odwroc(tab, lewy, prawy);
    wypisywanie(n, tab);
    int d;
    scanf("%d", &d);
    short tabik[N];
    short a = 2, b = 8;
    generuj2(tabik, d, 3, 20);

}