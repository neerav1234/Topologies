#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct node{
    int data;
    // node* prev;
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
        r->next = NULL;
        head = r; 
        pre = r;

    }
    void addNode(int a){
        node* r;
        r = new node;
        r->data = a;
        r->next = NULL;
        pre->next = r;
        pre = r;
    }
    void printLinkedList(){
        node* temp;
        temp = head;

        while(temp->next!=NULL){
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << temp->data;
        cout << endl;
    }
    void drain(){
        node* temp = head;
        node* pr = NULL;
        while(temp!=NULL){
            pr = temp;
            temp = temp->next;
            delete pr;
        }
        // delete head;
    }
    void deleteNodeFromList(int a){
        node* temp = head;
        node* pr = NULL;
        while(temp != head && temp->data != a){
            pr = temp;
            temp = temp->next;
        }
        pr->next = temp->next;
        delete temp;
        
    }
    

};

void insertNode(int a, vector<LinkedList> &adj, int &n){
    LinkedList l(1);
    for(int i = 2; i <=n; i++){
        if(i != a)
            l.addNode(i);
    }
    adj.push_back(l);
    for(int i = 1; i <= n; i++){
        adj[i].addNode(a);
    }
    n++;
}

void deleteNode(int a, vector<LinkedList> &adj, int &n){
    // adj.erase(find(adj.begin(), adj.end(), a));
// adj[a].drain();
    cout << "1";
    for(int i = 1; i < n; i++)
    {
        if(i!=a)
            adj[i].deleteNodeFromList(a);
    }
}

int main(){
    int n;
    cin >> n;
    vector<LinkedList> adj;
    LinkedList l1(2);
    adj.push_back(l1); //for node 0
    for(int i = 3; i <= n; i++){
        l1.addNode(i);
    }
    adj.push_back(l1); //for node 1


    //for all nodes
    for(int i = 2; i <= n; i++){
        LinkedList l(1);
        for(int j = 2; j <= n; j++){
            if(j != i){
                l.addNode(j);
            }
        }
        adj.push_back(l);
    }

    for(int i = 1; i <= n; i++){
        cout << i << " : ";
        adj[i].printLinkedList();
    }

    int a;
    cin >> a;
    deleteNode(a, adj, n);
    cout << "1" << endl;
    for(int i = 1; i <= n; i++){
        cout << i << " : ";
        adj[i].printLinkedList();
    }

    return 0;
}