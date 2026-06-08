#include "ApproximateSearch.h"
#include "StringUtils.h"

int ApproximateSearch::partition(SearchResult* arr, int low, int high) const {
    int pivot = arr[high].score;
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if (arr[j].score <= pivot) {
            ++i;
            SearchResult tmp = arr[i]; arr[i] = arr[j]; arr[j] = tmp;
        }
    }
    SearchResult tmp = arr[i + 1]; arr[i + 1] = arr[high]; arr[high] = tmp;
    return i + 1;
}

void ApproximateSearch::quickSort(SearchResult* arr, int low, int high) const {
    if (low < high) {
        int p = partition(arr, low, high);
        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}

void ApproximateSearch::search(const DynamicArray<Word>& words,
                               const std::string& query,
                               DynamicArray<SearchResult>& results) const {
    if (words.empty()) return;

    std::string q = StringUtils::toLower(query);
    int qLen = (int)q.length();

    SearchResult* tmp = new SearchResult[words.size()];
    int count = 0;

    for (int i = 0; i < words.size(); ++i) {
        std::string w = StringUtils::toLower(words[i].getEnglish());

        // Toi uu: bo qua tu co chenh lech do dai vuot nguong
        int wLen = (int)w.length();
        int diff = qLen - wLen;
        if (diff < 0) diff = -diff;
        if (diff > maxDistance_) continue;

        int d = StringUtils::levenshteinDistance(q, w);
        if (d <= maxDistance_) {
            tmp[count++] = SearchResult(i, d);
        }
    }

    if (count == 0) {
        delete[] tmp;
        return;
    }

    quickSort(tmp, 0, count - 1);

    int take = (count < maxSuggestions_) ? count : maxSuggestions_;
    for (int i = 0; i < take; ++i) {
        results.push_back(tmp[i]);
    }
    delete[] tmp;
}
