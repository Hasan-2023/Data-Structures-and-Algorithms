#include<iostream>
using namespace std;

class node{
        public:
            int key;
            int data;
            node* next;
            node* previous;

            node()
            {


                key = 0;
                data = 0;
                next = NULL;
                previous = NULL;

            }

            node(int k, int d)
            {

                key = k;
                data = d;

            }
            } ;

            class doublylinkedlist{
            public:
                node* head;

                doublylinkedlist()
                {
                    head = NULL;

                }

                doublylinkedlist(node *n)
                {
                    head = n;
                }

                //1. check if node value using key value
                node* nodeExists(int k)
                {
                    node* temp = NULL;
                    node* ptr = head;

                    while(ptr!=NULL)
                    {
                        if(ptr->key == k)
                        {
                            temp = ptr ;
                        }
                        ptr = ptr->next;
                    }

                    return temp;
                }

                //2. Append to the list
                void appendnode(node* n)
                {
                    if(nodeExists(n->key)!=NULL)
                    {
                        cout<<"node already exists"<<n->key<<endl;
                        cout<<"Append node with different key value"<<endl;

                    }


                    else
                    {
                        if(head == NULL)
                        {
                            head = n;
                            cout<<"node append as Head node"<<endl;

                        }

                        else
                        {
                            node* ptr = head;
                            while(ptr->next!=NULL)
                                  {
                                      ptr = ptr->next;
                                  }
                                  ptr->next = n;
                                  n->previous = ptr;
                                  cout<<"node appended"<<endl;
                        }
                    }
                }
                //3.Prepend node
                void prependnode(node* n)

                {
                    if(nodeExists(n->key)!=NULL)
                    {
                         cout<<"node already exists"<<n->key<<endl;
                        cout<<"Append node with different key value"<<endl;
                    }

                    else
                    {
                        if(head == NULL)


                           {
                               head = n;
                               cout<<"node prepended as Head node"<<endl;\

                           }

                           else
                            {
                                head->previous = n;
                                n->next = head ;
                                head = n;
                                cout<<"node prepended"<<endl;
                            }
                    }
                }
                //4.Insert a node after a particular node in the list

                void insertnodeafter(int k, node *n)
                {

                    node* ptr = nodeExists(k);
                    if(ptr==NULL)
                    {
                        cout<<"No node exists with key value"<<k<<endl;
                    }
                    else

                    {
                       if(nodeExists(n->key)!=NULL)
                        {
                        cout<<"Node already exists with key value"<<n->key<<"Append another node with different key value"<<endl;

                        }
                        else
                        {
                            cout<<"Inserting"<<endl;
                            node *nextnode  = ptr->next;
                            //appending at the end
                            if(nextnode == NULL)
                            {
                                ptr->next = n;
                                n->previous = ptr;
                                cout<<"node inserted at the end "<<endl;
                            }

                            else
                            {
                                n->next = nextnode;
                                nextnode->previous = n;
                                n->previous = ptr;
                                ptr->next = n;

                                cout<<"Node inserted in the between"<<endl;
                            }
                        }
                    }
                }

                void deletenodebykey(int k)
                {
                    node* ptr = nodeExists(k);
                    if(ptr == NULL)
                    {
                        cout<<"No node exists with key value"<<endl;
                    }
                    else
                    {
                        if(head == NULL)
                        {
                            cout<<"Doubly linked list already empty. can't delete"<<endl;
                        }
                        else if(head != NULL)
                                {
                                    if(head->key=k)
                                    {
                                        head = head->next;
                                        cout<<"Node unlinked with key value:"<<k<<endl;
                                    }
                                    else
                                    {
                                        node *nextnode = ptr->next;
                                        node *prevnode = ptr->previous;
                                        if(nextnode == NULL)
                                        {
                                            prevnode->next = NULL;
                                            cout<<"node deleted at the end"<<endl;
                                        }
                                        else
                                        {
                                            prevnode->next = nextnode;
                                            nextnode->previous = prevnode;
                                            cout<<"node deleted at the between"<<endl;

                                        }

                                    }
                                }
                    }
                }

 void updatenodebykey(int k, int d)
 {
     node* ptr = nodeExists(k);
     if(ptr!=NULL)
        {
            ptr->data = d;
            cout<<"Node data updated succesfully"<<endl;
        }
        else
            {
                cout<<"node doesn't exists with key value"<<k<<endl;
            }
 }

 void printlist()
 {

     if(head == NULL)
     {
         cout<<"no nods in doubly linked list"<<endl;
     }
     else
     {
         cout<<endl<<"Doubly linked list";
         node* temp = head;

         while(temp!=0)
         {
             cout<<"("<<temp->key<<","<<temp->data<<")<-->";
             temp = temp->next;
         }
     }
 }

                };
int main()
{
    doublylinkedlist obj;
    int option;
    int key1, k1, data1;

    do
    {
     cout<<"\n What option do you want to perform"<<endl ;
     cout<<"select the option number and Enter 0 to exit"<<endl;
     cout<<"1. AppendNode()"<<endl;
     cout<<"2. PrependNode()"<<endl;
     cout<<"3. InsertdNOdeAfter()"<<endl;
     cout<<"4. deletedNOdebykey()"<<endl;
     cout<<"5 UpdatedNOde()"<<endl;
     cout<<"6. print()"<<endl;
     cout<<"7. Clear Screen"<<endl<<endl;

     cin>>option;
     node* n1 = new node();

     switch(option)
     {
     case 0:
        break;
     case 1:
        cout<<"append node operation"<<endl;
        cout<<"Enter key of existing node after which you want to insert this new node"<<endl;
        cin>>k1;
        cout<<"Enter key and data of the new node first"<<endl;
        cin>>key1;
        cin>>data1;
        n1->key = key1;
        n1->data = data1;
        obj.appendnode(n1);
        break;

     case 2:
        cout<<"prepend node operation afetr operation"<<endl;
        cout<<"Enter key and data of the new node to be prepend"<<endl;
        cin>>key1;
        cin>>data1;
        n1->key = key1;
        n1->data = data1;
        obj.prependnode(n1);
        break;

     case 3:
        cout<<"Insert new node after operation"<<endl;
        cout<<"Enter key of of existing node after which you want to insert this new node"<<endl;
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
        cout<<"updated node by key operation"<<endl ;
        cout<<"Enter key and new data to be updated"<<endl ;
        cin>>key1;
        cin>>data1;
        obj.updatenodebykey(k1, data1);
        break;
     case 6:
        obj.printlist();
        break;
     case 7:
        system("cls");
        break;
     default:
        cout<<"Enter proper option number"<<endl ;





     }

    }while(option!=0);





    return 0 ;
}
