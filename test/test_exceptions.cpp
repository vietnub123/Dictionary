#include <gtest/gtest.h>
#include "Dictionary.h"
#include "Exceptions.h" // Nơi chứa các định nghĩa DuplicateWordException, v.v.
#include "Word.h"

class ExceptionTest : public ::testing::Test {
protected:
    Dictionary dict;

    void SetUp() override {
        // Thêm một từ mẫu để kiểm tra trùng lặp
        Word w;
        w.setEnglish("hello");
        dict.addWord(w);
    }
};

// --- TEST: DUPLICATE WORD EXCEPTION ---
TEST_F(ExceptionTest, AddDuplicateWord_ThrowsException) {
    Word w;
    w.setEnglish("hello"); // Từ này đã có trong SetUp
    
    // Kiểm tra xem hệ thống có ném đúng Exception không
    EXPECT_THROW(dict.addWord(w), DuplicateWordException);
}

// --- TEST: WORD NOT FOUND EXCEPTION (DELETE) ---
TEST_F(ExceptionTest, DeleteNonExistentWord_ThrowsException) {
    // Thử xóa một từ không tồn tại
    EXPECT_THROW(dict.deleteWord("ghost_word"), WordNotFoundException);
}

// --- TEST: WORD NOT FOUND EXCEPTION (SEARCH) ---
// Nếu hệ thống của bạn ném Exception khi tìm kiếm từ không thấy

// --- TEST: FILE IO EXCEPTION (Giả định bạn có quản lý lỗi file) ---
TEST_F(ExceptionTest, LoadInvalidFile_ThrowsException) {
    // Thử load một file không tồn tại hoặc file lỗi định dạng
    EXPECT_THROW(dict.loadFromFile("non_existent_file.txt"), FileIOException);
}