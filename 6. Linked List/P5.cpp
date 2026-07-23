// IDENTICAL LINKED LIST

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

bool areIdentical(Node* head1, Node* head2) {

    while (head1 != NULL && head2 != NULL) {

        if (head1->data != head2->data)
            return false;

        head1 = head1->next;
        head2 = head2->next;
    }

    return (head1 == NULL && head2 == NULL);
}

int main() {
    int n1, n2;

    cout << "Enter number of nodes in first linked list: ";
    cin >> n1;

    Node* head1 = NULL;
    Node* tail1 = NULL;

    cout << "Enter elements of first linked list:\n";

    for (int i = 0; i < n1; i++) {
        int x;
        cin >> x;

        Node* newNode = new Node(x);

        if (head1 == NULL) {
            head1 = tail1 = newNode;
        } else {
            tail1->next = newNode;
            tail1 = newNode;
        }
    }

    cout << "\nEnter number of nodes in second linked list: ";
    cin >> n2;

    Node* head2 = NULL;
    Node* tail2 = NULL;

    cout << "Enter elements of second linked list:\n";

    for (int i = 0; i < n2; i++) {
        int x;
        cin >> x;

        Node* newNode = new Node(x);

        if (head2 == NULL) {
            head2 = tail2 = newNode;
        } else {
            tail2->next = newNode;
            tail2 = newNode;
        }
    }

    if (areIdentical(head1, head2))
        cout << "\nBoth Linked Lists are Identical.";
    else
        cout << "\nBoth Linked Lists are Not Identical.";

    return 0;
}