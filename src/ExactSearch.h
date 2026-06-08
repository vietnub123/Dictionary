#ifndef EXACT_SEARCH_H
#define EXACT_SEARCH_H

#include "ISearchStrategy.h"

// =====================================================================
// ExactSearch - Chien luoc tim chinh xac (case-insensitive)
//
// Tra ve toi da 1 ket qua: phan tu duy nhat khop voi query.
// Score luon bang 0 (trung khop hoan toan).
// Do phuc tap: O(n * L) voi n la so tu, L la do dai trung binh.
// =====================================================================

class ExactSearch : public ISearchStrategy {
public:
    virtual void search(const DynamicArray<Word>& words,
                        const std::string& query,
                        DynamicArray<SearchResult>& results) const;

    virtual std::string getName() const { return "ExactSearch"; }
};

#endif // EXACT_SEARCH_H
