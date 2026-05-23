#include<iostream>
#include<conio.h>
using namespace std;
class Ass19
{
public:
    int Fact(int n)
    {
        if(n == 1)
            return 1;
        else
            return n * Fact(n-1);

    }
    int Fibo(int n)
    {
        if(n == 0)
            return 0;
        else if(n == 1){
            return 1;
        }
        else
            return Fibo(n-1)+Fibo(n-2);
    }
    void towerofhanoi(int n , char source ,  char auxiliary , char destination)
    {
        if(n == 1){
            cout<<"Move disk 1 from "<<source<<" to "<<destination<<endl;
            return;
        }
        towerofhanoi(n-1,source , destination,auxiliary);
        cout<<"Move disk "<<n<<" from "<<source<<" to "<<destination<<endl;
        towerofhanoi(n-1,source,auxiliary,destination);
    }
    void MainMenu()
    {
        system("cls");
        cout<<"Choose Any One Of The Following:\n";
        cout<<"1.Find Factorial\n";
        cout<<"2.Print Fibonacci\n";
        cout<<"3.Tower of Hanoi\n";
        cout<<"4.Exit\n\n";
        char c = getch();
        if (c == '1'){
            cout<<"Find Factorial Module ";
            int n;
            cout<<"Enter a Number : ";
            cin>>n;
            cout<<"Factorial of "<<n<<" is ";
            cout<<Fact(n);
        }
        else if ( c == '2'){
            cout<<"Find Fibonacci Module ";
            int limit;
            cout<<"Enter a Limit : ";
            cin>>limit;
            cout<<"Fibonacci Series -- \n";
            for(int i = 0 ; i < limit ; i++ ){
                cout<<Fibo(i)<<"  ";
            }
        }
        else if (c == '3'){
            cout<<"Tower of Hanoi Module..\n";
            cout<<"Enter limit(3-6) -- ";
            int n ;
            cin>>n;
            towerofhanoi(n,'A','B','C');
        }
        else if (c == '4'){
            exit(0);
        }
        cout<<"\n\nDo you want to continue press 1 else any key ";
        c = getch();
        if(c == '1')
            MainMenu();
    }
};
int main()
{
    Ass19 R;
    R.MainMenu();
}
