#include <iostream>
using namespace std;


template <class Type>
struct LinkedList{
    LinkedList(): size(0), head(nullptr){}
    ~LinkedList(){
        this->clear();
    }
    void pop_front(){
        Node<Type> * boof = head->next;
        delete head;
        head = boof;
        --size;
    }
    void clear(){
        while(size){
            pop_front();
        }
    }
    void push_back(Type data){
        if(head == 0){
            head = new Node<Type>(data);
        }
        else{
            Node<Type> * boof = head;
            while(boof->next != 0){
                boof = boof->next;
            }
            boof->next = new Node<Type>(data);
        }
        ++size;
    }
    void push_front(Type data){
        /*Node<Type> * boof = new Node<Type>;
        boof->data = data;
        boof->next = head;
        head = boof;
        ++size;
        */
        head = new Node<Type>(data, head);
        ++size;
    }
    size_t get_size(){return size;}
    void print_all(){
        cout << "LL elements: ";
        Node<Type> * boof = head;
        while(boof->next != 0){
            cout << boof->data << " ";
            boof  = boof->next;
        }
        cout<< boof->data << endl;
    }
    Type& operator[](const size_t ind){
        if(ind >= 0 && ind < size) {
            Node <Type> *boof = head;
            for (size_t i = 0; i < ind; ++i) {
                boof = boof->next;
            }
            return boof->data;
        }
        cout << "wrong index"<<endl;
    }
    /*Type& operator[](const int index){
        size_t counter = 0;
        Node<Type> * boof = head;
        while(boof != 0){
            if(counter == index){
                return boof->data;
            }
            boof = boof->next;
            ++counter;
        }
    }*/
    void insert(Type val, size_t index){
        if((index >= 0) && (index <= size )) {
                if (index == 0) {
                    this->push_front(val);

                } else {
                    Node <Type> *boof = head;
                    for (size_t i = 0; i < index - 1; ++i) {
                        boof = boof->next;
                    }
                    Node <Type> *boof2 = new Node<Type>;
                    boof2->data = val;
                    boof2->next = boof->next;
                    boof->next = boof2;
                }
                ++size;
        }
        else{
            cout << "wrong index"<<endl;
        }
    }
    void removeAt(size_t index){
        if(index == 0){
            this->pop_front();
        }
        else {
            Node <Type> *boof = head;
            for (size_t i = 0; i < index - 1; ++i) {
                boof = boof->next;
            }
            Node <Type> *boof2 = (boof->next)->next;
            delete boof->next;
            boof->next = boof2;
        }
        --size;
    } // нет проверки корректности индекса
    void pop_back(){
        this->removeAt(size - 1);
    }


private:
    template <class T>
    struct Node{
        Node(T data = T(), Node *pNext = 0) : data(data), next(pNext){}
        T data;
        Node * next;
    };

    Node<Type> * head;
    size_t  size;

};
int main() {
    LinkedList<int> a;
    a.push_front(11);
    for(int i = 0; i < a.get_size(); ++i){
        cout << a[i]<<" ";
    }
}
