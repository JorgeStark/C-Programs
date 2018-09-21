/*Lenguaje y Automatas I
  Jorge Osvaldo Morones Ornelas
  Parcial 3
*/
#include <iostream>
#include <map>

using namespace std;

class tape{

public:
    tape();
    char read();
    void print();
    void right();
    void right(int n=1);
    void left();
    void left(int n=1);
    void sigma(char s);
    void right_to(char s);
    void left_to(char s);

private:
    int limI, limD, indice;
    std::map< int , char > t;

};

tape::tape(){
    t[0]='@';
    t[-1]=' ';
    t[1]=' ';
    limI=-1;
    limD=1;
    indice=0;
}
char tape::read(){
    return t[indice];
}
void tape::print(){
    for(int i= limI; i<=limD; i++){
        if(i==indice) cout<<".";
        cout<<t[i];
    }
    cout<<"\n";
}
void tape::right(int n){
    indice+=n;

    int aux=0;
    if(indice>limD){
        aux = indice-limD;
        for(int i=limD+1; i<=indice ;i++){
            t[i]=' ';
        }
    }
    limD+=aux;
}
void tape::left(int n){
    indice-=n;

    int aux=0;
    if(indice<limI){
        aux=indice + (limI*-1);
        for(int i=limI+1; i<=indice ;i--){
            t[i]=' ';
        }
    }
    limI+=aux;
}
void tape::sigma(char s){
    t[indice]= s;

    if(indice==limD){
        limD+=1;
        t[indice+1]=' ';
    }
}
void tape::right_to(char s){
    for (int i=indice; i<=limD; i++){
        if(t[i]== s ){
            indice = i;
            break;
        }
    }

}
void tape::left_to(char s){
    for (int i=indice; i>=limI; i--){
        if(t[i]==s){
            indice = i;
            break;
        }
    }

}


void enqueue(tape &t,char s){
    t.print();
    t.right_to(' ');
    t.print();
    t.sigma(s);
    t.print();
    t.left_to('@');
    t.print();
}

void dequeue(tape &t){
char aux;
    t.print();
    t.right(1);
    aux = t.read();
    t.print();
    if(aux != ' '){
        t.left(2);
        t.print();
        t.sigma(aux);
        t.print();
        t.right(3);
        t.print();
        aux = t.read();
        while(aux !=' '){
            t.left(1);
            t.sigma(aux);
            t.print();
            t.right(2);
            t.print();
            aux = t.read();
        }
        if(aux==' '){
            t.left(1);
            t.sigma(' ');
            t.print();
        }
        t.left_to('@');
        t.print();

        //Informa cual simbolo fue extraido
        t.left(1);
        cout<<"Simbolo Extraido: "<<t.read()<<endl;
        t.right(1);
    }
    else if(aux == ' '){
            t.left(1);
            cout<<"Nigun Simbolo Extraido"<<endl;
    }
}

int main()
{
    int opc;
    char simbolo;

    tape t;
    tape();


    do{

        cout<<"\nEstado Actual: ";
        t.print();
        cout<<"\n(1) Ingresar Dato. (2) Extraer Datos.(3) Salir."<<endl;
        cin>>opc;

        switch (opc)
        {
        case 1:
            cout<<"Ingrese Dato: ";
            cin>>simbolo;
            enqueue(t,simbolo);
            break;
        case 2:
            dequeue(t);
            break;
        }



    }while(opc ==1 || opc ==2);

    return 0;
}
