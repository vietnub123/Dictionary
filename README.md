# Từ Điển Anh-Việt (Phiên bản OOP)

Đồ án môn Kỹ Thuật Lập Trình - Chủ đề 7.

Phiên bản nâng cấp với kiến trúc hướng đối tượng đầy đủ: encapsulation, inheritance, polymorphism, kèm các mẫu thiết kế Strategy, Facade, và hệ thống Exception.

## Cấu trúc OOP

```
src/
├── DynamicArray.h              Template mảng động (generic)
├── Exceptions.h                Hierarchy exception (kế thừa std::exception)
├── StringUtils.h/.cpp          Utility class (Levenshtein, toLower, trim, split)
│
├── IPersistable.h              Interface save/load
├── IUserInterface.h            Interface UI
├── ISearchStrategy.h           Interface chiến lược tìm kiếm (Strategy Pattern)
│
├── Word.h/.cpp                 Class với encapsulation đầy đủ, operator overloading
│
├── ExactSearch.h/.cpp          Chiến lược: tìm chính xác
├── ApproximateSearch.h/.cpp    Chiến lược: tìm gần đúng (Levenshtein)
│
├── Dictionary.h/.cpp           Implement IPersistable
├── History.h/.cpp              Implement IPersistable (Rule of Three)
├── Favorites.h/.cpp            Implement IPersistable
│
├── ConsoleUI.h/.cpp            Implement IUserInterface
├── Application.h/.cpp          Facade Pattern - điều phối hệ thống
└── main.cpp                    Cực ngắn: tạo Application và chạy
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
build.bat
TuDienAnhViet.exe
```

### Linux / macOS / WSL

```bash
make
./TuDienAnhViet
```

Lưu ý: phải chạy từ thư mục gốc của project (chứa thư mục `data/`).

Trên Windows PowerShell, nếu tiếng Việt hiển thị sai, gõ `chcp 65001` trước khi chạy chương trình.

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
