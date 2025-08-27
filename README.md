# STM32 Project Repository 🚀

Chào mừng đến với **STM32 Embedded Software Architecture** — một hệ thống phần mềm nhúng được phát triển theo triết lý **Clean Architecture**, kết hợp giữa **lập trình hướng cấu trúc** và **hướng đối tượng**.  
Dự án tập trung vào:

- Phát triển **library driver** trực tiếp bằng thanh ghi (CMSIS, assembly) 
- Thiết kế **RTOS tự xây dựng**
- Áp dụng các **Design Pattern hiện đại**
- Mô phỏng hệ thống STM32 bằng C++ & Python giúp kiểm thử phần mềm **không cần phần cứng**
- Phát triển **driver (MCAL)** trực tiếp bằng thanh ghi (CMSIS, assembly) 
---

## 📁 Cấu trúc dự án

| Thư mục | Mô tả |
|--------|------|
| `Designpattern/` | Cài đặt các pattern như Singleton, Observer, Strategy trong môi trường embedded |
| `MCAL/Dio/` | Driver điều khiển DIO cấp thanh ghi cho STM32F1/F4 |
| `MY_ASSEMBLY_STM32F4/` | Viết driver dùng CMSIS kết hợp inline assembly |
| `RTOS/` | Kernel RTOS tự viết với cơ chế task switching và scheduler cơ bản |
| `STM32F1_Driver/` | Bộ driver đầy đủ cho STM32F1: GPIO, UART, Timer... |
| `STM32F4_Driver/` | Bộ driver tương tự cho dòng STM32F4 |
| `VirtualSTM32/` | Mô phỏng phần cứng STM32 bằng C++, kiểm thử bằng Python, build tự động với Bash/Makefile |

---

## 🧠 Tính năng nổi bật

- 🧩 Áp dụng **Design Pattern** vào lập trình driver nhúng như Builder, Adapter, Factory,...
- ⚙️ Viết **driver cấp thấp thuần C**, không sử dụng HAL, không phụ thuộc IDE
- ⏱️ RTOS dạng cooperative, dễ mở rộng, phù hợp nhúng real-time đơn giản
- 🧪 Hỗ trợ **unit test**, tích hợp mô phỏng hardware logic để test không cần mạch thật
- 🛠️ Kết hợp **CMSIS + Assembly** để tối ưu hiệu năng điều khiển bit-level
- 💻 Mô phỏng phần cứng STM32 bằng C++ (OOP) + kiểm thử logic bằng Python

---

## 🎯 Nền tảng & Môi trường phát triển

- **Vi điều khiển hỗ trợ:**
  - STM32F103C8T6 (Blue Pill – STM32F1)
  - STM32F411VET6 / STM32F429 (STM32F4 series)

- **IDE & công cụ:**
  - 🧰 **Visual Studio Code** (chính): dùng để phát triển, biên dịch và debug toàn bộ dự án
  - ⚙️ **Makefile / Bash script / CMake**: hệ thống build thủ công, không cần IDE như STM32CubeIDE,KeilC
  - 🐍 **Python**: viết test case cho mô phỏng logic
  - 🔬 **GDB / Valgrind / AddressSanitizer**: debug và kiểm tra bộ nhớ

---

## 💼 Công nghệ sử dụng

- **Ngôn ngữ:** C (99), C++17+, Assembly, Python  
- **Build:** Makefile, Bash Script, CMake  
- **Mô hình:** Clean Architecture, Layered Driver Design  
- **Hướng đến:** Embedded Clean Architecture , MCAL Layer Abstraction, Unit Testing & Virtual Verification  

---

## 👨‍💻 Tác giả

Dự án được phát triển bởi **Thanhlearningcode** — một nền tảng cá nhân nhằm nghiên cứu kiến trúc phần mềm, driver nhúng và hệ điều hành thời gian thực cho dòng vi điều khiển STM32.  

