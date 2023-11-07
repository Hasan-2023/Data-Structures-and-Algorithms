#include<iostream>
#include<string>
using namespace std;

class stack
{
    public:
        int top;
        int arr[5];

    public:

            stack()
            {
                top = -1;
                for(int i =0; i<5; i++)
                {
                    arr[i] = 0;
                }
            }
    bool isEmpty()
    {
        if(top == -1)
            return true;
        else
            return false;
    }
    bool isFull()
    {
        if (top == 4)
            return true;
        else
            return false;
    }
    void push(int val)
    {
        if(isFull())
        {
            cout<<"stack overflow"<<endl;
        }
        else
        {
            top++;
            arr[top] = val;
        }
    }
    int pop()
    {
        if(isEmpty())
        {
            cout<<"Stack is underflow:"<<endl;
            return 0;
        }
        else
        {
            int popvalue = arr[top];
            arr[top] = 0;
            top--;
            return popvalue;
        }
    }

    int count()
    {
        return (top+1);
    }
    int peek(int pos)
    {
        if(isEmpty())
        {
            cout<<"Stack is underflow:"<<endl;
            return 0;
        }
        else
        {
            return arr[pos];
        }
    }
    void change(int pos, int val)
    {
        arr[pos] = val;
        cout<<"value change at location "<<pos<<endl;
    }

    void display()
    {
        cout<<"All values in the stack are "<<endl;
        for(int i =4; i>=0; i--)
        {
            cout<<arr[i]<<endl;
        }
    }
};



int main()
{
    stack s1;
    int option, position, value;

    do
    {
        cout<<"What option do you want to perform"<<endl;
        cout<<"Select option number"<<endl;
        cout<<"Enter 0 to exit"<<endl;
        cout<<"1. push()"<<endl;
        cout<<"2. pop()"<<endl;
        cout<<"3. isEmpty()"<<endl;
        cout<<"4. isFull()"<<endl;
        cout<<"5. peek()"<<endl;
        cout<<"6. count()"<<endl;
        cout<<"7. change()"<<endl;
        cout<<"8. display()"<<endl;
        cout<<"9. clear screen()"<<endl;

        cin>>option;
        switch(option)
        {
        case 0:
            cout<<"Invalid"<<endl;
            break;
        case 1:
            cout<<"Enter an item push in stack"<<endl;
            cin>>value;
            s1.push(value);
            break;

        case 2:
            cout<<"Pop function called - poped value: "<<s1.pop()<<endl;
            break;
        case 3:
            if(s1.isEmpty())
                cout<<"Stack is empty"<<endl;
            else

                cout<<"Stack is not empty"<<endl;
            break;
        case 4:
            if(s1.isFull())
                cout<<"Stack is Full"<<endl;
            else

                cout<<"Stack is not Full"<<endl;
                break;
        case 5:
            cout<<"Enter position of item you want to peek: "<<endl;
            cin>>position;
            cout<<"Peek function called , Value at position "<<position<<s1.peek(position)<<endl;
            break;
        case 6:
            cout<<"count function called"<<"Number of the item in the stack are: "<<s1.count()<<endl;
            break;
        case 7 :
            cout<<"change the function called"<<endl;
            cout<<"Enter position value of item you want to change"<<endl;
            cin>>position;
            cout<<endl;
            cout<<"Enter value of item do you want to change"<<endl;
            cin>>value;
            s1.change(position, value);
            break;
        case 8:
            cout<<"Display Function called "<<endl;
            s1.display();
            break;
        case 9:
            system("cls");
            break;
        default:
            cout<<"Enter proper option number"<<endl;



        }

    }
    while(option!=0);

    return 0;
}
