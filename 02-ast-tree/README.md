## 02-Интерпретатор с АСТ

### Описание возможностей

Программа представляет собой интерпретатор 
упрощённой версии языка Java, использующий `Abstract Syntax Tree`. 
Он умеет запускать код, который пишется в методе `main`.
Данный интерпретатор поддерживает следующие возможности:

   - Объявление переменных типа `int` с инициализацией или без
   - Присвоение числовых значений переменным
   - Арифметические операции с переменными и числовыми литералами
   - Объединение группы операций в фигурные скобки
   - Печать на стандартный поток вывода переменных

### Инструкция по запуску

После сборки проектов в директории `build`, в ней появится
директория `02-ast-tree`, а в ней файл `AST`.
Чтобы запустить код, нужно написать в терминале:
    
    ./AST [-p] [-s] source
    
`source` - путь до файла с кодом

`-s` - вывести вспомогательную информацию по 
лексическому анализу

`-p` - вывести вспомогательную информацию по
синтаксическому анализу  
