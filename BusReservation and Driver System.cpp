#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include<fstream>
#include <iomanip>
using namespace std;
int length;

class Node {
public:
    string data1, nId, phone; int Tseatnum, seatNo;
    Node* seat;
    //data for driver
    string name;
    string NID, Lnum, pNum;  int age, p_exp;
    Node* next;
    //waiting list
    string nametree, phonewait; Node* person;
    //data of tree
    int time, idt; string day, From, To;
    Node* left, * right;
    Node() {
        next = NULL;
        left = right = NULL;
    }

};


// start driver mood

class driver :public Node {
public:
    Node* front;
    Node* rear;

    driver() {
        // cout << "welcome , here drivers can apply for work" << endl;
        front = rear = NULL;
    }

    bool isEmpty() {
        if (front == NULL)
            return true;
        else
            return false;
    }

    void Enqueue(string name, string NID, string Lnum, string pNum, int age, int p_exp) {
        Node* newnode = new Node();

        newnode->name = name;
        newnode->NID = NID;
        newnode->Lnum = Lnum;
        newnode->pNum = pNum;
        newnode->age = age;
        newnode->p_exp = p_exp;

        if (isEmpty())
            front = rear = newnode;
        else
            rear->next = newnode;
    }


    void confirmation(string name, string NID, string Lnum, string pNum, int age, int p_exp) {
        if (age >= 21) {
            Enqueue(name, NID, Lnum, pNum, age, p_exp);
            cout << "Your application confirmed successfully" << endl;
        }
        else
            cout << "We regret not accepting your application due to your age" << endl;
    }
    void EnterData() {
        string NID, Lnum, pNum; int  age, p_exp; string name;

        cout << "Enter the following data  :  " << endl;
        cout << "Full name: ";  cin >> name; cout << endl;
        cout << "Age: ";   cin >> age;  cout << endl;
        cout << "Phone number: ";  cin >> pNum;   cout << endl;
        cout << "National ID: ";  cin >> NID;  cout << endl;
        cout << "License number: "; cin >> Lnum;  cout << endl;
        cout << "Number of practical experience: ";  cin >> p_exp;  cout << endl;
        confirmation(name, NID, Lnum, pNum, age, p_exp);
    }
    void display() {
        Node* temp = front;
        while (temp != NULL) {
            cout << "UserName :" << temp->name << endl;
            cout << "DriverAge :" << temp->age << endl;
            cout << "PhoneNum :" << temp->pNum << endl;
            cout << "NationalId :" << temp->NID << endl;
            cout << "License number :" << temp->Lnum << endl;
            cout << "Number of practical experience :" << temp->p_exp << endl;
            cout << endl;
            temp = temp->next;

        }
    }
};

//end of user mood

class BusReservation : public Node {
public:
    //int length; 
    int i = 1;

    Node* head;  Node* front;  Node* rear;
    Node* root;
    BusReservation()
    {

        head = NULL;
    }


    Node* InsertTree(Node* pnode, string data3, string data4, int data1, string data2) {
        if (pnode == NULL) {
            Node* newnode = new Node();
            newnode->time = data1;
            newnode->day = data2;
            newnode->From = data3;
            newnode->To = data4;
            pnode = newnode;
        }
        else if (data1 < pnode->time) {
            pnode->left = InsertTree(pnode->left, data3, data4, data1, data2);
        }
        else {
            pnode->right = InsertTree(pnode->right, data3, data4, data1, data2);
        }
        return pnode;

    }
    void InsertTree(string data3, string data4, int data1, string data2) {
        root = InsertTree(root, data3, data4, data1, data2);
    }
    void DataEntrytree(Node* r) {
        InsertTree("Alex", "Cairo", 3, "am");
        InsertTree("Cairo", "Alex", 0, "am");
        InsertTree("Sharm", "Alex", 6, "am");
        InsertTree("Aswan", "Cairo", 9, "am");
        InsertTree("Cairo", "Luxer", 18, "pm");
        InsertTree("Hurghada", "Cairo", 21, "pm");
        InsertTree("Cairo", "Alex", 12, "pm");
        InsertTree("Cairo", "Aswan", 15, "pm");
        //displaytreeinorder(root);
    }
    /* void data(Node* r) {
         char ch;
         cout << "Do you Want To see our trips for today (y/n)? "; cin >> ch;
         if (ch == 'y' || ch == 'Y')
         {
             DataEntrytree(r);
         }
         else {
             cout << "Thanks For UR Time " << endl;
             return ;
         }
     }*/
    void displaytreeinorder(Node* r) {
        if (r == NULL) {
            return;
        }
        displaytreeinorder(r->left);
        cout << r->idt << '-' << " From  " << r->From << " To  " << r->To << " At  " << r->time << " : " << r->day << endl;
        displaytreeinorder(r->right);

    }
    Node* searchtree(Node* r, int key) {
        if (r->time == key) {
            cout << "From : " << r->From << endl << "To : " << r->To << endl << " At " << r->time << " : " << r->day << endl;
            return r;
        }
        else if (key < r->time) {
            return searchtree(r->left, key);
        }
        else {
            return searchtree(r->right, key);
        }

    }

    bool searchtree(int key) {
        Node* res = searchtree(root, key);
        if (res == NULL) {

            return false;
        }
        else
        {
            return true;
        }
    }

    bool isempty() {
        if (head == NULL)
            return true;
        else if (head != NULL)
            return false;
        //for waiting list
        if (front == NULL)
            return true;
        else
            return false;
    }
    void InsertFirst(string Name, int seatNo, string Id, string phone) {
        Node* newnode = new Node;
        newnode->data1 = Name;
        newnode->seatNo = seatNo;
        newnode->nId = Id;
        newnode->phone = phone;
        newnode->seat = NULL;
        head = newnode;
        length++;
    }
    void InsertLast(string Name, int seatNo, string Id, string phone) {
        if (isempty())
            InsertFirst(Name, seatNo, Id, phone);
        else {
            Node* temp = head;
            while (temp->seat != NULL)
            {
                temp = temp->seat;
            }
            Node* newnode = new Node();
            newnode->data1 = Name;
            newnode->seatNo = seatNo;
            newnode->nId = Id;
            newnode->phone = phone;
            temp->seat = newnode;
            newnode->seat = NULL;
            length++;
        }

    }
    void EnterData(int key, int offer) {
        string Name, From, To, Id, phone; int Tseatnum, seatNo; char ch; char c;
        if (!search(key)) {
            cout << "This seat is available now , Do U want to reserve it (y/n)? :"; cin >> ch;
            if (ch == 'y' || ch == 'Y') {
                cout << "Enter UR Name :"; cin >> Name;
                cout << "Enter UR NationalId :"; cin >> Id;
                cout << "Enter UR Phone :"; cin >> phone;
                seatNo = key;
                cout << "Do U Want To Confirm UR Reserve?(y/n) :"; cin >> c;
                Confirmation(c);
                InsertLast(Name, seatNo, Id, phone);
                //Confirmation(c);
                system("cls");
                Display(key);
                searchtree(offer);

            }
        }

    }
    void Display(int key) {
        Node* temp = head;
        while (temp != NULL) {
            if (temp->seatNo == key) {
                cout << "UserName :" << temp->data1 << endl;
                cout << "PhoneNumber :" << temp->phone << endl;
                cout << "Seat_No:" << temp->seatNo << endl;
            }
            temp = temp->seat;
        }

    }
   /* void Display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << "UserName :" << temp->data1 << endl;
            cout << "PhoneNumber :" << temp->phone << endl;
            cout << "Seat_No:" << temp->seatNo << endl;
            cout << endl;
            temp = temp->seat;

        }
    }*/

    bool search(int key) {
        Node* temp2 = head;
        while (temp2 != NULL) {
            if (temp2->seatNo == key) {
                cout << "This Seat Is Not Available Now" << endl;
                return true;
            }

            else {
                return false;
            }
          temp2=temp2->seat;
        }
    }

    void cancellation(int key) {
        Node* current = head;
        Node* prev = head;
        if (current->seatNo == key) {  //if we has one node
            head = current->seat;
            //free(current);
            delete current;
            cout << "cancelaation was done" << endl;
            return;
        }
        else {
            while (current->seatNo != key)
            {
                prev = current;
                current = current->seat;
            }
            prev->seat = current->seat;
            delete current;
            cout << "cancelaation was done" << endl;
            length--;
        }
    }

    void Modify(int key, string Name, string From, string To, string Id, string phone, int seatNo) {
        Node* temp2 = head;
        while (temp2 != NULL) {
            if (temp2->seatNo == key) {
                temp2->data1 = Name;
                temp2->nId = Id;
                temp2->phone = phone;
                temp2->seatNo = seatNo;
                //temp2 = temp2->seat;
            }

            else
                cout << "UR Search Is Already Reserved" << endl;
            temp2 = temp2->seat;
        }
    }
    void EnterDAtaUpdate() {
        string Name, Id, phone; int  seatNo; int key;
        cout << "Enter Ur Seat Number :"; cin >> key;
        cout << "Enter UR Name :"; cin >> Name;
        cout << "Enter UR NationalId :"; cin >> Id;
        cout << "Enter UR Phone :"; cin >> phone;
        cout << "Enter UR seatno :"; cin >> seatNo;
        Modify(key, Name, From, To, Id, phone, seatNo);

    }

    void Confirmation(char ch) {
        if (ch == 'y' || ch == 'Y') {
            cout << endl;
            cout << "    **Reserved Is Confirmed**     ";
        }
        else {
            int b;
            cout << "if u want to modify enter 1 or 2 for cancellation" << endl;
            cout << "enter ur choice :"; cin >> b;
            if (b == 1) {
                cout << endl;

                EnterDAtaUpdate();

            }
            else {
                int n;
                cout << "enter UR Seat Number :"; cin >> n;
                cancellation(n);
            }
        }
    }

    void Enqueuewaitinglist(string name, string phone) {
        Node* newnode = new Node();

        newnode->name = nametree;
        newnode->phonewait = phone;

        if (isempty())
            front = rear = newnode;
        else
            rear->next = newnode;
        cout << "***We will send you a message when we add new trips***. " << endl;
    }
};
int main()
{
    BusReservation* op = new BusReservation(); driver* b = new driver(); op->DataEntrytree(op->root);
    cout << "********WELCOME*********" << endl;
    char ch;
    do {

        int num;
        cout << "1-User wants to book" << endl; cout << "2-Driver wants to apply for a job" << endl;
        cout << "Enter UR Choice : "; cin >> num;
        switch (num)
        {

        case 1: {
            int num2; //op->DataEntrytree(op->root);
            cout << "1-Reservation" << endl << "2-Modify" << endl << "3-Cancellation" << endl;
            cout << "Enter ur choice : "; cin >> num2;
            if (num2 == 1) {
                cout << "     ******Reservation Mood******    " << endl;
                int key; char ch; int offer;
                op->displaytreeinorder(op->root);
                cout << "is there a suitable trip for you that u would like to book (y/n)?"; cin >> ch;
                if (ch == 'y') {
                    cout << "Enter Seat Number To Reserve It :"; cin >> key;
                    cout << "Choce UR trip time :"; cin >> offer;
                    op->EnterData(key, offer);
                }
                else {
                    char m; string phone, name;
                    cout << "Do U want to send u a message if there are new trips(y/n)?"; cin >> m;
                    if (m == 'y') {
                        cout << "please enter these data: " << endl;
                        cout << "full name :"; cin >> name;
                        cout << endl;
                        cout << "phone :"; cin >> phone; cout << endl;
                        op->Enqueuewaitinglist(name, phone);
                    }
                    else {
                        cout << "thanks for your time" << endl;
                    }
                }
            }
            else if (num2 == 3) {
                int key;
                cout<<"enter seat number :"; cin >> key;
                op->cancellation(key);
            }
            else{

                op->EnterDAtaUpdate();
            }

        }break;
        case 2: {
            driver* b = new driver();

            cout << "welcome , here drivers can apply for work" << endl;
            b->EnterData();
        }



        }
        cout << endl;

        cout << "Do U want anything else(y/n) ?"; cin >> ch;

    } while (ch == 'y' || ch == 'Y');

    return 0;


}

