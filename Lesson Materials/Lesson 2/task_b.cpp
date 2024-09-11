// В принципе, можно вставлять сверху ссылку на текст задачи / успешную посылку в Яндекс.Контест:
// https://contest.yandex.ru/contest/40236/run-report/117792126/
#include <cmath>  // Алфавитный порядок инклюдов
#include <iostream>

int main() {  // Пробелы вокруг скобок, пропуск строк до и после объявления / реализации функций, классов и прочего
  size_t first_cathetus, second_cathetus;  // Понятный нейминг для задачи
  std::cin >> first_cathetus >> second_cathetus;

  // Вычисление гипотенузы, снова хороший нейминг + пробелы вокруг любых операторов
  double hypotenuse = std::sqrt(first_cathetus * first_cathetus + second_cathetus * second_cathetus);

  std::cout << hypotenuse << '\n';   // '\n' вместо std::endl
}
// Пустая строка в конце любого (!!!) файла! Кстати, в PEP8 для гуманитарного Питона также.
