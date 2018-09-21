#include <iostream>
#include <cstdio>
/*
    Teoría de Lenguajes y Autómatas I
    Prof. Alejandro Aguilar

    Práctica No. 1: Operaciones de cadenas
    Jorge Osvaldo Morones Ornelas
*/
using namespace std;

int longitud( char *a){
    int c=0;
    while(a[c]!='\0')
    {
        c++;
    }
return c;
}
void alfabeto( char *b){

    int c=0,cc=1,aux=0,cont=0;
    int tam=1;
    char *xAlf=NULL;
    xAlf= new char[tam];
//Busqueda de Alfabeto minimo, verifica los char repetidos
    while(b[c]!='\0')
    {
        while(b[cc]!='\0'){
            if(b[c]==b[cc]){
                aux++;
            }
            cc++;
        }
        if(aux == 0){
            xAlf[cont]=b[c];
            tam++;
            cont++;
        }
        else
            aux=0;

        c++;
        cc=c+1;
    }

    xAlf[tam-1]='\0';

//Ordena el alfabeto minimo en orden decendente a ascendente
    int Temp;
         for(int i=0;i<longitud(xAlf);i++){
                for(int j=0;j<longitud(xAlf)-1;j++){
                    if(xAlf[j]>xAlf[j+1]){
                        Temp=xAlf[j];
                        xAlf[j]=xAlf[j+1];
                        xAlf[j+1]=Temp;
                    }
                }
            }
            //Imprime en pantalla
            for(int i=0;i<longitud(xAlf);i++){
                    cout<<xAlf[i]<<",";
            }
        }



bool iguales( char *a, char *b){
    bool same;
    int c=0, cc=0, cont=0;
    //Hace comparacion de la longitud de ambas cadenas
    if(longitud(a)==longitud(b)){
            //Verifica caracter por caracter
            while(a[c]!='\0'){
                if(a[c]!=a[cc])
                    cont++;
                    c++;
                    cc++;
            }
            if(cont==0){
                return true;
            }
            else
                return false;
    }
    else
    return false;
}

char *concatenar( char *a, char *b){

    int tam= longitud(a)+longitud(b);
    char *ab=NULL;
    ab= new char[tam];
    int cc=0, con=0,c=0;
// Realiza la concatenación
    while(a[c]!='\0'){
            ab[cc]=a[c];
            cc++;
            c++;
    }
    c=0;
     while(b[c]!='\0'){
            ab[cc]=b[c];
            cc++;
            c++;
    }
    ab[tam]='\0';
    //Verifica si es una cadena vacia
    if(a[0]=='\0')
        ab[longitud(b)]=NULL;
    else if (b[0]=='\0')
        ab[longitud(a)]=NULL;
    return ab;
}
char *potencia( char *x, int n){

    int tam= longitud(x)*n;
    char *xPot=NULL;
    xPot= new char[tam];

    int cc=0, con=0,c=0;

    if(n>0){
     while(con<n){
        while(x[c]!='\0'){
            xPot[cc]=x[c];
            c++;
            cc++;
        }
        c=0;
        con++;
        xPot[tam]='\0';
     }
    }
    else
       xPot[0]=NULL;
     if(x[0]=='\0'){
        xPot[0]=NULL;
     }
    return xPot;
}

int main()
{
    cout << "Practica No. 1: Operaciones de cadenas\n\n" << endl;

    char *a=NULL,*b=NULL;
    int pot;
    a= new char[10];
    b= new char[10];

    cout<<"Cadena A: ";
    gets(a);
    cout<<"Cadena B: ";
    gets(b);
    cout<<"Potencia: ";
    cin>>pot;
    cout<<"---------------------------------------";

    cout<<"\n\nAlfabeto de la cadena A: [";
    alfabeto(a);
    cout<<"]\nLongitud Cadena A: "<<longitud(a);

    cout<<"\n\nAlfabeto de la cadena B: [";
    alfabeto(b);
    cout<<"]\nLongitud Cadena B: "<<longitud(b);

    if(iguales(a,b)==true)
        cout<<"\n\nLas cadenas A y B son iguales";
    else
        cout<<"\n\nLas cadenas A y B son diferentes";

    cout<<"\n\nConcatenacion de A y B: "<<concatenar(a,b);
    cout<<"\nLongitud de la Concatenacion : "<<longitud(a)+longitud(b);

    cout<<"\n\nConcatenacion de B y A: "<<concatenar(b,a);
    cout<<"\nLongitud de la Concatenacion : "<<longitud(b)+longitud(a);

    if(pot>=0){
        cout<<"\n\nLa Potencia "<<pot<<" de la Cadena A: "<<potencia(a,pot);
        cout<<"\nLa Potencia "<<pot<<" de la Cadena B: "<<potencia(b,pot)<<"\n\n";
    }
    else
        cout<<"\n\nPotecia:\nIngrese Numero Entero Positivo\n";

    delete []a;
    delete []b;
    a=NULL;
    b=NULL;

    return 0;
}
