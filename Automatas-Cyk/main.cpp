/*Lenguaje y Automatas I
  Jorge Osvaldo Morones Ornelas
  Parcial 2
  CYK
*/
#include <iostream>
#include <cstdio>
#include <string>
#include <set>
#include <map>

//Declaracion del Mapeo y set;
typedef std::set<char> set;
typedef std::map<int,set> fila;
typedef std::map<int,fila> tabla;

tabla table;
set aux2;

//Funcion que realiza la comparacion de simbolos de primer FOR
set PComparacion (char gram[48][3], std::string cadena,int n){

    set aux;

    char simbolo=cadena[n-1];

        for(int j=0;j<48;j++){
            if(gram[j][1] == simbolo){
                aux.insert(gram[j][0]);
            }
        }

    return aux;
}
//Funcion que realiza la comparacion de simbolos de segundo FOR
void SComparacion(char gram[48][3], set a, set b){

    std::set<char>::iterator it= a.begin();

    while(it != a.end()){
        std::set<char>::iterator it2= b.begin();
            while(it2 != b.end()){
                    for(int i=0; i<48; i++){
                       if(*it == gram[i][1])
                           if(*it2==gram[i][2]){
                                aux2.insert(gram[i][0]);
                           }
                    }

                it2++;
            }
        it++;
    }
}
//Funcion decision, seencarga de comparar el subconjunto N[1][n] y lo compara con el generador  de la produccion inicial(Q)
bool decision(char gram[48][3], set a,int n){

    std::set<char>::iterator respuesta = a.find(gram[8][0]);

    if(respuesta != a.end()){
        return true;
    }
    else{
        return false;
    }

}
//Funcion CYK
bool CYK(char gram[48][3], std::string cadena){

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
//Declaracion de Matriz Gramatica
char gram[48][3];
int inc=0;

//Funcion que almacena los caracteres en la matriz gram (Gramatica)
void produccion(char a, char b, char c ){

    gram[inc][0] = a;
    gram[inc][1] = b;
    gram[inc][2] = c;

    inc++;

}

int main()
{

    std::string cadena;

    std::cout<<"Ingrese una cadena: ";
    std::cin>>cadena;

    //Ingreso de los valores a la gramatica
    produccion('C'+'q','q','\0');
    produccion('C'+'e','e','\0');
    produccion('C'+'m','m','\0');
    produccion('C'+'d','d','\0');
    produccion('C'+'p','p','\0');
    produccion('C'+'s','s','\0');
    produccion('C'+'l','l','\0');
    produccion('C'+'r','r','\0');

    produccion('Q','E','D'+'1');
    produccion('D'+'1','C'+'q','D'+'2');
    produccion('D'+'2','Q','D'+'3');
    produccion('D'+'3','C'+'e','Q');
    produccion('Q','E','D'+'4');
    produccion('D'+'4','C'+'m','T');
    produccion('Q','E','D'+'5');
    produccion('D'+'5','C'+'d','T');
    produccion('Q','T','D'+'6');
    produccion('D'+'6','C'+'p','F');
    produccion('Q','T','D'+'7');
    produccion('D'+'7','C'+'s','F');
    produccion('Q','C'+'l','D'+'8');
    produccion('D'+'8','Q','C'+'r');
    produccion('Q','C'+'d','F');
    produccion('Q','n','\0');

    produccion('E','E','D'+'9');
    produccion('D'+'9','C'+'m','T');
    produccion('E','E','D'+'1'+'0');
    produccion('D'+'1'+'0','C'+'d','T');
    produccion('E','T','D'+'1'+'1');
    produccion('D'+'1'+'1','C'+'p','F');
    produccion('E','T','D'+'1'+'2');
    produccion('D'+'1'+'2','C'+'s','F');
    produccion('E','C'+'l','D'+'1'+'3');
    produccion('D'+'1'+'3','Q','C'+'r');
    produccion('E','C'+'d','F');
    produccion('E','n','\0');

    produccion('T','T','D'+'1'+'4');
    produccion('D'+'1'+'4','C'+'p','F');
    produccion('T','T','D'+'1'+'5');
    produccion('D'+'1'+'5','C'+'s','F');
    produccion('T','C'+'l','D'+'1'+'6');
    produccion('D'+'1'+'6','Q','C'+'r');
    produccion('T','C'+'d','F');
    produccion('T','n','\0');

    produccion('F','C'+'l','D'+'1'+'7');
    produccion('D'+'1'+'7','Q','C'+'r');
    produccion('F','C'+'d','F');
    produccion('F','n','\0');

    //Invocacion de la funcion CYK que retorna un valor booleano
    if(CYK(gram,cadena) == true){
        std::cout<<"\nLa Cadena Es Aceptada!\n";
    }else{
        std::cout<<"\nLa Cadena No Es Aceptada!\n";
    }


    return 0;
}
