cmake_minimum_required(VERSION 3.10)
project(SuperCalculator LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Находим Qt
find_package(Qt5 COMPONENTS Core Gui Widgets REQUIRED)

# Включаем автомокинг для Qt (MOC, UIC, RCC)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# Указываем Qt, что мы используем виджеты
set(CMAKE_PREFIX_PATH ${Qt5_PREFIX_PATH})

add_executable(SuperCalculator
    main.cpp
    calculator.h calculator.cpp
    mainwindow.h mainwindow.cpp
)

# Линкуем с библиотеками Qt
target_link_libraries(SuperCalculator PRIVATE Qt5::Core Qt5::Gui Qt5::Widgets)

# Включение заголовочных файлов Qt
target_include_directories(SuperCalculator PRIVATE ${Qt5Widgets_INCLUDE_DIRS})