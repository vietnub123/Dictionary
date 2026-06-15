#include "Word.h"
#include "StringUtils.h"

bool Word::operator==(const Word& other) const {
    return StringUtils::toLower(english_) == StringUtils::toLower(other.english_);
}

std::ostream& operator<<(std::ostream& os, const Word& w) {
    os << "-----------------------------------------\n";
    os << "Tu tieng Anh : " << w.english_ << "\n";

    os << "Nghia        : ";
    if (w.meanings_.empty()) {
        os << "(chua co)";
    } else {
        for (int i = 0; i < w.meanings_.size(); ++i) {
            os << w.meanings_[i];
            if (i < w.meanings_.size() - 1) os << "; ";
        }
    }
    os << "\n";

    os << "Vi du        : ";
    if (w.examples_.empty()) {
        os << "(chua co)\n";
    } else {
        os << "\n";
        for (int i = 0; i < w.examples_.size(); ++i) {
            os << "   - " << w.examples_[i] << "\n";
        }
    }

    os << "Dong nghia   : ";
    if (w.synonyms_.empty()) {
        os << "(chua co)";
    } else {
        for (int i = 0; i < w.synonyms_.size(); ++i) {
            os << w.synonyms_[i];
            if (i < w.synonyms_.size() - 1) os << ", ";
        }
    }
    os << "\n";
    os << "-----------------------------------------\n";
    return os;
}
