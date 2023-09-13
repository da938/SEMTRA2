#ifndef _PILA
#define _PILA

#include <list>
#include <iostream>
#include <string>

using namespace std;

class ElementoPila{
protected:
    string simbolo;
public:
    virtual void muestra() {}
    virtual string regresar() {
        return "0";
    
    }
};

class Terminal : public ElementoPila{
protected:
  
public:
    Terminal(string simbolo){
        this->simbolo = simbolo;
    }
    void muestra() {
        cout<<simbolo;
    }
    string regresar(){ 
        return simbolo;
    }
};

class Noterminal : public ElementoPila {
    
public:
    Noterminal(string simbolo){
        this->simbolo = simbolo;
    }
    void muestra() {
        cout<<simbolo;
    }
    string regresar(){
        return simbolo;
    }
};

class Estado : public ElementoPila {
public:
    Estado(string simbolo){
        this->simbolo = simbolo;
    }
    void muestra() {
        cout <<simbolo;
    }
    string regresar(){
        return simbolo;
    }
};

class Pila {

private:
    list <ElementoPila*> lista; 

public:
    void push(ElementoPila* x); 
    ElementoPila* top(); 
    ElementoPila* pop(); 
    void muestra();
};


#endif
