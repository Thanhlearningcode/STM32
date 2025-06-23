# ⚙️ STM32F1 Low-Level Driver Library – Pure C (Keil C)

Chào mừng đến với dự án **STM32F1 Driver Library**, nơi bạn có thể tìm thấy những thư viện **tự xây từ thanh ghi (register-level)** dành riêng cho vi điều khiển STM32F1.  
Tất cả được lập trình bằng **ngôn ngữ C thuần**, biên dịch trực tiếp trong **Keil µVision**, **không phụ thuộc HAL hoặc thư viện trung gian**.

---

## 🎯 Mục đích dự án

- ✨ Làm chủ việc truy xuất và điều khiển ngoại vi thông qua thanh ghi
- 🧠 Rèn luyện tư duy kiến trúc phần mềm nhúng (tách file, tái sử dụng code)
- 🛠️ Tạo bộ thư viện riêng dùng trong nhiều dự án nhúng STM32
- 📦 Tối ưu kích thước chương trình, đơn giản hóa việc debug

---

## 📁 Danh sách thư viện hiện có

| Tên driver | Mô tả |
|------------|-------|
| `GPIO_STM32.c/h`     | Cấu hình I/O, điều khiển LED, đọc nút nhấn |
| `SPI_STM32.c/h`      | SPI Master/Slave, gửi & nhận dữ liệu |
| `I2C_LCD.c/h`        | Điều khiển LCD 16x2 qua I2C |
| `ADC_Library.c/h`    | Đọc giá trị analog từ cảm biến |
| `FLASH.c/h`          | Đọc / ghi Flash nội STM32F1 |
| `ExternalIRQ.c/h`    | Cấu hình và xử lý ngắt ngoài (EXTI) |
| `RTC.c/h`            | Thiết lập thời gian thực (Real-Time Clock) |
| `CAN.c/h`            | Giao tiếp CAN (tầng điều khiển) |
| `BTS7960.c/h`        | Điều khiển động cơ sử dụng BTS7960 |
| `RCC_STM32.c/h`      | Cấu hình hệ thống xung clock, bật/tắt các bus |
| `My_driver.c/h`      | File kiểm thử tổng hợp các driver |

---

## 🛠️ Môi trường phát triển

- 🧩 IDE: **Keil µVision (Cortex-M3 support)**
- 💾 MCU: **STM32F103C8T6** (hoặc tương đương dòng STM32F1)
- 📚 Thư viện CMSIS: sử dụng từ gói ST chính thức
- 💻 Ngôn ngữ: **C,Assembly**

---