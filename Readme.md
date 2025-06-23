# STM32 Project Repository 🚀

Chào mừng đến với repository **STM32 Embedded Software Architecture**!  
Dự án được tổ chức theo hướng **clean architecture**, tập trung vào **Design Pattern**, **phát triển driver cấp thấp (MCAL)** và tích hợp **RTOS** cho dòng STM32F1/F4.

---

## 📁 Cấu trúc dự án

| Thư mục | Mô tả |
|--------|------|
| `Designpattern/` | Hiện thực các design pattern hiện đại trong môi trường nhúng như Singleton, Observer, Strategy |
| `MCAL/Dio/` | Driver Digital I/O điều khiển bằng thanh ghi (cho STM32F1/F4) |
| `MY_ASSEMBLY_STM32F4/` | Bộ driver cấp thấp cho STM32F4 viết bằng CMSIS và Assembly |
| `RTOS/` | Kernel RTOS tự viết hỗ trợ task scheduling và communication cơ bản |
| `STM32F1_Driver/` | Bộ driver đầy đủ cho STM32F1 (GPIO, Timer, UART, ...) |
| `STM32F4_Driver/` | Bộ driver đầy đủ cho STM32F4 |

---

## 🧠 Tính năng nổi bật

- 🧩 Tích hợp các **Design Pattern** (Builder, Factory, Adapter...) tối ưu cho nhúng  
- ⚙️ Viết **driver cấp thanh ghi**, không dùng HAL  
- ⏱️ RTOS đơn giản hỗ trợ multitask  
- 🧪 Thiết kế chuẩn để viết **unit test**, dễ tái sử dụng  
- 💡 Hỗ trợ **CMSIS & Assembly** để điều khiển tối ưu

---

## 🎯 Nền tảng hỗ trợ

- STM32F103C8T6 (Blue Pill – STM32F1)  
- STM32F411VET6 / STM32F429 (STM32F4)

---

## 👨‍💻 Tác giả

Dự án được phát triển bởi **Thanhlearningcode** — nền tảng thực hành lâu dài cho nghiên cứu về kiến trúc phần mềm nhúng, driver và RTOS.