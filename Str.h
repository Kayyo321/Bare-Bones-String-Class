#pragma once

#define null 0

class Str
{
public:
    //region Constructors
    Str() = default;           // Empty constructor.
    Str(const char *);         // Char array constructor.
    Str(const unsigned int &); // ASCII constructor.
    Str(const Str &);
    ~Str();
    //endregion

    //region Unsigned int
    /// <summary>
    /// Returns the lengths of the current string.
    /// </summary>
    [[nodiscard]] const unsigned int &Length() const;

    /// <summary>
    /// Copies a substring from the startPos, to the endPos, into the given string.
    /// </summary>
    unsigned int Copy(const char *, const unsigned int &, const unsigned int &);
    //endregion

    //region Character ref
    /// <summary>
    /// Returns the character at a given index.
    /// </summary>
    [[nodiscard]] char &operator[](const unsigned int &);

    /// <summary>
    /// Returns the character at a given index.
    /// </summary>
    char &At(const unsigned int &);

    /// <summary>
    /// Returns the character at the back of the string.
    /// </summary>
    char &Back();

    /// <summary>
    /// Returns the character at the front of the string.
    /// </summary>
    char &Front();
    //endregion

    //region Str ref
    Str &operator=(char *);
    Str &operator=(const unsigned int &);
    Str &operator=(const Str &);
    //endregion

    //region Void
    void operator+=(const char *);
    void operator+=(const unsigned int &);
    void operator+=(const Str &);

    /// <summary>
    /// Appends a character to the end of the string.
    /// </summary>
    void Append(const unsigned int &);

    /// <summary>
    /// Appends a string to the end of the current string.
    /// </summary>
    void Append(const char *);

    /// <summary>
    /// Appends a Str to the end of the current string.
    /// </summary>
    void Append(const Str &);

    /// <summary>
    /// Inserts a character at the given index.
    /// </summary>
    void Insert(const unsigned int &, const unsigned int &);

    /// <summary>
    /// Erases the contents of the current string.
    /// </summary>
    void Erase();

    /// <summary>
    /// Erases the character at the given index.
    /// </summary>
    void Erase(const unsigned int &);

    /// <summary>
    /// Erases the character at the end of the current string.
    /// </summary>
    void PopBack();

    /// <summary>
    /// Erases the character at the front of the current string.
    /// </summary>
    void PopFront();

    /// <summary>
    /// Appends a character to the beginning of the current string.
    /// </summary>
    void PushFront(const unsigned int &);
    // No PushBack, because Append already fulfills its roll.
    //endregion

    //region Str
    Str operator+(const Str &);
    Str operator+(const char *);
    Str operator+(const unsigned int &);
    //endregion

    //region Const char ptr
    explicit operator const char * () const;

    /// <summary>
    /// Returns a C-string with the contents of the current string.
    /// </summary>
    [[nodiscard]] const char *c_str() const;

    /// <summary>
    /// Returns && Alocates memory for a substring between two index's.
    /// </summary>
    const char *SubStr(const unsigned int &, const unsigned int &);
    //endregion

    //region Bool
    bool operator==(Str);
    bool operator==(const char *);
    bool operator==(const unsigned int &);
    bool operator!=(Str);
    bool operator!=(const char *);
    bool operator!=(const unsigned int &);

    /// <summary>
    /// Returns a boolean based off if the current string is the same as a given one.
    /// </summary>
    bool Compare(const char *);

    /// <summary>
    /// Returns a boolean based off if the current string is the same as a given Str.
    /// </summary>
    bool Compare(const Str &);

    /// <summary>
    /// Returns a boolean based off if the current string is the same as a given character.
    /// </summary>
    bool Compare(const unsigned int &);
    //endregion

private:
    char *string {};
    unsigned int length {};
};

/// <summary>
/// Returns the length of a given string.
/// </summary>
static unsigned int StrLen(const char *);

/// <summary>
/// Returns a concatenation of two strings.
/// </summary>
static char *ConCat(const char *, const char *);

/// <summary>
/// Returns a concatenation of a string, and a character.
/// </summary>
static char *ConCat(const char *, char);

/// <summary>
/// Returns a boolean based off if two strings are the same.
/// </summary>
bool StrCmp(const char *, const char *);