#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct node{
    int data;
    node* prev;
    node* next;

};

class LinkedList{
    private:
    node* head;
    node* pre;
    
    public:
    LinkedList(int a){
        node* r;
        r = new node;
        r->data = a;
        r->prev = NULL;
        r->next = r;
        head = r; 
        pre = r;

    }
    void addNode(int a){
        node* r;
        r = new node;
        r->data = a;
        r->prev = pre;
        r->next = NULL;
        pre->next = r;
        pre = r;
    }
    void endNode(){
        pre->next = head;
        head->prev = pre;
    }
    void printLinkedList(){
        node* temp;
        temp = head;
        cout << "Current Node: " << temp->data << "    Previous Node: " << temp->prev->data << "    Next Node: " << temp->next->data << endl;
        temp = temp->next;
        while(temp!=head){
            cout << "Current Node: " << temp->data << "    Previous Node: " << temp->prev->data << "    Next Node: " << temp->next->data << endl;
            temp = temp->next;
        }
    }

    void insertNode(int a){
        node* r;
        r = new node;
        r->data = a;
        r->next = head;
        r->prev = head->prev;
        head->prev->next = r;
        head->prev = r;

    }

    void deleteNode(int a){
        node * temp = head;
        if(temp->data != a){
            temp = temp->next;
        
            while(temp != head && temp->data != a){
                temp = temp->next;
            }
            if(temp == head){
                return;
            }
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;  
    }

};

int main(){

    int n;
    cin >> n;
    LinkedList top(1);
    for(int i = 2; i <= n; i++){
        top.addNode(i);
    }
    top.endNode();
    top.printLinkedList();

    int a;
    cin >> a;
    top.deleteNode(a);

    // top.insertNode(a);
    top.printLinkedList();
}