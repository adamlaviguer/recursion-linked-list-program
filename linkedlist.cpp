//Adam Laviguer
//Section 02
#include "linkedlist.h"

linkedlist::linkedlist() {
    head = nullptr;
}

linkedlist::~linkedlist() {
    // RECURSIVE
    deleteNode(head);
    head = nullptr;
}

void linkedlist::addToFront(int n) {
    node * newNode;
    node * tempNode;
    node * prevNode = nullptr;
    //Allocate a new node
    newNode = new node;
    tempNode = nullptr;
    //Store n in the new node
    newNode->data = n;
    //If there are no nodes in the list, make newNode the first node
    if (!head){
        head = newNode;
    } else { //otherwise, insert newNode
        //Position tempNode at the head of the list
        tempNode = head;
        //Initialize prevNode to nullptr
        prevNode = nullptr;
        //Skip all nodes whose value is less than n
        while (tempNode != nullptr && tempNode->data < n){
            prevNode = tempNode;
            tempNode = tempNode->next;
        }
        //If the new node is to be the 1st in the list,
        //insert it before all other nodes
        if (prevNode == nullptr){
            head = newNode;
            newNode->next = tempNode;
        } else { //Otherwise, insert after the previous node
            prevNode->next = newNode;
            newNode->next = tempNode;
        }
    }
}

/*void linkedlist::displayList() {
        node * tempNode;
        tempNode = head;
        while (tempNode){
            cout<<tempNode->data<<" ";
            tempNode = tempNode->next;
        }
        cout<<endl;
}*/

int linkedlist::count(node * head) {
    // RECURSIVE
    if (head == nullptr)
    return 0;
    else {
        return 1 + count(head->next);
    }
}

int linkedlist::sum(node * head) {
    // RECURSIVE
    if(head == nullptr)
    return 0;
    else {
        return head->data + sum(head->next);
    }
}

double linkedlist::average() {
    // uses sum and count functions
    double avg = solution()/numNodes();
    return avg;
}

void linkedlist::writeInorder(ofstream & outFile, string & file) {
    outFile.open(file, ios::app);
    node * tempNode = head;
    if (tempNode == nullptr)
    return;
    while (tempNode != nullptr){
        outFile<<tempNode->data<<" ";
        tempNode = tempNode->next;
    }
    outFile<<endl;
    outFile.close();
}

void linkedlist::writeReversed(ofstream & outFile, string & file){
    outFile.open(file, ios::app);
    node * tempNode = head;
    writeReversed(tempNode, outFile);
    outFile<<endl;
    outFile.close();
}

void linkedlist::writeReversed(node * tempNode, ofstream & outFile) {
    // RECURSIVE
    if (tempNode == nullptr)
    return;
    else {
        writeReversed(tempNode->next, outFile);
        outFile<<tempNode->data<<" ";
    }
}

void linkedlist::deleteNode(node * tempNode){
	if(tempNode == nullptr)
	return;
	else {
		delete tempNode;
		deleteNode(tempNode->next);
	}
}
