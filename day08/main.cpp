// failed compiles: 
// failed runs: 
// time taken: 

#include <iostream>

class Node{
public:

    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }

    Node(){}

    bool searchR(int value){
        if(data == value)
            return true;
        if(next != nullptr)
            return next->searchR(value);
        return false;
    }

    bool searchI(int value){
        Node* current = this;

        while(current != nullptr){
            if (current->data == value)
                return true;
            current = current->next;
        }
        return false;
    }

    void remove(int value){
        return; // depois eu penso nisso fodase
        Node* current = this->next;
        Node* prev = this;
        Node* hold;
        while(current != nullptr){
            if (current->data == value) {
                hold = current->next;
            }
            prev = next->next

        }
    }

    void insert(int value) {
        Node *current = this;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = new Node(value);
    }

    void replace(int value, int spot){
        Node* current = this;
        for (int i = 0; i <= spot; i++){
            current = current->next;
        }
        current->data = value;
    }

};

void print_list(Node* head){
    Node* current = head;
    while (current){
        std::cout << current->data << "->";
        current = current->next;
    }
    std::cout << std::endl;
}

int get_size(Node* head){
    int count = 0;
    Node* current = head;
    while (current->next != nullptr){
        count++;
        current = current->next;
    }
    return count;
}

int main(){
    Node head(0);


    for (int i = 1; i <= 10; i++){
        head.insert(i);
    }
    std::cout << "List size: " << get_size(&head) << std::endl;

    print_list(&head);

    head.remove(3);

    print_list(&head);

}

//struct Node{};