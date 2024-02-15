// failed compiles: 
// failed runs: 
// time taken: 

#include <iostream>

class Node {

private:
    int data;
    int size;
    Node *prev;
    Node *next;
public:
    Node(int val) {
        data = val;
        prev = nullptr;
        next = nullptr;
        size = 1;
    }


    bool searchR(int value) {
        if (data == value)
            return true;
        if (next != nullptr)
            return next->searchR(value);
        return false;
    }

    bool searchI(int value) {
        Node* current = this;

        while (current != nullptr) {
            if (current->data == value)
                return true;
            current = current->next;
        }
        return false;
    }

    int remove_val(int value){
        Node* current = next;
        while(current){
            if (current->data == value) {
                current->prev->next = current->next;
                size--;
                delete current;
                return 0;
            }
            current = current->next;
        }
        return -1;
    }

    int remove_pos(int pos){
        Node* current = next;
        int i = 0;
        while(i<size){
            if (i == pos-1) {
                current->prev->next = current->next;
                size--;
                delete current;
                return 0;
            }
            current = current->next;
            i++;
        }
        return -1;
    }

    void insert_back(int value) {
        Node* current = this;
        while (current->next) {
            current = current->next;
        }
        current->next = new Node(value);
        current->next->prev = current;
    }

    void insert_front(int value) {
        this->next->prev = new Node(data);
        Node* newNode = this->next->prev;
        newNode->next = this->next;
        newNode->prev = this;
        this->next = newNode;
        data = value;
    }

    void insert_in_pos(int value, int pos) {

    }

    void replace(int pos, int value) {
        Node *current = this;
        for (int i = 1; i < pos; i++) {
            current = current->next;
        }
        current->data = value;
    }


    void print_list() {
        Node *current = this;
        while (current) {
            std::cout << current->data << "->";
            current = current->next;
        }
        std::cout << std::endl;
    }

    int getData() const {
        return data;
    }

    void setData(int value) {
        data = value;
    }

    int getSize() const {
        return size;
    }

};


int main(){
    Node head(0);


    for (int i = 1; i <= 10; i++){
        head.insert_back(i);
    }

    std::cout << "Original list:" << std::endl;
    head.print_list();

    head.remove_val(3);
    std::cout << "List after remove_val(3):" << std::endl;
    head.print_list();

    std::cout << "List after remove_pos(0):" << std::endl;
    head.remove_pos(5);
    head.print_list();

    std::cout << "Insert_front(94)" << std::endl;
    head.insert_front(94);
    head.print_list();

    for (int i = 23; i < 28; i++){
        head.insert_front(i);
        head.print_list();
    }

    std::cout << "Replace 2, 15" << std::endl;
    head.replace(2,15);
    head.print_list();
}

//struct Node{};