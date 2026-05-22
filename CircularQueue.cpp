#include<iostream>
#include<conio.h>
#include<stdlib.h>

using namespace std;

class CQueue
{
public:
    int CQUEUE[10];
};

class CQueueOperation : public CQueue
{
public:
    int Front, Rear, MaxSize;

    CQueueOperation()
    {
        Front = Rear = -1;

        cout << "Enter Size of Circular Queue (1-10) -- ";
        cin >> MaxSize;

        if(MaxSize > 10 || MaxSize <= 0)
        {
            cout << "Invalid Queue Size...";
            exit(0);
        }
    }

    void Push()
    {
        system("cls");

        cout << "Push Operation Module\n\n";

        // Overflow Condition
        if((Front == 0 && Rear == MaxSize - 1) || (Rear + 1 == Front))
        {
            cout << "Circular Queue Overflow...\n\n";
            return;
        }

        int DATA;

        cout << "Enter Data -- ";
        cin >> DATA;

        // First Element
        if(Front == -1)
        {
            Front = Rear = 0;
        }

        // Circular Condition
        else if(Rear == MaxSize - 1)
        {
            Rear = 0;
        }

        else
        {
            Rear++;
        }

        CQUEUE[Rear] = DATA;

        cout << "\nData Inserted Successfully...\n\n";
    }

    void Pop()
    {
        system("cls");

        cout << "Pop Operation Module\n\n";

        // Underflow Condition
        if(Front == -1)
        {
            cout << "Circular Queue Underflow...\n\n";
            return;
        }

        cout << "Deleted Element -- " << CQUEUE[Front] << endl;

        CQUEUE[Front] = 0;

        // Only One Element
        if(Front == Rear)
        {
            Front = Rear = -1;
        }

        // Circular Movement
        else if(Front == MaxSize - 1)
        {
            Front = 0;
        }

        else
        {
            Front++;
        }

        cout << "\nData Deleted Successfully...\n\n";
    }

    void Peek()
    {
        system("cls");

        cout << "Display Circular Queue Module\n\n";

        if(Front == -1)
        {
            cout << "Circular Queue is Empty...\n\n";
            return;
        }

        cout << "Queue Elements are -- \n\n";

        int POS = Front;

        while(true)
        {
            cout << CQUEUE[POS] << " -> ";

            if(POS == Rear)
            {
                break;
            }

            POS = (POS + 1) % MaxSize;
        }

        cout << "NULL\n\n";
    }

    void MainMenu()
    {
        while(true)
        {
            system("cls");

            cout << "\tCIRCULAR QUEUE OPERATIONS\n\n";

            cout << "1. Push\n";
            cout << "2. Pop\n";
            cout << "3. Display Queue\n";
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
    CQueueOperation C;

    C.MainMenu();

    return 0;
}
