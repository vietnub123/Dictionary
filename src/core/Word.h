#ifndef WORD_H
#define WORD_H

#include <string>
#include <iostream>
#include "DynamicArray.h"

// =====================================================================
// Word - Lop bieu dien 1 tu vung trong tu dien
//
// Tinh chat OOP:
//   - Encapsulation: tat ca du lieu private, truy cap qua getter/setter
//   - Const correctness: getter deu la const
//   - Operator overloading:
//       operator==  : so sanh theo english (case-insensitive)
//       operator<<  : in ra ostream (friend function)
// =====================================================================

class Word {
private:
    std::string english_;
    DynamicArray<std::string> meanings_;
    DynamicArray<std::string> examples_;
    DynamicArray<std::string> synonyms_;

public:
    // Constructors
    Word() {}
    explicit Word(const std::string& english) : english_(english) {}

    // Getters (const)
    const std::string& getEnglish() const { return english_; }
    const DynamicArray<std::string>& getMeanings() const { return meanings_; }
    const DynamicArray<std::string>& getExamples() const { return examples_; }
    const DynamicArray<std::string>& getSynonyms() const { return synonyms_; }

    // Setters va modifier
    void setEnglish(const std::string& english) { english_ = english; }

    void addMeaning(const std::string& m) { meanings_.push_back(m); }
    void addExample(const std::string& e) { examples_.push_back(e); }
    void addSynonym(const std::string& s) { synonyms_.push_back(s); }

    void clearMeanings() { meanings_.clear(); }
    void clearExamples() { examples_.clear(); }
    void clearSynonyms() { synonyms_.clear(); }

    // Reset toan bo (giu lai english)
    void resetDetails() {
        meanings_.clear();
        examples_.clear();
        synonyms_.clear();
    }

    // So sanh theo english, khong phan biet hoa thuong
    bool operator==(const Word& other) const;
    bool operator!=(const Word& other) const { return !(*this == other); }

    // In ra ostream (overload << thong qua friend)
    friend std::ostream& operator<<(std::ostream& os, const Word& w);
};

#endif // WORD_H
