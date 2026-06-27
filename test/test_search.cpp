#include <gtest/gtest.h>
#include "Dictionary.h"
#include "ExactSearch.h"
#include "ApproximateSearch.h"

class SearchTest : public ::testing::Test {
protected:
    Dictionary dict;

    void SetUp() override {
        // Khởi tạo dữ liệu mẫu để tìm kiếm
        Word w1; w1.setEnglish("apple");
        Word w2; w2.setEnglish("appeal");
        Word w3; w3.setEnglish("apply");
        Word w4; w4.setEnglish("banana");
        
        
        dict.addWord(w1);
        dict.addWord(w2);
        dict.addWord(w3);
        dict.addWord(w4);
    }
};

// --- TEST: EXACT SEARCH ---
TEST_F(SearchTest, ExactSearch_Found) {
    ExactSearch strategy;
    DynamicArray<SearchResult> results;
    
    dict.search(strategy, "apple", results);
    
    // Tìm thấy 1 kết quả chính xác
    EXPECT_EQ(results.size(), 1);
    EXPECT_EQ(dict.at(results[0].wordIndex).getEnglish(), "apple");
}

TEST_F(SearchTest, ExactSearch_NotFound) {
    ExactSearch strategy;
    DynamicArray<SearchResult> results;
    
    dict.search(strategy, "orange", results);
    
    // Không tìm thấy
    EXPECT_EQ(results.size(), 0);
}

// --- TEST: APPROXIMATE SEARCH ---
TEST_F(SearchTest, ApproximateSearch_PartialMatch) {
    ApproximateSearch strategy;
    DynamicArray<SearchResult> results;
    
    // Tìm kiếm "appl" - thuật toán xấp xỉ phải tìm ra các từ bắt đầu bằng "appl"
    dict.search(strategy, "appl", results);
    
    // Kết quả phải bao gồm apple, application, apply
    EXPECT_GE(results.size(), 3); 
}

TEST_F(SearchTest, ApproximateSearch_TypoHandling) {
    ApproximateSearch strategy;
    DynamicArray<SearchResult> results;
    
    // Giả sử thuật toán xấp xỉ có khả năng sửa lỗi chính tả
    // Ví dụ: tìm "banan" (thiếu chữ a)
    dict.search(strategy, "banan", results);
    
    bool found = false;
    for(size_t i = 0; i < results.size(); ++i) {
        if(dict.at(results[i].wordIndex).getEnglish() == "banana") {
            found = true;
            break;
        }
    }
    EXPECT_TRUE(found);
}

// --- TEST: STRATEGY SWITCHING ---
TEST_F(SearchTest, SwitchStrategiesDynamically) {
    // Kiểm tra Dictionary có chấp nhận thay đổi chiến lược khi runtime không
    DynamicArray<SearchResult> resultsExact;
    DynamicArray<SearchResult> resultsApprox;
    
    dict.search(ExactSearch(), "apple", resultsExact);
    dict.search(ApproximateSearch(), "apple", resultsApprox);
    
    // Kết quả tìm xấp xỉ thường sẽ trả về nhiều hơn hoặc bằng tìm chính xác
    EXPECT_GE(resultsApprox.size(), resultsExact.size());
}