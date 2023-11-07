#include<bits/stdc++.h>
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
            next  = NULL;
        }

         node(int k, int d)

         {

             key = k ;
             data = d;

         }
};

class singlylinkedlist
{
        public:

            node* head;
            singlylinkedlist()
            {
                head  = NULL;

            }
            singlylinkedlist(node *n)
            {
                head = n;

            }

            node* nodeExists(int k)
            {
                node* temp = NULL;

                node* ptr = head;

                while(ptr!=NULL)
                {
                    if(ptr->key == k)
                    {
                        temp =  ptr;
                    }

                    ptr = ptr->next;
                }
                return temp;
            }

            void appendnode(node *n)
            {
                if(nodeExists(n->key)!=NULL)
                {
                    cout<<"Node already exists with key value : "<<n->key<<".Append another node with different key value"<<endl ;
                }

                else
                {
                    if(head == NULL)
                    {
                        head = n;
                        cout<<"Node appended"<<endl;
                    }

                    else
                    {
                      node* ptr = head;
                      while(ptr->next != NULL)
                      {
                          ptr = ptr->next;
                      }
                      ptr ->next = n;
                      cout<<"node appended"<<endl;
                    }
                }
            }

            void prependnode(node* n)
            {
                if(nodeExists(n->key)!=NULL)
                {
                    cout<<"Node already exists with key value : "<<n->key<<".Append another node with different key value"<<endl ;
                }

                else
                {
                    n->next = head ;
                    head = n;
                    cout<<"node prepended"<<endl;
                }
            }
            //insert a node after a particular node in the list
            void insertnodeafter(int k, node *n)
            {
                node* ptr = nodeExists(k);
                if(ptr == NULL)
                {
                    cout<<"No node exists with key value k"<<endl;
                }

                else
                {
                    if(nodeExists(n->key)!=NULL)
                {
                    cout<<"Node already exists with key value : "<<n->key<<".Append another node with different key value"<<endl ;
                }
                else
                {
                    n->next = ptr->next;
                    ptr->next = n;
                    cout<<"Node Inserted"<<endl;
                }

                }
            }
            //delete a node
            void deletenodebykey(int k)
            {
                if(head == NULL)
                {
                    cout<<"singly linked list already empty,Can't delete anything"<<endl;
                }

                else if(head != NULL)
                {
                 if(head ->key == k)
                 {
                     head = head->next;
                     cout<<"Node Unlinked with keys the value:"<<k<<endl;
                 }
                 else
                 {
                     node* temp = NULL;
                     node* prevptr = head;
                     node* currentptr = head->next;
                     while(currentptr!=NULL)
                     {
                         if(currentptr->key == NULL)
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
                     if(temp!=NULL)
                     {
                        prevptr->next = temp->next;
                        cout<<"Node Unlinked with keys value"<<k<<endl;
                     }
                     else
                     {
                         cout<<"Node doesn't exists with key value"<<
                         k<<endl;
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
                       cout<<"Node data updated successfully"<<endl;
                   }
                   else
                    {
                        cout<<"Node doesn`t exists with key value"<<endl;
                    }
            }

            void printlist()
            {
                if(head == NULL)
                {
                    cout<<"No node is singly linked list"<<endl;
                }
                else
                {
                    cout<<endl<<"singly linked list values :"<<endl;
                    node* temp = head;

                    while(temp!=NULL)
                        {
                            cout<<"("<<temp->key<<","<<temp->data<<")-->";
                            temp = temp ->next;
                        }
                }
            }

};
int main()
{
    singlylinkedlist s;
    int option;
    int key1, k1, data1;

    do
    {

        cout<<"\what option do you want to perform? select option number. Enter 0 to exit"<<endl;
        cout<<"1. AppendNode()"<<endl;
        cout<<"2. PrependNode()"<<endl;
        cout<<"3. InsertdNOdeAfter()"<<endl;
        cout<<"4. deletedNOdebykey()"<<endl;
        cout<<"5 UpdatedNOde()"<<endl;
        cout<<"6. print()"<<endl;
        cout<<"7. Clear Screen"<<endl<<endl;

        cin>>option;
        node* n1 = new node();

        switch (option)
        {
        case 0:
            break;
        case 1:
            cout<<"Append node operation \n Enter key and data of the node to be append"<<endl;
            cin>>key1;
            cin>>data1;
            n1->key = key1;
            n1->data = data1;
            s.appendnode(n1);
            break;
        case 2:
            cout<<"Prepend node operation \nEnter key and data of the node to perpend"<<endl;
            cin>>key1;
            cin>>data1;
            n1->key = key1;
            n1->data = data1;
            s.prependnode(n1);
            break;
        case 3:
            cout<<"Insert node after operation \nEnter key of existing node after which you want to insert this new node"<<endl;
            cin>>k1;
            cout<<"Enter key and data of the new node first"<<endl;
            cin>>key1;
            cin>>data1;
            n1->key = key1;
            n1->data = data1;
            s.insertnodeafter(k1, n1);
            break;
        case 4:
            cout<<"Delete node by key operation \nEnter key  of the node to Deleted "<<endl;
            cin>>k1;
            s.deletenodebykey(k1);
            break;
         case 5:
            cout<<"Update node by key operation \nEnter key and data of the node to updated "<<endl;
            cin>>key1;
            cin>>data1;
            s.updatenodebykey(key1, data1);
            break;
         case 6:
            s.printlist();
            break;
         case 7:
            system("cls");
            break;
         default:
            cout<<"Enter proper option number"<<endl;
        }



    }
    while(option!=0);


    return 0;
}
