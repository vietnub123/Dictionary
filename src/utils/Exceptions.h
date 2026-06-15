#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>
#include <string>

// =====================================================================
// He thong Exception cho ung dung Tu Dien
//
// Cay ke thua:
//   std::exception
//     └── DictionaryException (base)
//           ├── WordNotFoundException
//           ├── DuplicateWordException
//           ├── FileIOException
//           └── InvalidInputException
//
// Tat ca exception deu inherit virtual tu std::exception thong qua
// DictionaryException. Cho phep client code chi can catch
// DictionaryException de bat moi loi cua he thong.
// =====================================================================

class DictionaryException : public std::exception {
protected:
    std::string message_;
public:
    explicit DictionaryException(const std::string& msg) : message_(msg) {}
    virtual ~DictionaryException() throw() {}
    virtual const char* what() const throw() {
        return message_.c_str();
    }
};

class WordNotFoundException : public DictionaryException {
public:
    explicit WordNotFoundException(const std::string& word)
        : DictionaryException("Khong tim thay tu: \"" + word + "\"") {}
};

class DuplicateWordException : public DictionaryException {
public:
    explicit DuplicateWordException(const std::string& word)
        : DictionaryException("Tu da ton tai: \"" + word + "\"") {}
};

class FileIOException : public DictionaryException {
public:
    explicit FileIOException(const std::string& filename)
        : DictionaryException("Loi truy cap file: \"" + filename + "\"") {}
};

class InvalidInputException : public DictionaryException {
public:
    explicit InvalidInputException(const std::string& msg)
        : DictionaryException("Du lieu nhap khong hop le: " + msg) {}
};

#endif // EXCEPTIONS_H
