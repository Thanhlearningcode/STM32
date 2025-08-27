#DEADLINE T7/2025 FULL DESIGN PATTERN CHO UART,SPI,I2C,CAN,..
# STM32F411VET6 LED Blinking Project

## Giới thiệu


Dự án này nhằm hiện thực hóa các **Design Pattern kinh điển** trong phần mềm vào môi trường **embedded C (bare-metal)**, đặc biệt là các vi điều khiển STM32 (F1/F4 series).  
Mỗi pattern được tổ chức như một module độc lập, dễ tái sử dụng, dễ kiểm thử, và **không phụ thuộc vào HAL/IDE**.

---
## 🧱 Phân loại Design Pattern

### 📦 Creational Patterns

| Tên Pattern | Mô tả ngắn | Thư mục |
|-------------|------------|---------|
| **Builder** | Tách quá trình khởi tạo phức tạp thành từng bước — dùng để tạo driver UART/I2C/... theo module cấu hình | `Creational/Builder/` |
| **Factory** | Tạo đối tượng runtime tùy vào cấu hình — phù hợp với việc khởi tạo cảm biến hay protocol linh hoạt | `Creational/Factory/` |
| **Singleton** | Đảm bảo chỉ tồn tại một instance (VD: logger, timer manager...) — quản lý tài nguyên hệ thống | `Creational/Singleton/` |

## Cấu trúc thư mục

```
STM32F411VET6-Blink/
| Thư mục/File | Mô tả |
|--------------|-------|
| `CMSIS/`     | Tệp tiêu chuẩn của ARM và ST cho Cortex-M |
| `Inc/`       | Header file định nghĩa các thành phần trong mô hình Builder |
| `LOGGING/`   | Mô-đun in log/debug đơn giản |
| `scripts/`   | Bash script để build firmware và test |
| `Src/`       | Code cốt lõi hiện thực Builder Pattern |
| `Startup/`   | Startup code, vector table cho STM32 |
| `tests/`     | Unit test cho Builder Pattern (GoogleTest) |
| `main.c`     | File chính, khởi tạo và sử dụng builder |
| `README.md`  | File mô tả dự án hiện tại |

```

## ⚙️ Tính chất kỹ thuật

- ✍️ Viết bằng **C thuần**, tuân thủ chuẩn MISRA khi cần  
- 🧪 Có module **unit test riêng biệt** (GoogleTest/CMock) cho từng pattern  
- 🔧 Sử dụng **Makefile + bash script** để build tự động  
- 💻 Thử nghiệm trên **Visual Studio Code** với GCC toolchain

---
---
## 💡 Lợi ích khi áp dụng Design Pattern vào nhúng

| Vấn đề thường gặp | Giải pháp qua Pattern |
|------------------|------------------------|
| Code trùng lặp | Sử dụng Factory, Builder để cấu hình module |
| Cấu trúc rối | Dùng Facade, Singleton để tách logic và quản lý tài nguyên |
| Khó mở rộng | Tổ chức module đúng pattern giúp thêm chức năng không làm hỏng hệ thống cũ |
| Khó kiểm thử | Tách cấu trúc thành class/module dễ mock/test |

---


## Setting Environment
## Về CMSIS (Cortex Microcontroller Software Interface Standard)

CMSIS là bộ thư viện chuẩn do ARM phát triển nhằm chuẩn hóa giao diện lập trình cho các vi điều khiển Cortex-M.
Nó cung cấp các file header, định nghĩa register, cấu trúc dữ liệu và hàm API cơ bản giúp bạn viết code dễ dàng hơn, không cần viết trực tiếp các giá trị hex cho các thanh ghi.

Trong project STM32F411VET6, CMSIS sẽ bao gồm các file như:

* `core_cm4.h` - định nghĩa vi xử lý Cortex-M4
* `system_stm32f4xx.c/h` - cấu hình hệ thống (clock, vector table)
* `stm32f411xe.h` - định nghĩa register của STM32F411xE

### Lấy CMSIS cho STM32F4

Bạn có thể tải bộ CMSIS chuẩn từ:

* Trang chính thức của ARM:
  [https://developer.arm.com/tools-and-software/embedded/cmsis](https://developer.arm.com/tools-and-software/embedded/cmsis)
* Hoặc tải từ **STM32CubeF4** package của ST:
  [https://www.st.com/en/embedded-software/stm32cubef4.html](https://www.st.com/en/embedded-software/stm32cubef4.html)

Thư mục `CMSIS/` trong project sẽ gồm:

```
CMSIS/
├── Device/
│   └── ST/
│       └── STM32F4xx/
│           ├── Include/           # File header định nghĩa STM32F4, startup
│           └── Source/            # System configuration
├── Core/
    ├── Include/                  # Cortex-M core headers (core_cm4.h, ...)
```

---

## Yêu cầu cài đặt

* GCC ARM Embedded Toolchain (`arm-none-eabi-gcc`)
* `make`
* OpenOCD (để flash và debug)
* stlink-tools (`st-flash`)

Cài nhanh trên Ubuntu/Debian:

```bash
sudo apt update
sudo apt install gcc-arm-none-eabi gdb-multiarch make openocd stlink-tools
```

---


---

## Tham khảo

* [CMSIS Documentation](https://arm-software.github.io/CMSIS_5/Core/html/index.html)
* [STM32CubeF4 HAL libraries](https://www.st.com/en/embedded-software/stm32cubef4.html)
* [STM32F4 Reference Manual (PDF)](https://www.st.com/resource/en/reference_manual/dm00031020-stm32f405-415-stm32f407-417-stm32f427-437-and-stm32f429-439-advanced-armbased-32bit-mcus-stmicroelectronics.pdf)

---

**Chúc bạn thành công với STM32F411VET6!** 🚀

---

