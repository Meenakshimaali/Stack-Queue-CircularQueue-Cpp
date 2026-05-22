#include<iostream>
#include<conio.h>
using namespace std;

class Stack
{
public:
    int STACK[10];
};

class StackOperation : public Stack
{
public:
    int TOP, MaxSize;

    StackOperation()
    {
        TOP = -1;

        cout << "Enter Size of Stack (1-10) -- ";
        cin >> MaxSize;

        if(MaxSize > 10 || MaxSize <= 0)
        {
            cout << "Invalid Stack Size...";
            exit(0);
        }
    }

    void Push()
    {
        system("cls");

        cout << "Push In Stack Module\n\n";

        // Overflow Condition
        if(TOP == MaxSize - 1)
        {
            cout << "Stack Overflow...\n\n";
            return;
        }

        int DATA;

        cout << "Enter Data -- ";
        cin >> DATA;

        TOP++;

        STACK[TOP] = DATA;

        cout << "\nData Pushed Successfully...\n\n";
    }

    void Pop()
    {
        system("cls");

        cout << "Pop From Stack Module\n\n";

        // Underflow Condition
        if(TOP == -1)
        {
            cout << "Stack Underflow...\n\n";
            return;
        }

        cout << "Deleted Element -- " << STACK[TOP] << endl;

        STACK[TOP] = 0;

        TOP--;

        cout << "\nData Deleted Successfully...\n\n";
    }

    void Peek()
    {
        system("cls");

        cout << "Display Stack Module\n\n";

        if(TOP == -1)
        {
            cout << "Stack is Empty...\n\n";
            return;
        }

        cout << "Stack Elements are -- \n\n";

        for(int i = TOP; i >= 0; i--)
        {
            cout << STACK[i] << " -> ";
        }

        cout << "NULL\n\n";
    }

    void MainMenu()
    {
        while(true)
        {
            system("cls");

            cout << "\tSTACK OPERATIONS\n\n";

            cout << "1. Push\n";
            cout << "2. Pop\n";
            cout << "3. Display Stack\n";
            cout << "4. Exit\n\n";

            cout << "Choose Any Option -- ";

            char c = getch();

            switch(c)
            {
                case '1':
                    Push();
                    break;

                case '2':
                    Pop();
                    break;

                case '3':
                    Peek();
                    break;

                case '4':
                    exit(0);

                default:
                    cout << "\nInvalid Choice...\n";
            }

            cout << "\nPress Any Key To Continue...";
            getch();
        }
    }
};

int main()
{
    StackOperation S;

    S.MainMenu();

    return 0;
}
