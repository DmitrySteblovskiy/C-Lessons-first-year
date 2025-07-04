#pragma once

//   Базовый класс для всех исключений, содержит виртуальную функцию what() с описанием ошибки
//              std::exception
//                    │
//       ┌────────────┴─────────────┐
// std::logic_error        std::runtime_error
//       │                           │
//   ┌───┴────┬────┬─────┐          ...
//  std::domain_error  std::invalid_argument  std::length_error  std::out_of_range
