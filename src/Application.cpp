#include "Application.h"
#include "ConsoleUI.h"
#include "Exceptions.h"
#include <iostream>

static const std::string DICT_FILE = "data/dictionary.txt";
static const std::string HIST_FILE = "data/history.txt";
static const std::string FAV_FILE  = "data/favorites.txt";

Application::Application()
    : history_(HISTORY_MAX_SIZE), ui_(nullptr) {
    // UI duoc tao trong initialize() sau khi cac thanh phan da san sang
}

Application::~Application() {
    delete ui_;
}

void Application::initialize() {
    // Tai tu dien
    try {
        dict_.loadFromFile(DICT_FILE);
        std::cout << "Da tai " << dict_.size() << " tu tu \""
                  << DICT_FILE << "\".\n";
    } catch (const FileIOException&) {
        std::cout << "Khong tim thay \"" << DICT_FILE
                  << "\". Bat dau voi tu dien rong.\n";
    }

    // Tai lich su va yeu thich (khong la loi neu khong co)
    try { history_.loadFromFile(HIST_FILE); }
    catch (const FileIOException&) {}
    try { favorites_.loadFromFile(FAV_FILE); }
    catch (const FileIOException&) {}

    // Tao UI (polymorphism: co the thay bang GuiUI sau)
    ui_ = new ConsoleUI(dict_, history_, favorites_);
}

void Application::run() {
    if (ui_ == nullptr) {
        throw DictionaryException("Application chua duoc initialize()");
    }
    ui_->run();
}

void Application::shutdown() {
    // Cac doi tuong tu giai phong qua destructor (RAII)
}
