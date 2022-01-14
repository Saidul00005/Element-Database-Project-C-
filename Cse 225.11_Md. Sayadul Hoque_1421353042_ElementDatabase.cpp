#include <iostream>
#include<bits/stdc++.h>
using namespace std;


struct Element
{
    int atomicNumber;
    string symbol;
    string name;
    Element *left;
    Element *right;
};

class ElementDatabase{
    private:
        Element* root;

        void addElement(Element *&e, int atomicNumber, string symbol, string name){
            if(e == NULL){
                e = new Element;
                e->atomicNumber = atomicNumber;
                e->symbol=symbol;
                e->name=name;
                e->left = NULL;
                e->right = NULL;
            }else if(atomicNumber < e->atomicNumber){
                addElement(e->left,atomicNumber,symbol,name);
            }else{
                addElement(e->right,atomicNumber,symbol,name);
            }

        }


        void printElements(Element *e){
            if(e == NULL){
               return;
            }
            printElements(e->left);
            cout << e->atomicNumber << "," << e->symbol << "," << e->name << ".";
            cout<<"\n";
            printElements(e->right);
        }


         void printspecificElement(Element *e){
            if(e == NULL){
               cout<<"No element found";
            }
            cout << e->atomicNumber << "," << e->symbol << "," << e->name << ".";
        }


         void findspecificElement(Element *e, int atomicNumber){
            if(e==NULL){
                return ;
            }

            if(e->atomicNumber == atomicNumber){
                return printspecificElement(e);
            }else if(atomicNumber < e->atomicNumber){
                 findspecificElement(e->left,atomicNumber);
            }else{
                 findspecificElement(e->right,atomicNumber);
            }
        }


         bool availabilityofElement(Element *e, int atomicNumber){
            if(e==NULL){
                return false ;
            }

            if(e->atomicNumber == atomicNumber){
                return true;
            }else if(atomicNumber < e->atomicNumber){
                 availabilityofElement(e->left,atomicNumber);
            }else{
                 availabilityofElement(e->right,atomicNumber);
            }
        }

        bool validityofSymbol(Element *e, string symbol){
            if(e==NULL){
               return false ;
            }

            validityofSymbol(e->left,symbol);

            if (e->symbol== symbol){
                return true;
              }
            validityofSymbol(e->right,symbol);

        }


        // Returns the address of the element if a match is found
        // Return NULL if no match is found
        Element* findElementBySymbol(Element *e, string symbol){
            if(e==NULL){
               return NULL ;
            }

            findElementBySymbol(e->left,symbol);

            if (e->symbol== symbol){
                printspecificElement(e);
                return e;
              }
            findElementBySymbol(e->right,symbol);

        }

        bool validityofName(Element *e, string name){
            if(e==NULL){
               return false ;
            }
            validityofName(e->left,name);
            if (e->name== name){
                printspecificElement(e);
                return true;

            }
            validityofName(e->right,name);
        }


        // Returns the address of the element if a match is found
        // Return NULL if no match is found
        Element* findElementByName(Element *e, string name){
            if(e==NULL){
               return NULL ;
            }
            findElementByName(e->left,name);
            if (e->name== name){
                printspecificElement(e);
                return e;

            }
            findElementByName(e->right,name);
        }



        void deleteElement(Element *&e, int atomicNumber){
            if(e == NULL){
                return;
            }

             if(e->atomicNumber == atomicNumber){
                delete e;
                e=NULL;
            }else if(atomicNumber < e->atomicNumber){
                 deleteElement(e->left,atomicNumber);
            }else{
                 deleteElement(e->right,atomicNumber);
            }

        }



    public:
        ElementDatabase(){
            root = NULL;
        }

        void addElement(int atomicNumber, string symbol, string name){
            addElement(root, atomicNumber, symbol, name);
        }

        void printElements(){
            printElements(root);
        }

         void printspecificElement(){
            printspecificElement(root);
        }

        // Returns the address of the element if a match is found
        // Return NULL if no match is found
        Element* findElementBySymbol(string symbol){
            return findElementBySymbol(root, symbol);
        }

        bool validityofSymbol(string symbol){
            return validityofSymbol(root, symbol);
        }

        // Returns the address of the element if a match is found
        // Return NULL if no match is found
        Element* findElementByName(string name){
            return findElementByName(root,name);
        }

        bool validityofName(string name){
            return validityofName(root,name);
        }


        void deleteElement(int atomicNumber){
            deleteElement(root,atomicNumber);
        }

        void findspecificElement(int atomicNumber){
             findspecificElement(root,atomicNumber);
        }
        bool availabilityofElement(int atomicNumber){
             availabilityofElement(root,atomicNumber);
        }

};

void printmenu(){
    cout << "1. Add an Element\n";
    cout << "2. View Elements\n";
    cout << "3. Search elements by chemical symbol\n";
    cout << "4. Search elements by element name\n";
    cout << "5. Delete an element\n";
    cout << "6. Exit program\n";
    cout << endl;
    }
int main(){
        // Complete the functions above
        // Add more functions if necessary
        // Create the menu as shown in the example of program execution
        // The program should only exit when the user chooses "Exit program"

    ElementDatabase ED;
    int option;
     do
    {
        cout<<"\n";
        printmenu();
        cout<< "Enter your Choice:";
        cin >> option;
        cout << endl;
        if (option == 1)
        {
        int atN;
        string symb;
        string n;

        cout<< "**Add an Element**\n";
        cout<< "Enter atomic number:";
        cin >> atN;
        cout<< "Enter Chemical symbol:";
        cin >> symb;
        transform(symb.begin(), symb.end(), symb.begin(), ::tolower);
        cout<< "Enter element name:";
        cin >> n;
        transform(n.begin(), n.end(), n.begin(), ::tolower);

        ED.addElement(atN,symb,n);
        cout<<"\n";
        cout<< "Element added successfully\n";
        cout<<"\n\n";
        cout<<"---------------------------------";
        cout << endl;

        }
        else if (option == 2)
        {
        cout<< "**View Elements**\n";
        ED.printElements();
        cout<<"\n\n";
        cout<<"---------------------------------";
        cout << endl;
        }

        else if (option == 3)
        {
         string s;
         cout<< "**Search Elements by Chemical Symbol**\n";
         cout<< "Enter chemical symbol:";
         cin >> s;
         transform(s.begin(), s.end(), s.begin(), ::tolower);
         if (ED.validityofSymbol(s)==true){
         cout<<"\n";
         cout<<"Search result:\n";
         ED.findElementBySymbol(s);
         cout<<"\n\n";
         cout<<"---------------------------------";
         cout << endl;
         }else{
         cout<<"\n";
         cout<<"Search result:\n";
         cout<<"Not found";
         cout<<"\n\n";
         cout<<"---------------------------------";
         cout << endl;

         }
         }
        else if (option == 4)
        {
         string n;
         cout<< "**Search Elements by element name**\n";
         cout<< "Enter Element Name:";
         cin >> n;
         transform(n.begin(), n.end(), n.begin(), ::tolower);
         if (ED.validityofName(n)==true){
         cout<<"\n";
         cout<<"Search result:\n";
         ED.findElementByName(n);
         cout<<"\n\n";
         cout<<"---------------------------------";
         cout << endl;
         }else
         {
         cout<<"\n";
         cout<<"Search result:\n";
         cout<<"Not found";
         cout<<"\n\n";
         cout<<"---------------------------------";
         cout << endl;
         }

        }
        else if (option == 5)
        {
        int a;
        char b;
        cout<< "**Delete an Element**\n";
        cout<< "Enter atomic number:";
        cin >> a;
        cout<<"\n";
        if(ED.availabilityofElement(a)==true){
           cout<< "Do you want to delete:\n";
           cout<<"\n"; \
           ED.findspecificElement(a);
           cout<<"\n";
           cout<<"Enter y or n:";
           cin >> b;
           b=toupper(b);
           if(b=='Y'){
           ED.deleteElement(a);
           cout<<"Element deleted successfully";
           cout<<"\n\n";
           cout<<"---------------------------------";
           cout << endl;
           }else if(b=='N'){
             break;
            }else{
            cout<< "Inappropriate input";
            cout<<"\n\n";
            cout<<"---------------------------------";
            cout<<endl;
            }
          }else{
              cout<< "No element found";
              cout<<"\n\n";
              cout<<"---------------------------------";

          }

        }
        else if (option == 6)
        {
           cout << "Program has exited.....\n";
           break;
        }

    } while (option <=6 && option >=1);
      system ("Pause");
      return 0;
}


