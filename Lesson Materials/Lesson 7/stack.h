 #pragma once

template <typename T>
class Stack {
private:
    // Node - Слава
    struct Node {
        T data;
        Node* next;
        explicit Node(T value, Node* nextNode = nullptr) : data(value) , next(nextNode) {}

    };

    Node* top_;
    size_t size_{0};

public:

    // Конструктор и деструктор - Муслим
    Stack() : top_(nullptr) {}

    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }

// Добавление - Гарник
    void push(const T value) {
        ++size_;
        Node* new_node = new Node(value, top_);
        top_ = new_node;
    };

    // Удаление - Аня
    void pop() {
        if (!isEmpty()) {
            --size_;
            Node* temp = top_;
            top_ = top_->next;
            delete temp;
        }
        else {
            std::cout << "Stack is empty\n";
        }
    };

    // Подсмотреть элемент - Ани
    T& top() {
        if (isEmpty()) {
            std::cout << "Stack is empty\n";
        }
        return top_->data;
    };

    // Проверка на пустоту стека - Саша
    bool isEmpty() { return top_ == nullptr; }

    // Вывод размера - Саша
    size_t size() const {return size_;}
};
