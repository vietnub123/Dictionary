#include "ExactSearch.h"
#include "StringUtils.h"

void ExactSearch::search(const DynamicArray<Word>& words,
                         const std::string& query,
                         DynamicArray<SearchResult>& results) const {
    std::string q = StringUtils::toLower(query);
    for (int i = 0; i < words.size(); ++i) {
        if (StringUtils::toLower(words[i].getEnglish()) == q) {
            results.push_back(SearchResult(i, 0));
            return;  // Co the chi co 1 ket qua khop chinh xac
        }
    }
}
