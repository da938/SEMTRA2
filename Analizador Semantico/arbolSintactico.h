#ifndef _ARBOLSINTACTICO
#define _ARBOLSINTACTICO

#include <string>
#include <iostream>
#include "tablaSimbolos.h"

using namespace std;
string variables;

class Nodo{
	public:
		char tipoDato;
		static TablaSimbolos *TablaSimbolos;
		static string ambito;
		string simbolo;
		Nodo *sig;
		
		static int sangria;
		void muestraSangria(){
			for (int i=0; i < sangria; i++)
			cout << " ";
		}

		virtual void muestra(){};
		virtual Nodo* muestra2(){};
		virtual Nodo* muestra3(){};
		virtual string regresatipo(){};
		virtual string regresaListaVar(){};
		virtual bool esFuncion(){};
		virtual bool esParametro(){};
		virtual bool esVariable(){};
		virtual bool esAsignacion(){};
		virtual string regresaParametros(){};

		virtual void validaTipos(){
			tipoDato = 'v';
			if(sig != NULL)sig -> validaTipos();
		}
};

class Tipo: public Nodo{
public:
	Tipo(string simbolo){
		this->simbolo= simbolo;
		this->sig=NULL;
	}

	void muestra(){
		muestraSangria();
		cout << "<Tipo> " << simbolo << endl;
	}

	char dimeTipo(){
		if (simbolo.compare("int") == 0)return 'i';
		if (simbolo.compare("float") == 0)return 'f';
		if (simbolo.compare("string") == 0)return 's';
		if (simbolo.compare("void") == 0)return 'v';
	}

	string regresatipo(){
		return this->simbolo;
	};

	bool esFuncion(){
		return false;
	};
};

class Expresion: public Nodo{
public:
	Expresion *izq, *der;
		string guardaArbol(){
		return "";
	}

	bool esFuncion(){
		return false;
	};

};

class Identificador: public Expresion{
public:
	Identificador(string simbolo, Nodo *sig=NULL){
		this->simbolo= simbolo;
		this->sig=sig;
	}

	void muestra(){
		muestraSangria();
		cout << "<Identificador> " << simbolo << endl;
		if (sig != NULL) sig->muestra();
	}

	void regresaListaVar2(){
		if (sig != NULL){
			sig->regresaListaVar();
		}
		variables += simbolo;
		//cout << simbolo << endl;
	}

	string regresaListaVar(){
		regresaListaVar2();
		return variables;
	}

	bool esFuncion(){
		return false;
	};
};

class DefVar: public Nodo{
public:
	Tipo *tipo;
	Identificador *listaVar;
	friend class TablaSimbolos;

	DefVar(Tipo *tipo, Identificador *listaVar, Nodo *sig){
		this->tipo= tipo;
		this->listaVar= listaVar;
		this->sig = sig;
	};

	void muestra(){
		muestraSangria();
		cout << "<DefVar> " << endl;
		
		Nodo::sangria++;
		tipo->muestra();
		listaVar->muestra();
		Nodo::sangria--;

		if (sig != NULL) sig->muestra();
	};

	string regresaListaVar(){
		return listaVar->regresaListaVar();
	};

	string regresatipo(){
		return tipo->regresatipo();
	};

	void validaTipos(){
		tipoDato = tipo->dimeTipo();
		TablaSimbolos->agrega(this);
	};

	bool esVariable(){
		return true;
	};

	bool esFuncion(){
		return false;
	};

};

class Parametro: public Nodo{
protected:
public:
	Tipo *tipo;
	Identificador *id;
	friend class TablaSimbolos;

	Parametro (Tipo *tipo, Identificador *id, Nodo *sig){
		this->tipo= tipo;
		this->id= id;
		this->sig= sig;
	};

	void muestra(){
		muestraSangria();
		cout << "<Parametro> " << endl;
		
		Nodo::sangria++;
		tipo->muestra();
		id->muestra();
		Nodo::sangria--;

		if (sig != NULL) sig->muestra();
	};

	string cadTipos(){
		string cad;
		cad += tipo->dimeTipo();
		Parametro *p= (Parametro*)sig;

		while (p != NULL){
			cad += p->tipo->dimeTipo();
			p= (Parametro*)p->sig;
		}

		return cad;
	};
	
	void validaTipos(){
		tipoDato = tipo->dimeTipo();
		TablaSimbolos->agrega(this);
	};

	string regresaListaVar(){
		return this->id->simbolo;
	}

	bool esParametro(){
		return true;
	};

	bool esFuncion(){
		return false;
	};

	string regresaParametros(){
		return this->id->simbolo;
	}
};

class DefFunc: public Nodo{
protected:
public:
	Tipo *tipo;
	Identificador *id;
	Parametro *parametros;
	Nodo *bloqueFunc;
	friend class TablaSimbolos;

	DefFunc(Tipo *tipo, Identificador *id, Parametro *parametros, Nodo *bloqueFunc, Nodo *sig){
		this->tipo= tipo;
		this->id= id;
		this->parametros= parametros;
		this->bloqueFunc= bloqueFunc;
		this->sig= sig;
	};

	void muestra(){
		muestraSangria();
		cout << "<DefFunc> " << endl;
		
		Nodo::sangria++;
		tipo->muestra();
		id->muestra();
		if (parametros) parametros->muestra();
		if (bloqueFunc) bloqueFunc->muestra();
		Nodo::sangria--;

		if (sig != NULL) sig->muestra();
	};

	Nodo* muestra3(){
		if (parametros) return parametros;
	};

	Nodo* muestra2(){
		if (bloqueFunc) return bloqueFunc;
	};

	void validaTipos(){
		tipoDato = tipo->dimeTipo();
		TablaSimbolos->agrega(this);
	};

	bool esFuncion(){
		return true;
	};

	string regresaListaVar(){
		return id->regresaListaVar();
	};

	string regresatipo(){
		return tipo->regresatipo();
	};
};


class Asignacion: public Nodo{
public:
	Identificador *id;
	Expresion *expresion;
	friend class TablaSimbolos;

	Asignacion(	Identificador *id, Expresion *expresion, Nodo *sig= NULL){
		this->id= id;
		this->expresion= expresion;
		this->sig= sig;

	}

	void muestra(){
		muestraSangria();
		cout << "<Asignacion> " << endl;
		
		Nodo::sangria++;
		id->muestra();
		expresion->muestra();
		Nodo::sangria--;

		if (sig != NULL) sig->muestra();
	}

	bool esAsignacion(){
		return true;
	};
};

class Regresa: public Nodo{
protected:
	Expresion *expresion;
	friend class TablaSimbolos;

public:
	
	Regresa(Expresion *expresion, Nodo *sig= NULL){
		this->expresion= expresion;
		this->sig= sig;
	}

	void muestra(){
		muestraSangria();
		cout << "<Regresa> " << endl;
		
		Nodo::sangria++;		
			expresion->muestra();
		Nodo::sangria--;

		if (sig != NULL) sig->muestra();
	}

};

class Entero: public Expresion{
public:
	Entero(string simbolo){
		this->simbolo= simbolo;
		this->sig=NULL;
	}

	void muestra(){
		muestraSangria();
		cout << "<Entero> " << simbolo << endl;
	}
};

class Real: public Expresion{
public:
	Real(string simbolo){
		this->simbolo= simbolo;
		this->sig=NULL;
	}

	void muestra(){
		muestraSangria();
		cout << "<Real> " << simbolo << endl;
	}
};

class Cadena: public Expresion{
public:
	Cadena(string simbolo){
		this->simbolo= simbolo;
		this->sig=NULL;
	}

	void muestra(){
		muestraSangria();
		cout << "<Cadena> " << simbolo << endl;
	}
};

class Signo: public Expresion{
protected:	
public:

	Signo(string simbolo, Expresion *izq){
		this->simbolo = simbolo;
		this->izq= izq;
		sig= NULL;
	}

	void muestra(){
		muestraSangria();
		cout << "<Signo> " << endl;
		
		Nodo::sangria++;		
			izq->muestra();
		Nodo::sangria--;

		if (sig != NULL) sig->muestra();
	}

};

class Mult: public Expresion{
protected:	
public:

	Mult(string simbolo, Expresion *izq, Expresion *der){
		this->der= der;
		this->simbolo= simbolo;
		this->izq= izq;
		sig= NULL;

	}

	void muestra(){
		muestraSangria();
		cout << "<Multiplicacion> " << simbolo << endl;
		
		Nodo::sangria++;		
			izq->muestra();
			der->muestra();
		Nodo::sangria--;

		if (sig != NULL) sig->muestra();
	}

	string guardaArbol(){
		return "new Mult(" + simbolo + "," + izq->guardaArbol() + ", " +  der->guardaArbol() + ") ";
	}
};

class Suma: public Expresion{
protected:	
public:

	Suma(string simbolo, Expresion *izq, Expresion *der){
		this->der= der;
		this->simbolo= simbolo;
		this->izq= izq;
		sig= NULL;

	}

	void muestra(){
		muestraSangria();
		cout << "<Suma> " << simbolo << endl;
		
		Nodo::sangria++;		
			izq->muestra();
			der->muestra();
		Nodo::sangria--;

		if (sig != NULL) sig->muestra();
	}


	string guardaArbol(){
		return "new Suma(" + simbolo + "," + izq->guardaArbol() + ", " +  der->guardaArbol() + ") ";
	}

};


#endif
