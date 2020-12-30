// Practica5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

class TListNode
{
public:
    const char* data;
    TListNode* next;
    TListNode(const char* c):data(c), next(NULL) {}
};

class TList
{
public:
    TListNode* head;
    TList():head(NULL) {}

    int Size();
    
    void Push(const char* c);

    const char* First();

    const char* Next();

    const char* Pop();

    void Reset();

    void Print();

    ~TList();
};


int TList::Size() {
    TListNode* temp;
    int counter = 0;
    while (head != NULL)
    {
        temp = head;
        head = head->next;

        counter++;
    }
    return counter;
}

const char* TList::First() {
    TListNode* current = head;
    
    return (current->data);
}

const char* TList::Next() {
    TListNode* nextNode;
    if (head->next != nullptr) {
        nextNode = head->next;
        return (nextNode->data);
    }
    else {
        return TList::First();
    }
}

void TList::Push(const char* c) //inserting at end of TList
{
    if (head == NULL)
    {
        TListNode* newNode = new TListNode(c);
        newNode->next = head;
        head = newNode;
        return;
    }
    TListNode* newNode = new TListNode(c);
    TListNode* temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}
	
void TList::Print()//printing the TList
{
    TListNode* ptr = head;
    while (ptr != NULL)
    {
        std::cout << ptr->data << " | ";
        ptr = ptr->next;
    }
    std::cout << "\n";
}

TList::~TList()
{
    TListNode* ptr = head, * next = NULL;
    while (ptr != NULL)
    {
        next = ptr->next;
        delete(ptr);
        ptr = next;
    }
}

const char* TList::Pop() {
    TListNode* current = head;
    
    return (current->data);
}


void TList::Reset()//removing an element
{
    TListNode* temp;

    while (head != NULL)
    {
        temp = head;
        head = head->next;

        free(temp);
    }
}

int main()
{
	TList* l = new TList(); //Inicialización a vacío
	l->Push("hola");
	l->Push("adios");
    l->Push("adios");
    printf("Lista con 3 elementos: ");
    l->Print(); //Mostrar lista
    std::cout << "Primer nodo: " << l->First() << "\n";
    std::cout << "Siguiente nodo: " << l->Next() << "\n";
    std::cout << "Numero de elementos: " << l->Size() << "\n";
    l->Reset();
    l->Push("hola");
    l->Push("adios");
    printf("Lista reiniciada con 2 elementos añadidos: ");
    l->Print(); //Mostrar lista
    std::cout << "Primer nodo: " << l->First() << "\n";
    std::cout << "Siguiente nodo: " << l->Next() << "\n";
    std::cout << "Elemento eliminado con Pop: " << l->Pop() << "\n";
    std::cout << "Numero de elementos: " << l->Size() << "\n";
     //ESTO PUEDE ESTAR MAL HECHO POR LO QUE SE PIDE EN EL ENUNCIADO
    printf("Lista tras el Pop: ");
    l->Print(); //Mostrar lista
    l->~TList(); //Destructor
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error TList window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
