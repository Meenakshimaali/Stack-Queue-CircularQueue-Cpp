#include<iostream>
#include<conio.h>
using namespace std;

class Queue
{
public:
    int QUEUE[10];
};

class QueueOperation : public Queue
{
public:
    int Front, Rear, MaxSize;

    QueueOperation()
    {
        Front = Rear = -1;

        cout << "Enter Size of Queue (1-10) -- ";
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

        int DATA;

        // Overflow Condition
        if(Rear == MaxSize - 1)
        {
            cout << "Queue Overflow...\n\n";
            return;
        }

        cout << "Enter Data -- ";
        cin >> DATA;

        // First Element
        if(Front == -1)
        {
            Front = Rear = 0;
        }
        else
        {
            Rear++;
        }

        QUEUE[Rear] = DATA;

        cout << "\nData Inserted Successfully...\n\n";
    }

    void Pop()
    {
        system("cls");

        cout << "Pop Operation Module\n\n";

        // Underflow Condition
        if(Front == -1)
        {
            cout << "Queue Underflow...\n\n";
            return;
        }

        cout << "Deleted Element -- " << QUEUE[Front] << endl;

        // Only One Element
        if(Front == Rear)
        {
            Front = Rear = -1;
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

        cout << "Display Queue Module\n\n";

        if(Front == -1)
        {
            cout << "Queue is Empty...\n\n";
            return;
        }

        cout << "Queue Elements are -- \n\n";

        for(int i = Front; i <= Rear; i++)
        {
            cout << QUEUE[i] << " -> ";
        }

        cout << "NULL\n\n";
    }

    void MainMenu()
    {
        while(true)
        {
            system("cls");

            cout << "\tQUEUE OPERATIONS\n\n";

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
    QueueOperation Q;
    Q.MainMenu();

    return 0;
}
