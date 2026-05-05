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

          }

           
    }
};



