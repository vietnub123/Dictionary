# Makefile cho project Tu Dien Anh-Viet (Phien ban OOP)

CXX      = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -O2
SRC      = src/main.cpp src/Application.cpp src/ConsoleUI.cpp \
           src/Dictionary.cpp src/History.cpp src/Favorites.cpp \
           src/Word.cpp src/StringUtils.cpp \
           src/ExactSearch.cpp src/ApproximateSearch.cpp
TARGET   = TuDienAnhViet

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET) $(TARGET).exe

.PHONY: all run clean
