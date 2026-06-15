#ifndef I_SEARCH_STRATEGY_H
#define I_SEARCH_STRATEGY_H

#include <string>
#include "DynamicArray.h"
#include "Word.h"

// =====================================================================
// ISearchStrategy - Interface cho thuat toan tim kiem (Strategy Pattern)
//
// Mau thiet ke Strategy: dong goi cac thuat toan khac nhau vao cac lop
// rieng, cho phep doi thuat toan tai runtime ma khong sua client.
//
// Cac implementation hien co:
//   - ExactSearch       : tim chinh xac (case-insensitive)
//   - ApproximateSearch : tim gan dung (Levenshtein distance)
//
// Co the de dang them moi:
//   - PrefixSearch  : tim theo tien to (Trie)
//   - PhoneticSearch: tim theo phat am (Soundex)
//
// Loi ich:
//   - Client (Dictionary) khong biet thuat toan cu the
//   - Co the doi chien luoc bang Dictionary::setSearchStrategy()
// =====================================================================

// Ket qua mot lan tim kiem
struct SearchResult {
    int wordIndex;      // Chi so trong mang words cua Dictionary
    int score;          // Diem khoang cach (0 = trung khop hoan toan)

    SearchResult() : wordIndex(-1), score(0) {}
    SearchResult(int idx, int s) : wordIndex(idx), score(s) {}
};

class ISearchStrategy {
public:
    virtual ~ISearchStrategy() {}

    // Tim kiem trong tap tu, day ket qua vao mang `results`
    // Tham so:
    //   words   : tap tu can tim
    //   query   : tu khoa tra cuu
    //   results : mang ket qua (output)
    virtual void search(const DynamicArray<Word>& words,
                        const std::string& query,
                        DynamicArray<SearchResult>& results) const = 0;

    // Ten cua chien luoc (dung de in/log)
    virtual std::string getName() const = 0;
};

#endif // I_SEARCH_STRATEGY_H
