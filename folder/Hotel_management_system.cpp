#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

class Hotel
{
private:
    struct Node
    {
        int id;
        string date, type, name, bill;
        Node *next = NULL;
    };

public:
    Node *head = NULL;
    void allocRoom();
    void display();
    void updateRoom();
    void searchRoom();
    void delRoom();
    void showAll();
    void mainmenu();
};

void Hotel::mainmenu()
{
    int btn;
    cout << "\n\npress any key to exit and 0 to go to the main menu\n\n";
    cout << "-> ";
    cin >> btn;
    if (btn == 0)
    {
        display();
    }
    else
    {
        exit(0);
    }
}

void Hotel::display() // display menu..................
{
    system("cls");
    int opt;
    do
    {
        cout << "---------Hotel Management System---------\n\n";
        cout << "Enter your choice and 0 to exit.\n\n";
        cout << "1. Allocate Room.\n";
        cout << "2. Search Room\n";
        cout << "3. Update Room info\n";
        cout << "4. Delete info\n";
        cout << "5. Show all list\n";
        cout << "0. Exit\n\n";
        cout << "Enter-> ";
        cin >> opt;
        switch (opt)
        {
        case 1:
            allocRoom();
            break;
        case 2:
            searchRoom();
            break;
        case 3:
            updateRoom();
            break;
        case 4:
            delRoom();
            break;
        case 5:
            showAll();
            break;
        case 0:
            exit(0);
            break;
        default:
            cout << "\nInvalid choice.\n";
            break;
        }
    } while (opt != 0);
}

void Hotel ::allocRoom()
{ // room allocation..........
top:
    system("cls");
    Node *new_node = new Node();
    cout << "---------Hotel Management System---------\n";
    cout << "-------------Room Allocation-------------\n\n";
    cout << "Enter Room ID.\n";
    cout << "->";
    cin >> new_node->id;
    Node *ptr = head;
    while (ptr != NULL)
    {
        if (ptr->id == new_node->id)
        {
            cout << "\nThis room is booked\n";
            Sleep(2000);
            goto top;
        }
        ptr = ptr->next;
    }
    cout << "\nEnter Name.\n";
    cout << "->";
    fflush(stdin);
    getline(cin, new_node->name);
    cout << "\nEnter Date.\n";
    cout << "->";
    fflush(stdin);
    getline(cin, new_node->date);
t:
    cout << "\nEnter room type (double, twin , single)\n";
    cout << "->";
    cin >> new_node->type;
    if (new_node->type == "double")
    {
        new_node->bill = "BDT 2000";
        cout << "\nBill for double room: " << new_node->bill;
        cout << "\n-----------------------------------------\n";
    }
    else if (new_node->type == "twin")
    {
        new_node->bill = "BDT 1850";
        cout << "\nBill for twin room: " << new_node->bill;
        cout << "\n-----------------------------------------\n";
    }
    else if (new_node->type == "single")
    {
        new_node->bill = "BDT 1400";
        cout << "\nBill for single room: " << new_node->bill;
        cout << "\n-----------------------------------------\n";
    }
    else
    {
        cout << "\nSpelling mistake in selecting type...\n";
        goto t;
    }

    if (head == NULL)
    {
        head = new_node;
    }
    else
    {
        Node *ptr = head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = new_node;
    }
    cout << "\n\nRoom allocation successfull...\n";
    mainmenu();
}

void Hotel::searchRoom()
{
    system("cls"); // search room...............
    cout << "---------Hotel Management System---------\n";
    cout << "---------Search Room Information---------\n\n";
    int r_id;
    cout << "Enter the room ID.\n";
    cout << "-> ";
    cin >> r_id;
    if (head == NULL)
    {
        cout << "There are no allocated room to show.";
        mainmenu();
    }
    else
    {
        Node *ptr = head;
        while (ptr != NULL)
        {
            if (ptr->id == r_id)
            {
                cout << "Room ID        : " << ptr->id << "\n\n";
                cout << "Name           : " << ptr->name << "\n\n";
                cout << "Allocation Date: " << ptr->date << "\n\n";
                cout << "Room type      : " << ptr->type << "\n\n";
                cout << "Total Bill     : " << ptr->bill << "\n\n";
                break;
            }
            else if (ptr->next == NULL)
            {
                cout << "\n No room information for given ID.\n\n";
            }
            ptr = ptr->next;
        }
    }

    mainmenu();
}

void Hotel::updateRoom()
{
    system("cls");
    cout << "---------Hotel Management System---------\n";
    cout << "---------Update Room Information---------\n\n";
    if (head == NULL)
    {
        cout << "\nThere are no allocated room\n";
        mainmenu();
    }
    else
    {
        int r_id;
        cout << "Enter Room ID.\n";
        cout << "-> ";
        cin >> r_id;
        Node *ptr = head;
        while (ptr != NULL)
        {
            if (r_id == ptr->id)
            {
                cout << "Update ID       : ";
                cin >> ptr->id;
                cout << "\n";
                cout << "Update Name     : ";
                fflush(stdin);
                getline(cin, ptr->name);
                cout << "\n";
                cout << "Update Date     : ";
                fflush(stdin);
                getline(cin, ptr->date);
                cout << "\n";
            t:
                cout << "Update room type: ";

                fflush(stdin);
                getline(cin, ptr->type);
                cout << "\n";
                if (ptr->type == "double")
                {
                    ptr->bill = "BDT 2000";
                    cout << "\nBill for double room: " << ptr->bill;
                    cout << "\n-----------------------------------------\n";
                }
                else if (ptr->type == "twin")
                {
                    ptr->bill = "BDT 1850";
                    cout << "\nBill for twin room: " << ptr->bill;
                    cout << "\n-----------------------------------------\n";
                }
                else if (ptr->type == "single")
                {
                    ptr->bill = "BDT 1400";
                    cout << "\nBill for single room: " << ptr->bill;
                    cout << "\n-----------------------------------------\n";
                }
                else
                {
                    cout << "\nSpelling mistake in selecting type...\n";
                    goto t;
                }
                break;
            }
            else if (ptr->next == NULL)
            {
                cout << "\n\nNo room inforamtion for given ID.\n\n";
            }

            ptr = ptr->next;
        }
    }
    mainmenu();
}

void Hotel::showAll()
{
    system("cls");
    cout << "---------Hotel Management System---------\n";
    cout << "---------Showing all infomations---------\n\n";
    if (head == NULL)
    {
        cout << "\n\nThere are no allocated room to show.\n\n";
        mainmenu();
    }

    else
    {
        Node *ptr = head;
        int count = 1;
        while (ptr != NULL)
        {

            cout << count << "."
                 << " Room ID\t\t: " << ptr->id << "\n\n";
            cout << "   Name   \t\t: " << ptr->name << "\n\n";
            cout << "   Allocation Date\t: " << ptr->date << "\n\n";
            cout << "   Room type      \t: " << ptr->type << "\n\n";
            cout << "   Total Bill           : "<< ptr->bill<<"\n\n";
            cout << "\n-------------------------------------\n";
            cout << "\n-------------------------------------\n";
            ptr = ptr->next;
            count++;
        }
    }
    mainmenu();
}

void Hotel::delRoom()
{
    system("cls");
    cout << "---------Hotel Management System---------\n";
    cout << "---------Delete Room Information---------\n\n";
    if (head == NULL)
    {
        cout << "\n\nThere are no information.\n\n";
        mainmenu();
    }
    else
    {
        int r_id;
        cout << "Enter the ID: ";
        cin >> r_id;
        Node *prev = head;
        Node *ptr = head;
        while (ptr != NULL)
        {
            if (r_id == ptr->id)
            {
                cout << "Room ID        : " << ptr->id << "\n\n";
                cout << "Name           : " << ptr->name << "\n\n";
                cout << "Allocation Date: " << ptr->date << "\n\n";
                cout << "Room type      : " << ptr->type << "\n\n";
                cout << "-------------------------------------------\n";
                if (r_id == head->id)
                {
                    Node *ptr1 = head;
                    head = head->next;
                    delete ptr1;
                    cout << "Above information deleted..\n";
                    mainmenu();
                }
                else
                {
                    prev->next = ptr->next;
                    delete ptr;
                    cout << "Above information deleted..\n";
                    mainmenu();
                }
            }
            else if (ptr->next == NULL)
            {
                cout << "\nIvalid ID.....\n";
                mainmenu();
            }
            prev = ptr;
            ptr = ptr->next;
        }
    }
}

int main()
{
    Hotel h1;
    h1.display();
}
