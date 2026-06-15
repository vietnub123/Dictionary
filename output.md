Đồ án Kỹ thuật Lập trình – Chủ đề 7: Từ điển Anh-Việt (OOP)
ĐẠI HỌC BÁCH KHOA HÀ NỘI
TRƯỜNG CÔNG NGHỆ THÔNG TIN VÀ TRUYỀN THÔNG
BÁO CÁO ĐỒ ÁN
MÔN: KỸ THUẬT LẬP TRÌNH
Chủ đề 7:
TỪ ĐIỂN ANH – VIỆT
(Phiên bản nâng cấp hướng đối tượng)
Sinh viên thực hiện: Phạm Xuân Việt - Lã Mạnh Cường
MSSV: [Mã số sinh viên]
Lớp: 169313
Giảng viên hướng dẫn: [Tên giảng viên]
Hà Nội, 2026

Contents
1 GIỚI THIỆU ĐỀ TÀI 3
1.1 Mô tả đề tài . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 3
1.2 Yêu cầu chức năng . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 3
1.3 Yêu cầu phi chức năng . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 3
2 PHÂN TÍCH YÊU CẦU 4
2.1 Phân tích chức năng theo nhóm trách nhiệm . . . . . . . . . . . . . . . . . 4
2.2 Nhận xét . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 4
3 THIẾT KẾ HƯỚNG ĐỐI TƯỢNG 5
3.1 Các nguyên tắc OOP đã áp dụng . . . . . . . . . . . . . . . . . . . . . . . 5
3.1.1 Đóng gói (Encapsulation) . . . . . . . . . . . . . . . . . . . . . . . 5
3.1.2 Kế thừa (Inheritance) . . . . . . . . . . . . . . . . . . . . . . . . . 5
3.1.3 Đa hình (Polymorphism) . . . . . . . . . . . . . . . . . . . . . . . . 5
3.1.4 Trừu tượng hoá (Abstraction) . . . . . . . . . . . . . . . . . . . . . 6
3.2 Hệ thống lớp – sơ đồ tổng quan . . . . . . . . . . . . . . . . . . . . . . . . 6
3.3 Các mẫu thiết kế (Design Patterns) . . . . . . . . . . . . . . . . . . . . . . 6
3.3.1 Strategy Pattern – Chiến lược tìm kiếm . . . . . . . . . . . . . . . 6
3.3.2 Facade Pattern – Lớp Application . . . . . . . . . . . . . . . . . . . 6
3.3.3 Template Method ngầm – IPersistable . . . . . . . . . . . . . . . . 7
3.4 Hệ thống Exception . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 7
4 TRIỂN KHAI CHƯƠNG TRÌNH 8
4.1 Cấu trúc thư mục . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 8
4.2 Mô tả chi tiết các lớp . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 8
4.2.1 Lớp template DynamicArray<T> . . . . . . . . . . . . . . . . . . . . 8
4.2.2 Lớp Word . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 8
4.2.3 Strategy Pattern: ISearchStrategy . . . . . . . . . . . . . . . . . 9
4.2.4 Lớp Dictionary . . . . . . . . . . . . . . . . . . . . . . . . . . . . 9
4.2.5 Lớp History (Linked List + Rule of Three) . . . . . . . . . . . . . 9
4.2.6 Facade: Application . . . . . . . . . . . . . . . . . . . . . . . . . . 9
4.3 Định dạng file dữ liệu . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 10
5 KIỂM THỬ 11
6 TỔNG KẾT CÁC KỸ THUẬT ĐÃ VẬN DỤNG 13
6.1 Kỹ thuật về thiết kế hướng đối tượng (OOP) . . . . . . . . . . . . . . . . . 13
6.2 Các mẫu thiết kế (Design Patterns) . . . . . . . . . . . . . . . . . . . . . . 13
6.3 Kỹ thuật về thuật toán và cấu trúc dữ liệu . . . . . . . . . . . . . . . . . . 13
1

Báo cáo Đồ án – Từ điển Anh-Việt (OOP) 2
6.4 So sánh với phiên bản trước nâng cấp . . . . . . . . . . . . . . . . . . . . . 14
6.5 Kỹ thuật kiểm thử . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 14
A MÃ NGUỒN CÁC THÀNH PHẦN CHÍNH 15
A.1 Hàm main . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 15
A.2 Facade: Application . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 16
A.2.1 Application.h . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 16
A.2.2 Application.cpp . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 17
A.3 Hệ thống Exception . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 18
A.4 Interface IPersistable . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 19
A.5 Strategy Pattern – ISearchStrategy . . . . . . . . . . . . . . . . . . . . . . 20
A.6 Dictionary.cpp (trích) . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 20
A.7 History.cpp (Rule of Three) . . . . . . . . . . . . . . . . . . . . . . . . . . 22

Chương 1. GIỚI THIỆU ĐỀ TÀI
1.1. Mô tả đề tài
Đề tài “Từ điển Anh – Việt” thuộc Chủ đề 7 của môn Kỹ thuật Lập trình. Mục tiêu xây
dựng chương trình tra cứu từ vựng với các tính năng cốt lõi của một từ điển điện tử:
quản lý từ vựng, tra cứu chính xác, tra cứu gần đúng dựa trên thuật toán so khớp chuỗi,
lưu lịch sử và đánh dấu từ yêu thích.
Phiên bản trình bày trong báo cáo này là phiên bản nâng cấp theo hướng đối tượng
(OOP) của một thiết kế thủ tục – đối tượng đơn giản trước đó. Việc nâng cấp nhằm
minh hoạ rõ nét các nguyên tắc và mẫu thiết kế hướng đối tượng đã học, đồng thời cải
thiện độ mở rộng và bảo trì của hệ thống.
1.2. Yêu cầu chức năng
• Quản lý từ vựng: thêm, sửa, xóa từ. Mỗi từ bao gồm nghĩa tiếng Việt, ví dụ, từ
đồng nghĩa.
• Tra cứu chính xác (không phân biệt hoa - thường).
• Tra cứu gần đúng dựa trên khoảng cách Levenshtein, gợi ý các từ tương tự khi người
dùng gõ sai.
• Lịch sử tra cứu (most-recently-used, có giới hạn).
• Đánh dấu từ vựng yêu thích.
• Lưu trữ dữ liệu trong file text.
1.3. Yêu cầu phi chức năng
Đề bài yêu cầu không sử dụng các cấu trúc dữ liệu nâng cao hay thư viện có sẵn
(std::vector, std::list, std::map, std::sort, ...). Ngoài ra, phiên bản OOP còn
đặt thêm các yêu cầu nội bộ:
• Áp dụng đầy đủ 4 trụ cột OOP: đóng gói, kế thừa, đa hình, trừu tượng hoá.
• Áp dụng ít nhất 2 mẫu thiết kế (design pattern) đã học.
• Tách biệt rõ tầng dữ liệu, tầng thuật toán, tầng giao diện.
• Sử dụng exception thay cho mã trả về bool/int để báo lỗi.
3

Chương 2. PHÂN TÍCH YÊU CẦU
2.1. Phân tích chức năng theo nhóm trách nhiệm
Trên cơ sở các yêu cầu chức năng, hệ thống được phân rã thành các nhóm trách nhiệm.
Mỗi nhóm sau này sẽ tương ứng với một (hoặc một số) lớp:
Nhóm trách nhiệm Mô tả
Mô hình dữ liệu Biểudiễn1từvựng(Word)vớicáctrường: từtiếngAnh,
danh sách nghĩa, ví dụ, đồng nghĩa.
Quản lý kho từ Tập hợp các từ (Dictionary), hỗ trợ thêm/sửa/xóa và
truy vấn.
Thuật toán tìm Các chiến lược khác nhau: chính xác, gần đúng. Phải
kiếm có khả năng đổi chiến lược runtime và dễ mở rộng.
Trạng thái phụ trợ Lịch sử tra cứu (FIFO có giới hạn), danh sách yêu thích.
Bền vững hoá Lưu/tải dữ liệu xuống/từ file text. Áp dụng cho
Dictionary, History, Favorites – cùng một giao diện.
Giao diện người Hiển thị menu, nhận lệnh, hiển thị kết quả. Phải tách
dùng biệt với phần logic để có thể thay thế bằng GUI sau này.
Điều phối Khởi tạo, kết nối các thành phần, quản lý vòng đời.
2.2. Nhận xét
Phân tích trên cho thấy ba quan sát quan trọng:
• Có 3 nhóm lớp cùng cần khả năng lưu/tải file (Dictionary, History, Favorites)
⇒ nên trừu tượng hoá thành một interface IPersistable chung.
• Hệ thống có nhiều thuật toán tìm kiếm khác nhau ⇒ áp dụng Strategy Pattern,
gói mỗi thuật toán thành một lớp con của ISearchStrategy.
• Giaodiệnngườidùngcầndễthaythế⇒trừutượnghoáthànhinterfaceIUserInterface,
hiện tại có ConsoleUI, tương lai có thể có GuiUI.
4

|        | Chương |        |     | 3. THIẾT        |     | KẾ HƯỚNG |      |     | ĐỐI TƯỢNG |     |
| ------ | ------ | ------ | --- | --------------- | --- | -------- | ---- | --- | --------- | --- |
| 3.1.   | Các    | nguyên |     | tắc             | OOP | đã áp    | dụng |     |           |     |
| 3.1.1. |        | Đóng   | gói | (Encapsulation) |     |          |      |     |           |     |
Tất cả các lớp đều có trường dữ liệu private, được truy cập thông qua getter/setter công
| khai. | Ví    | dụ lớp | Word: |     |     |     |     |     |     |     |
| ----- | ----- | ------ | ----- | --- | --- | --- | --- | --- | --- | --- |
|       | class | Word   | {     |     |     |     |     |     |     |     |
1
private:
2
|     |     | std::string |     |     | english_; |     |     |     |     |     |
| --- | --- | ----------- | --- | --- | --------- | --- | --- | --- | --- | --- |
3
|     |     | DynamicArray<std::string> |     |     |     | meanings_; |     |     |     |     |
| --- | --- | ------------------------- | --- | --- | --- | ---------- | --- | --- | --- | --- |
4
|     |     | DynamicArray<std::string> |     |     |     | examples_; |     |     |     |     |
| --- | --- | ------------------------- | --- | --- | --- | ---------- | --- | --- | --- | --- |
5
| 6   |     | DynamicArray<std::string> |     |     |     | synonyms_; |     |     |     |     |
| --- | --- | ------------------------- | --- | --- | --- | ---------- | --- | --- | --- | --- |
7
public:
8
| 9   |     | const | std::string&     |     |     | getEnglish() | const |     | { return english_; | }   |
| --- | --- | ----- | ---------------- | --- | --- | ------------ | ----- | --- | ------------------ | --- |
|     |     | void  | addMeaning(const |     |     | std::string& |       | m)  | {                  |     |
10
|     |     | meanings_.push_back(m); |     |     |     |     | }   |     |     |     |
| --- | --- | ----------------------- | --- | --- | --- | --- | --- | --- | --- | --- |
// ...
11
12 };
Lưu ý quy ước đặt tên: trường private có hậu tố underscore (english_, meanings_)
– một quy ước phổ biến trong các dự án C++ chuyên nghiệp (Google Style Guide).
| 3.1.2. |                | Kế thừa | (Inheritance) |             |       |               |          |           |     |     |
| ------ | -------------- | ------- | ------------- | ----------- | ----- | ------------- | -------- | --------- | --- | --- |
| Có     | ba cây         | kế      | thừa chính    |             | trong | hệ thống:     |          |           |     |     |
|        | • IPersistable |         |               | (interface) |       | ← Dictionary, | History, | Favorites |     |     |
•
|     | ISearchStrategy |     |     | (interface) |     | ← ExactSearch, |     | ApproximateSearch |     |     |
| --- | --------------- | --- | --- | ----------- | --- | -------------- | --- | ----------------- | --- | --- |
•
|     | IUserInterface |     |     | (interface) |     | ← ConsoleUI |     |     |     |     |
| --- | -------------- | --- | --- | ----------- | --- | ----------- | --- | --- | --- | --- |
• std::exception←DictionaryException←WordNotFoundException,DuplicateWordException,
|        | FileIOException, |         |                |         | InvalidInputException |             |     |     |     |     |
| ------ | ---------------- | ------- | -------------- | ------- | --------------------- | ----------- | --- | --- | --- | --- |
| 3.1.3. |                  | Đa hình | (Polymorphism) |         |                       |             |     |     |     |     |
| Đa     | hình             | động    | được           | sử dụng | tại                   | nhiều điểm: |     |     |     |     |
• Dictionary::searchnhậnmộtconst ISearchStrategy&–cùngmộtlờigọisearch(strategy,
query, results) có thể thực thi thuật toán khác nhau tuỳ vào kiểu thực tế của
strategy.
•
Application giữ con trỏ IUserInterface* – sau này thay ConsoleUI bằng GuiUI
chỉ cần đổi một dòng new ConsoleUI(...) thành new GuiUI(...).
• Catch DictionaryException bắt được tất cả exception con nhờ đa hình của hàm
what().
5

| Báo cáo | Đồ án | – Từ  | điển | Anh-Việt      | (OOP) |     |     |     | 6   |
| ------- | ----- | ----- | ---- | ------------- | ----- | --- | --- | --- | --- |
| 3.1.4.  | Trừu  | tượng | hoá  | (Abstraction) |       |     |     |     |     |
Các interface (IPersistable, ISearchStrategy, IUserInterface) đều là abstract class
chứa pure virtual function. Client code không cần biết chi tiết cài đặt – chỉ làm việc
| thông | qua interface. |     |     |      |     |           |     |     |     |
| ----- | -------------- | --- | --- | ---- | --- | --------- | --- | --- | --- |
| 3.2.  | Hệ thống       |     | lớp | – sơ | đồ  | tổng quan |     |     |     |
Sơ đồ lớp dưới đây thể hiện toàn bộ kiến trúc của hệ thống. Các ô màu vàng nhạt là
interface, các ô màu xanh dương/xanh lá/hồng/tím là các lớp cụ thể, các mũi tên rỗng
| là quan | hệ kế | thừa, | các mũi | tên  | đứt | nét là quan | hệ   | phụ thuộc.    |     |
| ------- | ----- | ----- | ------- | ---- | --- | ----------- | ---- | ------------- | --- |
|         |       |       | [Hình   | 3.1. | Sơ  | đồ lớp tổng | quan | của hệ thống] |     |
|         |       |       | (Chèn   | file |     |             |      | vào đây)      |     |
docs/class_diagram.png
|        |          |         | Figure | 3.1: | Sơ      | đồ lớp tổng | quan | của hệ thống |     |
| ------ | -------- | ------- | ------ | ---- | ------- | ----------- | ---- | ------------ | --- |
| 3.3.   | Các mẫu  |         | thiết  | kế   | (Design | Patterns)   |      |              |     |
| 3.3.1. | Strategy | Pattern |        | –    | Chiến   | lược tìm    | kiếm |              |     |
Strategy Pattern đóng gói các thuật toán khác nhau vào các lớp riêng và cho phép thay
| đổi thuật | toán | tại thời | điểm | chạy. |     | Trong hệ thống |     | này: |     |
| --------- | ---- | -------- | ---- | ----- | --- | -------------- | --- | ---- | --- |
•
InterfaceISearchStrategyđịnhnghĩahợpđồngsearch(words, query, results).
•
ExactSearch cài đặt thuật toán tìm chính xác (case-insensitive).
• ApproximateSearch cài đặt thuật toán tìm gần đúng (Levenshtein).
• Dictionary::search nhận một const ISearchStrategy& – không phụ thuộc vào
| thuật | toán | cụ  | thể. |     |     |     |     |     |     |
| ----- | ---- | --- | ---- | --- | --- | --- | --- | --- | --- |
Lợi ích thực tế: trong tác vụ tra cứu, ConsoleUI thử ExactSearch trước, nếu không
có kết quả thì chuyển sang ApproximateSearch – đổi chiến lược động ngay trong một lần
thao tác. Khi muốn thêm thuật toán mới (PrefixSearch dùng Trie, PhoneticSearch
dùng Soundex, ...) chỉ cần tạo lớp mới kế thừa ISearchStrategy mà không sửa
Dictionary.
| 3.3.2. | Facade | Pattern |     | – Lớp | Application |     |     |     |     |
| ------ | ------ | ------- | --- | ----- | ----------- | --- | --- | --- | --- |
Facade Pattern cung cấp một giao diện thống nhất cho một tập các giao diện trong
một hệ thống con. Application gói tất cả các thành phần (Dictionary, History,
Favorites, IUserInterface)vàexposebaphươngthứcđơngiản: initialize(), run(),
shutdown().
| Nhờ | vậy main() |     | chỉ còn | khoảng |     | 15 dòng: |     |     |     |
| --- | ---------- | --- | ------- | ------ | --- | -------- | --- | --- | --- |

| Báo cáo | Đồ     | án – | Từ điển | Anh-Việt | (OOP) |     |     |     | 7   |
| ------- | ------ | ---- | ------- | -------- | ----- | --- | --- | --- | --- |
| 1 int   | main() |      | {       |          |       |     |     |     |     |
try {
2
|     |     | Application |     | app; |     |     |     |     |     |
| --- | --- | ----------- | --- | ---- | --- | --- | --- | --- | --- |
3
app.initialize();
4
| 5   |     | app.run(); |     |     |     |     |     |     |     |
| --- | --- | ---------- | --- | --- | --- | --- | --- | --- | --- |
app.shutdown();
6
|     | }   | catch | (const | DictionaryException& |     |     |     | e) { |     |
| --- | --- | ----- | ------ | -------------------- | --- | --- | --- | ---- | --- |
7
| 8   |     | std::cerr |     | <<  | "Loi: | " << e.what() |     | << "\n"; |     |
| --- | --- | --------- | --- | --- | ----- | ------------- | --- | -------- | --- |
|     |     | return    |     | 1;  |       |               |     |          |     |
9
}
10
|     | return |     | 0;  |     |     |     |     |     |     |
| --- | ------ | --- | --- | --- | --- | --- | --- | --- | --- |
11
12 }
| 3.3.3. | Template |     | Method | ngầm |     | – IPersistable |     |     |     |
| ------ | -------- | --- | ------ | ---- | --- | -------------- | --- | --- | --- |
IPersistable không phải Template Method điển hình, nhưng chia sẻ tinh thần tương
tự: ba lớp con (Dictionary, History, Favorites) đều cài đặt cùng cặp phương thức
saveToFile/loadFromFile theo cách phù hợp với cấu trúc dữ liệu nội bộ của mình.
Client code có thể duyệt một mảng IPersistable* và gọi saveToFile() đồng loạt mà
| không | cần | biết kiểu | cụ        | thể. |     |     |     |     |     |
| ----- | --- | --------- | --------- | ---- | --- | --- | --- | --- | --- |
| 3.4.  | Hệ  | thống     | Exception |      |     |     |     |     |     |
Thay vì trả về bool hoặc -1 để báo lỗi, hệ thống dùng exception. Cây kế thừa:
std::exception
| DictionaryException |     |     |     |     |     | (base, chứa | message_) |     |     |
| ------------------- | --- | --- | --- | --- | --- | ----------- | --------- | --- | --- |
WordNotFoundException
DuplicateWordException
FileIOException
InvalidInputException
Mọi exception trong hệ thống đều xuất phát từ DictionaryException, nên client có
| thể bắt | một | lần | là đủ: |     |     |     |     |     |     |
| ------- | --- | --- | ------ | --- | --- | --- | --- | --- | --- |
| try     | {   |     |        |     |     |     |     |     |     |
1
dict_.addWord(w);
2
| 3   | std::cout |        |     | << "Da                  | them | tu.\n"; |     |      |     |
| --- | --------- | ------ | --- | ----------------------- | ---- | ------- | --- | ---- | --- |
| }   | catch     | (const |     | DuplicateWordException& |      |         |     | e) { |     |
4
|     | std::cout |     |     | << "Loi: | "   | << e.what() |     | << "\n"; |     |
| --- | --------- | --- | --- | -------- | --- | ----------- | --- | -------- | --- |
5
}
6
Ưu điểm: tách rõ luồng thành công và luồng lỗi, code chính dễ đọc hơn, không phải
| kiểm | tra trị | trả | về sau | mỗi lệnh. |     |     |     |     |     |
| ---- | ------- | --- | ------ | --------- | --- | --- | --- | --- | --- |

|      | Chương |      |     | 4. TRIỂN |     | KHAI |     | CHƯƠNG |     | TRÌNH |
| ---- | ------ | ---- | --- | -------- | --- | ---- | --- | ------ | --- | ----- |
| 4.1. | Cấu    | trúc | thư | mục      |     |      |     |        |     |       |
TuDienAnhViet/
src/
|     | DynamicArray.h      |     |        |        | Template    |           | mảng        | động   |          |     |
| --- | ------------------- | --- | ------ | ------ | ----------- | --------- | ----------- | ------ | -------- | --- |
|     | Exceptions.h        |     |        |        | Hierarchy   |           | exception   |        |          |     |
|     | StringUtils.h       |     |        | / .cpp | Utility     |           | class       |        |          |     |
|     | IPersistable.h      |     |        |        | Interface   |           | persistence |        |          |     |
|     | IUserInterface.h    |     |        |        | Interface   |           | UI          |        |          |     |
|     | ISearchStrategy.h   |     |        |        | Interface   |           | chiến       | lược   | tìm kiếm |     |
|     | Word.h              | /   | .cpp   |        | Model:      |           | 1 từ        | vựng   |          |     |
|     | ExactSearch.h       |     |        | / .cpp | Strategy:   |           | tìm         | chính  | xác      |     |
|     | ApproximateSearch.h |     |        | /      | .cpp        | Strategy: |             | tìm    | gần đúng |     |
|     | Dictionary.h        |     |        | / .cpp | Repository: |           |             | kho từ |          |     |
|     | History.h           |     | / .cpp |        | Lịch        | sử        | (linked     | list)  |          |     |
|     | Favorites.h         |     | /      | .cpp   | Yêu         | thích     |             |        |          |     |
|     | ConsoleUI.h         |     | /      | .cpp   | Giao        | diện      | console     |        |          |     |
|     | Application.h       |     |        | / .cpp | Facade      |           |             |        |          |     |
main.cpp
data/
dictionary.txt
history.txt
favorites.txt
docs/
class_diagram.png
Makefile
build.bat
README.md
| 4.2.   | Mô  | tả       | chi | tiết các        | lớp |     |     |     |     |     |
| ------ | --- | -------- | --- | --------------- | --- | --- | --- | --- | --- | --- |
| 4.2.1. | Lớp | template |     | DynamicArray<T> |     |     |     |     |     |     |
Càiđặtmảngđộngkiểugeneric, đầyđủRuleofThree(copyconstructor, copyassignment,
destructor). Cơ chế nhân đôi capacity khi đầy cho push_back đạt O(1) amortized.
| 4.2.2. | Lớp | Word |     |     |     |     |     |     |     |     |
| ------ | --- | ---- | --- | --- | --- | --- | --- | --- | --- | --- |
Đại diện một từ với 4 thuộc tính private. Cài đặt operator==, operator!= (so sánh
theo english không phân biệt hoa – thường) và friend operator« (in ra ostream).
Việc dùng thay cho hàm có ưu điểm: cú pháp tự nhiên, có thể ghép
|     |     | operator« |     |     |     | print() |     |     |     |     |
| --- | --- | --------- | --- | --- | --- | ------- | --- | --- | --- | --- |
nối (std::cout « word1 « word2), tương thích với mọi std::ostream (cả console lẫn
file).
8

| Báo cáo | Đồ án    | – Từ điển | Anh-Việt | (OOP)           |     |     |     |     | 9   |
| ------- | -------- | --------- | -------- | --------------- | --- | --- | --- | --- | --- |
| 4.2.3.  | Strategy | Pattern:  |          | ISearchStrategy |     |     |     |     |     |
Đoạn code thể hiện rõ Strategy Pattern trong ConsoleUI::handleLookup:
| 1 // Bư´oc                 | 1:  | dùng | Strategy | ExactSearch   |     |     |     |     |     |
| -------------------------- | --- | ---- | -------- | ------------- | --- | --- | --- | --- | --- |
| DynamicArray<SearchResult> |     |      |          | exactResults; |     |     |     |     |     |
2
| dict_.search(exactSearch_, |     |     |     | q,  | exactResults); |     |     |     |     |
| -------------------------- | --- | --- | --- | --- | -------------- | --- | --- | --- | --- |
3
4
| if (!exactResults.empty()) |     |     |     | {   |     |     |     |     |     |
| -------------------------- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
5
|     | const | Word& | w = | dict_.at(exactResults[0].wordIndex); |     |     |     |     |     |
| --- | ----- | ----- | --- | ------------------------------------ | --- | --- | --- | --- | --- |
6
|     | std::cout |     | << w; |     |     |     |     |     |     |
| --- | --------- | --- | ----- | --- | --- | --- | --- | --- | --- |
7
| 8   | history_.add(w.getEnglish()); |     |     |     |     |     |     |     |     |
| --- | ----------------------------- | --- | --- | --- | --- | --- | --- | --- | --- |
return;
9
}
10
11
(cid:12)
| // Bư´oc | 2:  | chuyên | sang | Strategy | ApproximateSearch |     |     |     |     |
| -------- | --- | ------ | ---- | -------- | ----------------- | --- | --- | --- | --- |
12
| 13 DynamicArray<SearchResult> |     |     |     | approxResults; |                 |     |     |     |     |
| ----------------------------- | --- | --- | --- | -------------- | --------------- | --- | --- | --- | --- |
| dict_.search(approxSearch_,   |     |     |     | q,             | approxResults); |     |     |     |     |
14
Cùng một phương thức dict_.search() được gọi với hai strategy khác nhau và cho
| hai hành | vi khác        | nhau | – đây | chính là điểm | mạnh của | đa hình. |     |     |     |
| -------- | -------------- | ---- | ----- | ------------- | -------- | -------- | --- | --- | --- |
| 4.2.4.   | Lớp Dictionary |      |       |               |          |          |     |     |     |
Quản lý DynamicArray<Word>. Cung cấp các phép CRUD ném exception khi gặp lỗi:
| void | Dictionary::addWord(const |     |     |     | Word& | w) { |     |     |     |
| ---- | ------------------------- | --- | --- | --- | ----- | ---- | --- | --- | --- |
1
| 2   | if (findIndexExact(w.getEnglish()) |     |                                         |     |     | != -1) | {   |     |     |
| --- | ---------------------------------- | --- | --------------------------------------- | --- | --- | ------ | --- | --- | --- |
|     | throw                              |     | DuplicateWordException(w.getEnglish()); |     |     |        |     |     |     |
3
}
4
words_.push_back(w);
5
6 }
7
| void | Dictionary::deleteWord(const |     |     |     | std::string& |     | english) | {   |     |
| ---- | ---------------------------- | --- | --- | --- | ------------ | --- | -------- | --- | --- |
8
| 9   | int idx | =   | findIndexExact(english); |     |     |     |     |     |     |
| --- | ------- | --- | ------------------------ | --- | --- | --- | --- | --- | --- |
|     | if (idx | ==  | -1)                      | {   |     |     |     |     |     |
10
|     | throw |     | WordNotFoundException(english); |     |     |     |     |     |     |
| --- | ----- | --- | ------------------------------- | --- | --- | --- | --- | --- | --- |
11
}
12
words_.removeAt(idx);
13
}
14
| 4.2.5. | Lớp History |     | (Linked | List + Rule | of Three) |     |     |     |     |
| ------ | ----------- | --- | ------- | ----------- | --------- | --- | --- | --- | --- |
History dùng danh sách liên kết đơn, quản lý heap thông qua new/delete. Vì có pointer
member nên phải cài đặt đầy đủ Rule of Three: copy constructor, copy assignment,
destructor. Hàm copyFrom() thực hiện deep copy theo đúng thứ tự để giữ nguyên ngữ
nghĩa “most-recently-used”.
| 4.2.6. | Facade: | Application |     |     |     |     |     |     |     |
| ------ | ------- | ----------- | --- | --- | --- | --- | --- | --- | --- |

| Báo    | cáo Đồ                    | án – | Từ điển | Anh-Việt | (OOP) |     |     |     |     |     | 10  |     |
| ------ | ------------------------- | ---- | ------- | -------- | ----- | --- | --- | --- | --- | --- | --- | --- |
| 1 void | Application::initialize() |      |         |          |       | {   |     |     |     |     |     |     |
try {
2
dict_.loadFromFile(DICT_FILE);
3
|     | }   | catch | (const | FileIOException&) |     |     | {   |     |     |     |     |     |
| --- | --- | ----- | ------ | ----------------- | --- | --- | --- | --- | --- | --- | --- | --- |
4
| 5   |     | // OK: | la  |     | n đa |     | u chạy, | chưa | có filetry |     |     |     |
| --- | --- | ------ | --- | --- | ---- | --- | ------- | ---- | ---------- | --- | --- | --- |
historyloadFromFile(HIST ILE);catch(constFileIOException)tryfavoritesloadFromFile(FAV ILE);catch(constFileIOException)//Polymorphism :
|                        | .    |      |     | F                                 |      |     |     |     |     | .   |     | F   |
| ---------------------- | ---- | ---- | --- | --------------------------------- | ---- | --- | --- | --- | --- | --- | --- | --- |
| cththaybngGuiUIsaunyui |      |      |     | newConsoleUI(dicthistoryfavorites |      |     |     | ;   |     |     |     |     |
|                        |      |      |     | =                                 |      | ,   | ,   | )   |     |     |     |     |
| 4.3.                   | Định | dạng |     | file dữ                           | liệu |     |     |     |     |     |     |     |
File dictionary.txt giữ nguyên định dạng của phiên bản trước để tương thích ngược:
@english=hello
| meaning=xin    |     | chào|chào |     | hỏi          |       |     |           |     |     |     |     |     |
| -------------- | --- | --------- | --- | ------------ | ----- | --- | --------- | --- | --- | --- | --- | --- |
| example=Hello, |     |           | how | are you?|Say | hello | to  | your mom. |     |     |     |     |     |
synonym=hi|hey|greetings
@end
|             |     |     | và            |     | mỗi | dòng một | từ tiếng | Anh. |     |     |     |     |
| ----------- | --- | --- | ------------- | --- | --- | -------- | -------- | ---- | --- | --- | --- | --- |
| history.txt |     |     | favorites.txt |     |     |          |          |      |     |     |     |     |

Chương 5. KIỂM THỬ
Các tình huống kiểm thử được thực hiện trên file dữ liệu mẫu gồm 20 từ. Đặc biệt
chú trọng các test case kiểm tra cơ chế OOP: exception, polymorphism, strategy.
STTTình huống / Cơ chế Thao tác Kết quả mong KQ
kiểm tra đợi
1 ExactSearch strategy Chọn 1, nhập Hiển thị đủ nghĩa, Đạt
hoạt động hello ví dụ, đồng nghĩa
2 Operator« của Word Tra một từ Output đúng for- Đạt
mat định nghĩa
trong operator«
3 Polymorphism: chuyển Chọn 1, nhập ExactSearch fail Đạt
Strategy runtime computter (sai) → tự động chuyển
sang Approxi-
mateSearch, gợi ý
computer khoảng
cách 1
4 ApproximateSearch với Nhập beatiful Gợi ý beautiful Đạt
từ sai nặng khoảng cách 1
5 Encapsulation: không Test com- Compile lỗi private Đạt
thể truy cập trực tiếp pile: viết code member
dict_.words_ dict_.words_
trong main
6 DuplicateWordException Thêm từ hello Throw Đạt
đã tồn tại DuplicateWordException,
message rõ ràng,
chương trình không
crash
7 WordNotFoundException Sửa từ không Throw Đạt
tồn tại WordNotFoundException,
được catch và in lỗi
gọn
8 Đa hình bắt lỗi qua base main() Bắt được mọi ex- Đạt
class bắt const ception con
DictionaryException&
9 IPersistable polymor- Chọn lưu: gọi Cả 3 file được lưu, Đạt
phism saveToFile() mỗi loại theo định
trên cả 3 đối dạng riêng
tượng
10 History – linked list Tra 5 từ, sau đó Từ đó nhảy lên Đạt
MRU tra lại từ đầu đầu, không bị nhân
tiên đôi
11 History vượt giới hạn Tra 25 từ khác Chỉ giữ 20 từ gần Đạt
nhau nhất (maxSize)
11

| Báo | cáo     | Đồ án                | – Từ điển | Anh-Việt |     | (OOP)   |          |       |       |        |     | 12  |
| --- | ------- | -------------------- | --------- | -------- | --- | ------- | -------- | ----- | ----- | ------ | --- | --- |
|     | STTTình |                      | huống     | / Cơ     | chế | Thao    | tác      | Kết   | quả   | mong   | KQ  |     |
|     |         | kiểm                 | tra       |          |     |         |          | đợi   |       |        |     |     |
|     | 12      | RuleofThree–copyHis- |           |          |     | Tạo     | bản sao  | h1    | không | bị ảnh | Đạt |     |
|     |         | tory                 |           |          |     | History | h2 =     | hưởng | (deep | copy)  |     |     |
|     |         |                      |           |          |     | h1, sửa | h2, kiểm |       |       |        |     |     |
|     |         |                      |           |          |     | tra h1  |          |       |       |        |     |     |
13 Favorites – encapsulation Thêm study vào study tự động biến Đạt
|     |     | kiểm | soát thêm/xóa |     |     | yêu thích, | xóa     | mất | khỏi | yêu thích |     |     |
| --- | --- | ---- | ------------- | --- | --- | ---------- | ------- | --- | ---- | --------- | --- | --- |
|     |     |      |               |     |     | study      | khỏi từ |     |      |           |     |     |
điển
14 Lưu/tải – bền vững hoá Thay đổi, thoát Mọi thay đổi được Đạt
|     |     |        |             |       |     | chương      | trình,   | giữ     | nguyên |           |     |     |
| --- | --- | ------ | ----------- | ----- | --- | ----------- | -------- | ------- | ------ | --------- | --- | --- |
|     |     |        |             |       |     | mở lại      |          |         |        |           |     |     |
|     | 15  | Const  | correctness |       |     | Cố          | gọi      | Compile |        | báo lỗi – | Đạt |     |
|     |     |        |             |       |     | addWord()   |          | tham    | chiếu  | const     |     |     |
|     |     |        |             |       |     | trên        | const    | không   | thể    | gọi non-  |     |     |
|     |     |        |             |       |     | Dictionary& |          | const   | method |           |     |     |
|     | 16  | RAII   | – giải      | phóng | tài | Thoát       | chương   | Không   | rò     | rỉ bộ nhớ | Đạt |     |
|     |     | nguyên |             |       |     | trình,      | kiểm tra |         |        |           |     |     |
valgrind
17 Trachuỗirỗng/menusai Nhập rỗng, chọn Báo lỗi gọn, không Đạt
|     |     |     |     |     |     | 99  |     | crash |     |     |     |     |
| --- | --- | --- | --- | --- | --- | --- | --- | ----- | --- | --- | --- | --- |
Ghi chú: hình ảnh chụp màn hình thực tế của từng test case sẽ được chèn vào báo cáo
| in  | để minh | hoạ. |     |     |     |     |     |     |     |     |     |     |
| --- | ------- | ---- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |

| Chương | 6. TỔNG |     | KẾT |     | CÁC | KỸ  | THUẬT |     |     | ĐÃ VẬN |
| ------ | ------- | --- | --- | --- | --- | --- | ----- | --- | --- | ------ |
DỤNG
| 6.1. Kỹ | thuật về | thiết | kế       | hướng | đối | tượng | (OOP) |     |     |     |
| ------- | -------- | ----- | -------- | ----- | --- | ----- | ----- | --- | --- | --- |
| Kỹ      | thuật    |       | Vận dụng | tại   |     |       |       |     |     |     |
Encapsulation Tất cả các lớp: trường private + getter/setter công
|              |     |     | khai. Quy          | ước      | hậu | tố underscore.   |       |                   |            |            |
| ------------ | --- | --- | ------------------ | -------- | --- | ---------------- | ----- | ----------------- | ---------- | ---------- |
| Inheritance  |     |     | 3 cây              | kế thừa: |     | IPersistable,    |       | ISearchStrategy,  |            |            |
|              |     |     | IUserInterface;    |          |     | cộng thêm        | hệ    | thống             | Exception. |            |
| Polymorphism |     |     | Pure               | virtual  |     | function         | trong |                   | các        | interface. |
|              |     |     | Dictionary::search |          |     | nhận             | const | ISearchStrategy&, |            |            |
|              |     |     | Application        |          | giữ | IUserInterface*. |       |                   |            |            |
Abstraction Các interface chỉ định nghĩa hợp đồng, ẩn cài đặt cụ thể.
| Operator | overload- |     | Word::operator==, |     |     | friend | operator« |     |     |     |
| -------- | --------- | --- | ----------------- | --- | --- | ------ | --------- | --- | --- | --- |
ing
Template (generic) DynamicArray<T> dùng được cho mọi kiểu (string,
|     |     |     | Word, | SearchResult, |     | ...) |     |     |     |     |
| --- | --- | --- | ----- | ------------- | --- | ---- | --- | --- | --- | --- |
Const correctness Mọi getter, mọi tham chiếu read-only đều là const.
|     |     |     | Đảm bảo | invariant |     | của object. |     |     |     |     |
| --- | --- | --- | ------- | --------- | --- | ----------- | --- | --- | --- | --- |
Rule of Three History (linked list quản lý heap): copy ctor + copy
|      |     |     | assign             | + dtor | đầy | đủ.            |          |       |       |          |
| ---- | --- | --- | ------------------ | ------ | --- | -------------- | -------- | ----- | ----- | -------- |
| RAII |     |     | Mọi tài            | nguyên | cấp | phát           | đều giải | phóng | trong | destruc- |
|      |     |     | tor: DynamicArray, |        |     | History::Node, |          |       | bảng  | DP trong |
Levenshtein.
Exception handling Thay return code bằng exception, cây kế thừa từ
|          |           |     | std::exception, |     |           | polymorphism |     | trong | catch. |     |
| -------- | --------- | --- | --------------- | --- | --------- | ------------ | --- | ----- | ------ | --- |
| 6.2. Các | mẫu thiết | kế  | (Design         |     | Patterns) |              |     |       |        |     |
• Strategy Pattern: ISearchStrategy + ExactSearch, ApproximateSearch.
| • Facade | Pattern: | Application |     | gói | toàn | bộ hệ thống |     | con. |     |     |
| -------- | -------- | ----------- | --- | --- | ---- | ----------- | --- | ---- | --- | --- |
• DependencyInjection: ConsoleUIvàApplicationnhậnthamchiếuDictionary/History/Favorites
| thay | vì tự tạo. |     |     |     |     |     |     |     |     |     |
| ---- | ---------- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
•
Single Responsibility Principle: mỗilớpmộttráchnhiệm. UI/data/algorithm
| tách    | 3 layer. |       |      |     |     |      |     |      |     |     |
| ------- | -------- | ----- | ---- | --- | --- | ---- | --- | ---- | --- | --- |
| 6.3. Kỹ | thuật về | thuật | toán | và  | cấu | trúc | dữ  | liệu |     |     |
•
Quy hoạch động: Levenshtein distance với bảng DP 2 chiều tự cấp phát.
13

| Báo | cáo | Đồ án | – Từ | điển Anh-Việt |     | (OOP) |     |     |     |     |     |     | 14  |
| --- | --- | ----- | ---- | ------------- | --- | ----- | --- | --- | --- | --- | --- | --- | --- |
•
|     | Quicksort |     | tự cài | cho | SearchResult. |     |     |     |     |     |     |     |     |
| --- | --------- | --- | ------ | --- | ------------- | --- | --- | --- | --- | --- | --- | --- | --- |
•
|     | Mảng   | động | (template) |         | – thay | vector. |         |        |        |     |     |     |     |
| --- | ------ | ---- | ---------- | ------- | ------ | ------- | ------- | ------ | ------ | --- | --- | --- | --- |
|     | • Danh | sách | liên       | kết đơn | với    | FIFO    | bounded | – thay | deque. |     |     |     |     |
• Pruning sớm theo chênh lệch độ dài trong ApproximateSearch.
| 6.4. | So   | sánh | với | phiên | bản     |           | trước nâng |     | cấp        |         |          |            |     |
| ---- | ---- | ---- | --- | ----- | ------- | --------- | ---------- | --- | ---------- | ------- | -------- | ---------- | --- |
|      | Khía | cạnh |     |       | Phiên   | bản trước |            |     | Phiên      | bản OOP |          |            |     |
|      | Word |      |     |       | struct, | trường    | public     |     | class,     | private |          | + get-     |     |
|      |      |      |     |       |         |           |            |     | ter/setter | +       | operator |            |     |
|      | Tìm  | kiếm |     |       | Hai hàm | riêng     |            |     | / Strategy | Pattern |          | – đổi run- |     |
findExact
|     |         |     |     |     | findApproximate |      |        |          | time          |           |               |      |     |
| --- | ------- | --- | --- | --- | --------------- | ---- | ------ | -------- | ------------- | --------- | ------------- | ---- | --- |
|     | Lưu/tải |     |     |     | Namespace       |      | FileIO | với free | Interface     |           | IPersistable, |      |     |
|     |         |     |     |     | function        |      |        |          | các lớp       | tự lo     |               |      |     |
|     | Báo     | lỗi |     |     | Trả về          | bool | / -1   |          | Exception     | hierarchy |               |      |     |
|     | UI      |     |     |     | Code            | menu | nằm    | trong    | Lớp ConsoleUI |           | tách          | biệt |     |
main.cpp
|      | main() |       |     |      | ∼270      | dòng       |      |     | ∼20 dòng | (Facade)        |     |        |     |
| ---- | ------ | ----- | --- | ---- | --------- | ---------- | ---- | --- | -------- | --------------- | --- | ------ | --- |
|      | Mở     | rộng  | UI  |      | Phải viết | lại        | main |     | Chỉ thêm | lớp             | mới | imple- |     |
|      |        |       |     |      |           |            |      |     | ment     | IUserInterface  |     |        |     |
|      | Mở     | rộng  |     | tìm  | Phải sửa  | Dictionary |      |     | Chỉ thêm | lớp             | mới | imple- |     |
|      | kiếm   |       |     |      |           |            |      |     | ment     | ISearchStrategy |     |        |     |
| 6.5. | Kỹ     | thuật |     | kiểm | thử       |            |      |     |          |                 |     |        |     |
•
Phân nhóm test case theo cơ chế OOP cần kiểm tra (exception, polymorphism,
|     | encapsulation, |     |     | ...). |     |     |     |     |     |     |     |     |     |
| --- | -------------- | --- | --- | ----- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
• Test biên: chuỗi rỗng, lựa chọn ngoài phạm vi, vượt giới hạn lịch sử.
• Test tích hợp: thoát – mở lại để kiểm tra tính toàn vẹn dữ liệu.
• Test ngữ pháp: thử biên dịch các đoạn code vi phạm const/private để xác nhận
|     | encapsulation |     |     | thực | sự hoạt | động. |     |     |     |     |     |     |     |
| --- | ------------- | --- | --- | ---- | ------- | ----- | --- | --- | --- | --- | --- | --- | --- |

| Chương |     |     | A.  | MÃ  | NGUỒN |     |     | CÁC | THÀNH |     | PHẦN |     |
| ------ | --- | --- | --- | --- | ----- | --- | --- | --- | ----- | --- | ---- | --- |
CHÍNH
| A.1. | Hàm | main |     |     |     |     |     |     |     |     |     |     |
| ---- | --- | ---- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
1 //
=====================================================================
| //  | Tu  | Dien | Anh-Viet |     | (Phien | ban | OOP) |     |     |     |     |     |
| --- | --- | ---- | -------- | --- | ------ | --- | ---- | --- | --- | --- | --- | --- |
2
| //  | Mon: | Ky  | Thuat | Lap | Trinh |     |     |     |     |     |     |     |
| --- | ---- | --- | ----- | --- | ----- | --- | --- | --- | --- | --- | --- | --- |
3
4 //
// File main: chi tao Application va goi run(). Toan bo logic
5
duoc
6 // uy quyen cho cac doi tuong nghiep vu (Single Responsibility
Principle).
//
7
=====================================================================
8
| #ifdef |     | _WIN32 |     |     |     |     |     |     |     |     |     |     |
| ------ | --- | ------ | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
9
| #include |     | <windows.h> |     |     |     |     |     |     |     |     |     |     |
| -------- | --- | ----------- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
10
11 #endif
12
| #include |     | <iostream> |     |     |     |     |     |     |     |     |     |     |
| -------- | --- | ---------- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
13
| #include |     | "Application.h" |     |     |     |     |     |     |     |     |     |     |
| -------- | --- | --------------- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
14
| #include |     | "Exceptions.h" |     |     |     |     |     |     |     |     |     |     |
| -------- | --- | -------------- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
15
16
| int | main() |     | {   |     |     |     |     |     |     |     |     |     |
| --- | ------ | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
17
| 18 #ifdef |     | _WIN32 |     |     |     |     |     |     |     |     |     |     |
| --------- | --- | ------ | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
SetConsoleOutputCP(65001);
19
SetConsoleCP(65001);
20
21 #endif
22
try {
23
|     |     | Application |     |     | app; |     |     |     |     |     |     |     |
| --- | --- | ----------- | --- | --- | ---- | --- | --- | --- | --- | --- | --- | --- |
24
| 25  |     | app.initialize(); |     |     |     |     |     |     |     |     |     |     |
| --- | --- | ----------------- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
app.run();
26
app.shutdown();
27
| 28  | }   | catch     | (const |     | DictionaryException& |     |        |     | e)          | {   |          |     |
| --- | --- | --------- | ------ | --- | -------------------- | --- | ------ | --- | ----------- | --- | -------- | --- |
|     |     | std::cerr |        | <<  | "Loi                 | he  | thong: | "   | << e.what() |     | << "\n"; |     |
29
|     |     | return |     | 1;  |     |     |     |     |     |     |     |     |
| --- | --- | ------ | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
30
|     | }   | catch | (const |     | std::exception& |     |     | e)  | {   |     |     |     |
| --- | --- | ----- | ------ | --- | --------------- | --- | --- | --- | --- | --- | --- | --- |
31
| 32  |     | std::cerr |     | <<  | "Loi | khong | xac | dinh: |     | " << e.what() |     | <<  |
| --- | --- | --------- | --- | --- | ---- | ----- | --- | ----- | --- | ------------- | --- | --- |
"\n";
|     |     | return |     | 2;  |     |     |     |     |     |     |     |     |
| --- | --- | ------ | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
33
| 34  | }   |     |     |     |     |     |     |     |     |     |     |     |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
35
|     | return |     | 0;  |     |     |     |     |     |     |     |     |     |
| --- | ------ | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
36
}
37
15

| Báo cáo | Đồ án – Từ          | điển Anh-Việt |     | (OOP) |     |     |     |     | 16  |
| ------- | ------------------- | ------------- | --- | ----- | --- | --- | --- | --- | --- |
| A.2.    | Facade: Application |               |     |       |     |     |     |     |     |
| A.2.1.  | Application.h       |               |     |       |     |     |     |     |     |
| #ifndef | APPLICATION_H       |               |     |       |     |     |     |     |     |
1
| #define | APPLICATION_H |     |     |     |     |     |     |     |     |
| ------- | ------------- | --- | --- | --- | --- | --- | --- | --- | --- |
2
3
| #include | "Dictionary.h" |     |     |     |     |     |     |     |     |
| -------- | -------------- | --- | --- | --- | --- | --- | --- | --- | --- |
4
| #include | "History.h" |     |     |     |     |     |     |     |     |
| -------- | ----------- | --- | --- | --- | --- | --- | --- | --- | --- |
5
| 6 #include | "Favorites.h"      |     |     |     |     |     |     |     |     |
| ---------- | ------------------ | --- | --- | --- | --- | --- | --- | --- | --- |
| #include   | "IUserInterface.h" |     |     |     |     |     |     |     |     |
7
8
//
9
=====================================================================
| //  | Application | -   | Facade | Pattern |     |     |     |     |     |
| --- | ----------- | --- | ------ | ------- | --- | --- | --- | --- | --- |
10
//
11
12 // Dong vai tro mat tien: gom tat ca thanh phan cua he thong
|     | va expose |     |     |     |     |     |     |     |     |
| --- | --------- | --- | --- | --- | --- | --- | --- | --- | --- |
// mot API don gian (initialize + run + shutdown) cho main().
13
//
14
| 15 // | Quan ly vong  | doi | cua:     |     |           |     |              |     |     |
| ----- | ------------- | --- | -------- | --- | --------- | --- | ------------ | --- | --- |
| //    | - Dictionary, |     | History, |     | Favorites |     | (data layer) |     |     |
16
| //  | - IUserInterface |     |     | (presentation |     |     | layer) |     |     |
| --- | ---------------- | --- | --- | ------------- | --- | --- | ------ | --- | --- |
17
18 //
// Su dung composition: app KHONG inherit cac doi tuong tren,
19
|     | ma chua chung. |     |     |     |     |     |     |     |     |
| --- | -------------- | --- | --- | --- | --- | --- | --- | --- | --- |
// Sau nay neu doi UI thanh GUI, chi can sua Application, main
20
|     | giu nguyen. |     |     |     |     |     |     |     |     |
| --- | ----------- | --- | --- | --- | --- | --- | --- | --- | --- |
//
21
=====================================================================
22
| class | Application |     | {   |     |     |     |     |     |     |
| ----- | ----------- | --- | --- | --- | --- | --- | --- | --- | --- |
23
private:
24
|     | Dictionary | dict_; |     |     |     |     |     |     |     |
| --- | ---------- | ------ | --- | --- | --- | --- | --- | --- | --- |
25
|     | History history_; |     |     |     |     |     |     |     |     |
| --- | ----------------- | --- | --- | --- | --- | --- | --- | --- | --- |
26
|     | Favorites | favorites_; |     |     |     |     |     |     |     |
| --- | --------- | ----------- | --- | --- | --- | --- | --- | --- | --- |
27
|     | IUserInterface* |     | ui_; | //  | pointer |     | de cho phep | polymorphism |     |
| --- | --------------- | --- | ---- | --- | ------- | --- | ----------- | ------------ | --- |
28
29
|     | static const |     | int HISTORY_MAX_SIZE |     |     |     | = 20; |     |     |
| --- | ------------ | --- | -------------------- | --- | --- | --- | ----- | --- | --- |
30
31
32 public:
Application();
33
~Application();
34
35
| 36  | void initialize(); |     |     |     |     |     |     |     |     |
| --- | ------------------ | --- | --- | --- | --- | --- | --- | --- | --- |
void run();
37
void shutdown();
38
39
private:
40
|     | Application(const |     |     | Application&); |     |     |     |     |     |
| --- | ----------------- | --- | --- | -------------- | --- | --- | --- | --- | --- |
41
|     | Application& |     | operator=(const |     |     | Application&); |     |     |     |
| --- | ------------ | --- | --------------- | --- | --- | -------------- | --- | --- | --- |
42

| Báo cáo | Đồ  | án – | Từ điển | Anh-Việt | (OOP) |     |     |     |     |     |     | 17  |
| ------- | --- | ---- | ------- | -------- | ----- | --- | --- | --- | --- | --- | --- | --- |
};
43
44
| #endif |     | //  | APPLICATION_H |     |     |     |     |     |     |     |     |     |
| ------ | --- | --- | ------------- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
45
| A.2.2.   | Application.cpp |                 |     |     |     |     |     |     |     |     |     |     |
| -------- | --------------- | --------------- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| #include |                 | "Application.h" |     |     |     |     |     |     |     |     |     |     |
1
| #include |     | "ConsoleUI.h" |     |     |     |     |     |     |     |     |     |     |
| -------- | --- | ------------- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
2
| 3 #include |     | "Exceptions.h" |     |     |     |     |     |     |     |     |     |     |
| ---------- | --- | -------------- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| #include   |     | <iostream>     |     |     |     |     |     |     |     |     |     |     |
4
5
| static |     | const |     | std::string | DICT_FILE |     | = "data/dictionary.txt"; |     |     |     |     |     |
| ------ | --- | ----- | --- | ----------- | --------- | --- | ------------------------ | --- | --- | --- | --- | --- |
6
| 7 static |     | const |     | std::string | HIST_FILE |     | = "data/history.txt";   |     |     |     |     |     |
| -------- | --- | ----- | --- | ----------- | --------- | --- | ----------------------- | --- | --- | --- | --- | --- |
| static   |     | const |     | std::string | FAV_FILE  |     | = "data/favorites.txt"; |     |     |     |     |     |
8
9
10 Application::Application()
|     | :   | history_(HISTORY_MAX_SIZE), |     |     |     |     | ui_(nullptr) |     | {}  |     |     |     |
| --- | --- | --------------------------- | --- | --- | --- | --- | ------------ | --- | --- | --- | --- | --- |
11
12
| Application::~Application() |     |     |     |     |     | {   |     |     |     |     |     |     |
| --------------------------- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
13
| 14  | delete |     | ui_; |     |     |     |     |     |     |     |     |     |
| --- | ------ | --- | ---- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
}
15
16
| 17 void | Application::initialize() |     |     |     |     | {   |     |     |     |     |     |     |
| ------- | ------------------------- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
try {
18
dict_.loadFromFile(DICT_FILE);
19
| 20  |     | std::cout |     | << "Da       | tai | " << | dict_.size() |     | <<  | " tu | tu \"" |     |
| --- | --- | --------- | --- | ------------ | --- | ---- | ------------ | --- | --- | ---- | ------ | --- |
|     |     |           |     | << DICT_FILE |     | <<   | "\".\n";     |     |     |      |        |     |
21
|     | }   | catch | (const | FileIOException&) |     |     | {   |     |     |     |     |     |
| --- | --- | ----- | ------ | ----------------- | --- | --- | --- | --- | --- | --- | --- | --- |
22
|     |     | std::cout |     | << "Khong |     | tim | thay \"" | <<  | DICT_FILE |     |     |     |
| --- | --- | --------- | --- | --------- | --- | --- | -------- | --- | --------- | --- | --- | --- |
23
| 24  |     |     |     | << "\". |     | Bat dau | voi tu | dien | rong.\n"; |     |     |     |
| --- | --- | --- | --- | ------- | --- | ------- | ------ | ---- | --------- | --- | --- | --- |
}
25
26
| 27  | try   | {   | history_.loadFromFile(HIST_FILE); |                   |     |     |     |     | }   |     |     |     |
| --- | ----- | --- | --------------------------------- | ----------------- | --- | --- | --- | --- | --- | --- | --- | --- |
|     | catch |     | (const                            | FileIOException&) |     |     | {}  |     |     |     |     |     |
28
|     | try | {   | favorites_.loadFromFile(FAV_FILE); |     |     |     |     |     | }   |     |     |     |
| --- | --- | --- | ---------------------------------- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
29
|     | catch |     | (const | FileIOException&) |     |     | {}  |     |     |     |     |     |
| --- | ----- | --- | ------ | ----------------- | --- | --- | --- | --- | --- | --- | --- | --- |
30
31
|     | ui_ | =   | new | ConsoleUI(dict_, |     | history_, |     | favorites_); |     |     |     |     |
| --- | --- | --- | --- | ---------------- | --- | --------- | --- | ------------ | --- | --- | --- | --- |
32
}
33
34
| void | Application::run() |     |     |     | {   |     |     |     |     |     |     |     |
| ---- | ------------------ | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
35
|     | if  | (ui_ | ==  | nullptr) | {   |     |     |     |     |     |     |     |
| --- | --- | ---- | --- | -------- | --- | --- | --- | --- | --- | --- | --- | --- |
36
|     |     | throw |     | DictionaryException("Application |     |     |     |     | chua | duoc |     |     |
| --- | --- | ----- | --- | -------------------------------- | --- | --- | --- | --- | ---- | ---- | --- | --- |
37
initialize()");
}
38
ui_->run();
39
40 }
41
| void | Application::shutdown() |     |     |     |     | {   |     |     |     |     |     |     |
| ---- | ----------------------- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
42
|     | //  | Cac | doi | tuong tu | giai | phong | qua | destructor |     | (RAII) |     |     |
| --- | --- | --- | --- | -------- | ---- | ----- | --- | ---------- | --- | ------ | --- | --- |
43
44 }

Báo cáo Đồ án – Từ điển Anh-Việt (OOP) 18
A.3. Hệ thống Exception
#ifndef EXCEPTIONS_H
1
#define EXCEPTIONS_H
2
3
#include <exception>
4
#include <string>
5
6
//
7
=====================================================================
// He thong Exception cho ung dung Tu Dien
8
//
9
// Cay ke thua:
10
// std::exception
11
// DictionaryException (base)
12
// WordNotFoundException
13
// DuplicateWordException
14
// FileIOException
15
// InvalidInputException
16
//
17
=====================================================================
18
class DictionaryException : public std::exception {
19
protected:
20
std::string message_;
21
public:
22
explicit DictionaryException(const std::string& msg) :
23
message_(msg) {}
virtual ~DictionaryException() throw() {}
24
virtual const char* what() const throw() {
25
return message_.c_str();
26
}
27
};
28
29
class WordNotFoundException : public DictionaryException {
30
public:
31
explicit WordNotFoundException(const std::string& word)
32
: DictionaryException("Khong tim thay tu: \"" + word +
33
"\"") {}
};
34
35
class DuplicateWordException : public DictionaryException {
36
public:
37
explicit DuplicateWordException(const std::string& word)
38
: DictionaryException("Tu da ton tai: \"" + word +
39
"\"") {}
};
40
41

| Báo cáo | Đồ  | án –            | Từ điển | Anh-Việt | (OOP)    |     |                     |     |     |     |     |     | 19  |
| ------- | --- | --------------- | ------- | -------- | -------- | --- | ------------------- | --- | --- | --- | --- | --- | --- |
| class   |     | FileIOException |         |          | : public |     | DictionaryException |     |     |     | {   |     |     |
42
43 public:
|     | explicit |     |     | FileIOException(const |     |     |     | std::string& |     | filename) |     |     |     |
| --- | -------- | --- | --- | --------------------- | --- | --- | --- | ------------ | --- | --------- | --- | --- | --- |
44
|     |     | :   | DictionaryException("Loi |     |     |     |     | truy | cap | file: | \"" + |     |     |
| --- | --- | --- | ------------------------ | --- | --- | --- | --- | ---- | --- | ----- | ----- | --- | --- |
45
|     |     |     | filename |     | + "\"") | {}  |     |     |     |     |     |     |     |
| --- | --- | --- | -------- | --- | ------- | --- | --- | --- | --- | --- | --- | --- | --- |
};
46
47
| class |     | InvalidInputException |     |     |     | : public |     | DictionaryException |     |     |     | {   |     |
| ----- | --- | --------------------- | --- | --- | --- | -------- | --- | ------------------- | --- | --- | --- | --- | --- |
48
49 public:
|     | explicit |     |     | InvalidInputException(const |     |     |     |     | std::string& |     | msg) |     |     |
| --- | -------- | --- | --- | --------------------------- | --- | --- | --- | --- | ------------ | --- | ---- | --- | --- |
50
|     |     | :   | DictionaryException("Du |     |     |     | lieu |     | nhap | khong | hop le: | "   | +   |
| --- | --- | --- | ----------------------- | --- | --- | --- | ---- | --- | ---- | ----- | ------- | --- | --- |
51
|     |     |     | msg) | {}  |     |     |     |     |     |     |     |     |     |
| --- | --- | --- | ---- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
};
52
53
| #endif |     | //  | EXCEPTIONS_H |     |     |     |     |     |     |     |     |     |     |
| ------ | --- | --- | ------------ | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
54
| A.4.    | Interface |                 | IPersistable |     |     |     |     |     |     |     |     |     |     |
| ------- | --------- | --------------- | ------------ | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| #ifndef |           | I_PERSISTABLE_H |              |     |     |     |     |     |     |     |     |     |     |
1
| #define |     | I_PERSISTABLE_H |     |     |     |     |     |     |     |     |     |     |     |
| ------- | --- | --------------- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
2
3
| #include |     | <string> |     |     |     |     |     |     |     |     |     |     |     |
| -------- | --- | -------- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
4
5
//
6
=====================================================================
| //  | IPersistable |     |     | -   | Interface | cho | cac | doi | tuong | co  | the luu/tai |     |     |
| --- | ------------ | --- | --- | --- | --------- | --- | --- | --- | ----- | --- | ----------- | --- | --- |
7
|     | tu  | file |     |     |     |     |     |     |     |     |     |     |     |
| --- | --- | ---- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
8 //
// Abstract base class (pure virtual), khong the instantiate.
9
| //  | Bat | ky  | lop | nao | can persistence |     | deu | phai | override |     | 2 phuong |     |     |
| --- | --- | --- | --- | --- | --------------- | --- | --- | ---- | -------- | --- | -------- | --- | --- |
10
thuc:
| 11 // | -   | saveToFile():   |     |     | ghi | du lieu | xuong |         | file |     |     |     |     |
| ----- | --- | --------------- | --- | --- | --- | ------- | ----- | ------- | ---- | --- | --- | --- | --- |
| //    | -   | loadFromFile(): |     |     | doc | du lieu |       | tu file |      |     |     |     |     |
12
//
13
14 // Hien tai duoc implement boi: Dictionary, History, Favorites.
//
15
=====================================================================
16
| 17 class |     | IPersistable |     |     | {   |     |     |     |     |     |     |     |     |
| -------- | --- | ------------ | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
public:
18
|     | virtual |     | ~IPersistable() |     |     | {}  |     |     |     |     |     |     |     |
| --- | ------- | --- | --------------- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
19
20
|     | virtual |     | void |     | saveToFile(const |     | std::string& |     |     | filename) |     | const |     |
| --- | ------- | --- | ---- | --- | ---------------- | --- | ------------ | --- | --- | --------- | --- | ----- | --- |
21
= 0;
|     | virtual |     | void |     | loadFromFile(const |     |     | std::string& |     |     | filename) |     | = 0; |
| --- | ------- | --- | ---- | --- | ------------------ | --- | --- | ------------ | --- | --- | --------- | --- | ---- |
22
23 };
24
| #endif |     | //  | I_PERSISTABLE_H |     |     |     |     |     |     |     |     |     |     |
| ------ | --- | --- | --------------- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
25

| Báo cáo | Đồ án –             | Từ điển | Anh-Việt |     | (OOP)           |     |     |     |     |     |     | 20  |
| ------- | ------------------- | ------- | -------- | --- | --------------- | --- | --- | --- | --- | --- | --- | --- |
| A.5.    | Strategy            | Pattern |          | –   | ISearchStrategy |     |     |     |     |     |     |     |
| #ifndef | I_SEARCH_STRATEGY_H |         |          |     |                 |     |     |     |     |     |     |     |
1
| #define | I_SEARCH_STRATEGY_H |     |     |     |     |     |     |     |     |     |     |     |
| ------- | ------------------- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
2
3
| #include | <string> |     |     |     |     |     |     |     |     |     |     |     |
| -------- | -------- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
4
| #include | "DynamicArray.h" |     |     |     |     |     |     |     |     |     |     |     |
| -------- | ---------------- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
5
| #include | "Word.h" |     |     |     |     |     |     |     |     |     |     |     |
| -------- | -------- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
6
7
//
8
=====================================================================
| 9 // | ISearchStrategy |     |          | - Interface |     | cho | thuat | toan | tim | kiem |     |     |
| ---- | --------------- | --- | -------- | ----------- | --- | --- | ----- | ---- | --- | ---- | --- | --- |
|      | (Strategy       |     | Pattern) |             |     |     |       |      |     |      |     |     |
//
10
| //  | Cac implementation |     |     | hien | co: |     |     |     |     |     |     |     |
| --- | ------------------ | --- | --- | ---- | --- | --- | --- | --- | --- | --- | --- | --- |
11
| 12 // | - ExactSearch       |     |     |     | : tim | chinh | xac  | (case-insensitive) |     |     |           |     |
| ----- | ------------------- | --- | --- | --- | ----- | ----- | ---- | ------------------ | --- | --- | --------- | --- |
| //    | - ApproximateSearch |     |     |     | : tim | gan   | dung | (Levenshtein       |     |     | distance) |     |
13
//
14
| 15 // | Co the         | de  | dang them |     | moi:     |      |     |        |     |     |     |     |
| ----- | -------------- | --- | --------- | --- | -------- | ---- | --- | ------ | --- | --- | --- | --- |
| //    | - PrefixSearch |     |           | :   | tim theo | tien | to  | (Trie) |     |     |     |     |
16
| //  | - PhoneticSearch: |     |     |     | tim theo | phat | am  | (Soundex) |     |     |     |     |
| --- | ----------------- | --- | --- | --- | -------- | ---- | --- | --------- | --- | --- | --- | --- |
17
//
18
=====================================================================
19
| struct | SearchResult |     |     | {   |     |     |     |     |     |     |     |     |
| ------ | ------------ | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
20
| 21  | int wordIndex; |     |     |     |     |     |     |     |     |     |     |     |
| --- | -------------- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
int score;
22
23
|     | SearchResult() |     |     | : wordIndex(-1), |     |     | score(0) |     | {}  |     |     |     |
| --- | -------------- | --- | --- | ---------------- | --- | --- | -------- | --- | --- | --- | --- | --- |
24
25 SearchResult(int idx, int s) : wordIndex(idx), score(s) {}
};
26
27
| 28 class | ISearchStrategy |     |     | {   |     |     |     |     |     |     |     |     |
| -------- | --------------- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
public:
29
|     | virtual | ~ISearchStrategy() |     |     |     | {}  |     |     |     |     |     |     |
| --- | ------- | ------------------ | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
30
31
|     | virtual | void | search(const |     |     | DynamicArray<Word>& |     |     |     | words, |     |     |
| --- | ------- | ---- | ------------ | --- | --- | ------------------- | --- | --- | --- | ------ | --- | --- |
32
|     |     |     |     |     | const | std::string& |     |     | query, |     |     |     |
| --- | --- | --- | --- | --- | ----- | ------------ | --- | --- | ------ | --- | --- | --- |
33
|     |     |     |     |     | DynamicArray<SearchResult>& |     |     |     |     |     | results) |     |
| --- | --- | --- | --- | --- | --------------------------- | --- | --- | --- | --- | --- | -------- | --- |
34
|     |     |     |     |     | const |     | = 0; |     |     |     |     |     |
| --- | --- | --- | --- | --- | ----- | --- | ---- | --- | --- | --- | --- | --- |
};
35
36
| 37 #endif | //                             | I_SEARCH_STRATEGY_H |     |         |     |     |              |     |     |           |     |     |
| --------- | ------------------------------ | ------------------- | --- | ------- | --- | --- | ------------ | --- | --- | --------- | --- | --- |
| A.6.      | Dictionary.cpp                 |                     |     | (trích) |     |     |              |     |     |           |     |     |
| void      | Dictionary::loadFromFile(const |                     |     |         |     |     | std::string& |     |     | filename) |     | {   |
1
|     | std::ifstream |     | fin(filename.c_str()); |     |     |     |     |     |     |     |     |     |
| --- | ------------- | --- | ---------------------- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
2
| 3   | if (!fin.is_open()) |     |     |     | {   |     |     |     |     |     |     |     |
| --- | ------------------- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |

| Báo cáo | Đồ  | án –  | Từ điển | Anh-Việt                   |     | (OOP) |     |     |     |     |     |     | 21  |
| ------- | --- | ----- | ------- | -------------------------- | --- | ----- | --- | --- | --- | --- | --- | --- | --- |
|         |     | throw |         | FileIOException(filename); |     |       |     |     |     |     |     |     |     |
4
| 5   | }   |     |     |     |     |     |     |     |     |     |     |     |     |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
6
|     | std::string |     |     | line; |     |     |     |     |     |     |     |     |     |
| --- | ----------- | --- | --- | ----- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
7
| 8   | Word | current; |     |          |     |     |     |     |     |     |     |     |     |
| --- | ---- | -------- | --- | -------- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
|     | bool | inWord   |     | = false; |     |     |     |     |     |     |     |     |     |
9
10
|     | while |     | (std::getline(fin, |     |     |     | line)) |     | {   |     |     |     |     |
| --- | ----- | --- | ------------------ | --- | --- | --- | ------ | --- | --- | --- | --- | --- | --- |
11
| 12  |     | StringUtils::trim(line); |                |     |     |           |     |     |     |     |     |     |     |
| --- | --- | ------------------------ | -------------- | --- | --- | --------- | --- | --- | --- | --- | --- | --- | --- |
|     |     | if                       | (line.empty()) |     |     | continue; |     |     |     |     |     |     |     |
13
14
| 15  |     | if  | (line.length() |     |         | >=  | 8 && | line.substr(0, |     |     | 8)  | ==  |     |
| --- | --- | --- | -------------- | --- | ------- | --- | ---- | -------------- | --- | --- | --- | --- | --- |
|     |     |     | "@english")    |     |         | {   |      |                |     |     |     |     |     |
|     |     |     | inWord         |     | = true; |     |      |                |     |     |     |     |     |
16
|     |     |     | current |     | = Word(); |     |     |     |     |     |     |     |     |
| --- | --- | --- | ------- | --- | --------- | --- | --- | --- | --- | --- | --- | --- | --- |
17
| 18  |     |     | current.setEnglish(line.substr(9)); |          |     |     |         |     |     |     |     |     |     |
| --- | --- | --- | ----------------------------------- | -------- | --- | --- | ------- | --- | --- | --- | --- | --- | --- |
|     |     | }   | else                                | if (line |     | ==  | "@end") | {   |     |     |     |     |     |
19
|     |     |     | if  | (!current.getEnglish().empty()) |     |     |     |     |     |     | {   |     |     |
| --- | --- | --- | --- | ------------------------------- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
20
| 21  |     |     |     | try   | { addWord(current); |     |                          |     | }   |     |     |     |     |
| --- | --- | --- | --- | ----- | ------------------- | --- | ------------------------ | --- | --- | --- | --- | --- | --- |
|     |     |     |     | catch | (const              |     | DuplicateWordException&) |     |     |     |     | {}  |     |
22
}
23
|     |     |     | inWord |     | = false; |     |     |     |     |     |     |     |     |
| --- | --- | --- | ------ | --- | -------- | --- | --- | --- | --- | --- | --- | --- | --- |
24
|     |     | }   | else | if (inWord) |     |     | {   |     |     |     |     |     |     |
| --- | --- | --- | ---- | ----------- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
25
|     |     |     | std::string |     |     | val; |     |     |     |     |     |     |     |
| --- | --- | --- | ----------- | --- | --- | ---- | --- | --- | --- | --- | --- | --- | --- |
26
|     |     |     | DynamicArray<std::string> |     |     |     |     |     | parts; |     |     |     |     |
| --- | --- | --- | ------------------------- | --- | --- | --- | --- | --- | ------ | --- | --- | --- | --- |
27
| 28  |     |     | if  | (line.length() |                   |     | >=  | 7 && | line.substr(0, |     |     | 7) == |     |
| --- | --- | --- | --- | -------------- | ----------------- | --- | --- | ---- | -------------- | --- | --- | ----- | --- |
|     |     |     |     | "meaning")     |                   | {   |     |      |                |     |     |       |     |
|     |     |     |     | val            | = line.substr(8); |     |     |      |                |     |     |       |     |
29
| 30  |     |     |     | StringUtils::split(val, |      |     |      |     | ’|’,          | parts); |      |     |     |
| --- | --- | --- | --- | ----------------------- | ---- | --- | ---- | --- | ------------- | ------- | ---- | --- | --- |
|     |     |     |     | for                     | (int | i   | = 0; | i < | parts.size(); |         | ++i) |     |     |
31
current.addMeaning(parts[i]);
|     |     |     | }   | else | if (line.length() |     |     |     | >= 7 && | line.substr(0, |     |     | 7)  |
| --- | --- | --- | --- | ---- | ----------------- | --- | --- | --- | ------- | -------------- | --- | --- | --- |
32
|     |     |     |     | == "example") |                   |     | {   |     |     |     |     |     |     |
| --- | --- | --- | --- | ------------- | ----------------- | --- | --- | --- | --- | --- | --- | --- | --- |
|     |     |     |     | val           | = line.substr(8); |     |     |     |     |     |     |     |     |
33
|     |     |     |     | StringUtils::split(val, |     |     |     |     | ’|’, | parts); |     |     |     |
| --- | --- | --- | --- | ----------------------- | --- | --- | --- | --- | ---- | ------- | --- | --- | --- |
34
| 35  |     |     |     | for | (int | i   | = 0; | i < | parts.size(); |     | ++i) |     |     |
| --- | --- | --- | --- | --- | ---- | --- | ---- | --- | ------------- | --- | ---- | --- | --- |
current.addExample(parts[i]);
|     |     |     | }   | else | if (line.length() |     |     |     | >= 7 && | line.substr(0, |     |     | 7)  |
| --- | --- | --- | --- | ---- | ----------------- | --- | --- | --- | ------- | -------------- | --- | --- | --- |
36
|     |     |     |     | == "synonym")           |                   |     | {   |     |      |         |     |     |     |
| --- | --- | --- | --- | ----------------------- | ----------------- | --- | --- | --- | ---- | ------- | --- | --- | --- |
| 37  |     |     |     | val                     | = line.substr(8); |     |     |     |      |         |     |     |     |
|     |     |     |     | StringUtils::split(val, |                   |     |     |     | ’|’, | parts); |     |     |     |
38
|     |     |     |     | for | (int | i   | = 0; | i < | parts.size(); |     | ++i) |     |     |
| --- | --- | --- | --- | --- | ---- | --- | ---- | --- | ------------- | --- | ---- | --- | --- |
39
current.addSynonym(parts[i]);
}
40
}
41
}
42
43
|     | if  | (inWord |     | && !current.getEnglish().empty()) |     |     |     |     |     |     | {   |     |     |
| --- | --- | ------- | --- | --------------------------------- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
44
|     |     | try | {   | addWord(current); |     |     |     | }   |     |     |     |     |     |
| --- | --- | --- | --- | ----------------- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
45
| 46  |     | catch |     | (const | DuplicateWordException&) |     |     |     |     | {}  |     |     |     |
| --- | --- | ----- | --- | ------ | ------------------------ | --- | --- | --- | --- | --- | --- | --- | --- |
}
47

Báo cáo Đồ án – Từ điển Anh-Việt (OOP) 22
fin.close();
48
}
49
50
void Dictionary::saveToFile(const std::string& filename) const
51
{
std::ofstream fout(filename.c_str());
52
if (!fout.is_open()) {
53
throw FileIOException(filename);
54
}
55
56
fout << "# File du lieu tu dien Anh-Viet\n";
57
fout << "# Moi tu mot block, bat dau @english va ket thuc
58
@end\n\n";
59
for (int i = 0; i < words_.size(); ++i) {
60
const Word& w = words_[i];
61
fout << "@english=" << w.getEnglish() << "\n";
62
writeField(fout, "meaning", w.getMeanings());
63
writeField(fout, "example", w.getExamples());
64
writeField(fout, "synonym", w.getSynonyms());
65
fout << "@end\n\n";
66
}
67
fout.close();
68
}
69
A.7. History.cpp (Rule of Three)
History::History(int maxSize)
1
: head_(nullptr), count_(0), maxSize_(maxSize) {}
2
3
History::History(const History& other)
4
: head_(nullptr), count_(0), maxSize_(other.maxSize_) {
5
copyFrom(other);
6
}
7
8
History& History::operator=(const History& other) {
9
if (this == &other) return *this;
10
freeAll();
11
maxSize_ = other.maxSize_;
12
copyFrom(other);
13
return *this;
14
}
15
16
History::~History() {
17
freeAll();
18
}
19
20
void History::add(const std::string& word) {
21
// 1) Neu da co, xoa ban cu
22
Node* prev = nullptr;
23

| Báo cáo | Đồ    | án – | Từ điển | Anh-Việt | (OOP) |     |     |     | 23  |
| ------- | ----- | ---- | ------- | -------- | ----- | --- | --- | --- | --- |
|         | Node* |      | cur     | = head_; |       |     |     |     |     |
24
| 25  | while |     | (cur)      | {   |     |       |     |     |     |
| --- | ----- | --- | ---------- | --- | --- | ----- | --- | --- | --- |
|     |       | if  | (cur->word |     | ==  | word) | {   |     |     |
26
|     |     |     | if  | (prev | ==  | nullptr) | head_ | = cur->next; |     |
| --- | --- | --- | --- | ----- | --- | -------- | ----- | ------------ | --- |
27
| 28  |     |     | else   | prev->next |      | =   | cur->next; |     |     |
| --- | --- | --- | ------ | ---------- | ---- | --- | ---------- | --- | --- |
|     |     |     | delete |            | cur; |     |            |     |     |
29
--count_;
30
break;
31
| 32  |     | }    |     |        |     |     |     |     |     |
| --- | --- | ---- | --- | ------ | --- | --- | --- | --- | --- |
|     |     | prev |     | = cur; |     |     |     |     |     |
33
|     |     | cur | =   | cur->next; |     |     |     |     |     |
| --- | --- | --- | --- | ---------- | --- | --- | --- | --- | --- |
34
| 35  | }   |     |     |     |     |     |     |     |     |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
36
|     | //  | 2)  | Chen | vao | dau |     |     |     |     |
| --- | --- | --- | ---- | --- | --- | --- | --- | --- | --- |
37
|     | Node* |     | newNode | =   | new | Node(word); |     |     |     |
| --- | ----- | --- | ------- | --- | --- | ----------- | --- | --- | --- |
38
| 39  | newNode->next |     |            | =   | head_; |     |     |     |     |
| --- | ------------- | --- | ---------- | --- | ------ | --- | --- | --- | --- |
|     | head_         |     | = newNode; |     |        |     |     |     |     |
40
++count_;
41
42
|     | //  | 3)  | Cat | duoi | neu vuot | gioi | han |     |     |
| --- | --- | --- | --- | ---- | -------- | ---- | --- | --- | --- |
43
|     | if  | (count_ |     | > maxSize_) |     | {   |     |     |     |
| --- | --- | ------- | --- | ----------- | --- | --- | --- | --- | --- |
44
|     |     | Node* |     | p = head_; |     |     |     |     |     |
| --- | --- | ----- | --- | ---------- | --- | --- | --- | --- | --- |
45
|     |     | while |     | (p->next | &&  | p->next->next) |     | p = p->next; |     |
| --- | --- | ----- | --- | -------- | --- | -------------- | --- | ------------ | --- |
46
|     |     | delete |     | p->next; |     |     |     |     |     |
| --- | --- | ------ | --- | -------- | --- | --- | --- | --- | --- |
47
|     |     | p->next |     | = nullptr; |     |     |     |     |     |
| --- | --- | ------- | --- | ---------- | --- | --- | --- | --- | --- |
48
| 49  |     | --count_; |     |     |     |     |     |     |     |
| --- | --- | --------- | --- | --- | --- | --- | --- | --- | --- |
}
50
}
51
52
void History::saveToFile(const std::string& filename) const {
53
|     | std::ofstream |     |     | fout(filename.c_str()); |     |     |     |     |     |
| --- | ------------- | --- | --- | ----------------------- | --- | --- | --- | --- | --- |
54
|     | if  | (!fout.is_open()) |     |     |     | {   |     |     |     |
| --- | --- | ----------------- | --- | --- | --- | --- | --- | --- | --- |
55
| 56  |     | throw |     | FileIOException(filename); |     |     |     |     |     |
| --- | --- | ----- | --- | -------------------------- | --- | --- | --- | --- | --- |
}
57
|     | Node* |     | cur | = head_; |     |     |     |     |     |
| --- | ----- | --- | --- | -------- | --- | --- | --- | --- | --- |
58
| 59  | while |      | (cur) | {            |     |     |       |     |     |
| --- | ----- | ---- | ----- | ------------ | --- | --- | ----- | --- | --- |
|     |       | fout |       | << cur->word |     | <<  | "\n"; |     |     |
60
|     |     | cur | =   | cur->next; |     |     |     |     |     |
| --- | --- | --- | --- | ---------- | --- | --- | --- | --- | --- |
61
}
62
| 63  | fout.close(); |     |     |     |     |     |     |     |     |
| --- | ------------- | --- | --- | --- | --- | --- | --- | --- | --- |
}
64