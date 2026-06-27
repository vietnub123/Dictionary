#include <gtest/gtest.h>
#include "History.h"

class HistoryTest : public ::testing::Test {
protected:
    // Sử dụng size nhỏ để dễ kiểm soát capacity
    const int TEST_SIZE = 3;
};

// --- TEST: CƠ CHẾ THÊM VÀ THỨ TỰ (MRU) ---
TEST_F(HistoryTest, AddAndOrder) {
    History h(TEST_SIZE);
    h.add("apple");
    h.add("banana");
    
    // Kiểm tra thứ tự mới nhất nằm ở đầu (head)
    EXPECT_EQ(h.at(0), "banana");
    EXPECT_EQ(h.at(1), "apple");
}

TEST_F(HistoryTest, MRULogicMoveToFront) {
    History h(TEST_SIZE);
    h.add("apple");
    h.add("banana");
    h.add("cherry");
    
    // Gọi lại từ cũ ("apple"), nó phải nhảy lên đầu và không được nhân đôi
    h.add("apple");
    
    EXPECT_EQ(h.at(0), "apple");
    EXPECT_EQ(h.at(1), "cherry");
    EXPECT_EQ(h.at(2), "banana");
}

// --- TEST: GIỚI HẠN DUNG LƯỢNG (CAPACITY) ---
TEST_F(HistoryTest, BoundCapacity) {
    History h(2); // Chỉ giữ tối đa 2 phần tử
    h.add("A");
    h.add("B");
    h.add("C"); // "C" vào đầu, "A" bị đẩy ra
    
    EXPECT_EQ(h.at(0), "C");
    EXPECT_EQ(h.at(1), "B");
    // Kiểm tra xem phần tử cũ đã bị xóa chưa (hàm at cần đảm bảo không lỗi)
}

// --- TEST: RULE OF THREE (COPY CONSTRUCTOR) ---
TEST_F(HistoryTest, CopyConstructorDeepCopy) {
    History h1(TEST_SIZE);
    h1.add("A");
    
    // Gọi copy constructor
    History h2 = h1; 
    
    // Sửa h2, đảm bảo h1 không đổi (chứng minh deep copy, không phải shallow copy)
    h2.add("B");
    
    EXPECT_EQ(h2.at(0), "B");
    EXPECT_EQ(h1.at(0), "A"); 
    // Nếu h1 cũng bị "B" thì tức là bạn bị lỗi Shallow Copy (trỏ chung vùng nhớ)
}

// --- TEST: RULE OF THREE (COPY ASSIGNMENT) ---
TEST_F(HistoryTest, AssignmentOperatorDeepCopy) {
    History h1(TEST_SIZE);
    h1.add("A");
    
    History h2(TEST_SIZE);
    h2 = h1; // Gọi operator=
    
    h2.add("B");
    
    EXPECT_EQ(h2.at(0), "B");
    EXPECT_EQ(h1.at(0), "A");
}