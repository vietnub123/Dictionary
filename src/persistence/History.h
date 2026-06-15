#ifndef HISTORY_H
#define HISTORY_H

#include <string>
#include "IPersistable.h"

// =====================================================================
// History - Lich su tra cuu, dung danh sach lien ket don
//
// Inheritance: implement IPersistable
// Co che: FIFO co gioi han kich thuoc
//   - Them o dau
//   - Neu tu da co, xoa ban cu (most-recently-used)
//   - Neu vuot maxSize, cat node cuoi
//
// Rule of Three: dinh nghia copy ctor / copy assign / dtor day du
// vi co quan ly bo nho dong qua linked list.
// =====================================================================

class History : public IPersistable {
private:
    struct Node {
        std::string word;
        Node* next;
        Node(const std::string& w) : word(w), next(nullptr) {}
    };

    Node* head_;
    int count_;
    int maxSize_;

    void copyFrom(const History& other);
    void freeAll();

public:
    explicit History(int maxSize = 20);
    History(const History& other);
    History& operator=(const History& other);
    virtual ~History();

    void add(const std::string& word);
    void clear();

    int size() const { return count_; }
    bool empty() const { return count_ == 0; }
    int getMaxSize() const { return maxSize_; }

    // Duyet: tra ve tu thu i (0-indexed), throw nếu out of range
    std::string at(int i) const;

    // Implement IPersistable
    virtual void saveToFile(const std::string& filename) const;
    virtual void loadFromFile(const std::string& filename);
};

#endif // HISTORY_H
