#ifndef _LEXICO
#define _LEXICO

#include <iostream>
#include <string>
using namespace std;

class TipoSimbolo{
      public:
            static const int ERROR= -1;       
            static const int IDENTIFICADOR= 0;
            static const int OPADIC= 5;
            static const int OPMULT= 6;
            static const int PESOS= 23;
            static const int E= 47;  
            static const int ENTERO= 1;
            static const int REAL= 2;
            static const int OPRELAC= 7;
            static const int OPOR= 8;
            static const int OPAND= 9;
            static const int OPNOT= 10;
            static const int OPIGUALDAD= 11;
            static const int PUNTOYCOMA= 12;
            static const int COMA= 13;
            static const int PARENABI= 14;//parentesis abierto "("
            static const int PARENCER= 15;//parentesis cerrado ")"
            static const int CORCHETEABI= 16;//corchete abierto "{"
            static const int CORCHETECER= 17;//corchete cerrado "}"
            static const int IGUAL= 18;
            static const int IF= 19;
            static const int WHILE= 20;
            static const int RETURN= 21;
            static const int ELSE= 22;
            static const int CADENA= 3;
            static const int TIPO= 4;
            static const int ESPACIO= 46;
            static const int PROGRAMA= 24;
            static const int DEFINICIONES= 25;
            static const int DEFINICION= 26;
            static const int DEFVAR= 27;
            static const int LISTAVAR= 28;
            static const int DEFFUNC= 29;
            static const int PARAMETROS= 30;
            static const int LISTAPARAM= 31;
            static const int BLOQFUNC= 32;
            static const int DEFLOCALES= 33;
            static const int DEFLOCAL= 34;
            static const int SENTENCIAS= 35;
            static const int SENTENCIA= 36;
            static const int OTRO= 37;
            static const int BLOQUE= 38;
            static const int VALORREGRESA = 39;
            static const int ARGUMENTOS = 40;
            static const int LISTAARGUMENTOS = 41;
            static const int TERMINO= 42;
            static const int LLAMADAFUNC= 43;
            static const int SENTENCIABLOQUE= 44;
            static const int EXPRESION= 45;
};


class Lexico{
      private:
            string fuente;

            int ind;       
            bool continua;
            int estado;

            string sigCaracter();       
            void sigEstado(int estado);
            void aceptacion(int estado);
            bool esLetra(char c);
            bool esDigito(char c);
            bool esEspacio(char c);
            void retroceso();

      public:
            string c;
            string simbolo;
            int tipo;
            
            Lexico(string fuente);             
            Lexico();
      
            void entrada(string fuente);              
            string tipoAcad(int tipo);

            int sigSimbolo();
            bool terminado();
      
};
#endif
