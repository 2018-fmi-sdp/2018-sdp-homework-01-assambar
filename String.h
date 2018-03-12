#pragma once

#include <iosfwd>

class String {
private:
  char* _data;
  unsigned int _size;

  void copyFrom(const String& other);
  void deleteThis();

public:
  String();
  ~String();
  String(const String& other);
  String& operator=(const String& other);

  String(unsigned int size);
  String(const char* str);

  const char* data() const { return _data; }
  unsigned int size() const { return _size; }
  unsigned int len() const;

  char& operator[](unsigned int i) { return _data[i]; }
  const char& operator[](unsigned int i) const { return _data[i]; }
  
  bool operator==(const char* str) const;
  bool startsWith(const char* str) const;

  void resize(unsigned int newSize);

  friend std::ostream& operator<<(std::ostream& o, const String& s);
  friend std::istream& operator>>(std::istream& o, String& s);
};

String reverse(const String& s);
// to = 0 means till the end
// to is non-inclusive limit
String subString(const String& s, unsigned int from, unsigned int to = 0);
