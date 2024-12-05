#include <cstring>
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
        void BaseString<CharT>::copyFrom(const CharT *str)
        {
            length = std::strlen(str);
            data = new CharT[length + 1];
            std::strcpy(data, str);
        }
    }
}