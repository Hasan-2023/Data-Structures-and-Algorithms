#include<iostream>
using namespace std;

class node
{
public:
    int key;
    int data;
    node* next;

    node()
    {
        key = 0;
        data = 0;
        next = NULL;
    }
    node(int k , int d)
    {
        key = k;
        data = d;
        next = NULL;
    }
};
    class Stack
    {
    public:
        node *top;

        Stack()
        {
            top = NULL;
        }

        bool isEmpty()
        {
            if(top == NULL)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        bool checkifnodeexist(node *n)
        {
            node *temp = top;
            bool exist = false;
            while(temp!=NULL)
            {
                if(temp->key == n->key)
                {
                    exist = true;
                    break;
                }
                temp = temp->next;

            }
            return exist;

        }

        void push(node * n)
        {
            if(top == NULL)
            {
                top = n;
                cout<<"node pushed successfully"<<endl;
            }
            else if(checkifnodeexist(n))
            {
              cout<<"node already exist with this key value"<<endl;
              cout<<"Enter different key value"<<endl;
            }
            else
            {
                node *temp = top;
                top = n;
                n->next = temp;
                cout<<"Node pushed successfully"<<endl;
            }
        }
        node* pop()
        {
            node *temp = NULL;
            if(isEmpty())
            {
                cout<<"Stack is underflow"<<endl;
                return temp;
            }
            else
            {
                temp = top;
                top = top->next;
                return temp;
            }
        }
        node* peek()
        {
            if(isEmpty())
            {
                cout<<"stack is empty"<<endl;
                return NULL;
            }
            else
            {
                return top;
            }

        }
        int count()
        {
            int count = 0;
            node *temp = top;
            while(temp!=NULL)
            {
              count++;
              temp = temp->next;
            }
            return count;
        }
        void display()
        {
            cout<<"All the vales in the stack are: "<<endl;
            node *temp = top;
            while(temp!=NULL)
            {
             cout<<"("<<temp->key<<","<<temp->data<<")"<<"->"<<endl;
             temp = temp->next;
            }
            cout<<"total no of nodes in the stack: "<<count()<<endl;
            cout<<endl;
        }

    };




int main()
{
    Stack s1;
    int option,  key, data;

    do {
         cout<<"What operation do you want to perform"<<endl;
         cout<<"Select option number and enter 0 to exit"<<endl;
         cout<<"1. push()"<<endl;
         cout<<"2. pop()"<<endl;
         cout<<"3. isEmpty()"<<endl;
         cout<<"4. peek()"<<endl;
         cout<<"5. count()"<<endl;
         cout<<"6. display()"<<endl;
         cout<<"7. Clear screen "<<endl;
         cin>>option;

         node *new_node = new node();

         switch(option)
         {
         case 0:
            break;
         case 1:
            cout<<"Enter key and value of NDOE push in the stack"<<endl;
            cin>>key;
            cin>>data;
            new_node->key = key;
            new_node-> data =  data;
            s1.push(new_node);
            break;
         case 2:
            cout<<"Pop function called - Poped value: "<<endl;
            new_node = s1.pop();
            cout<<"Top of stack is : ("<<new_node->key<<","<<new_node->data<<")" ;
            delete new_node;
            cout<<endl;
            break;

         case 3:
            if(s1.isEmpty())
                cout<<"stack is empty"<<endl;
            else
                cout<<"stack is not empty"<<endl;
            break;
         case 4:
            if(s1.isEmpty())
            {
                cout<<"stack is empty"<<endl;
            }
            else
            {
                cout<<"Peek function called: "<<endl;
                new_node = s1.peek();
                cout<<"Top of stack is :("<<new_node->key<<","<<new_node->data<<")"<<endl;

            }
            break;
         case 5:
            cout<<"Count function called"<<endl;
            cout<<"no of nodes in the stack is "<<s1.count()<<endl;
            break;


         case 6:
            cout<<"Display function called"<<endl;
            s1.display();
            cout<<endl;
            break;
         case 7:
            system("cls");
            break;
         default:
            cout<<"Enter proper number"<<endl;
         }
    }  while(option!=0);


    return 0;
}
