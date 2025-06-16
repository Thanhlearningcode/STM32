#include <sys/stat.h>
#include <errno.h>
#include <unistd.h>
register char *stack_ptr asm("sp");

caddr_t _sbrk(int incr) {
    extern char _end;  // symbol defined in linker script
    static char *heap_end;
    char *prev_heap_end;

    if (heap_end == 0) {
        heap_end = &_end;
    }
    prev_heap_end = heap_end;

    char *stack = stack_ptr;
    if (heap_end + incr > stack) {
        // không đủ heap, gây lỗi
        errno = ENOMEM;
        return (caddr_t) -1;
    }

    heap_end += incr;
    return (caddr_t) prev_heap_end;
}

int _write(int file, char *ptr, int len) {
    // Gửi chuỗi ptr dài len ra UART, hoặc giả lập debug
    // Ví dụ: gọi hàm UART1_SendData(ptr, len);
    for (int i = 0; i < len; i++) {
        // Gửi từng ký tự ra UART (bạn tự implement)
        UART2_SendChar(ptr[i]); // bạn cần có hàm này trong UART driver
    }
    return len;
}

int _read(int file, char *ptr, int len) {
    // đọc từ UART hoặc không hỗ trợ
    return 0;
}

int _close(int file) { return -1; }
int _fstat(int file, struct stat *st) { st->st_mode = S_IFCHR; return 0; }
int _isatty(int file) { return 1; }
int _lseek(int file, int ptr, int dir) { return 0; }
void _exit(int status) {
    while(1);
}
int _kill(int pid, int sig) { return -1; }
int _getpid(void) { return 1; }
