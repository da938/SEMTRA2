#ifndef _PILA
#define _PILA

#include <list>
#include <iostream>
#include <string>

using namespace std;

class ElementoPila{
   protected:
      int valor;
   public:
      virtual void muestra(){}
      virtual void muestra2(){}
      virtual int numero(){}
};

class Terminal: public ElementoPila{
   protected:
      string literal;
   public:
      Terminal(int valor, string literal){
         this->valor = valor;
         this->literal= literal;
      }

      void muestra(){
         cout << "Terminal" << endl;
         cout << "valor: " << valor << endl;
         cout << "Literal: " << literal << endl << endl;
      }

      void muestra2(){
         cout << "Ter-";
      }

      int numero(){
         return valor;
      }
};
class NoTerminal: public ElementoPila{
   protected:
      string literal;
   public:
      NoTerminal(int valor, string literal){
         this->valor = valor;
         this->literal= literal;
      }
      void muestra(){
         cout << "NoTerminal" << endl;
         cout << "valor: " << valor << endl;
         cout << "Literal: " << literal << endl << endl;
      }
      void muestra2(){
         cout << "NoTer-";
      }
      int numero(){
         return valor;
      }
};
class Estado: public ElementoPila{
   public:
      Estado(int valor){
         this->valor = valor;
      }
      void muestra(){
         cout << "Estado" << endl;
         cout << "valor: " << valor << endl;
      }
      void muestra2(){
         cout << "Est-";
      }
      int numero(){
         return valor;
      }
};

class Pila{
   private:      
      list<ElementoPila*> lista;      
      
   public:  
      void push(ElementoPila* x);
      int top();
      ElementoPila* pop();
      void muestra();
};


#endif
