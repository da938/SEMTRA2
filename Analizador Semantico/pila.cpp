#include "pila.h"
//#include "lexico.h"
#include <sstream>

//Ingresa el elemento a la pila
void Pila::push(ElementoPila *x){
   lista.push_front(x);
}

//Saca el elemento de la pila y lo regresa
ElementoPila* Pila::pop(){
   ElementoPila* x = *lista.begin();
   lista.erase(lista.begin());
   return x;
};

//regresa el ultimo elemento de la pila
int Pila::top(){
   ElementoPila *x = *lista.begin();
   int y = x->numero();
   return y;     
};

//Imprime toda la pila
void Pila::muestra(){
   list <ElementoPila*>::reverse_iterator it;
   ElementoPila *x;
   cout << "Pila: ";
   for (it= lista.rbegin(); it != lista.rend(); it++){
      x= *it;
      x->muestra();
      //cout << (*it) << " ";
   }
   cout << endl;
};

string Pila::buscador(){
   string literales;
   list <ElementoPila*>::reverse_iterator it;
   ElementoPila *x;
   cout << "Pila: ";
   for (it= lista.rbegin(); it != lista.rend(); it++){
      x= *it;
      literales += x->muestra3();
      //cout << (*it) << " ";
   }
   /* cout << literales << endl;
   cout << endl; */
   return literales;
};

string Pila::imprime(){
   string literales;
   list <ElementoPila*>::reverse_iterator it;
   ElementoPila *x;
   cout << "Pila: ";
   for (it= lista.rbegin(); it != lista.rend(); it++){
      x= *it;
      literales += x->muestra3();
      if(x->muestra3() == "Expresion"){
         cout << x->numero() << endl;
      }
      //cout << (*it) << " ";
   }
   /* cout << literales << endl;
   cout << endl; */
   return literales;
};