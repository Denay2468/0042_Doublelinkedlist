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

    void addEnd(){
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
            cout << "list is empty" << endl;
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

    void Traversal(){
          if (START == NULL) {
            cout << "list is empty" << endl;
            return;
        }

        Node *currentNode = START;

        cout << "Records in ascending order of roll number are:\n";
        int i = 0;
        while (currentNode != NULL) {
            cout << i + 1 << ". " << currentNode->nuMo << " " << endl;
            currentNode = currentNode->next;
            i++;
        }

    }
    void ReverseTraversal(){

        if (START == NULL) {
            cout << "list is empty" << endl;
            return;
        }

        Node *currentNode = START;
        int i = 0;
        while (currentNode->next != NULL) {
            currentNode = currentNode->next;
            i++;
        }

        cout << "Records in descending order of roll number are:\n";
        while (currentNode != NULL) {
            cout << i << ". " << currentNode->nuMo << " " << endl;
            currentNode = currentNode->prev;
            i--;
        }

    }

        void searchData() {
        if (START == NULL) {
            cout << "list is empty" << endl;
            return;
        }

        int rollNo;
        cout << "Enter the roll number to search: ";
        cin >> rollNo;

        Node *current = START;

        while (current != NULL && current->nuMo != rollNo)
            current = current->next;

        if (current == NULL) {
            cout << "Record not found";
        } else {
            cout << "Record found!" << endl;
            cout << "Roll number: " << current->nuMo << endl;
        }
    }
};

int main() {
    DoublyLinkedList list;
    int choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Add Record\n";
        cout << "2. Delete Record\n";
        cout << "3. View Ascending\n";
        cout << "4. View Descending\n";
        cout << "5. Search Record\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";

        cin >> choice;

        switch (choice) {
            case 1:
                list.addEnd();
                break;
            case 2:
                list.hapus();
                break;
            case 3:
                list.Traversal();
                break;
            case 4:
                list.ReverseTraversal();
                break;
            case 5:
                list.searchData();
                break;
            case 6:
                break;
            default:
                cout << "Invalid options.";
        }

        cout << "\nPress Enter to continue...";
        cin.get();
        cin.get();
    } while (choice != 6);
}



