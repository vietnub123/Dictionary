#ifndef CONSOLE_UI_H
#define CONSOLE_UI_H

#include "IUserInterface.h"
#include "Dictionary.h"
#include "History.h"
#include "Favorites.h"
#include "ExactSearch.h"
#include "ApproximateSearch.h"

// =====================================================================
// ConsoleUI - Giao dien console, implement IUserInterface
//
// Dam nhiem:
//   - Hien thi menu, doc lua chon nguoi dung
//   - Goi cac thao tac nghiep vu tren Dictionary/History/Favorites
//   - Hien thi ket qua va thong bao loi
//
// Khong dam nhiem:
//   - Luu/tai file (uy quyen cho cac doi tuong IPersistable)
//   - Logic tim kiem (uy quyen cho ISearchStrategy)
//
// Reference (khong own) cac doi tuong nghiep vu - Application giu vong doi.
// =====================================================================

class ConsoleUI : public IUserInterface {
private:
    Dictionary& dict_;
    History& history_;
    Favorites& favorites_;

    ExactSearch exactSearch_;
    ApproximateSearch approxSearch_;

    bool running_;

    // Cac handler cho tung muc menu
    void handleLookup();
    void handleAddWord();
    void handleUpdateWord();
    void handleDeleteWord();
    void handleListAll();
    void handleShowHistory();
    void handleFavoritesMenu();
    void handleSave();
    void handleReload();

    // Helpers giao tiep
    void printMenu() const;
    void printSeparator() const;
    std::string readLine() const;
    int readInt() const;
    void readMultipleInto(const std::string& prompt,
                          DynamicArray<std::string>& out) const;

public:
    ConsoleUI(Dictionary& dict, History& history, Favorites& favorites);
    virtual ~ConsoleUI() {}

    virtual void run();
};

#endif // CONSOLE_UI_H
