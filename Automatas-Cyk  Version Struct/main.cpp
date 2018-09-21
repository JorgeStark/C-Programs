#include <iostream>
#include <string>
#include <cstdio>
#include <set>
#include <map>


typedef struct {
    char generador;
    char primero;
    char segundo;
} producciones;

typedef std::set<char> set;
typedef std::map<int,set> fila;
typedef std::map<int,fila> tabla;

tabla table;
set aux2;

producciones produccion(char a, char b, char c ){
    producciones aux;

    aux.generador=a;
    aux.primero=b;
    aux.segundo=c;

    return aux;

}

set PComparacion (producciones *gram, std::string cadena,int n){

    set aux;

    char simbolo=cadena[n-1];

        for(int j=0;j<48;j++){
            if(gram[j].primero == simbolo || gram[j].segundo == simbolo){
                aux.insert(gram[j].generador);
                //std::cout<<"\nSet"<<n<<" "<< gram[j].gen;
            }
        }

    return aux;
}

void SComparacion(producciones *gram, set a, set b){

    std::set<char>::iterator it= a.begin();


    while(it != a.end()){
        std::set<char>::iterator it2= b.begin();
            while(it2 != b.end()){
                    for(int i=0; i<48; i++){
                       if(*it == gram[i].primero)
                           if(*it2==gram[i].segundo){
                                aux2.insert(gram[i].generador);
                                //std::cout<<"\n\nSet"<<" "<< gram[i].gen;
                           }
                    }

                it2++;
            }
        it++;
    }
}

bool decision(producciones *gram, set a,int n){

    std::set<char>::iterator respuesta = a.find(gram[8].generador);

    if(respuesta != a.end()){
        return true;
    }
    else{
        return false;
    }

}

bool CYK(producciones *gram, std::string cadena){

    int n=cadena.length();
    for(int i=1; i<=n; i++) table[i][1]=(PComparacion(gram,cadena,i));

    for(int j=2; j<=n; j++){
        for(int i=1; i<=n-j+1; i++){
            for(int k=1; k<=j-1; k++){
                SComparacion(gram, table[i][k], table[i+k][j-k]);
            }
            table[i][j]=aux2;
            aux2.clear();
        }
    }

    return decision(gram,table[1][n],n);
}

int main()
{

    std::string cadena;
    producciones gram[48];

    std::cout<<"Ingrese una cadena: ";
    std::cin>>cadena;

    gram[0]=produccion('C'+'q','q','\0');
    gram[1]=produccion('C'+'e','e','\0');
    gram[2]=produccion('C'+'m','m','\0');
    gram[3]=produccion('C'+'d','d','\0');
    gram[4]=produccion('C'+'p','p','\0');
    gram[5]=produccion('C'+'s','s','\0');
    gram[6]=produccion('C'+'l','l','\0');
    gram[7]=produccion('C'+'r','r','\0');

    gram[8]=produccion('Q','E','D'+'1');
    gram[9]=produccion('D'+'1','C'+'q','D'+'2');
    gram[10]=produccion('D'+'2','Q','D'+'3');
    gram[11]=produccion('D'+'3','C'+'e','Q');
    gram[12]=produccion('Q','E','D'+'4');
    gram[13]=produccion('D'+'4','C'+'m','T');
    gram[14]=produccion('Q','E','D'+'5');
    gram[15]=produccion('D'+'5','C'+'d','T');
    gram[16]=produccion('Q','T','D'+'6');
    gram[17]=produccion('D'+'6','C'+'p','F');
    gram[18]=produccion('Q','T','D'+'7');
    gram[19]=produccion('D'+'7','C'+'s','F');
    gram[20]=produccion('Q','C'+'l','D'+'8');
    gram[21]=produccion('D'+'8','Q','C'+'r');
    gram[22]=produccion('Q','C'+'d','F');
    gram[23]=produccion('Q','n','\0');

    gram[24]=produccion('E','E','D'+'9');
    gram[25]=produccion('D'+'9','C'+'m','T');
    gram[26]=produccion('E','E','D'+'1'+'0');
    gram[27]=produccion('D'+'1'+'0','C'+'d','T');
    gram[28]=produccion('E','T','D'+'1'+'1');
    gram[29]=produccion('D'+'1'+'1','C'+'p','F');
    gram[30]=produccion('E','T','D'+'1'+'2');
    gram[31]=produccion('D'+'1'+'2','C'+'s','F');
    gram[32]=produccion('E','C'+'l','D'+'1'+'3');
    gram[33]=produccion('D'+'1'+'3','Q','C'+'r');
    gram[34]=produccion('E','C'+'d','F');
    gram[35]=produccion('E','n','\0');

    gram[36]=produccion('T','T','D'+'1'+'4');
    gram[37]=produccion('D'+'1'+'4','C'+'p','F');
    gram[38]=produccion('T','T','D'+'1'+'5');
    gram[39]=produccion('D'+'1'+'5','C'+'s','F');
    gram[40]=produccion('T','C'+'l','D'+'1'+'6');
    gram[41]=produccion('D'+'1'+'6','Q','C'+'r');
    gram[42]=produccion('T','C'+'d','F');
    gram[43]=produccion('T','n','\0');

    gram[44]=produccion('F','C'+'l','D'+'1'+'7');
    gram[45]=produccion('D'+'1'+'7','Q','C'+'r');
    gram[46]=produccion('F','C'+'d','F');
    gram[47]=produccion('F','n','\0');


    if(CYK(gram,cadena) == true){
        std::cout<<"\nLa Cadena Es Aceptada!\n";
    }else{
        std::cout<<"\nLa Cadena No Es Aceptada!\n";
    }


    return 0;
}
