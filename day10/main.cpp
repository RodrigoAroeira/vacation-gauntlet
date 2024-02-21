// failed compiles: 
// failed runs: 
// time taken: 

#include <iostream>

template<typename Type>
class TreeNode{
private:
    Type data;
    TreeNode* left = nullptr;
    TreeNode* right = nullptr;
    TreeNode* prev = nullptr;
    int depth = 0;
public:

    explicit TreeNode(){};

    explicit TreeNode(Type data){
        this->data = data;
    }

    explicit TreeNode(Type data, TreeNode<Type>* left, TreeNode<Type>* right){
        this->data = data;
        this->left = left;
        this->right = right;
        left->prev = this;
        right->prev = this;

        if(left)
            left->depth = depth + 1;
        if(right)
            right->depth = depth + 1;
    }

    void insert(Type value){
        if(value > data){
            if (right == nullptr) {
                right = new TreeNode<Type>(value);
                right->depth = depth + 1;
                right->prev = this;
            } else{
                right->insert(value);
            }

        } else{
            if (left == nullptr) {
                left = new TreeNode<Type>(value);
                left->depth = depth + 1;
                left->prev = this;
            } else {
                left->insert(value);
            }
        }
    }

    void remove(Type value){
        if (value == data){
            if (prev){

            }
            else {
                std::cout << "Depth minimum reached. Use the change() method to alter value." /*??*/ << std::endl;
            }
        }else if(value > data){
            if(right != nullptr){
                right->remove(value);
            }
        }
        else{
            if(left != nullptr){
                left->remove(value);
            }
        }
    }

    bool contains(Type value){
        if (value == data)
            return true;
        else if (value > data){
            if (right == nullptr)
                return false;
            else
                return right->contains(value);
        }
        else {
            if (left == nullptr)
                return false;
            else
                return left->contains(value);
        }
    }

    void print(){
        std::cout << "KKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKK nao" << std::endl;
    }
};

int main(){

    TreeNode<int> root(0);
    root.remove(0);
    return 0;
}