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

    //nuevos métodos practica 11

    TList(const TList& other);

    TList GetReverseList(TList IstSrc);
};

//constructor copia
TList::TList(const TList& other):head(nullptr) {
    TListNode* node = other.head;
    while (node != nullptr)
    {
        Push(node->data);
        node = node->next;
    }
}

//lista invertida
TList TList::GetReverseList(TList IstSrc) {
    
    const TList& copyl = TList(IstSrc);
    TList* resl = new TList();

    TListNode* node = copyl.head;
    while (node != nullptr)
    {
       TListNode* newNode = new TListNode(node->data);
        newNode->next = resl->head;
        resl->head = newNode;
        node = node->next;
    }

    return *resl;
}

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
	/*TList* l = new TList(); //Inicialización a vacío
	l->Push("hola");
	l->Push("adios");
    l->Push("adios");
    printf("Lista inicial: ");
    l->Print(); //Mostrar lista
   
    printf("Lista copiada: ");
    TList* l2 = new TList(*l);
    l2->Print(); //Mostrar lista
    printf("\n");

    l->~TList(); //Destructor
    l2->~TList(); //Destructor*/
    
    TList* l3 = new TList();
    l3->Push("hola");
    l3->Push("adios");
    l3->Push("adios");
    printf("Lista inicial a invertir: ");
    l3->Print(); //Mostrar lista

    TList* l4 = new TList(l3->GetReverseList(*l3));
    printf("Lista Invertida: ");
    l4->Print();
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
