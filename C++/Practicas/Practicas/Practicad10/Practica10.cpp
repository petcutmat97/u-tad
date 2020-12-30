// Practica7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdlib.h> 
#include <fstream>
#include <string>
#include <sstream>
#include <math.h>


using namespace std;

//Fichero en carpeta Debug

namespace TListOperations {
    class TListNode
    {
    public:
        const char* data;
        TListNode* next;
        TListNode(const char* c) :data(c), next(NULL) {}
    };

    class TList
    {
    public:
        TListNode* head;
        TList() :head(NULL) {}

        void Push(const char* c);

        const char* First();

        const char* Next();

        const char* Pop();

        void Reset();

        void Print();

        ~TList();
    };

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
            std::cout << " | " << ptr->data;
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
}

using namespace TListOperations;

namespace fileOperations {

    template <typename T>
    void OpenFile(T& _file, const char* _filename, const char* _mode) {

        if (_mode == "r") {
            _file.open(_filename, std::ios_base::in);
        }
        else if (_mode == "w") {
            _file.open(_filename, std::ios_base::out);
        }
        else {
            printf("Modo incorrecto, introducir r o w");
        }
    }

    template <typename T>
    void CloseFile(T& _file) {
        _file.close();
    }

    void ReadFile(ifstream& _file) {

        string line;

        if (_file.is_open())
        {
            while (getline(_file, line))
            {
                cout << line << '\n';
            }
        }

        else printf("No se pudo abrir el archivo");

    }

    void WriteFile(ofstream& _file, string _s) {
        if (_file.is_open())
        {
            _file << _s << "\n";
            _file.close();
        }
        else printf("No se pudo abrir el archivo");
    }

    TList* ConvertToTList(ifstream& _file) {

        std::streampos p = _file.tellg();
        stringstream ss;
        ss << _file.rdbuf();
        _file.seekg(p);

        TList* l = new TList();

        while (ss.good()) {
            string substr;
            getline(ss, substr, ','); //separa por comas

            //conversion a char[]
            char* data = new char[substr.size() + 1];
            copy(substr.begin(), substr.end(), data);
            data[substr.size()] = '\0';

            l->Push(data);
        }

        return l;
    }
}

using namespace fileOperations;


int main()
{
    ifstream inmainFile;
    fileOperations::OpenFile(inmainFile, "fichero.txt", "r");

    TList* l = fileOperations::ConvertToTList(inmainFile);
    l->TListOperations::TList::Print();
    std::cout << "Primer nodo: " << l->TListOperations::TList::First() << "\n";

    fileOperations::CloseFile(inmainFile);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
