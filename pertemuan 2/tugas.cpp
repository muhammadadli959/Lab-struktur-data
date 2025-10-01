#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class Stack {
private:
    Node* top;
public:
    Stack() : top(nullptr) {}
    ~Stack() {
        while (top) { Node* temp = top; top = top->next; delete temp; }
    }

    void push(int val) {
        Node* newNode = new Node(val);
        newNode->next = top;
        top = newNode;
        cout << "PUSH: Angka " << val << " dimasukkan." << endl;
    }

    int pop() {
        if (!top) {
            cout << "Stack kosong, tidak bisa POP." << endl;
            return -1;
        }
        int poppedVal = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        cout << "POP: Angka " << poppedVal << " dikeluarkan." << endl;
        return poppedVal;
    }
    
    void print_top() const {
        if (top) {
            cout << "\nAngka teratas yang tersisa di Stack: " << top->data << endl;
        } else {
            cout << "\nStack kosong." << endl;
        }
    }
};

int main() {
    cout << "--- Stack Linked List: PUSH 3 & POP 1 ---" << endl;
    
    Stack s;
    
    s.push(5);
    s.push(10);
    s.push(15);
    
    s.pop();
    
    s.print_top();

    return 0;
}
