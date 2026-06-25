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
