#pragma once
class String
{

    size_t size = 0;
    char* Item = nullptr;
public:


    String() = default;
    String(const char* Item, size_t size) {
        SetName(Item, size);
    }
    String(String&& other);
    void SetName(const char* item, size_t size = 0);
    void SetSize(const size_t size);
    const char* getItem() const;
    void print() const;
    void assing(const String& other);
    String(const String& other) {
        assing(other);
    }
    void operator=(const String& other);
    void operator=( String&& other);
    void input();
    bool operator==(const String& other)const;
    bool operator!=(const String& other)const;
    int operator [](int index)const;
    ~String() {
        delete[]Item;
        Item = nullptr;
    }

};

