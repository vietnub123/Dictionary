# Makefile cho project Tu Dien Anh-Viet (Phien ban OOP)

CXX      = g++
# Sử dụng cờ -I để định tuyến trình biên dịch tự động tìm kiếm tệp .h trong các thư mục con
CXXFLAGS = -std=c++11 -Wall -Wextra -O2 -Isrc/core -Isrc/persistence -Isrc/search -Isrc/ui -Isrc/utils -Isrc/app
# Cập nhật chính xác đường dẫn phân cấp mới của các tệp .cpp
SRC      = src/app/main.cpp \
           src/app/Application.cpp \
           src/ui/ConsoleUI.cpp \
           src/persistence/Dictionary.cpp \
           src/persistence/History.cpp \
           src/persistence/Favorites.cpp \
           src/core/Word.cpp \
           src/utils/StringUtils.cpp \
           src/search/ExactSearch.cpp \
           src/search/ApproximateSearch.cpp
TARGET   = TuDienAnhViet

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET) $(TARGET).exe

.PHONY: all run clean