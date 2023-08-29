#ifndef PILA_H
#define PILA_H

#include <list>
#include <iostream>
#include <string>

using namespace std;

class Pila
{
	public:
		void push(int x);
    	int top();
    	int pop();
    	void muestra();

	protected:
		list <int> lista;

};

#endif
