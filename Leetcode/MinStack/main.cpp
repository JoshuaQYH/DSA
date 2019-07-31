#include <iostream>

using namespace std;

class MinStack {
private:
    struct Node{
        int val;
        Node *next;
        Node(int val):val(val),next(NULL){}
    };

    Node* stack;  // head node pointer;
    int min;

public:
    /** initialize your data structure here. */
    MinStack() {
        Node* head = new Node(0); // head node;
        this->stack = head;
        this->min = 0;
    }

    void push(int x) {
        Node* newNode = new Node(x);

        if(this->isEmpty()){
            this->stack->next = newNode;
            this->min = x;
        }
        else{
            Node* oldTopNode = this->stack->next;
            newNode->next = oldTopNode;
            this->stack->next = newNode;
            this->min = this->min > x ? x : this->min;
        }
    }

    void pop() {
        if(this->isEmpty()) return;
        Node* topNode = this->stack->next;
        if(topNode->next == NULL){ // 只有一个结点
            this->stack->next = NULL;
        }
        else{ // 多个结点
            Node* newTopNode = topNode->next;
            this->stack->next = newTopNode;
        }
        if(topNode->val == this->min && topNode->next){
            this->min = topNode->next->val;
            Node* tmp = topNode->next;
            while(tmp){
                if(tmp->val < this->min)
                    this->min = tmp->val;
                tmp = tmp->next;
            }
        }
        delete topNode;
        topNode=NULL;
    }

    int top() {
        if(this->isEmpty()) return NULL;
        else{
            return this->stack->next->val;
        }
    }

    int getMin() {
        if(this->isEmpty()) return NULL;
        return this->min;
    }

    bool isEmpty(){
        return this->stack->next == NULL;
    }
};


int main()
{
    MinStack* s = new MinStack();
    for(int i = 0; i < 100; i ++){
        s->push(i);
        cout << s->getMin() << endl;
    }
    return 0;
}
