 Bank Managemnet System

Welcome to the ** Bank Managemnet System** — a simple, console-based banking management software written in C.

## 💡 Features

- Admin and User login system
- View customer accounts
- Add new customer records
- Edit existing accounts
- Transaction module (To be implemented)
- Search and Delete functionality (Partial/dummy)
- Console UI with `gotoxy()` positioning
- Data stored in binary format (`record.bin`)

## 🔐 Login Credentials

| Role      | Username | Password  |
|-----------|----------|-----------|
| Admin     | admin    | admin123  |
| User      | user     | user      |

## 📁 File Structure

- `main()` — Entry point that handles login and account type selection
- `admin()` — Admin dashboard
- `login()` — Login input form
- `verify()` — Credential checker
- `menu()` — Main menu for admin
- `option()` — Menu options handler
- `view()` — View all customer accounts
- `add()` — Register a new customer
- `edit()` — Modify an existing customer
- `record.bin` — Binary file storing all account data

## 🧪 Future Features

- Implement full transaction functionality
- Enable search by account and name
- Add data validation and uniqueness checks
- Improve security for password storage

## ⚙️ Requirements

- Windows OS (uses `windows.h` and `conio.h`)
- C compiler like GCC (Code::Blocks / Turbo C / Dev C++)

