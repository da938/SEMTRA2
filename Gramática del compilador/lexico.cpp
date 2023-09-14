#include "lexico.h"

Lexico::Lexico(string fuente){
     ind= 0;                  
     this->fuente= fuente;
}      

Lexico::Lexico(){
     ind= 0;                  
}      

string Lexico::tipoAcad(int tipo){
     string cad= "";

     switch (tipo){
          case TipoSimbolo::IDENTIFICADOR:
               cad= "Identificador";
               break;

          case TipoSimbolo::OPADIC:
               cad= "Op. Adicion";
               break;

          case TipoSimbolo::OPMULT:
               cad= "Op. Multiplicacion";
               break;            

          case TipoSimbolo::PESOS:
               cad= "Fin de la Entrada";
               break;            

          case TipoSimbolo::ENTERO:
               cad= "Entero";
               break;

          case TipoSimbolo::REAL:
               cad= "Real";
               break;

          case TipoSimbolo::OPRELAC:
               cad= "Op. Relacional";
               break;

          case TipoSimbolo::OPOR:
               cad= "Op. Or";
               break;

          case TipoSimbolo::OPAND:
               cad= "Op. And";
               break;

          case TipoSimbolo::OPNOT:
               cad= "Op. Not";
               break;
          
          case TipoSimbolo::OPIGUALDAD:
               cad= "Op. Igualdad";
               break;
          
          case TipoSimbolo::PUNTOYCOMA:
               cad= "Punto y coma";
               break;
          
          case TipoSimbolo::COMA:
               cad= "Coma";
               break;
          
          case TipoSimbolo::PARENABI:
               cad= "Parentesis abierto";
               break;

          case TipoSimbolo::PARENCER:
               cad= "Parentesis cerrado";
               break;

          case TipoSimbolo::CORCHETEABI:
               cad= "Corchete abierto";
               break;

          case TipoSimbolo::CORCHETECER:
               cad= "Corchete cerrado";
               break;

          case TipoSimbolo::IGUAL:
               cad= "Igual";
               break;

          case TipoSimbolo::IF:
               cad= "If";
               break;

          case TipoSimbolo::WHILE:
               cad= "While";
               break;

          case TipoSimbolo::RETURN:
               cad= "Return";
               break;

          case TipoSimbolo::ELSE:
               cad= "Else";
               break;

          case TipoSimbolo::CADENA:
               cad= "Cadena";
               break;

          case TipoSimbolo::TIPO:
               cad= "Tipo";
               break;

          case TipoSimbolo::ESPACIO:
               cad= "Espacio";
               break;
     }
     return cad;
}

void Lexico::entrada(string fuente){
     ind= 0;//se inicializa el contador que recorre la cadena              
     this->fuente= fuente;//guardamas la cadena que dio el usuario en fuente
}

int Lexico::sigSimbolo(){
     estado=0; //inicializamos estado en 0
     continua= true; 
     simbolo= "";
     bool entero = true;
     bool reales = true;
     bool cadena = false;
     //Inicio del Automata
     while (continua){
          //llamamos a la funcion que separa las palabras de la cadena
          c = sigCaracter();
          int longitud = c.length();//obtenemos la longitud de la palabra
          switch (estado){
               case 0:
                    if ( c == "+" || c=="-"){
                         aceptacion(2);
                         break;
                    }
                    else
                    if ( c == "*" || c=="/"){ 
                         aceptacion(5);
                         break;
                    }
                    else
                    if ( c == "<" || c=="<=" || c == ">" || c==">="){ 
                         aceptacion(7);
                         break;
                    }
                    else
                    if ( c == "||"){ 
                         aceptacion(8);
                         break;
                    }
                    else
                    if ( c == "&&"){ 
                         aceptacion(9);
                         break;
                    }
                    else
                    if ( c == "!"){ 
                         aceptacion(10);
                         break;
                    }
                    else
                    if ( c == "!=" || c == "=="){ 
                         aceptacion(11);
                         break;
                    }
                    else
                    if ( c == ";"){ 
                         aceptacion(12);
                         break;
                    }
                    else
                    if ( c == ","){ 
                         aceptacion(13);
                         break;
                    }
                    else
                    if ( c == "("){ 
                         aceptacion(14);
                         break;
                    }
                    else
                    if ( c == ")"){ 
                         aceptacion(15);
                         break;
                    }
                    else
                    if ( c == "{"){ 
                         aceptacion(16);
                         break;
                    }
                    else
                    if ( c == "}"){ 
                         aceptacion(17);
                         break;
                    }
                    else
                    if ( c == "="){ 
                         aceptacion(18);
                         break;
                    }
                    else
                    if ( c == "if" ){ 
                         aceptacion(19);
                         break;
                    }
                    else
                    if ( c == "while" ){
                         aceptacion(20);
                         break;
                    }
                    else
                    if ( c == "return" ){ 
                         aceptacion(21);
                         break;
                    }
                    else
                    if ( c == "else" ){
                         aceptacion(22);
                         break;
                    }
                    else
                    if ( c == "int" || c=="float" || c == "void" || c=="char"){ 
                         aceptacion(24);
                         break;
                    }
                    else
                    if ( c == "programa"){ 
                         aceptacion(27);
                         break;
                    }
                    else
                    if ( c == "ListaVar"){ 
                         aceptacion(26);
                         break;
                    }
                    else
                    if ( c == "Definiciones"){ 
                         aceptacion(28);
                         break;
                    }
                    else
                    if ( c == "Definicion"){ 
                         aceptacion(29);
                         break;
                    }
                    else
                    if ( c == "DefVar"){ 
                         aceptacion(30);
                         break;
                    }
                    else
                    if ( c == "DefFunc"){ 
                         aceptacion(31);
                         break;
                    }
                    else
                    if ( c == "Parametros"){ 
                         aceptacion(32);
                         break;
                    }
                    else
                    if ( c == "ListaParam"){ 
                         aceptacion(33);
                         break;
                    }
                    else
                    if ( c == "BloqFunc"){ 
                         aceptacion(34);
                         break;
                    }
                    else
                    if ( c == "DefLocales"){ 
                         aceptacion(35);
                         break;
                    }
                    else
                    if ( c == "DefLocal"){ 
                         aceptacion(36);
                         break;
                    }
                    else
                    if ( c == "Sentencias"){ 
                         aceptacion(37);
                         break;
                    }
                    else
                    if ( c == "Sentencia"){ 
                         aceptacion(38);
                         break;
                    }
                    else
                    if ( c == "Otro"){ 
                         aceptacion(39);
                         break;
                    }
                    else
                    if ( c == "Bloque"){ 
                         aceptacion(40);
                         break;
                    }
                    else
                    if ( c == "ValorRegresa"){ 
                         aceptacion(41);
                         break;
                    }
                    else
                    if ( c == "Argumentos"){ 
                         aceptacion(42);
                         break;
                    }
                    else
                    if ( c == "ListaArgumentos"){ 
                         aceptacion(43);
                         break;
                    }
                    else
                    if ( c == "Termino"){ 
                         aceptacion(44);
                         break;
                    }
                    else
                    if ( c == "LlamadaFunc"){ 
                         aceptacion(45);
                         break;
                    }
                    else
                    if ( c == "SentenciaBloque"){ 
                         aceptacion(46);
                         break;
                    }
                    else
                    if ( c == "Expresion"){ 
                         aceptacion(47);
                         break;
                    }
                    else
                    if ( c == "$" ){ 
                         aceptacion(3);
                         break;
                    }
                    else
                    if ( c == " " || c == "\t"){ 
                         aceptacion(25);
                         break;
                    }
                    //para palabras que son numeros variables o cadenas se hace un for para comprobar que tipo de palabra es
                    for (int i=0; i < longitud ; i++){ 
                         bool x = isdigit(c[i]);
                         if(x == 0 && c[i] != '-'){entero = false;}//si los caracteres de la palabra no son solo digitos sognifica que no es un entero
                         if(x == 0 && c[i] != '.' && c[i] != '-')reales = false;//si uno de los caracteres no es digito y no es un punto no es un real
                         if(x == 0 && c[i] == '\"')cadena = true;//si el caracter no es digito, ni es punto pero es comilla entonces es cadena.
                    }
                    if (entero == true){ 
                         aceptacion(4);
                         break;
                    }
                    else
                    if (reales == true){ 
                         aceptacion(6);
                         break;
                    }
                    else
                    if (cadena == true){
                         aceptacion(23);
                         break;
                    }
                    else{//si al analizar la palabra no fue ni palabra reservada, ni entero, ni real, ni cadena entonces es identificador
                         aceptacion(1);
                         break;
                    }
               break;                       
          }  
     }    
    //Fin del Automata
     switch (estado){
          case 1:
               tipo = TipoSimbolo::IDENTIFICADOR;
               break; 
          case 2:
               tipo = TipoSimbolo::OPADIC;
               break; 
          case 3:
               tipo = TipoSimbolo::PESOS;
               break; 
          case 4:
               tipo = TipoSimbolo::ENTERO;
               break;
          case 5:
               tipo = TipoSimbolo::OPMULT;
               break;
          case 6:
               tipo = TipoSimbolo::REAL;
               break;
          case 7:
               tipo = TipoSimbolo::OPRELAC;
               break;
          case 8:
               tipo = TipoSimbolo::OPOR;
               break;
          case 9:
               tipo = TipoSimbolo::OPAND;
               break;
          case 10:
               tipo = TipoSimbolo::OPNOT;
               break;
          case 11:
               tipo = TipoSimbolo::OPIGUALDAD;
               break;
          case 12:
               tipo = TipoSimbolo::PUNTOYCOMA;
               break;
          case 13:
               tipo = TipoSimbolo::COMA;
               break;
          case 14:
               tipo = TipoSimbolo::PARENABI;
               break;
          case 15:
               tipo = TipoSimbolo::PARENCER;
               break;
          case 16:
               tipo = TipoSimbolo::CORCHETEABI;
               break;
          case 17:
               tipo = TipoSimbolo::CORCHETECER;
               break;
          case 18:
               tipo = TipoSimbolo::IGUAL;
               break;
          case 19:
               tipo = TipoSimbolo::IF;
               break;
          case 20:
               tipo = TipoSimbolo::WHILE;
               break;
          case 21:
               tipo = TipoSimbolo::RETURN;
               break;
          case 22:
               tipo = TipoSimbolo::ELSE;
               break;
          case 23:
               tipo = TipoSimbolo::CADENA;
               break;
          case 24:
               tipo = TipoSimbolo::TIPO;
               break;
          case 26:
               tipo = TipoSimbolo::LISTAVAR;
               break;
          case 27:
               tipo = TipoSimbolo::PROGRAMA;
               break;
          case 28:
               tipo = TipoSimbolo::DEFINICIONES;
               break;
          case 29:
               tipo = TipoSimbolo::DEFINICION;
               break;
          case 30:
               tipo = TipoSimbolo::DEFVAR;
               break;
          case 31:
               tipo = TipoSimbolo::DEFFUNC;
               break;
          case 32:
               tipo = TipoSimbolo::PARAMETROS;
               break;
          case 33:
               tipo = TipoSimbolo::LISTAPARAM;
               break;
          case 34:
               tipo = TipoSimbolo::BLOQFUNC;
               break;
          case 35:
               tipo = TipoSimbolo::DEFLOCALES;
               break;
          case 36:
               tipo = TipoSimbolo::DEFLOCAL;
               break;
          case 37:
               tipo = TipoSimbolo::SENTENCIAS;
               break;
          case 38:
               tipo = TipoSimbolo::SENTENCIA;
               break;
          case 39:
               tipo = TipoSimbolo::OTRO;
               break;
          case 40:
               tipo = TipoSimbolo::BLOQUE;
               break;
          case 41:
               tipo = TipoSimbolo::VALORREGRESA;
               break;
          case 42:
               tipo = TipoSimbolo::ARGUMENTOS;
               break;
          case 43:
               tipo = TipoSimbolo::LISTAARGUMENTOS;
               break;
          case 44:
               tipo = TipoSimbolo::TERMINO;
               break;
          case 45:
               tipo = TipoSimbolo::LLAMADAFUNC;
               break;
          case 46:
               tipo = TipoSimbolo::SENTENCIABLOQUE;
               break;
          case 47:
               tipo = TipoSimbolo::EXPRESION;
               break;
          default:                 
               tipo= TipoSimbolo::ERROR;
     }
	return tipo;
}

string Lexico::sigCaracter(){
     string palabra;
     if (terminado()){ 
          return "$";
     }
     //revisamos si hay un simbolo de $ antes del final de la cadena para terminar precipitadamente
     if(fuente[ind] == '$'){
          return "$";
     }
     // recorremos la cadena letra por leta y se suman en una variable, cuando hay un espacio
     // esta variable forma una "palabra" y esta se regresa para analizar de que tipo es
     else{
          while(fuente[ind] != ' '){
               palabra += fuente[ind];
               ind++;
          }
          if(fuente[ind] == ' '){
               ind++;
          }
          return palabra;
     }
}

//asigna a estado el numero de oprador del que se trata la palabra.
void Lexico::sigEstado(int estado){
     this->estado = estado;
     simbolo += c;
}

//llama a la funcion para asignar estado y pausa el siclo while principal
void Lexico::aceptacion(int estado){
     sigEstado(estado);
     continua= false;
}

bool Lexico::terminado(){//fin de cadena
     if (ind >= fuente.length()){
          return true;
     }
}
