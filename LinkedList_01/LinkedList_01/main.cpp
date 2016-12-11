#include <iostream>
using namespace std;

class Node
{
public:
    string text;
    Node* tail;
};

class SLL
{
public:
    Node *LinkHead;
    Node *tempPoint;
    
    SLL()
    {
        LinkHead = NULL;
    }
    
    void CreatLinkToFirst(string txt)
    {
        Node *temp = new Node();
        
        temp->text = txt;
        temp->tail = LinkHead;
        
        LinkHead = temp;
    }
};

int main(int argc, const char * argv[]) {
    
    int *p;
    
    cout << p;
    
    cout << *p;
    
    return 0;
}
