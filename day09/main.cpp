// failed compiles: 
// failed runs: 
// time taken: 

#include <iostream>

template <typename T>
class Stack{
private:
    T data;
    int size = 1;
    Stack* next = nullptr;
    Stack* top = nullptr;
public:
    explicit Stack(T value){
        data = value;
        top = this;
    }

    void push(T val){
        Stack* NewNode = new Stack<T>(val);
        top->next = NewNode;
        top = NewNode;
        size++;
    }

    void pop(){
        Stack* current = this;
        Stack* prev = nullptr;
        while (current->next){
            prev = current;
            current = current->next;
        }
        if(prev){
            prev->next = nullptr;
        }
        top = prev;
        size--;
        delete current;
    }

    T peek(){
        return top->data;
    }

    T peek(int pos){
        Stack* current = this;
        if (pos > size || pos == size){
            return peek();
        }
        int i = 1;
        while(current->next && i < pos){
            current = current->next;
            i++;
        }
        return current->data;
    }

    int getSize(){
        return size;
    }

    void print(){
        Stack* current = this;
        std::cout << "Stack: ";
        while(current) {
            std::cout << current->data << "->";
            current = current->next;
        }
        std::cout << std::endl;
    }

    void print(int until){
        Stack* current = this;
        std::cout << "Stack: ";
        int i = 0;
        while(current && i < until) {
            std::cout << current->data << "->";
            current = current->next;
            i++;
        }
        std::cout << std::endl;
    }
    
    void print(int from, int to){
        Stack* current = this;
        std::cout << "Stack: ";
        int i = 1;
        if (from > 1 && from < to)
        {
            std::cout << "....->";
        }
        
        while(current && i < to) {
            if (i >= from)
            {
                std::cout << current->data << "->";
            }
            current = current->next;
            i++;
        }
        std::cout << std::endl;
    }
};

template <typename T>
class Queue{
private:
    T data;
    Queue* next;
    int size = 1;
public:
    explicit Queue(T val){
        data = val;
    }

    void enqueue(T val){
        Queue* cur = this;
        size++;
        while(cur->next){
            cur = cur->next;
        }
        cur->next = new Queue<T>(val);
    }
    T dequeue(){
        if(next){
            data = next->data;
            Queue* del = next;
            next = next->next;
            delete del;
        }else{
            delete this;
        }
    }
    T peek(int pos){
        Queue* cur = this;

        int i = 0;
        while(cur->next && i < pos){
            cur = cur->next;
            i++;
        }
        return cur->data;
    }

    T peek(){
        Queue* cur = this;
        while(cur->next)
            cur = cur->next;

        return cur->data;
    }
    void print(){
        Queue* current = this;
        std::cout << "Queue: <-";
        while(current){
            std::cout << current->data;
            if(current->next){
                std::cout << "<-";
            }
            current = current->next;
        }
    std::cout << std::endl;
    }
};

int main(int argc, char const *argv[])
{
    Stack<int> s(1);
    int start = argc > 1 ? std::stoi(argv[1]) : 3;
    int end = argc > 2 ? std::stoi(argv[2]) : 27;
    for (int i = 2; i <= 1e6; i++)
    {
        s.push(i);
    }

    s.print(start, end);

    Queue<int> q(1);
    for (int i = 2; i <= 1e6; i++)
    {
        q.enqueue(i);
    }

    q.print();

    return 0;
}