#include "Favorites.h"
#include "StringUtils.h"
#include "Exceptions.h"
#include <fstream>

bool Favorites::contains(const std::string& word) const {
    std::string q = StringUtils::toLower(word);
    for (int i = 0; i < items_.size(); ++i) {
        if (StringUtils::toLower(items_[i]) == q) return true;
    }
    return false;
}

void Favorites::add(const std::string& word) {
    if (contains(word)) {
        throw DuplicateWordException(word);
    }
    items_.push_back(word);
}

void Favorites::remove(const std::string& word) {
    std::string q = StringUtils::toLower(word);
    for (int i = 0; i < items_.size(); ++i) {
        if (StringUtils::toLower(items_[i]) == q) {
            items_.removeAt(i);
            return;
        }
    }
    throw WordNotFoundException(word);
}

void Favorites::saveToFile(const std::string& filename) const {
    std::ofstream fout(filename.c_str());
    if (!fout.is_open()) {
        throw FileIOException(filename);
    }
    for (int i = 0; i < items_.size(); ++i) {
        fout << items_[i] << "\n";
    }
    fout.close();
}

void Favorites::loadFromFile(const std::string& filename) {
    std::ifstream fin(filename.c_str());
    if (!fin.is_open()) return;
    items_.clear();
    std::string line;
    while (std::getline(fin, line)) {
        if (!line.empty()) items_.push_back(line);
    }
    fin.close();
}
