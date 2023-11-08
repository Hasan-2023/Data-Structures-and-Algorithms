#include<iostream>
using namespace std;

class node
{
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
    node (int k, int d)
    {
        key = k;
        data = d;
        next = NULL;
    }
};

    class queue
    {
    public:
        node *front;
        node *rear;

        queue()
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
                cout<<"node already exist with this key value"<<endl;
                cout<<"enter different key value"<<endl;
            }
            else
            {
                rear->next = n;
                rear = n;

                cout<<"node enqueued successfully"<<endl;
            }
        }
        node *dequeue()
        {
            node *temp = NULL;
            if(isEmpty())
            {
                cout<<"Stack is underflow"<<endl;
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
                    temp = front ;
                    front = front->next;
                    return temp;
                }
                }
            }
            int count()
            {
                int count = 0;
                node *temp = front;

                while(temp!=NULL)
                {
                    count++;
                    temp = temp->next;
                }
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
                cout<<"All values in Queue are : "<<endl;
                node *temp = front;
                while(temp!=NULL)
                {
                    cout<<"("<<temp->key<<","<<temp->data<<")"<<"->";
                    temp = temp->next;

                }
                cout<<endl;
            }
        }


    };

int main()
{
    queue q;
    int option, key, data;

    do{
        cout<<"What operation do you want to perform?"<<endl;
        cout<<"Select the option. Enter 0 to exit"<<endl;
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
            cout<<"Enter key and value of node to enqueue in the enqueue"<<endl;
            cin>>key;
            cin>>data;
            new_node->key = key;
            new_node->data = data;
            q.enqueue(new_node);
            break;
        case 2:
            cout<<"Dequeue function called"<<endl;
            new_node = q.dequeue();
            cout<<"Dequeued value is: ("<<new_node->key<<","<<new_node->data<<")"<<endl;
            delete new_node;
            cout<<endl;
            break;
        case 3:
            cout<<"isEmpty function called - "<<endl;
            if(q.isEmpty())
            {
                cout<<"Queue is empty"<<endl;

            }
            else
            {
                cout<<"Queue is not empty"<<endl;
            }
            break;
        case 4:
            cout<<"Count function called"<<endl;
            cout<<"No of nodes in the queue is:"<<q.count()<<endl;
            break;
        case 5:
            cout<<"Display function called"<<endl;
            q.display();
            cout<<endl;
            break;
        case 6:
            system("cls");
            break;
        default:
            cout<<"Enter proper option number"<<endl;
            break;


        }
    } while(option!=0);

    return 0;
}
