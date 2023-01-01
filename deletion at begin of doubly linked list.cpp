#include<iostream>
using namespace std;

class node                  		     //USER DEFINED
{
    public:
    int data;
    node*next;
    node*prev;
    
    node(int value)         		     //TO SPECIFY DATA AND NEXT 
    {
        data=value;
        next=NULL;
        prev=NULL;
    }
};


void insertathead(node*&head,int val)   //NEED TO SPECIFY BECAUSE AT FIRST THE NODE IS ALWAYS POINTED TO NULL
{
    node*n=new node(val);
    n->next=head;
    if(head!=NULL)
    {
        head->prev=n; 
    }
   head=n;
}

void deletion_head(node*&head)
{
    node*todelete=head;
    head=head->next;
    head->prev=NULL;
    
    delete todelete;
}

void deletion_pos(node*&head,int pos)
{
    node*temp=head;
    
    if(pos==1)
    {
        deletion_head(head);
        return;
    }
    
    int count=1;
    
    while(temp!=NULL && count!=pos)
    {
        temp=temp->next;
        count++;
    }
    
    temp->prev->next=temp->next;
    
    if(temp->next!=NULL)
    {
       temp->next->prev=temp->prev; 
    }
}


void display(node*head)                 //TO DISPLAY THE NODE
{
    node*temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

int main()
{
    node*head=NULL;        
    cout<<"the data added at begin of doubly linked list:"<<endl;  
    
    insertathead(head,1);
    insertathead(head,2);
    insertathead(head,3);
    insertathead(head,4);
    insertathead(head,5);
    display(head);
    
    cout<<endl;
    cout<<"the data after deletion from position of doubly linked list:"<<endl;  
    deletion_pos(head,1);
    display(head);
    return 0;
}


OUTPUT:

the data added at begin of doubly linked list:
5->4->3->2->1->NULL

the data after deletion from position of doubly linked list:
4->3->2->1->NULL
