#include "Dictionary.h"
#include "StringUtils.h"
#include "Exceptions.h"
#include <fstream>
#include <iostream>

void Dictionary::search(const ISearchStrategy& strategy,
                        const std::string& query,
                        DynamicArray<SearchResult>& results) const {
    strategy.search(words_, query, results);
}

int Dictionary::findIndexExact(const std::string& english) const {
    std::string q = StringUtils::toLower(english);
    for (int i = 0; i < words_.size(); ++i) {
        if (StringUtils::toLower(words_[i].getEnglish()) == q) {
            return i;
        }
    }
    return -1;
}

void Dictionary::addWord(const Word& w) {
    if (findIndexExact(w.getEnglish()) != -1) {
        throw DuplicateWordException(w.getEnglish());
    }
    words_.push_back(w);
}

void Dictionary::updateWord(const std::string& english, const Word& newData) {
    int idx = findIndexExact(english);
    if (idx == -1) {
        throw WordNotFoundException(english);
    }
    words_[idx] = newData;
}

void Dictionary::deleteWord(const std::string& english) {
    int idx = findIndexExact(english);
    if (idx == -1) {
        throw WordNotFoundException(english);
    }
    words_.removeAt(idx);
}

// -------- File I/O --------

// Lay phan sau dau '=' dau tien
static std::string valueAfterEqual(const std::string& line) {
    for (int i = 0; i < (int)line.length(); ++i) {
        if (line[i] == '=') {
            return StringUtils::trim(line.substr(i + 1));
        }
    }
    return "";
}

void Dictionary::loadFromFile(const std::string& filename) {
    std::ifstream fin(filename.c_str());
    if (!fin.is_open()) {
        throw FileIOException(filename);
    }

    words_.clear();
    std::string line;
    Word current;
    bool inWord = false;

    while (std::getline(fin, line)) {
        line = StringUtils::trim(line);
        if (line.empty() || line[0] == '#') continue;

        if (line.length() >= 8 && line.substr(0, 8) == "@english") {
            if (inWord && !current.getEnglish().empty()) {
                try { addWord(current); }
                catch (const DuplicateWordException&) { /* bo qua trung */ }
            }
            current = Word(valueAfterEqual(line));
            inWord = true;
        }
        else if (line == "@end") {
            if (inWord && !current.getEnglish().empty()) {
                try { addWord(current); }
                catch (const DuplicateWordException&) { /* bo qua trung */ }
            }
            inWord = false;
            current = Word();
        }
        else if (inWord) {
            DynamicArray<std::string> parts;
            std::string val = valueAfterEqual(line);

            if (line.length() >= 7 && line.substr(0, 7) == "meaning") {
                StringUtils::split(val, '|', parts);
                for (int i = 0; i < parts.size(); ++i) current.addMeaning(parts[i]);
            }
            else if (line.length() >= 7 && line.substr(0, 7) == "example") {
                StringUtils::split(val, '|', parts);
                for (int i = 0; i < parts.size(); ++i) current.addExample(parts[i]);
            }
            else if (line.length() >= 7 && line.substr(0, 7) == "synonym") {
                StringUtils::split(val, '|', parts);
                for (int i = 0; i < parts.size(); ++i) current.addSynonym(parts[i]);
            }
        }
    }

    if (inWord && !current.getEnglish().empty()) {
        try { addWord(current); }
        catch (const DuplicateWordException&) {}
    }
    fin.close();
}

static void writeField(std::ofstream& fout, const std::string& name,
                       const DynamicArray<std::string>& arr) {
    if (arr.empty()) return;
    fout << name << "=";
    for (int i = 0; i < arr.size(); ++i) {
        fout << arr[i];
        if (i < arr.size() - 1) fout << "|";
    }
    fout << "\n";
}

void Dictionary::saveToFile(const std::string& filename) const {
    std::ofstream fout(filename.c_str());
    if (!fout.is_open()) {
        throw FileIOException(filename);
    }

    fout << "# File du lieu tu dien Anh-Viet\n";
    fout << "# Moi tu mot block, bat dau @english va ket thuc @end\n\n";

    for (int i = 0; i < words_.size(); ++i) {
        const Word& w = words_[i];
        fout << "@english=" << w.getEnglish() << "\n";
        writeField(fout, "meaning", w.getMeanings());
        writeField(fout, "example", w.getExamples());
        writeField(fout, "synonym", w.getSynonyms());
        fout << "@end\n\n";
    }
    fout.close();
}

void Dictionary::printAll(std::ostream& os) const {
    if (words_.empty()) {
        os << "(Tu dien rong)\n";
        return;
    }
    os << "Tong so tu: " << words_.size() << "\n";
    for (int i = 0; i < words_.size(); ++i) {
        os << "  " << (i + 1) << ". " << words_[i].getEnglish() << "\n";
    }
}
