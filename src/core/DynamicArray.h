#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

// =====================================================================
// DynamicArray<T> - Template mang dong tu cai dat (thay the std::vector)
//
// Ap dung Rule of Three: dinh nghia day du
//   - Destructor: giai phong bo nho
//   - Copy constructor: deep copy
//   - Copy assignment operator: deep copy + tu gan an toan
//
// Co che: nhan doi capacity khi day; do phuc tap amortized O(1) cho push_back
// =====================================================================

template <typename T>
class DynamicArray {
private:
    T* data_;
    int size_;
    int capacity_;

    void reallocate(int newCap) {
        T* newData = new T[newCap];
        for (int i = 0; i < size_; ++i) {
            newData[i] = data_[i];
        }
        delete[] data_;
        data_ = newData;
        capacity_ = newCap;
    }

public:
    DynamicArray() : data_(nullptr), size_(0), capacity_(0) {}

    DynamicArray(const DynamicArray& other)
        : data_(nullptr), size_(0), capacity_(0) {
        if (other.capacity_ > 0) {
            data_ = new T[other.capacity_];
            capacity_ = other.capacity_;
            size_ = other.size_;
            for (int i = 0; i < size_; ++i) {
                data_[i] = other.data_[i];
            }
        }
    }

    DynamicArray& operator=(const DynamicArray& other) {
        if (this == &other) return *this;
        delete[] data_;
        data_ = nullptr;
        size_ = 0;
        capacity_ = 0;
        if (other.capacity_ > 0) {
            data_ = new T[other.capacity_];
            capacity_ = other.capacity_;
            size_ = other.size_;
            for (int i = 0; i < size_; ++i) {
                data_[i] = other.data_[i];
            }
        }
        return *this;
    }

    ~DynamicArray() {
        delete[] data_;
    }

    int size() const { return size_; }
    bool empty() const { return size_ == 0; }

    T& operator[](int i) { return data_[i]; }
    const T& operator[](int i) const { return data_[i]; }

    void push_back(const T& value) {
        if (size_ >= capacity_) {
            int newCap = (capacity_ == 0) ? 4 : capacity_ * 2;
            reallocate(newCap);
        }
        data_[size_++] = value;
    }

    void removeAt(int idx) {
        if (idx < 0 || idx >= size_) return;
        for (int i = idx; i < size_ - 1; ++i) {
            data_[i] = data_[i + 1];
        }
        --size_;
    }

    void clear() { size_ = 0; }
};

#endif // DYNAMIC_ARRAY_H
