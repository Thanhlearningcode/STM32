# 🧠 STM32  RTOS Project - Bare Metal C

Dự án này xây dựng một **Real-Time Operating System (RTOS) đơn giản** cho STM32F1/F4, **viết hoàn toàn bằng ngôn ngữ C**, không dùng bất kỳ thư viện HAL hoặc hệ điều hành nào bên ngoài.  
RTOS hỗ trợ đa nhiệm vòng tròn (Round-Robin), sleep, semaphore, mail box, FIFO queue và periodic task — phục vụ mục tiêu **hiểu sâu về cơ chế lập lịch, context switch, đồng bộ và xử lý ngắt**.

---

## ⚙️ Tính năng chính

- ✅ **Round-Robin Scheduler** với cấu trúc TCB vòng
- ⏱️ **SysTick** được cấu hình để tạo ngắt định kỳ và chuyển context
- 😴 **Thread Sleep API** (delay logic)
- 📬 **Mailbox** cho giao tiếp giữa các thread
- 📦 **FIFO Buffer** để truyền dữ liệu kiểu producer-consumer
- 🧵 Hỗ trợ **tạo 1 hoặc nhiều thread**
- 🔁 **Periodic Tasks** — xử lý định kỳ các hàm
- 🔐 **Spinlock / Cooperative Semaphore** để đồng bộ giữa các thread
- ⚡ **Ngắt ngoài (EXTI)** có thể đánh thức thread hoặc xử lý bất đồng bộ
- 🛠️ Tích hợp dễ dàng với CMSIS và có thể chạy trên **STM32F103/STM32F411**

---

## 🧠 Cấu trúc hệ thống

| Thành phần | Vai trò |
|-----------|---------|
| `tcb struct` | Lưu trạng thái từng thread (stack pointer, sleepTime, con trỏ kế tiếp) |
| `osKernelStackInit()` | Chuẩn bị stack cho mỗi thread, giả lập frame như sau ngắt |
| `osKernelAddThread()` | Thêm nhiều thread vào hệ thống |
| `osSchedulerRoundRobin()` | Lập lịch theo cơ chế vòng tròn, bỏ qua thread đang sleep |
| `osThreadsSleep()` | Cho phép thread ngủ trong thời gian nhất định |
| `osThreadYield()` | Gây ngắt để đổi thread sớm |
| `osSemaphore_*()` | Giao thức đồng bộ bằng semaphore |
| `osMailBoxSend/Receive()` | Gửi/nhận dữ liệu kiểu blocking, dùng trong truyền thông |
| `osFIFOPut/Get()` | Buffer dạng vòng để truyền dữ liệu giữa thread |
| `osEdgeTriggerInit()` | Kích hoạt ngắt ngoài (EXTI) và liên kết với semaphore |
| `osKernelLaunch()` | Khởi động toàn bộ hệ thống, bật Systick và bắt đầu lập lịch |

---

## 🛠️ Môi trường phát triển

- ✅ **CMSIS**: sử dụng CMSIS để cấu hình thanh ghi chuẩn ARM Cortex-M
- ✅ **KEILC**: Dự án RTOS_F1 được phát triển và biên dịch bằng Keil , với cấu trúc thư mục tiêu chuẩn phục vụ debug, build, và quản lý module RTOS.
- ✅ **Toolchain**: `arm-none-eabi-gcc`, có thể tích hợp vào Makefile hoặc Visual Studio Code
- ✅ **Debug/Flash**: hỗ trợ với OpenOCD, ST-Link

---

## 💡 Ví dụ tính năng

- Tạo 3 thread chạy vòng tròn
- Một thread sleep 100ms
- Một thread đọc giá trị sensor rồi đưa vào FIFO
- Một thread đọc FIFO rồi gửi qua UART (hoặc LED blink)
- Một ngắt ngoài (EXTI) gọi semaphore để đánh thức một thread

---

## 📌 Ghi chú

- **StackFrame** được mô phỏng đúng như context switch thực tế khi ngắt xảy ra (giống như phần cứng xử lý sau ISR)
- **Không sử dụng bất kỳ HAL hoặc thư viện ngoại vi của ST**
- **RTOS được thiết kế để mở rộng**: bạn có thể thêm mutex, priority scheduler, tickless mode, dynamic thread...

---

## 📂 Thư mục đề xuất

