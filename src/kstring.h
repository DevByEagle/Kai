#ifndef KSTRING_H
#define KSTRING_H

#include <cstddef>

namespace Kargo {
    namespace Foundation {
        template <typename CharT>
        class BaseString {
        public:
            BaseString() : data(nullptr), length(0) {}
            BaseString(const CharT* initial);
            virtual ~BaseString();

            BaseString& operator=(const BaseString& other);
            
            size_t size() const { return length; }
            const CharT* c_str() const { return data; }
            bool empty() const { return length == 0; }
            
        private:
            CharT* data;
            size_t length;

            void copyFrom(const CharT* str);
        };
    }

    typedef Foundation::BaseString<char> String;
}

#endif // KSTRING_H