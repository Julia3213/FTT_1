# Домашнее задание №1

*Задание:* Напишите функцию, которая инвертирует только выбранные биты в участке памяти, заданном указателем и длиной в байтах. Способ выбора битов для инвертирования на ваше усмотрение.

Принцип работы программы:
1. При запуске программы пользователю предлагается ввести строку, которая в программе переводится в массив байтов
2. Исходные данные и исходные данные в бинарном формате выводятся на экран
3. Пользователю предлагается ввести маску для инфертирования бит в формате целого числа от 0 до 255 или -1, если пользователь хочет сгенерировать маску рандомно

   *Пример ввода числа: 105*
   
   *Маска: 01101001*

   *При вводе -1 вызывается функция* `generate_mask`*, которая генерирует число от 0 до 255*

4. Пользователю предлагается ввести длину в байтах участка памяти, который будет инвертирован по маске

   *При вводе длины, большей длины строки ввод запрашивается снова*

5. Вызывается функция `inverting_bits`, которая инвертирует каждый байт массива по маске
6. Результат инвертирования выводится на экран

   
