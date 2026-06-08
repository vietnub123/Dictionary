// =====================================================================
// Tu Dien Anh-Viet (Phien ban OOP)
// Mon: Ky Thuat Lap Trinh
//
// File main: chi tao Application va goi run(). Toan bo logic duoc
// uy quyen cho cac doi tuong nghiep vu (Single Responsibility Principle).
// =====================================================================

#ifdef _WIN32
#include <windows.h>
#endif

#include <iostream>
#include "Application.h"
#include "Exceptions.h"

int main() {
#ifdef _WIN32
    // Bat che do UTF-8 de hien thi tieng Viet tren Windows console
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
#endif

    try {
        Application app;
        app.initialize();
        app.run();
        app.shutdown();
    } catch (const DictionaryException& e) {
        std::cerr << "Loi he thong: " << e.what() << "\n";
        return 1;
    } catch (const std::exception& e) {
        std::cerr << "Loi khong xac dinh: " << e.what() << "\n";
        return 2;
    }

    return 0;
}
