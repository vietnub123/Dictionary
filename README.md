# Từ Điển Anh-Việt (OOP)

Dự án môn Kỹ Thuật Lập Trình - Chủ đề 7.

Kiến trúc hướng đối tượng: encapsulation, inheritance, polymorphism, kèm các mẫu thiết kế Strategy, Facade, và hệ thống Exception.

## Cấu trúc OOP

```
src/
├── app/                        Miền Điều phối (Facade & Bootstrap)
│   ├── Application.h/.cpp      Facade Pattern - điều phối hệ thống
│   └── main.cpp                Entry point: Khởi tạo Application và chạy
│
├── core/                       Miền Cốt lõi (Cấu trúc nền tảng)
│   ├── DynamicArray.h          Template mảng động (generic)
│   └── Word.h/.cpp             Class thực thể với encapsulation đầy đủ, operator overloading
│
├── persistence/                Miền Bền vững hóa (Bảo toàn trạng thái)
│   ├── IPersistable.h          Interface save/load
│   ├── Dictionary.h/.cpp       Implement IPersistable (Quản lý tập Word)
│   ├── Favorites.h/.cpp        Implement IPersistable
│   └── History.h/.cpp          Implement IPersistable (Linked list, Rule of Three)
│
├── search/                     Miền Thuật toán (Strategy Pattern)
│   ├── ISearchStrategy.h       Interface chiến lược tìm kiếm
│   ├── ExactSearch.h/.cpp      Chiến lược: Khớp chuỗi tuyệt đối
│   └── ApproximateSearch.h/.cpp Chiến lược: Khớp chuỗi xấp xỉ (Khoảng cách Levenshtein)
│
├── ui/                         Miền Giao diện
│   ├── IUserInterface.h        Interface tương tác
│   └── ConsoleUI.h/.cpp        Implement IUserInterface (Giao thức dòng lệnh)
│
└── utils/                      Miền Tiện ích & Biệt lệ
    ├── Exceptions.h            Cây kế thừa ngoại lệ (mở rộng từ std::exception)
    └── StringUtils.h/.cpp      Tiện ích xử lý chuỗi (Levenshtein, toLower, trim, split)
```

## Các kỹ thuật OOP đã áp dụng

| Kỹ thuật | Vị trí |
|----------|--------|
| Encapsulation | Word (private fields + getter/setter) |
| Inheritance | IPersistable → Dictionary, History, Favorites |
| Polymorphism (virtual) | IUserInterface, ISearchStrategy, IPersistable |
| Abstract class / Interface | IPersistable, IUserInterface, ISearchStrategy |
| Operator overloading | Word::operator==, operator<< |
| Template (generic) | DynamicArray\<T\> |
| Exception handling | DictionaryException hierarchy |
| Const correctness | Mọi getter, mọi tham chiếu read-only |
| Rule of Three | History (linked list quản lý heap) |
| RAII | Tất cả tài nguyên giải phóng trong destructor |
| Strategy Pattern | ISearchStrategy + ExactSearch, ApproximateSearch |
| Facade Pattern | Application |
| Dependency Injection | ConsoleUI nhận tham chiếu Dictionary/History/Favorites |
| Single Responsibility | UI/data/algorithm tách 3 layer riêng |

## Biên dịch và chạy

### Windows (MinGW / MSYS2)

```cmd
.\build.bat
TuDienAnhViet.exe
```

### Linux / macOS / WSL

```bash
make
./TuDienAnhViet
```

Lưu ý: phải chạy từ thư mục gốc của project (chứa thư mục `data/`).

Trên Windows PowerShell, nếu tiếng Việt hiển thị sai, gõ `chcp 65001` trước khi chạy chương trình.


## Kiểm thử

Dự án sử dụng khung kiểm thử **Google Test (gTest)** để đảm bảo tính toàn vẹn của các cấu trúc dữ liệu và logic nghiệp vụ.

### 1. Cấu trúc thư mục kiểm thử
Các tệp kiểm thử được tổ chức theo module để đảm bảo tính phân tách trách nhiệm:

```
test/
├── test_dictionary.cpp       # Kiểm thử CRUD và Persistence
├── test_history.cpp          # Kiểm thử Linked List, MRU và Rule of Three
├── test_search.cpp           # Kiểm thử Strategy Pattern
└── test_exceptions.cpp       # Kiểm thử cơ chế quản lý ngoại lệ
```
### 2. Lệnh biên dịch đa module
Để biên dịch toàn bộ các file trong thư mục test/ và liên kết với các file mã nguồn cốt lõi (src/), sử dụng lệnh sau tại thư mục gốc của dự án (sử dụng trình biên dịch G++ từ MSYS2/UCRT64):

```Bash
C:/msys64/ucrt64/bin/g++.exe -std=c++17 -I C:/msys64/ucrt64/include -L C:/msys64/ucrt64/lib -I src/core -I src/persistence -I src/search -I src/ui -I src/utils test/*.cpp src/core/Word.cpp src/persistence/Dictionary.cpp src/persistence/History.cpp src/persistence/Favorites.cpp src/search/ExactSearch.cpp src/search/ApproximateSearch.cpp src/ui/ConsoleUI.cpp src/utils/StringUtils.cpp -lgtest -lgtest_main -pthread -o run_tests.exe
```

### 3. Thực thi kiểm thử
Sau khi quá trình biên dịch hoàn tất mà không phát sinh lỗi, tệp run_tests.exe sẽ được khởi tạo. Để chạy toàn bộ các kịch bản kiểm thử, thực thi lệnh:

```Bash
./run_tests.exe
```
Hệ thống sẽ xuất ra ma trận kết quả, hiển thị trạng thái [ PASSED ] cho các kiểm thử thành công hoặc [ FAILED ] kèm theo thông tin chi tiết nếu có sai lệch logic.



## Menu

| Số | Chức năng |
|----|-----------|
| 1 | Tra cứu (tự động: thử ExactSearch trước, không thấy thì gọi ApproximateSearch) |
| 2 | Thêm từ mới (throw DuplicateWordException nếu trùng) |
| 3 | Sửa từ (throw WordNotFoundException nếu không có) |
| 4 | Xóa từ |
| 5 | Liệt kê toàn bộ |
| 6 | Lịch sử (linked list, 20 từ gần nhất) |
| 7 | Quản lý Favorites |
| 8 | Lưu xuống file (gọi saveToFile() qua IPersistable) |
| 9 | Tải lại từ file |
| 0 | Thoát (tự động lưu) |
