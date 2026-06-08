#ifndef APPROXIMATE_SEARCH_H
#define APPROXIMATE_SEARCH_H

#include "ISearchStrategy.h"

// =====================================================================
// ApproximateSearch - Chien luoc tim gan dung dua tren Levenshtein
//
// Tham so cau hinh:
//   - maxDistance   : nguong khoang cach toi da chap nhan
//   - maxSuggestions: so ket qua toi da tra ve
//
// Score = khoang cach Levenshtein, sap xep tang dan.
//
// Toi uu: bo qua tu co chenh lech do dai > maxDistance ma khong tinh DP.
// =====================================================================

class ApproximateSearch : public ISearchStrategy {
private:
    int maxDistance_;
    int maxSuggestions_;

    // Quicksort tu cai dat (khong dung std::sort)
    void quickSort(SearchResult* arr, int low, int high) const;
    int partition(SearchResult* arr, int low, int high) const;

public:
    ApproximateSearch(int maxDistance = 3, int maxSuggestions = 7)
        : maxDistance_(maxDistance), maxSuggestions_(maxSuggestions) {}

    // Cau hinh runtime
    void setMaxDistance(int d) { maxDistance_ = d; }
    void setMaxSuggestions(int n) { maxSuggestions_ = n; }
    int getMaxDistance() const { return maxDistance_; }

    virtual void search(const DynamicArray<Word>& words,
                        const std::string& query,
                        DynamicArray<SearchResult>& results) const;

    virtual std::string getName() const { return "ApproximateSearch"; }
};

#endif // APPROXIMATE_SEARCH_H
