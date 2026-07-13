#include <iostream>

template <typename T> class My_queue
{
    public:
    struct Node
    {
        Node* prev = nullptr;
        T data;
        Node()
        {
            data = T(); 
        }
        Node(T element)
        {
            data = element;
        }
        ~Node()
        {
            prev = nullptr;
        }
    };


    void insert (T element);
    T pop();
    My_queue();
    ~My_queue();
    
    
    private:
    Node* root = nullptr;
    Node* tail = nullptr;


    template <typename T> friend std::ostream& operator << (std::ostream& os, My_queue<T> My_que)
    {
    Node* node = My_que.root;
    if(My_que.tail != nullptr){
        while (node != My_que.tail)
    {
         if(node->prev == nullptr && node != My_que.tail) node = My_que.root;
        os << node->data;
        node = node->prev;
        os<< std::endl;
    }
                               }
    os << node->data;
    return os;
    }   
};


template <typename T> My_queue<T>::My_queue()
{}


template <typename T> void My_queue<T>::insert(T element)
{
    Node* node_m = new Node(element);
    if(root == nullptr)
    {
        root = node_m;
        tail = node_m;
    }
    if(root != nullptr)
    {
        tail->prev = node_m;
        tail = node_m;
    }
}


template <typename T> T My_queue<T>::pop()
{  
    T result = root->data;
    Node* node = root;
    root = root->prev;
    delete node;
    return result;
}


template <typename T> My_queue<T>::~My_queue()
{
    while (root!=tail && root!= nullptr)
    {
      T resu = this->pop();
    }
    root = nullptr;
    tail = nullptr;
}





int main(int argc, char* argv[])
{
    My_queue<float> My_que;
    My_que.insert(20.2);
    My_que.insert(15.2);
    My_que.insert(20.61);
    std::cout << My_que;
    int a = 0;
    std::cin>> a;
    return 0;
}