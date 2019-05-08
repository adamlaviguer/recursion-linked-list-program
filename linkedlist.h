//begin linkedlist.h
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <string>

using namespace std;

struct node {
    int data;
    node * next = nullptr;
};

class linkedlist {
private:
    node * head;
    int count(node *); // RECURSIVE
    int sum(node *); // RECURSIVE

public:
    linkedlist();
    ~linkedlist(); // RECURSIVE
    void addToFront(int n);
    void displayList();
    double average(); // uses sum and count functions
    void writeInorder(ofstream & outFile, string & file);
    void writeReversed(ofstream & outFile, string & file);
    void writeReversed(node *, ofstream & outFile);
    int numNodes(){
        return count(head);
    }
    double solution(){
        return sum(head);
    }
    void deleteNode(node *);
};
#endif // end linkedlist.h
