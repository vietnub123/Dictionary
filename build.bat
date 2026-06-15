@echo off
echo Dang bien dich he thong Tu dien Anh - Viet...
g++ -std=c++11 -Wall -Wextra -O2 -Isrc/core -Isrc/persistence -Isrc/search -Isrc/ui -Isrc/utils -Isrc/app ^
src/app/main.cpp ^
src/app/Application.cpp ^
src/ui/ConsoleUI.cpp ^
src/persistence/Dictionary.cpp ^
src/persistence/History.cpp ^
src/persistence/Favorites.cpp ^
src/core/Word.cpp ^
src/utils/StringUtils.cpp ^
src/search/ExactSearch.cpp ^
src/search/ApproximateSearch.cpp ^
-o TuDienAnhViet.exe
if %errorlevel% equ 0 (
    echo Bien dich thanh cong!
) else (
    echo Co loi xay ra trong qua trinh bien dich.
)
pause