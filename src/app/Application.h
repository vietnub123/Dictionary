#ifndef APPLICATION_H
#define APPLICATION_H

#include "Dictionary.h"
#include "History.h"
#include "Favorites.h"
#include "IUserInterface.h"

// =====================================================================
// Application - Facade Pattern
//
// Dong vai tro mat tien: gom tat ca thanh phan cua he thong va expose
// mot API don gian (initialize + run + shutdown) cho main().
//
// Quan ly vong doi cua:
//   - Dictionary, History, Favorites (data layer)
//   - IUserInterface (presentation layer)
//
// Su dung composition: app KHONG inherit cac doi tuong tren, ma chua chung.
// Sau nay neu doi UI thanh GUI, chi can sua Application, main giu nguyen.
// =====================================================================

class Application {
private:
    Dictionary dict_;
    History history_;
    Favorites favorites_;
    IUserInterface* ui_;  // pointer de cho phep polymorphism (Console/Gui)

    // Cau hinh duong dan
    static const int HISTORY_MAX_SIZE = 20;

public:
    Application();
    ~Application();

    // Tai du lieu khoi dong
    void initialize();

    // Chay UI
    void run();

    // Don dep
    void shutdown();

private:
    // Cam copy de tranh nham lan vong doi
    Application(const Application&);
    Application& operator=(const Application&);
};

#endif // APPLICATION_H
