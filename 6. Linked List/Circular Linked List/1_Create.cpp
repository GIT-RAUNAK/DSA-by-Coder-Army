#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    Node(int Val){
        data=Val;
        next=NULL;
    }
};

int main(){
    int n;
    cout<<"Enter number of nodes:\n";
    cin>>n;
    Node *head=NULL,*temp=NULL;
    for(int i=0;i<n;i++){
        int a;
        cout<<"Enter element in Node "<<i+1<<":\n";
        cin>>a;
        if(head==NULL){
            head=new Node(a);
            temp=head;
        }
        else{
            temp->next=new Node(a);
            temp=temp->next;
        }
    }
    temp->next=head;
    temp=head;
    do
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    } while (temp!=head);
    
}