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

    // Конструктор копирования
    // Гарник и Захар
    Stack(const Stack& other) : top_(nullptr) {
        if (other.top_ != nullptr) { //
            // Переменная для итерации по другому стеку
            Node* currentOther = other.top_;
            // Создаем первый узел
            top_ = new Node(currentOther->data);
            Node* currentThis = top_;

            // Копируем оставшиеся узлы
            while (currentOther->next != nullptr) {
                currentOther = currentOther->next;
                currentThis->next = new Node(currentOther->data);
                currentThis = currentThis->next;
            }

            size_ = other.size_;
        }
    }

    Stack(const Stack&& other)  noexcept : top_(nullptr), size_(other.size()) {
        top_ = nullptr;
        size_ = 0;
    }



    // move assignment operator
    Stack& operator = (Stack&& other) noexcept {
        if (this != &other) {
            while (!isEmpty()) {
                pop();
            }
            top_ = nullptr, size_ = other.size();

            other.top_ = nullptr;
            other.size_ = 0;

            return *this;
        }
        return *this;
    }

    // operators
    // Аня и Диана
    Stack& operator = (const Stack& other) {
        if (this != &other) {
            while (!isEmpty()) {
                pop();
            }

            while (!isEmpty()) {
                if (top_ != nullptr) {
                    Node* current = other.top_;

                    top_ = new Node(current->data);

                    Node* thisCurr = top_;

                    while (current->next) {
                        current = current->next;
                        thisCurr->next = new Node(current->data);
                        thisCurr = thisCurr->next;
                    }
                    size_ = other.size_;
                }
            }
            return *this;
        }
        return *this;
    }

    // Азиза и Ани
    bool operator == (const Stack& other) const {
        if (size_ != other.size_) {
            return false;
        }

        Node* curr = top_;
        Node* othCurr = other.top_;

        while (curr != nullptr && othCurr != nullptr) {
            if (curr->data != othCurr->data) {
                return false;
            }
            curr = curr->next;
            othCurr = othCurr->next;
        }

        return true;
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
    [[nodiscard]] size_t size() const {return size_;}
};
