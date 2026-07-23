// COUNT NUMBER OF NODES

#include<iostream>
#include<vector>
using namespace std;

class Node{
public:
    int data;
    Node *next;
    Node(int x){
        this->data=x;
        this->next=NULL;
    }
};

int countNodes(Node *head){
    int count=0;
    while(head){
        count++;
        head=head->next;
    }
    return count;
}

int main(){
    int n;
    cout<<"Enter number of nodes:\n";
    cin>>n;
    
    Node *head=NULL;

    cout<<"Enter Elements:\n";

    for(int i=0;i<n;i++){
        int x;
        cin >> x;

        Node *newNode = new Node(x);

        if(head==NULL){
            head=newNode;
        }
        else{
            Node *temp=head;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=newNode;
        }
    }

    cout<<"Total Noumber of Nodes present int the Linked List is: "<<countNodes(head);
}