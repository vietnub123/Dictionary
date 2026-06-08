#include "ConsoleUI.h"
#include "Exceptions.h"
#include "StringUtils.h"
#include <iostream>

// Duong dan file du lieu (cau hinh tap trung)
static const std::string DICT_FILE = "data/dictionary.txt";
static const std::string HIST_FILE = "data/history.txt";
static const std::string FAV_FILE  = "data/favorites.txt";

ConsoleUI::ConsoleUI(Dictionary& dict, History& history, Favorites& favorites)
    : dict_(dict), history_(history), favorites_(favorites),
      approxSearch_(3, 7), running_(true) {}

void ConsoleUI::printSeparator() const {
    std::cout << "-----------------------------------------\n";
}

void ConsoleUI::printMenu() const {
    std::cout << "\n=========================================\n";
    std::cout << "        TU DIEN ANH-VIET (OOP)           \n";
    std::cout << "=========================================\n";
    std::cout << "  1. Tra cuu tu (chinh xac + gan dung)\n";
    std::cout << "  2. Them tu moi\n";
    std::cout << "  3. Sua tu\n";
    std::cout << "  4. Xoa tu\n";
    std::cout << "  5. Liet ke tat ca tu\n";
    std::cout << "  6. Xem lich su tra cuu\n";
    std::cout << "  7. Quan ly yeu thich\n";
    std::cout << "  8. Luu du lieu xuong file\n";
    std::cout << "  9. Tai lai du lieu tu file\n";
    std::cout << "  0. Thoat (tu dong luu)\n";
    printSeparator();
    std::cout << "Chon chuc nang: ";
}

std::string ConsoleUI::readLine() const {
    std::string s;
    std::getline(std::cin, s);
    while (!s.empty() && (s[s.length() - 1] == '\r'
                          || s[s.length() - 1] == '\n')) {
        s.erase(s.length() - 1);
    }
    return s;
}

int ConsoleUI::readInt() const {
    std::string s = readLine();
    int n = 0, sign = 1, i = 0;
    if (i < (int)s.length() && s[i] == '-') { sign = -1; ++i; }
    bool any = false;
    for (; i < (int)s.length(); ++i) {
        if (s[i] >= '0' && s[i] <= '9') {
            n = n * 10 + (s[i] - '0');
            any = true;
        } else break;
    }
    if (!any) return -1;
    return sign * n;
}

void ConsoleUI::readMultipleInto(const std::string& prompt,
                                 DynamicArray<std::string>& out) const {
    std::cout << prompt;
    std::string line = readLine();
    StringUtils::split(line, '|', out);
}

// -------- Handlers --------

void ConsoleUI::handleLookup() {
    std::cout << "\n>>> TRA CUU TU\n";
    std::cout << "Nhap tu can tra: ";
    std::string q = readLine();
    if (q.empty()) {
        std::cout << "Tu rong, bo qua.\n";
        return;
    }

    // Buoc 1: dung Strategy ExactSearch
    DynamicArray<SearchResult> exactResults;
    dict_.search(exactSearch_, q, exactResults);

    if (!exactResults.empty()) {
        const Word& w = dict_.at(exactResults[0].wordIndex);
        std::cout << w;
        history_.add(w.getEnglish());
        return;
    }

    std::cout << "Khong tim thay tu \"" << q << "\" chinh xac.\n";

    // Buoc 2: chuyen sang Strategy ApproximateSearch
    DynamicArray<SearchResult> approxResults;
    dict_.search(approxSearch_, q, approxResults);

    if (approxResults.empty()) {
        std::cout << "Khong co goi y nao gan giong.\n";
        return;
    }

    std::cout << "Co phai ban muon tim:\n";
    for (int i = 0; i < approxResults.size(); ++i) {
        std::cout << "  " << (i + 1) << ". "
                  << dict_.at(approxResults[i].wordIndex).getEnglish()
                  << "  (khoang cach = " << approxResults[i].score << ")\n";
    }
    std::cout << "Chon so de xem chi tiet (0 de bo qua): ";
    int pick = readInt();
    if (pick >= 1 && pick <= approxResults.size()) {
        const Word& w = dict_.at(approxResults[pick - 1].wordIndex);
        std::cout << w;
        history_.add(w.getEnglish());
    }
}

void ConsoleUI::handleAddWord() {
    std::cout << "\n>>> THEM TU MOI\n";
    std::cout << "Tu tieng Anh: ";
    std::string eng = readLine();
    if (eng.empty()) {
        std::cout << "Tu rong, bo qua.\n";
        return;
    }

    Word w(eng);
    DynamicArray<std::string> tmp;

    readMultipleInto("Nghia tieng Viet (cach nhau bang '|'): ", tmp);
    for (int i = 0; i < tmp.size(); ++i) w.addMeaning(tmp[i]);
    tmp.clear();

    readMultipleInto("Vi du (cach nhau bang '|'): ", tmp);
    for (int i = 0; i < tmp.size(); ++i) w.addExample(tmp[i]);
    tmp.clear();

    readMultipleInto("Tu dong nghia (cach nhau bang '|'): ", tmp);
    for (int i = 0; i < tmp.size(); ++i) w.addSynonym(tmp[i]);

    try {
        dict_.addWord(w);
        std::cout << "Da them tu \"" << eng << "\" vao tu dien.\n";
    } catch (const DuplicateWordException& e) {
        std::cout << "Loi: " << e.what() << "\n";
    }
}

void ConsoleUI::handleUpdateWord() {
    std::cout << "\n>>> SUA TU\n";
    std::cout << "Nhap tu can sua: ";
    std::string eng = readLine();

    int idx = dict_.findIndexExact(eng);
    if (idx == -1) {
        std::cout << "Khong tim thay tu \"" << eng << "\".\n";
        return;
    }

    std::cout << "Thong tin hien tai:\n";
    std::cout << dict_.at(idx);

    Word w(dict_.at(idx).getEnglish());
    DynamicArray<std::string> tmp;
    std::cout << "Nhap thong tin moi (bo trong se xoa truong):\n";

    readMultipleInto("Nghia moi: ", tmp);
    for (int i = 0; i < tmp.size(); ++i) w.addMeaning(tmp[i]);
    tmp.clear();

    readMultipleInto("Vi du moi: ", tmp);
    for (int i = 0; i < tmp.size(); ++i) w.addExample(tmp[i]);
    tmp.clear();

    readMultipleInto("Dong nghia moi: ", tmp);
    for (int i = 0; i < tmp.size(); ++i) w.addSynonym(tmp[i]);

    try {
        dict_.updateWord(eng, w);
        std::cout << "Da cap nhat tu \"" << eng << "\".\n";
    } catch (const WordNotFoundException& e) {
        std::cout << "Loi: " << e.what() << "\n";
    }
}

void ConsoleUI::handleDeleteWord() {
    std::cout << "\n>>> XOA TU\n";
    std::cout << "Nhap tu can xoa: ";
    std::string eng = readLine();

    int idx = dict_.findIndexExact(eng);
    if (idx == -1) {
        std::cout << "Khong tim thay tu \"" << eng << "\".\n";
        return;
    }

    std::string realName = dict_.at(idx).getEnglish();
    std::cout << "Xac nhan xoa tu \"" << realName << "\"? (y/n): ";
    std::string c = readLine();
    if (c != "y" && c != "Y") {
        std::cout << "Huy thao tac.\n";
        return;
    }

    try {
        dict_.deleteWord(eng);
        // Xoa khoi yeu thich neu co
        try { favorites_.remove(realName); }
        catch (const WordNotFoundException&) { /* khong co thi thoi */ }
        std::cout << "Da xoa tu \"" << realName << "\".\n";
    } catch (const DictionaryException& e) {
        std::cout << "Loi: " << e.what() << "\n";
    }
}

void ConsoleUI::handleListAll() {
    std::cout << "\n>>> DANH SACH TAT CA TU\n";
    dict_.printAll(std::cout);
}

void ConsoleUI::handleShowHistory() {
    std::cout << "\n>>> LICH SU TRA CUU\n";
    if (history_.empty()) {
        std::cout << "(Lich su trong)\n";
        return;
    }
    std::cout << "Lich su (moi nhat truoc):\n";
    for (int i = 0; i < history_.size(); ++i) {
        std::cout << "  " << (i + 1) << ". " << history_.at(i) << "\n";
    }
}

void ConsoleUI::handleFavoritesMenu() {
    while (true) {
        std::cout << "\n>>> QUAN LY YEU THICH\n";
        std::cout << "  1. Xem danh sach yeu thich\n";
        std::cout << "  2. Them tu vao yeu thich\n";
        std::cout << "  3. Xoa tu khoi yeu thich\n";
        std::cout << "  4. Xem chi tiet mot tu yeu thich\n";
        std::cout << "  0. Quay lai menu chinh\n";
        std::cout << "Chon: ";
        int c = readInt();

        if (c == 0) return;
        else if (c == 1) {
            if (favorites_.empty()) {
                std::cout << "(Chua co tu yeu thich)\n";
            } else {
                std::cout << "Danh sach (" << favorites_.size() << " tu):\n";
                for (int i = 0; i < favorites_.size(); ++i) {
                    std::cout << "  " << (i + 1) << ". " << favorites_.at(i) << "\n";
                }
            }
        }
        else if (c == 2) {
            std::cout << "Nhap tu can them: ";
            std::string w = readLine();
            int idx = dict_.findIndexExact(w);
            if (idx == -1) {
                std::cout << "Tu khong co trong tu dien.\n";
                continue;
            }
            try {
                favorites_.add(dict_.at(idx).getEnglish());
                std::cout << "Da them vao yeu thich.\n";
            } catch (const DuplicateWordException& e) {
                std::cout << "Loi: " << e.what() << "\n";
            }
        }
        else if (c == 3) {
            std::cout << "Nhap tu can bo: ";
            std::string w = readLine();
            try {
                favorites_.remove(w);
                std::cout << "Da bo khoi yeu thich.\n";
            } catch (const WordNotFoundException& e) {
                std::cout << "Loi: " << e.what() << "\n";
            }
        }
        else if (c == 4) {
            if (favorites_.empty()) {
                std::cout << "(Chua co tu yeu thich)\n";
                continue;
            }
            for (int i = 0; i < favorites_.size(); ++i) {
                std::cout << "  " << (i + 1) << ". " << favorites_.at(i) << "\n";
            }
            std::cout << "Chon so thu tu: ";
            int n = readInt();
            if (n < 1 || n > favorites_.size()) {
                std::cout << "So thu tu khong hop le.\n";
                continue;
            }
            int idx = dict_.findIndexExact(favorites_.at(n - 1));
            if (idx == -1) std::cout << "Tu khong con trong tu dien.\n";
            else std::cout << dict_.at(idx);
        }
        else {
            std::cout << "Lua chon khong hop le.\n";
        }
    }
}

void ConsoleUI::handleSave() {
    try {
        dict_.saveToFile(DICT_FILE);
        history_.saveToFile(HIST_FILE);
        favorites_.saveToFile(FAV_FILE);
        std::cout << "Da luu du lieu xuong file.\n";
    } catch (const FileIOException& e) {
        std::cout << "Loi: " << e.what() << "\n";
    }
}

void ConsoleUI::handleReload() {
    try {
        dict_.loadFromFile(DICT_FILE);
        history_.loadFromFile(HIST_FILE);
        favorites_.loadFromFile(FAV_FILE);
        std::cout << "Da tai lai du lieu (" << dict_.size() << " tu).\n";
    } catch (const FileIOException& e) {
        std::cout << "Loi: " << e.what() << "\n";
    }
}

// -------- Main loop --------

void ConsoleUI::run() {
    running_ = true;
    while (running_) {
        printMenu();
        int c = readInt();
        switch (c) {
            case 1: handleLookup(); break;
            case 2: handleAddWord(); break;
            case 3: handleUpdateWord(); break;
            case 4: handleDeleteWord(); break;
            case 5: handleListAll(); break;
            case 6: handleShowHistory(); break;
            case 7: handleFavoritesMenu(); break;
            case 8: handleSave(); break;
            case 9: handleReload(); break;
            case 0:
                handleSave();
                std::cout << "Tam biet!\n";
                running_ = false;
                break;
            default:
                std::cout << "Lua chon khong hop le, vui long chon lai.\n";
        }
    }
}
