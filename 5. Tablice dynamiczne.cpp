#include<iostream>

using namespace std;

static const float PI = 3.14;
class Okrag{
    string nazwa_;
    float r_;
public:
    Okrag(){}
    ~Okrag(){}
    void wstawdane(){
        cin>>nazwa_;
        do{
        cin>>r_;
        }while(r_<=0);
    }
    void wyswietl(){
        cout<<nazwa_<<" "<<r_;
    }
    void wyswietlzo(){
        cout<<nazwa_<<" "<<obwod();
    }
    float obwod(){
        return 2*PI*r_;
    }
static void sortowanie(Okrag tablica[], int pierwszy , int ostatni){
    if(pierwszy >= ostatni) return;
    int lewy = pierwszy, prawy = ostatni + 1;
    Okrag srodek = tablica[pierwszy];
        while(true){
            do{
                lewy++;
            }while(lewy <= ostatni and tablica[lewy].obwod() > srodek.obwod());
            do{ 
                prawy--;
            }while(tablica[prawy].obwod() < srodek.obwod());
            if(lewy > prawy) break;
            swap(tablica[lewy], tablica[prawy]);
            }
            swap(tablica[pierwszy], tablica[prawy]);
            sortowanie(tablica, pierwszy, prawy-1);
            sortowanie(tablica, prawy+1, ostatni);
    }
};
class Ksztalt{
public:
    virtual float obwod() = 0;
    virtual void wstawdane() = 0;
    virtual void wyswietl() = 0;
};
class Kolo:public Ksztalt{
    string  nazwa_;
    float r_;
public:
    Kolo(){}
    ~Kolo(){}
    void wstawdane(){
        cin>>nazwa_;
        do{
            cin>>r_;
        }while(r_<=0);
    }
    void wyswietl(){
    cout<<nazwa_<<" "<<r_;
    }
    float obwod(){
        return PI*2*r_;
    }
};
class Prostokat:public Ksztalt{
    string nazwa_;
    float a_, b_;
public:
    Prostokat(){}
    ~Prostokat(){}
    void wstawdane(){
        cin>>nazwa_;
        do{
        cin>>a_;
        }while(a_<=0);
        do{
        cin>>b_;
        }while(b_<=0);
    }
    void wyswietl(){
        cout<<nazwa_<<" "<<a_<<" "<<b_;
    }
    float pole(){
        return a_*b_;
    }
    float obwod(){
        return 2*a_+2*b_;
    }
};
int main()
{
    short int zadanie;
    cin >> zadanie;
    switch(zadanie)
    {
    case(1):
    {
    int rozmiar;
    cin>>rozmiar;
    Okrag *tablicaokregow = new Okrag[rozmiar];
    for(int i = 0; i < rozmiar; i++){
    tablicaokregow[i].wstawdane();
    }
            
    Okrag::sortowanie(tablicaokregow, 0, rozmiar-1);
    for(int i =0; i < rozmiar; i++){
        tablicaokregow[i].wyswietlzo();
        cout<<" ";
    }
    delete[] tablicaokregow;
    break;
    }   
    case(2):
    {
    int wiersz, kolumna;
    cin>>wiersz>>kolumna;
    
    Ksztalt*** tablicaksztaltow = new Ksztalt**[wiersz];
    for(int i = 0; i < wiersz; i++) tablicaksztaltow[i] = new Ksztalt*[kolumna];
        for(int i = 0; i < wiersz; i++){
            for(int k = 0; k < kolumna; k++){
                if(i%2==0){
                    tablicaksztaltow[i][k] = new Kolo();
                }else{
                    tablicaksztaltow[i][k] = new Prostokat();
                }
                    tablicaksztaltow[i][k]->wstawdane();
        }
    }
    int w, k;
    cin>>w>>k;
    tablicaksztaltow[w][k]->wyswietl();
            
    for(int i = 0; i< wiersz; i++){
        for(int k = 0; k < kolumna; k++) delete  tablicaksztaltow[i][k];
        }
        delete[] tablicaksztaltow;
        break;
        }
    }
    return 1;
}