#include<iostream>
using namespace std;

class node {
public:
    int key;
    int data;
    node * next;

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
    class circularqueue{

 public:
    node *front;
    node *rear;

    cicularqueue()
    {
        front = NULL;
        rear = NULL;

    }
    bool isEmpty()
    {
        if(front == NULL && rear == NULL)
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
        node *temp = front;
        bool exist = false;
        do
        {
            if(temp->key == n->key)
            {
                exist = true;
                break;
            }
            temp = temp->next;
        } while(temp!=front);
        return exist;
    }

    void enqueue(node *n)
    {
        if(isEmpty())
        {
            front = n;
            rear = n;
            cout<<"Node enqueued successfully"<<endl;
        }
        else if(checkifnodeexist(n))
        {
            cout<<"Node already exist with this key value"<<endl;
            cout<<"Enter different key value"<<endl;
        }
        else
        {
            rear->next = n;
            rear = n;
            n->next = front;
            cout<<"node enqueued successfully"<<endl;
        }
    }
    node* dequeue()
    {
        node *temp = NULL;
        if(isEmpty())
        {
            cout<<"Queue is empty"<<endl;
            return NULL;
        }
        else
        {
            if(front == rear)
            {
                temp = front;
                front = NULL;
                rear = NULL;
                return temp;
            }
            else
            {
                temp = front;
                front = front->next;
                rear->next = front;
                return temp;
            }
        }
    }
    int count()
    {
        int count = 0;
        node *temp = front;
        do
        {
            count++;
            temp = temp->next;
        } while(temp!=front) ;

        return count;
    }
    void display()
    {
        if(isEmpty())
        {
            cout<<"Queue is empty"<<endl;
        }
        else
        {
            cout<<"All values in the queue are: "<<endl;
            node *temp = front;
            do

            {
                cout<<"("<<temp->key<<","<<temp->data<<")"<<"->";
                temp = temp->next;
            } while(temp!=NULL);
            cout<<"("<<temp->key<<","<<temp->data<<")";
            cout<<endl;
        }
    }

     };


int main()
{
    circularqueue q;
    int option, key, data;

    do
    {
        cout<<"What operation do you want to perform?"<<endl;
        cout<<"Select option number and Enter 0 to Exit"<<endl;
        cout<<"1. enqueue()"<<endl;
        cout<<"2. dequeue()"<<endl;
        cout<<"3. isEmpty()"<<endl;
        cout<<"4. count()"<<endl;
        cout<<"5. display()"<<endl;
        cout<<"6. Clear screen"<<endl;
        cin>>option;

        node * new_node = new node();

        switch(option)
        {
        case 0:
            break;
        case 1:
            cout<<"Enqueue function called"<<endl;
            cout<<"Enter key and value of node to enqueue in the queue"<<endl;
            cin>>key;
            cin>>data;
            new_node->key = key;
            new_node->data = data;
            q.enqueue(new_node);
            break;
        case 2:
            cout<<"Dequeue Function called"<<endl;
            new_node = q.dequeue();
            cout<<"Dequeue value is: ("<<new_node->key<<","<<new_node->data<<")";
            delete new_node;
            cout<<endl;
            break;
        case 3:
            cout<<"isEmpty Function called"<<endl;
            if(q.isEmpty())
            {
                cout<<"queue is empty"<<endl;
            }
            else
            {
                cout<<"Queue is not empty"<<endl;
            }
            break;
            case 4:
            cout<<"Count function called"<<endl;
            cout<<"No of nodes in the queue "<<q.count();
            cout<<endl;
            break;
        case 5:
            cout<<"Display function is called "<<endl;
            q.display();
            cout<<endl;
            break;
        case 6:
            system("cls");
            break;
        default:
            cout<<"Enter proper option number"<<endl;
        }


    }while(option!=0);


    return 0;
}
