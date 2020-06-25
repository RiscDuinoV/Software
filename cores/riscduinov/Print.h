#ifndef PRINT_H_
#define PRINT_H_
#include <string.h>
#include <stdint.h>

#define DEC 10
#define HEX 16
#define OCT 8
#ifdef BIN
#undef BIN
#endif
#define BIN 2

class Print
{
  private:
    int write_error;
    size_t printNumber(unsigned long, uint8_t);
    size_t printFloat(double, uint8_t);
  protected:
    void setWriteError(int err = 1) { write_error = err; }
  public:
    Print() : write_error(0) {}
  
    int getWriteError() { return write_error; }
    void clearWriteError() { setWriteError(0); }
  
    virtual size_t write(uint8_t) = 0;
    size_t write(const char *str) {
      if (str == NULL) return 0;
      return write((const uint8_t *)str, strlen(str));
    }
    virtual size_t write(const uint8_t *buffer, size_t size);
    size_t write(const char *buffer, size_t size) {
      return write((const uint8_t *)buffer, size);
    }

    // default to zero, meaning "a single write may block"
    // should be overriden by subclasses with buffering
    virtual int availableForWrite() { return 0; }
    size_t print(const char str[]);
    size_t print(char c);
    size_t print(unsigned char b, int base = DEC);
    size_t print(int n, int base);
    size_t print(unsigned int n, int base = DEC);
    size_t print(long n, int base);
    size_t print(unsigned long n, int base = DEC);
    size_t print(double n, int digits);

    size_t println(void);
    size_t println(const char c[]);
    size_t println(char c);
    size_t println(unsigned char b, int base = DEC);
    size_t println(int num, int base);
    size_t println(unsigned int num, int base = DEC);
    size_t println(long num, int base);
    size_t println(unsigned long num, int base = DEC);
    size_t println(double num, int digits);

    virtual void flush() { /* Empty implementation for backward compatibility */ }
};
#endif /* PRINT_H_ */