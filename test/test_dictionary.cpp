#include <gtest/gtest.h>
#include "Dictionary.h"
#include "Word.h"
#include "Exceptions.h"
#include <cstdio> // Để dùng std::remove xóa file test

class DictionaryTest : public ::testing::Test {
protected:
    Dictionary dict;
    const std::string testFile = "test_dict.txt";

    // Chạy trước mỗi test case
    void SetUp() override {
        // Có thể add sẵn vài từ mẫu nếu cần
    }

    // Chạy sau mỗi test case
    void TearDown() override {
        // Dọn dẹp file test để không ảnh hưởng các lần chạy sau
        std::remove(testFile.c_str());
    }
};

// --- CRUD: CREATE & READ ---
TEST_F(DictionaryTest, AddAndFindWord) {
    Word w;
    w.setEnglish("book");
    w.addMeaning("sach");
    
    dict.addWord(w);
    
    // Kiểm tra findIndexExact (CRUD: Read)
    int idx = dict.findIndexExact("book");
    EXPECT_NE(idx, -1);
    EXPECT_EQ(dict.at(idx).getEnglish(), "book");
}

// --- CRUD: EXCEPTION HANDLING (Duplicate) ---
TEST_F(DictionaryTest, AddDuplicateWordThrows) {
    Word w;
    w.setEnglish("apple");
    dict.addWord(w);
    
    // Thêm lần 2 phải ném DuplicateWordException
    EXPECT_THROW(dict.addWord(w), DuplicateWordException);
}

// --- CRUD: DELETE ---
TEST_F(DictionaryTest, DeleteExistingWord) {
    Word w;
    w.setEnglish("temp");
    dict.addWord(w);
    
    dict.deleteWord("temp");
    EXPECT_EQ(dict.findIndexExact("temp"), -1);
}

// --- CRUD: EXCEPTION HANDLING (Not Found) ---
TEST_F(DictionaryTest, DeleteNonExistentWordThrows) {
    EXPECT_THROW(dict.deleteWord("non_existent"), WordNotFoundException);
}

// --- PERSISTENCE: SAVE & LOAD ---
TEST_F(DictionaryTest, SaveAndLoadPersistence) {
    Word w1; w1.setEnglish("cat"); w1.addMeaning("meo");
    Word w2; w2.setEnglish("dog"); w2.addMeaning("cho");
    
    dict.addWord(w1);
    dict.addWord(w2);
    
    // Kiểm tra lưu file
    ASSERT_NO_THROW(dict.saveToFile(testFile));
    
    // Tạo từ điển mới và load lại
    Dictionary newDict;
    ASSERT_NO_THROW(newDict.loadFromFile(testFile));
    
    // Kiểm tra dữ liệu sau khi load
    EXPECT_NE(newDict.findIndexExact("cat"), -1);
    EXPECT_NE(newDict.findIndexExact("dog"), -1);
}