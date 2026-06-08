@echo off
REM Script bien dich cho Windows (can MinGW-w64 hoac g++)
echo Dang bien dich phien ban OOP...
g++ -std=c++11 -Wall -O2 ^
  src/main.cpp src/Application.cpp src/ConsoleUI.cpp ^
  src/Dictionary.cpp src/History.cpp src/Favorites.cpp ^
  src/Word.cpp src/StringUtils.cpp ^
  src/ExactSearch.cpp src/ApproximateSearch.cpp ^
  -o TuDienAnhViet.exe
if %ERRORLEVEL% == 0 (
    echo.
    echo Bien dich thanh cong! Chay bang lenh: TuDienAnhViet.exe
) else (
    echo.
    echo Bien dich that bai. Kiem tra lai g++ da cai chua.
)
pause
