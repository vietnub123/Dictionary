#ifndef DICTIONARY_H
#define DICTIONARY_H

#include "Word.h"
#include "DynamicArray.h"
#include "IPersistable.h"
#include "ISearchStrategy.h"

// =====================================================================
// Dictionary - Lop quan ly tap tu vung
//
// Inheritance: implement IPersistable (save/load tu file)
// Composition: chua DynamicArray<Word>, ISearchStrategy*
//
// Strategy Pattern: chien luoc tim kiem co the doi runtime qua
// setSearchStrategy(). Mac dinh khong giu chien luoc rieng - client
// truyen vao moi lan goi search().
//
// Exception:
//   - addWord  -> nem DuplicateWordException neu trung
//   - update/delete -> nem WordNotFoundException neu khong co
//   - save/load -> nem FileIOException neu loi I/O
// =====================================================================

class Dictionary : public IPersistable {
private:
    DynamicArray<Word> words_;

public:
    Dictionary() {}
    virtual ~Dictionary() {}

    // Truy van co ban
    int size() const { return words_.size(); }
    bool empty() const { return words_.empty(); }
    const Word& at(int i) const { return words_[i]; }

    // Truy cap mang noi bo (cho search strategy)
    const DynamicArray<Word>& getWords() const { return words_; }

    // Tim kiem voi mot chien luoc cu the (Strategy Pattern)
    // Strategy duoc truyen vao theo dependency injection
    void search(const ISearchStrategy& strategy,
                const std::string& query,
                DynamicArray<SearchResult>& results) const;

    // Helper: tim chinh xac, tra ve chi so hoac -1
    int findIndexExact(const std::string& english) const;

    // Thao tac CRUD - su dung exception thay vi return bool
    void addWord(const Word& w);       // throws DuplicateWordException
    void updateWord(const std::string& english, const Word& newData);
                                        // throws WordNotFoundException
    void deleteWord(const std::string& english);
                                        // throws WordNotFoundException

    // Implement IPersistable
    virtual void saveToFile(const std::string& filename) const;
    virtual void loadFromFile(const std::string& filename);

    // In danh sach tat ca tu (chi english)
    void printAll(std::ostream& os) const;
};

#endif // DICTIONARY_H
