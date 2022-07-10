#include "Str.h"

//region Constructors
Str::Str(const char *string1)
{
    char str[StrLen(string1) + 1];
    for (unsigned int i {0}; i <= StrLen(string1); ++i)
    {
        str[i] = string1[i];
    }
    str[StrLen(string1) + 1] = '\0';

    this->length = StrLen(string1);

    this->string = new char [this->length + 1];

    for (unsigned int i {0}; i <= this->length; ++i)
    {
        this->string[i] = str[i];
    }

    this->string[this->length + 1] = '\0';
}

Str::Str(const unsigned int &asciiVal)
{
    this->length = 1;
    this->string = new char [2];

    this->string[0] = (char)asciiVal;
    this->string[1] = '\0';
}

Str::Str(const Str &ref)
{
    this->length = ref.length;

    this->string = new char [this->length + 1];

    for (unsigned int i {0}; i <= this->length; ++i)
    {
        this->string[i] = ref.string[i];
    }

    this->string[this->length + 1] = '\0';
}

Str::~Str()
{
    delete this->string;
    this->length = 0;
}
//endregion

//region Methods
unsigned int StrLen(const char *string1)
{
    unsigned int _len {};

    while (string1[_len] != '\0')
    {
        ++_len;
    }

    return _len;
}

char *ConCat(const char *str1, const char c2)
{
    if (str1 == null || c2 == null) return nullptr;

    unsigned int newLen {StrLen(str1) + 1};

    char ret[newLen + 1];

    for (unsigned int i {0}; i < newLen; ++i)
    {
        if (i == (newLen - 1))
        {
            ret[i] = c2;

            break;
        }

        ret[i] = str1[i];
    }

    ret[newLen + 1] = '\0';

    return ret;
}

char *ConCat(const char *str1, const char *str2)
{
    if (str1 == null || str2 == null) return nullptr;

    unsigned int len1 {StrLen(str1)}, len2 {StrLen(str2)}, newLen {};

    newLen = (len1 + len2) + 1;

    char ret[newLen];

    for (unsigned int i {0}; i < len1; ++i)
    {
        ret[i] = str1[i];
    }

    for (unsigned int i {0}; i < len2; ++i)
    {
        ret[i + len1] = str2[i];
    }

    ret[newLen] = '\0';

    return ret;
}

bool StrCmp(const char *str1, const char *str2)
{
    bool ret {false};

    if (StrLen(str1) != StrLen(str2)) return false; // Will return false if lengths are different.

    for (unsigned int i {0}; i < StrLen(str1); ++i)
    {
        const char &c1 {str1[i]}, &c2 {str2[i]};

        if (c1 != c2)
        {
            ret = false;

            break;
        }
        else
            ret = true;
    }

    return ret;
}
//endregion

//region Member Methods
const unsigned int &Str::Length() const
{
    return this->length;
}

char &Str::At(const unsigned int &index)
{
    return this->string[index];
}

char &Str::Back()
{
    return this->string[this->length - 1];
}

char &Str::Front()
{
    return this->string[0];
}

void Str::Append(const unsigned int &asciiValue)
{
    ++this->length;

    char tmpStr[this->length + 1];
    for (unsigned int i {0}; i <= this->length - 1; ++i)
    {
        if (i == length - 1)
        {
            tmpStr[i] = (char)asciiValue;

            break;
        }

        tmpStr[i] = this->string[i];
    }

    delete this->string;
    this->string = new char [this->length + 1];

    for (unsigned int i {0}; i <= length; ++i)
    {
        this->string[i] = tmpStr[i];
    }

    this->string[this->length + 1] = '\0';
}

void Str::Append(const char *string1)
{
    const unsigned int _len {StrLen(string1)};

    for (unsigned int i {0}; i <= _len; ++i)
    {
        Append(string1[i]);
    }
}

void Str::Append(const Str &ref)
{
    Append(ref.string);
}

void Str::Insert(const unsigned int &index, const unsigned int &value)
{
    ++length;

    char *tmpStr {string};

    delete string;
    string = new char [length + 1];

    for (unsigned int i {0}; i <= length; ++i)
    {
        if (i == index)
        {
            string[i] = (char)value;
            string[i + 1] = tmpStr[i];

            ++i;
        }
    }

    string[length + 1] = '\0';
}

void Str::Erase()
{
    string = nullptr;
    length = 0;
}

void Str::Erase(const unsigned int &index)
{
    --this->length;

    const unsigned int &len {this->length};

    char tmpStr[len + 1];
    for (unsigned int i {0}; i <= len; ++i)
    {
        if (i < index)
        {
            tmpStr[i] = this->string[i];

            continue;
        }
        else if (i >= index)
        {
            tmpStr[i] = this->string[i + 1];

            continue;
        }
    }

    tmpStr[len + 1] = '\0';

    delete this->string;
    this->string = new char[this->length + 1];

    for (unsigned int i {0}; i <= this->length; ++i)
    {
        this->string[i] = tmpStr[i];
    }

    this->string[this->length + 1] = '\0';
}

void Str::PopBack()
{
    Erase(length);
}

void Str::PopFront()
{
    Erase(0);
}

void Str::PushFront(const unsigned int &asciiVal)
{
    ++this->length;

    const unsigned int len {this->length + 1};

    char tmpStr[len];
    tmpStr[0] = (char)asciiVal;
    for (unsigned int i {1}; i <= this->length; ++i)
    {
        tmpStr[i] = this->string[i - 1];
    }

    tmpStr[len] = '\0';

    delete this->string;
    this->string = new char [len + 1];

    for (unsigned int i {0}; i <= len; ++i)
    {
        this->string[i] = tmpStr[i];
    }

    this->string[len + 1] = '\0';
}

unsigned int Str::Copy(const char *s, const unsigned int &len, const unsigned int &pos)
{
    char *toCopy {};

    unsigned int o {};

    for (unsigned int i {pos}; i <= len; ++i, ++o)
    {
        if (toCopy[0] == null || string[i] == null) break;

        toCopy[o] = string[i];
    }

    return o;
}

const char *Str::c_str() const
{
    return this->string;
}

const char *Str::SubStr(const unsigned int &startPos, const unsigned int &endPos)
{
    if ((startPos < 0 || startPos >= this->length)
        || (endPos < 0 || endPos > this->length)) return nullptr; // Make sure index's are valid.
    if ((startPos == endPos) || (startPos > endPos)) return nullptr;

    const unsigned int newLen {endPos - startPos};

    char *ret {new char [newLen + 1]};
    for (unsigned int i {startPos}; i <= endPos; ++i)
    {
        ret[i] = this->string[i];
    }
    ret[newLen + 1] = '\0';

    return ret;
}

bool Str::Compare(const char *str1)
{
    return bool {StrCmp(this->string, str1)};
}

bool Str::Compare(const Str &ref)
{
    return bool {StrCmp(this->string, ref.string)};
}

bool Str::Compare(const unsigned int &asciiVal)
{
    if (this->length != 1) return false;

    return bool {this->string[0] == (char)asciiVal};
}
//endregion

//region Operator Overloads
char &Str::operator[](const unsigned int &index)
{
    return At(index);
}

Str &Str::operator=(char *ref)
{
    const Str str {ref};
    *this = str;

    return *this;
}

Str &Str::operator=(const unsigned int &ref)
{
    const char tmp[1] {(char)ref};
    const Str str {tmp};
    *this = str;

    return *this;
}

Str &Str::operator=(const Str &ref)
{
    this->length = ref.length;

    const char *tmp {ref.string};

    delete this->string;
    this->string = new char[this->length + 1];

    for (unsigned int i {0}; i <= this->length; ++i)
    {
        this->string[i] = tmp[i];
    }

    this->string[this->length + 1] = '\0';

    return *this;
}

void Str::operator+=(const char *string1)
{
    Append(string1);
}

void Str::operator+=(const unsigned int &asciiValue)
{
    Append(asciiValue);
}

void Str::operator+=(const Str &ref)
{
    Append(ref.string);
}

Str Str::operator+(const Str &ref)
{
    const char *tmp {ConCat(this->string, ref.string)};

    this->length = StrLen(tmp);

    char retStr[StrLen(tmp) + 1];
    for (unsigned int i {0}; i < StrLen(tmp); ++i)
    {
        retStr[i] = tmp[i];
    }
    retStr[StrLen(tmp) + 1] = '\0';

    return Str {retStr};
}

Str Str::operator+(const char *string1)
{
    // Using char arr so new name isn't lost in memory.

    const char *tmp {ConCat(this->string, string1)};

    this->length = StrLen(tmp);

    char retStr[StrLen(tmp) + 1];
    for (unsigned int i {0}; i < StrLen(tmp); ++i)
    {
        retStr[i] = tmp[i];
    }
    retStr[StrLen(tmp) + 1] = '\0';

    return Str {retStr};
}

Str Str::operator+(const unsigned int &asciiVal)
{
    const char *tmp {ConCat(this->string, (char)asciiVal)};

    this->length = StrLen(tmp);

    char retStr[StrLen(tmp) + 1];
    for (unsigned int i {0}; i < StrLen(tmp); ++i)
    {
        retStr[i] = tmp[i];
    }
    retStr[StrLen(tmp) + 1] = '\0';

    return Str {retStr};
}

Str::operator const char *() const
{
    return c_str();
}

bool Str::operator==(Str ref)
{
    bool ret {StrCmp(this->string, ref.string)};

    return ret;
}

bool Str::operator==(const char *string1)
{
    bool ret {StrCmp(this->string, string1)};

    return ret;
}

bool Str::operator==(const unsigned int &asciiVal)
{
    if (this->length != 1) return false;

    char tmp[2] {(char)asciiVal};
    tmp[1] = '\0';
    bool ret {StrCmp(this->string, tmp)};

    return ret;
}

bool Str::operator!=(Str ref)
{
    bool ret {!StrCmp(this->string, ref.string)};

    return ret;
}

bool Str::operator!=(const char *string1)
{
    bool ret {!StrCmp(this->string, string1)};

    return ret;
}

bool Str::operator!=(const unsigned int &asciiVal)
{
    if (this->length != 1) return false;

    char tmp[2] {(char)asciiVal};
    tmp[1] = '\0';
    bool ret {!StrCmp(this->string, tmp)};

    return ret;
}
//endregion