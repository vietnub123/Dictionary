#ifndef I_PERSISTABLE_H
#define I_PERSISTABLE_H

#include <string>

// =====================================================================
// IPersistable - Interface cho cac doi tuong co the luu/tai tu file
//
// Day la abstract base class (pure virtual), khong the instantiate.
// Bat ky lop nao can persistence deu phai override 2 phuong thuc:
//   - saveToFile(): ghi du lieu xuong file
//   - loadFromFile(): doc du lieu tu file
//
// Hien tai duoc implement boi: Dictionary, History, Favorites.
//
// Loi ich:
//   - Code client co the duyet collection cua IPersistable* va goi
//     saveToFile() / loadFromFile() bat ke kieu thuc cu the.
//   - Sau nay them lop moi (vd: Statistics) chi can implement interface.
// =====================================================================

class IPersistable {
public:
    virtual ~IPersistable() {}  // virtual destructor de an toan khi delete

    // Cac phuong thuc thuan ao (pure virtual) - bat buoc override
    virtual void saveToFile(const std::string& filename) const = 0;
    virtual void loadFromFile(const std::string& filename) = 0;
};

#endif // I_PERSISTABLE_H
