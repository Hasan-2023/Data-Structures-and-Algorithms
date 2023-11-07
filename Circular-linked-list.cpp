#include<iostream>
using namespace std;

class node{
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

        node(int k, int d)
        {
            key = k;
            data = d;

        }
        };

        class circularlinkedlist
        {
        public:
            node* head;

            circularlinkedlist()
            {
                head = NULL;
            }

            //1.check if node exists using key value
            node* nodeExists(int k)
            {
                node* temp = NULL;
                node* ptr = head;

                if(ptr == NULL)
                {
                    return temp;
                }

                else
                {
                    do
                    {
                        if(ptr->key == k)
                        {
                            temp = ptr;

                        }
                        ptr = ptr->next;

                    } while(ptr!=head);

                    return temp;
                }
            }
            //2.append a node to the list
            void appendnode(node *new_node)
            {
                if(nodeExists(new_node->key)!=NULL)
                {
                    cout<<"node already exists with key value"<<new_node->key<<"append another node with different key value"<<endl;
                }
                else
                {
                    if(head == NULL)
                    {
                        head = new_node;
                        new_node ->next = head;
                        cout<<"node append at first head position"<<endl;
                    }
                    else
                    {
                        node* ptr = head;
                        while(ptr->next!=head)
                        {
                            ptr = ptr->next;
                        }
                        ptr->next = new_node;
                        new_node -> next = head;
                        cout<<"Node appended"<<endl;
                    }
                }
            }
            //3.prepend node
            void prependnode(node* new_node)
            {
                if(nodeExists(new_node->key)!=NULL)

        {


                    cout<<"node already exists"<<new_node->key<<"append another node with different key value"<<endl;
        }
            else
            {
                if(head == NULL)
                   {
                       head = new_node;
                       new_node->next = head;
                       cout<<"Node prepended at first position"<<endl;
                   }
            else
            {
                node* ptr = head;
                while(ptr->next!=head)
                {
                    ptr = ptr->next;
                }
                ptr->next = new_node;
                new_node->next = head;
                head = new_node;

                cout<<"node prepended"<<endl;
            }
            }
            }
            //4.Insert a node after a particular node
            void insertnodeafter(int k, node *new_node)
            {
                node* ptr = nodeExists(k);
                if(ptr == NULL)

                {
                    cout<<"no node exists with key value of"<<k<<endl;
                }
                else
                {
                    if(nodeExists(new_node->key)!=NULL)
                    {
                    cout<<"node already exists"<<new_node->key<<"append another node with different key value"<<endl;
                    }
                    else
                    {
                        if(ptr->next  == head)
                        {
                            new_node->next = head;
                            ptr->next = new_node;
                            cout<<"node inserted at the end"<<endl;
                        }
                        else
                        {
                            new_node -> next = ptr->next;
                            ptr->next = new_node;
                            cout<<"node inserted in between"<<endl;
                        }
                    }

                }
            }
            //5. Deleted node by unique key
            void deletenodebykey(int k)
            {
                node* ptr = nodeExists(k);
                if(ptr == NULL)
                {
                    cout<<"No node exists with key value"<<endl ;
                }
                else
                {
                    if(head == NULL)
                    {
                        cout<<"circular linked list already empty"<<endl;
                    }
                    else if(ptr == head)
                    {
                        if(head->next == NULL)
                        {
                            head = NULL;
                            cout<<"Head node unlinked... list empty"<<endl;
                        }
                        else
                        {
                            node* ptr1 = head ;
                            while(ptr->next!=head)
                            {
                                ptr1 = ptr1->next;
                            }
                            ptr1->next = head->next;
                            head = head->next;
                            cout<<"Node unlinked with key values"<<k<<endl;
                        }
                    }
                    else
                    {
                        node* temp = NULL;
                        node* prevptr = head;
                        node* currentptr = head->next;
                        while(currentptr!=NULL)
                        {
                            if(currentptr->key = k)
                            {
                                temp = currentptr;
                                currentptr = NULL;
                            }
                            else
                            {
                                prevptr = prevptr->next;
                                currentptr = currentptr->next;

                            }
                        }
                        prevptr->next = temp->next;
                        cout<<"node unlinked with key values"<<k<<endl;
                    }

                }
            }
            //6. Update node
            void updatenodebykey(int k, int new_data)
            {
                node* ptr = nodeExists(k);
                if(ptr!=NULL)
                   {
                        ptr->data = new_data;
                        cout<<"Node updated successfully"<<endl;

                   }
                   else
                   {
                       cout<<"Node doesn't exists with the key value"<<endl;
                   }
            }
            //7. printing

            void printlist()
            {
                if(head == NULL)
                {
                    cout<<"no nodes in circular linked list"<<endl;
                }
                else
                {
                    cout<<endl<<"head address : "<<head<<endl;
                    cout<<"Circular linked list values"<<endl;
                    node* temp = head;

                    do{
                        cout<<"("<<temp->key<<","<<temp->data<<","<<temp->next<<")-->";
                        temp = temp->next;

                    }while(temp!=head);
                }
            }
        };

int main()
{
    circularlinkedlist obj;
    int option;
    int key1, k1, data1;
    do{
        cout<<"\nwhat operation do you want to perform"<<endl;
        cout<<"select option number. Enter 0 to exit"<<endl;
        cout<<"1.appendnode()"<<endl;
        cout<<"2.prependnode()"<<endl;
        cout<<"3.Insertnode()"<<endl;
        cout<<"4.deletenode()"<<endl;
        cout<<"5.Updatenode()"<<endl;
        cout<<"6.print()"<<endl;
        cout<<"7.clear screen"<<endl;

        cin>>option;
        node* n1 = new node();

        switch(option)
        {
        case 0:
            break;

        case 1:
            cout<<"Append node operation"<<endl;
            cout<<"Enter key and data of  the node to be append"<<endl;
            cin>>key1;
            cin>>data1;
            n1->key = key1;
            n1->data = data1;
            obj.appendnode(n1);
            break;

        case 2:
            cout<<"prepend node operation"<<endl;
            cout<<"Enter key and data of the node to be prepend"<<endl;
            cin>>key1;
            cin>>data1;
            n1->key = key1;
            n1->data = data1;
            obj.prependnode(n1);
            break;

        case 3:
            cout<<"Insert node after operation"<<endl;
            cout<<"Enter key of existing node after which you want to insert this new node"<<endl;
            cin>>k1;
            cout<<"Enter key and data of the new node first"<<endl;
            cin>>key1;
            cin>>data1;
            n1->key = key1;
            n1->data = data1;
            obj.insertnodeafter(k1, n1);
            break;

        case 4:
            cout<<"Delete node by key operation"<<endl;
            cout<<"Enter key of the node to be deleted"<<endl;
            cin>>k1;
            obj.deletenodebykey(k1);
            break;

        case 5:
            cout<<"Update node by key operation"<<endl;
            cout<<"Enter key and new data to be updated"<<endl;
            cin>>key1;
            cin>>data1;
            obj.updatenodebykey(key1, data1);
            break ;

        case 6:
            obj.printlist();
            break;
        case 7:
            system("cls");
            break;
        default:
            cout<<"Enter proper option number"<<endl;



        }
    }while(option!=0);

    return 0;
}
