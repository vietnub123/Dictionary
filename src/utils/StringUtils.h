#ifndef STRING_UTILS_H
#define STRING_UTILS_H

#include <string>
#include "DynamicArray.h"

// =====================================================================
// StringUtils - Lop tien ich (utility class) cho thao tac chuoi
//
// Tat ca phuong thuc deu la static (stateless utility), giong nhu
// Math class trong cac ngon ngu khac.
//
// Bao gom:
//   - Khoang cach Levenshtein (DP 2 chieu tu cai dat)
//   - Chuyen chu thuong
//   - Trim khoang trang
//   - Tach chuoi theo delimiter
// =====================================================================

class StringUtils {
public:
    // Khoang cach chinh sua giua 2 chuoi - O(m*n)
    static int levenshteinDistance(const std::string& a, const std::string& b);

    // Chuyen chuoi ASCII ve chu thuong (Khong xu ly Unicode multi-byte)
    static std::string toLower(const std::string& s);

    // Cat khoang trang dau/cuoi (space, tab, CR, LF)
    static std::string trim(const std::string& s);

    // Tach chuoi theo ky tu phan cach, ghi vao out
    static void split(const std::string& s, char delimiter,
                      DynamicArray<std::string>& out);

    // Khoi tao private khong cho phep instantiate
private:
    StringUtils() {}
};

#endif // STRING_UTILS_H
