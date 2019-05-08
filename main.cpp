#include <fstream>
#include <iostream>
#include <string>
#include "linkedlist.cpp"

using namespace std;

void readFile(linkedlist & list, string & file);
void writeFile(linkedlist & list, string & file);

int main() {
    linkedlist list;
    string file = "list.txt";

    readFile(list, file);
    /*list.displayList();
    cout<<list.numNodes()<<endl;
    cout<<list.solution()<<endl;*/
    cout<<"The average is: "<<list.average()<<endl;
    writeFile(list, file);
    return 0;
}

void readFile(linkedlist & list, string & file) {
    ifstream inFile;
    int num;
    inFile.open(file, ios::in);
    if (inFile.eof())
    return;
    while (inFile>>num){
        list.addToFront(num);
    }
    inFile.close();
}

void writeFile(linkedlist & list, string & file){
    ofstream outFile;
    list.writeInorder(outFile, file);
    list.writeReversed(outFile, file);
}
