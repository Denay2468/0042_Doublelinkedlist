#include <iostream>
#include <string>
using namespace std;

class Node 
{
    public:
        int nuMo;
        Node *next;
        Node *prev;
};

class DoublyLinkedList {

    private:
        Node *START;

    public:
        DoublyLinkedList() {
            START = NULL;
    }

    void addError(){
        int nim;
          cout << "Enter the roll number of the student: ";
          cin >> nim;

          Node *newNode = new Node();

          newNode->nuMo = nim;

          if (START == NULL || nim <= START->nuMo) {

            if (START != NULL && nim == START->nuMo) {
                cout << "Unduplicate number not allowed" << endl;
                return;
            }

            if (START != NULL)
                START->prev = newNode;
            newNode->next = START;
            newNode->prev = NULL;
            START = newNode;
            return;

          }

           Node *current = START;
        while (current->next != NULL && current->next->nuMo < nim)
            current = current->next;

        if (current->next != NULL && nim == current->next->nuMo) {
            cout << "Unduplicate roll numbers not allowed" << endl;
            return;
        }

         newNode->next = current->next;
         newNode->prev = current;

         if (current->next != NULL)
            current->next->prev = newNode;
         current->next = newNode;      
    }

    void hapus(){
         if (START == NULL) {
            cout << "sklist is empty" << endl;
            return;
        }

        int rollNo;
        cout << "Enter the roll number of the student whose record is to be deleted: ";
        cin >> rollNo;

        Node *current = START;

           while (current != NULL && current->nuMo != rollNo)
            current = current->next;

        if (current == NULL) {
            cout << "Record not found" << endl;
            return;
        }

          if (current == START) {
            START = current->next; 
            if (START != NULL)
                START->prev = NULL; 
        } else {

            current->prev->next = current->next;

            if (current->next != NULL)
                current->next->prev = current->prev;
        }

        delete current;
        cout << "Record with roll number " << rollNo << " deleted" << endl;

    }
};



