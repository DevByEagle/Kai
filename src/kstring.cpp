#include <cstring>
#include <stdexcept>
#include "kstring.h"

namespace Kargo
{
    namespace Foundation
    {
        template <typename CharT>
        BaseString<CharT>::BaseString(const CharT *initial)
        {
            copyFrom(initial);
        }

        template <typename CharT>
        BaseString<CharT>::BaseString(const CharT* buffer, size_t len) {
            length = len;
            data = new CharT[length + 1];
            std::memcpy(data, buffer, len * sizeof(CharT));
            data[length] = '\0';
        }

        template <typename CharT>
        BaseString<CharT>::~BaseString()
        {
            delete[] data;
        }

        template <typename CharT>
        BaseString<CharT> &BaseString<CharT>::operator=(const BaseString &other)
        {
            if (this != other)
            {
                delete[] data;
                copyFrom(other.data);
            }
            return *this;
        }

        template <typename CharT>
        CharT& BaseString<CharT>::operator[](size_t index) {
            if (index >= length) {
                throw std::out_of_range("Index out of bounds");
            }
            return data[index];
        }

        template <typename CharT>
        void BaseString<CharT>::copyFrom(const CharT *str)
        {
            length = std::strlen(str);
            data = new CharT[length + 1];
            std::strcpy(data, str);
        }
    }
}