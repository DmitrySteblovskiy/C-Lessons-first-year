/*
Дополните класс Calculator базовыми арифметическими операциями:
1) Суммирование, разность, умножение
2) Деление всех видов (целое, с остатком, обычное деление)
3) *Звёздочка* - научиться насильно удалять калькулятор при получении более 10 операций in a row

Файл с классом нужно добавить в main и запустить в нём свой простенький тест (например, проверить каждую операцию по очереди)
Если делаете звездочку - придется проверить и её.

Не забывайте про кодстайл, правило трёх, поддержку всех типов через темплейты и перегрузки, ну и прочие прелести, которые я рассказывал.
*/

class Calculator {
public:
    // Конструктор
    Calculator();

    // Деструктор
    ~Calculator();

    // Базовые методы для арифм. операций
    int Add(const int a, const int b);

    int Multiply(const int a, const int b);

    ...

/*
private:
    current_op_counter_ = 0;
*/
};


