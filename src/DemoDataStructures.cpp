//============================================================================
// Autor: Diardon
// Blog : https://diardon.wordpress.com/
//============================================================================

#include <iostream>
#include <string>
#include <vector>		// Arrays
#include <algorithm>	// Algoritmos como el ordenamiento
#include <list>			// Listas enlazadas
#include <stack>		// Pilas
#include <queue>		// Colas
#include <set>			// Conjuntos
#include <map>			// Diccionarios o mapas

using namespace std;

void testArray();
void showVector(std::vector<int> vec, std::string titulo);
void testList();
void showList(std::list<int> numeros, std::string titulo);
void testStack();
void testQueue();
void showSet(std::set<int> numeros, std::string titulo);
void testSet();
void showMultiSet(std::multiset<int> numeros, std::string titulo);
void testMultiSet();
void showMap(std::map<std::string, int> numeros, std::string titulo);
void testMap();
void showMultiMap(std::multimap<std::string, int> numeros, std::string titulo);
void testMultiMap();

int main()
{
	//testArray();
	//testList();
	//testStack();
	//testQueue();
	//testSet();
	//testMultiSet();
	//testMap();
	testMultiMap();

	return 0;
}

void showMultiMap(std::multimap<std::string, int> numeros, std::string titulo = "")
{
	if(!titulo.empty())
    {
		std::cout << titulo << std::endl;
    }
    for(std::map<std::string, int>::iterator it = numeros.begin(); it != numeros.end(); ++it)
    {
        std::cout << "{" << it->first << ", "<<  it->second << "} ";
    }
    std::cout << std::endl << "Tamaño: " << numeros.size() << std::endl << std::endl;
}

void testMultiMap()
{
    // Crear mapa
    std::multimap<std::string, int> numeros;

    // Añadir elementos
    numeros.insert(std::pair<std::string, int>("Uno", 1));
    numeros.insert(std::pair<std::string, int>("Dos", 2));
    numeros.insert(std::pair<std::string, int>("Dos", 20));
    numeros.insert(std::pair<std::string, int>("Tres", 3));
    numeros.insert(std::pair<std::string, int>("Cuatro", 4));
    numeros.insert(std::pair<std::string, int>("Uno", 10));
    numeros.insert(std::pair<std::string, int>("Uno", 100));
    numeros.insert(std::pair<std::string, int>("Uno", 1000));

    showMultiMap(numeros, "Mapa creado");

    std::pair<std::multimap<std::string, int>::iterator, std::multimap<std::string, int>::iterator> rango = numeros.equal_range("Uno");
	std::cout << "Elementos con clave 'Uno':" << std::endl;
	for(std::multimap<std::string, int>::iterator it = rango.first; it != rango.second; ++it)
	{
		std::cout << it->first << " -> " << it->second << std::endl;
	}
	std::cout << std::endl;

    // Mapa vacío
    std::cout << "¿Mapa vacío?: " << (numeros.empty() ? "Sí" : "No") << std::endl << std::endl;

    numeros.erase("Uno"); // Elimina elementos
    showMultiMap(numeros, "Mapa despues de borrar");

    // Buscar elementos
    std::map<std::string, int>::iterator it = numeros.find("Dos");	// Encuentra el primero
    if(it != numeros.end())
    {
        std::cout << "Elemento encontrado: {" << it->first << ", "<<  it->second << "}"<< std::endl << std::endl;
    }

    // Contar elementos
    std::cout << "Ocurrencia(s) de 'Dos': " << numeros.count("Dos") << std::endl;
    std::cout << "Ocurrencia(s) de 'Cinco': " << numeros.count("Cinco") << std::endl;
}

void showMap(std::map<std::string, int> numeros, std::string titulo = "")
{
	if(!titulo.empty())
    {
		std::cout << titulo << std::endl;
    }
    for(std::map<std::string, int>::iterator it = numeros.begin(); it != numeros.end(); ++it)
    {
        std::cout << "{" << it->first << ", "<<  it->second << "} ";
    }
    std::cout << std::endl << "Tamaño: " << numeros.size() << std::endl << std::endl;
}

void testMap()
{
    // Crear mapa
    std::map<std::string, int> numeros;

    // Añadir elementos
    numeros.insert(std::pair<std::string, int>("Uno", 1));
    numeros.insert(std::pair<std::string, int>("Dos", 2));
    numeros.insert(std::pair<std::string, int>("Tres", 3));
    numeros.insert(std::pair<std::string, int>("Cuatro", 4));
    numeros.insert(std::pair<std::string, int>("Uno", 1));	// Ya existe, no se agrega

    showMap(numeros, "Mapa creado");

    std::cout << "Valor para clave 'Dos': " << numeros["Dos"] << std::endl;

    // Mapa vacío
    std::cout << "¿Mapa vacío?: " << (numeros.empty() ? "Sí" : "No") << std::endl;

    numeros.erase("Uno"); // Elimina el elemento
    showMap(numeros, "Mapa despues de borrar 'Uno'");

    // Buscar elementos
    std::map<std::string, int>::iterator it = numeros.find("Tres");
    if(it != numeros.end())
    {
        std::cout << "Elemento encontrado: {" << it->first << ", "<<  it->second << "}"<< std::endl;
    }

    // Contar elementos
    std::cout << "Ocurrencia(s) de 'Dos': " << numeros.count("Dos") << std::endl;
    std::cout << "Ocurrencia(s) de 'Cinco': " << numeros.count("Cinco") << std::endl;
}

void showMultiSet(std::multiset<int> numeros, std::string titulo = "")
{
	if(!titulo.empty())
    {
		std::cout << titulo << std::endl;
    }
    for(std::set<int>::iterator it = numeros.begin(); it != numeros.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << "Tamaño: " << numeros.size() << std::endl << std::endl;
}

void testMultiSet()
{
    // Crear conjunto
    std::multiset<int> numeros;

    // Añadir elementos
    numeros.insert(10);
    numeros.insert(10);
    numeros.insert(10);
    numeros.insert(20);
    numeros.insert(30);
    numeros.insert(30);
    numeros.insert(40);
    numeros.insert(50);

    showMultiSet(numeros, "Conjunto creado");

    // empty(): Verificar el conjunto está vacío
    std::cout << "¿Conjunto vacío?: " << (numeros.empty() ? "Sí" : "No") << std::endl;

    numeros.erase(20); // Elimina el elemento 20.
    showMultiSet(numeros, "Conjunto despues de borrar 20");

    // Buscar elementos
    std::set<int>::iterator it = numeros.find(30);
    if(it != numeros.end())
    {
        std::cout << "Elemento encontrado: " << *it << std::endl;
    }

    // Contar elementos
    std::cout << "Ocurrencia(s) de 10: " << numeros.count(10) << std::endl;
    std::cout << "Ocurrencia(s) de 30: " << numeros.count(30) << std::endl;
    std::cout << "Ocurrencia(s) de 60: " << numeros.count(60) << std::endl;
}

void showSet(std::set<int> numeros, std::string titulo = "")
{
	if(!titulo.empty())
    {
		std::cout << titulo << std::endl;
    }
    for(std::set<int>::iterator it = numeros.begin(); it != numeros.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << "Tamaño: " << numeros.size() << std::endl << std::endl;
}

void testSet()
{
    // Crear conjunto
    std::set<int> numeros;

    // Añadir elementos
    numeros.insert(10);
    numeros.insert(20);
    numeros.insert(30);
    numeros.insert(40);
    numeros.insert(50);
    numeros.insert(10);	// Ya existe, no se agrega

    showSet(numeros, "Conjunto creado");

    // empty(): Verificar el conjunto está vacío
    std::cout << "¿Conjunto vacío?: " << (numeros.empty() ? "Sí" : "No") << std::endl;

    numeros.erase(10); // Elimina el elemento 10.
    showSet(numeros, "Conjunto despues de borrar 10");

    // Buscar elementos
    std::set<int>::iterator it = numeros.find(20);
    if(it != numeros.end())
    {
        std::cout << "Elemento encontrado: " << *it << std::endl;
    }

    // Contar elementos
    std::cout << "Ocurrencia(s) de 20: " << numeros.count(20) << std::endl;
    std::cout << "Ocurrencia(s) de 60: " << numeros.count(60) << std::endl;
}

void testQueue()
{
    // Crear una pila de enteros
    std::queue<int> numeros;

    // Añadir elementos a la parte superior de la pila
    numeros.push(2);
    numeros.push(4);
    numeros.push(6);
    numeros.push(8);
    numeros.push(10);

    // Primer y último elemento
    std::cout << "Frente de la cola: " << numeros.front() << std::endl;
    std::cout << "Final de la cola: " << numeros.back() << std::endl;

    // empty(): Verificar si la pila está vacía
    std::cout << "¿La cola está vacía?: " << (numeros.empty() ? "Sí" : "No") << std::endl;

    // Tamaño
    std::cout << "Tamaño: " << numeros.size() << std::endl << std::endl;

	// Para mostrar la pila debemos ir vaciándola para acceder al elemento superior
    std::cout << "Elementos de la cola: ";
	while(!numeros.empty ())
	{
		std::cout << numeros.front() << " ";
		numeros.pop ();
	}
    std::cout << std::endl;
}

void testStack()
{
    // Crear una pila de enteros
    std::stack<int> numeros;

    // Añadir elementos a la parte superior de la pila
    numeros.push(1);
    numeros.push(2);
    numeros.push(3);
    numeros.push(5);
    numeros.push(7);

    // Elemento en la cima de la pila
    std::cout << "Elemento en la cima de la pila: " << numeros.top() << std::endl;

    // Eliminar el elemento en la cima de la pila
    numeros.pop();
    std::cout << "Elemento en la cima de la pila después de pop(): " << numeros.top() << std::endl;

    // empty(): Verificar si la pila está vacía
    std::cout << "¿La pila está vacía?: " << (numeros.empty() ? "Sí" : "No") << std::endl;

    // Tamaño
    std::cout << "Tamaño: " << numeros.size() << std::endl << std::endl;

	// Para mostrar la pila debemos ir vaciándola para acceder al elemento superior
    std::cout << "Elementos de la pila: ";
	while(!numeros.empty ())
	{
		std::cout << numeros.top () << " ";
		numeros.pop ();
	}
    std::cout << std::endl;
}

void showList(std::list<int> numeros, std::string titulo = "")
{
	if(!titulo.empty())
    {
		std::cout << titulo << std::endl;
    }
    for(std::list<int>::iterator it = numeros.begin(); it != numeros.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << "Tamaño: " << numeros.size() << std::endl << std::endl;
};

void testList()
{
    // Lista de enteros
    std::list<int> numeros;

    // Insertar al final y al principio
    numeros.push_back(7);    // Inserta 10 al final
    numeros.push_front(9);    // Inserta 5 al principio

    // Agregar elementos
    numeros.push_back(17);
    numeros.push_front(5);

    // Mostrar contenido usando un iterador
    showList(numeros, "Contenido inicial de la lista:");

    // Primer y último elemento
    std::cout << "Primer elemento: " << numeros.front() << std::endl;
    std::cout << "Último elemento: " << numeros.back() << std::endl << std::endl;

    // Eliminación de elementos de los extremos
    numeros.pop_front();  // Elimina el primer elemento
    numeros.pop_back();   // Elimina el último elemento
    showList(numeros, "Lista después de pop_front() y pop_back():");

    // Insertar en posición
    // Nos posicionamos en la segunda posición
    std::list<int>::iterator it = numeros.begin();
    ++it;
    numeros.insert(it, 100);  // Inserta 15 del segundo elemento
    showList(numeros, "Lista despues insertar 100:");

    // Eliminación de un elemento específico mediante iterador
    it = numeros.begin();
    std::advance(it, 1);  // Avanza al segundo elemento
    numeros.erase(it);    // Elimina el elemento en esa posición
    showList(numeros, "Lista despues de borrar el segundo elemento:");

    // Uso de remove: elimina todas las ocurrencias de un valor
    numeros.push_back(10);
    numeros.push_back(10);
    showList(numeros, "Lista con duplicados (10):");

    numeros.remove(10);   // Elimina todos los elementos con valor 10
    showList(numeros, "Lista tras remove(10):");

    // Ordenar la lista
    numeros.push_back(3);
    numeros.push_back(7);
    showList(numeros, "Lista antes de sort():");

    numeros.sort();
    showList(numeros, "Lista tras sort():");

    // Invertir el orden de la lista
    numeros.reverse();
    showList(numeros, "Lista tras reverse():");

    // Limpiar la lista
    numeros.clear();
    showList(numeros, "Lista tras clear():");
}

void showVector(std::vector<int> vec, std::string titulo = "")
{
	if(!titulo.empty())
    {
		std::cout << titulo << std::endl;
    }
    for(std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}
void testArray()
{
    std::vector<int> numeros;
    numeros.push_back(5);
    numeros.push_back(2);
    numeros.push_back(9);
    numeros.push_back(1);
    numeros.push_back(7);
    showVector(numeros, "Orignal");

    std::cout << "Primero: " << numeros.at(0) << ". Último: " << numeros.at(numeros.size() - 1) << std::endl;
    std::cout << "Primero: " << numeros[0] << ". Último: " << numeros[numeros.size() - 1] << std::endl;

    // Insertar nuevo elemento en la posicón 2
    numeros.insert(numeros.begin() + 2, 11);
    showVector(numeros, "Valor insertado");

    // Ordenar
    std::sort(numeros.begin(), numeros.end());
    showVector(numeros, "Ordenado");

    // Tamaño truncado a 3
    numeros.resize(3);
    showVector(numeros, "Tamaño ajustado");

    // Tamaño extendido a 6 y nuevos elementos puestos a cero
    numeros.resize(6, 0);
    showVector(numeros, "Tamaño ajustado");
}
