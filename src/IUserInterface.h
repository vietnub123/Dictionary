#ifndef I_USER_INTERFACE_H
#define I_USER_INTERFACE_H

#include <string>

// =====================================================================
// IUserInterface - Interface cho lop giao tiep nguoi dung
//
// Cho phep sau nay thay the bang lop GUI ma khong sua phan logic.
// Tach giao dien ra khoi logic la nguyen tac SoC (Separation of Concerns).
//
// Hien tai: ConsoleUI implement interface nay.
// Tuong lai co the them: GuiUI (Qt), WebUI (FastAPI), ...
// =====================================================================

class IUserInterface {
public:
    virtual ~IUserInterface() {}

    // Phuong thuc chinh: chay vong lap chinh cua UI
    virtual void run() = 0;
};

#endif // I_USER_INTERFACE_H
