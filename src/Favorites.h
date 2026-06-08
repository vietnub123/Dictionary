#ifndef FAVORITES_H
#define FAVORITES_H

#include <string>
#include "DynamicArray.h"
#include "IPersistable.h"

// =====================================================================
// Favorites - Danh sach tu yeu thich (implement IPersistable)
//
// Luu trong DynamicArray<string>: don gian, ben vung,
// khong bi anh huong khi tu dien thay doi thu tu.
// So sanh khong phan biet hoa thuong.
// =====================================================================

class Favorites : public IPersistable {
private:
    DynamicArray<std::string> items_;

public:
    Favorites() {}
    virtual ~Favorites() {}

    int size() const { return items_.size(); }
    bool empty() const { return items_.empty(); }
    const std::string& at(int i) const { return items_[i]; }

    bool contains(const std::string& word) const;
    void add(const std::string& word);     // throw DuplicateWordException
    void remove(const std::string& word);  // throw WordNotFoundException
    void clear() { items_.clear(); }

    virtual void saveToFile(const std::string& filename) const;
    virtual void loadFromFile(const std::string& filename);
};

#endif // FAVORITES_H
