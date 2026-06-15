#include "History.h"
#include "Exceptions.h"
#include <fstream>

History::History(int maxSize)
    : head_(nullptr), count_(0), maxSize_(maxSize) {}

History::History(const History& other)
    : head_(nullptr), count_(0), maxSize_(other.maxSize_) {
    copyFrom(other);
}

History& History::operator=(const History& other) {
    if (this == &other) return *this;
    freeAll();
    maxSize_ = other.maxSize_;
    copyFrom(other);
    return *this;
}

History::~History() {
    freeAll();
}

void History::freeAll() {
    Node* cur = head_;
    while (cur) {
        Node* next = cur->next;
        delete cur;
        cur = next;
    }
    head_ = nullptr;
    count_ = 0;
}

void History::copyFrom(const History& other) {
    // Deep copy theo dung thu tu (head -> tail)
    if (other.head_ == nullptr) return;

    head_ = new Node(other.head_->word);
    Node* cur = head_;
    Node* otherCur = other.head_->next;
    while (otherCur) {
        cur->next = new Node(otherCur->word);
        cur = cur->next;
        otherCur = otherCur->next;
    }
    count_ = other.count_;
}

void History::clear() {
    freeAll();
}

void History::add(const std::string& word) {
    // 1) Neu da co, xoa ban cu
    Node* prev = nullptr;
    Node* cur = head_;
    while (cur) {
        if (cur->word == word) {
            if (prev == nullptr) head_ = cur->next;
            else prev->next = cur->next;
            delete cur;
            --count_;
            break;
        }
        prev = cur;
        cur = cur->next;
    }

    // 2) Chen vao dau
    Node* newNode = new Node(word);
    newNode->next = head_;
    head_ = newNode;
    ++count_;

    // 3) Cat duoi neu vuot gioi han
    if (count_ > maxSize_) {
        Node* p = head_;
        while (p->next && p->next->next) p = p->next;
        delete p->next;
        p->next = nullptr;
        --count_;
    }
}

std::string History::at(int i) const {
    if (i < 0 || i >= count_) {
        throw InvalidInputException("Chi so lich su ngoai pham vi");
    }
    Node* cur = head_;
    for (int k = 0; k < i; ++k) cur = cur->next;
    return cur->word;
}

void History::saveToFile(const std::string& filename) const {
    std::ofstream fout(filename.c_str());
    if (!fout.is_open()) {
        throw FileIOException(filename);
    }
    Node* cur = head_;
    while (cur) {
        fout << cur->word << "\n";
        cur = cur->next;
    }
    fout.close();
}

void History::loadFromFile(const std::string& filename) {
    std::ifstream fin(filename.c_str());
    if (!fin.is_open()) {
        // Khong co file la binh thuong (lan dau chay)
        return;
    }
    freeAll();

    // Doc vao mang tam de bao toan thu tu
    int cap = 16;
    std::string* tmp = new std::string[cap];
    int n = 0;
    std::string line;
    while (std::getline(fin, line)) {
        if (line.empty()) continue;
        if (n >= cap) {
            int newCap = cap * 2;
            std::string* newTmp = new std::string[newCap];
            for (int i = 0; i < n; ++i) newTmp[i] = tmp[i];
            delete[] tmp;
            tmp = newTmp;
            cap = newCap;
        }
        tmp[n++] = line;
    }
    fin.close();

    // Them tu cuoi -> dau de phan tu dau file thanh head (moi nhat)
    for (int i = n - 1; i >= 0; --i) add(tmp[i]);
    delete[] tmp;
}
