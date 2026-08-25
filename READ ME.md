# 🏦 ATM Banking Management System in C

A beginner-friendly **ATM Banking Management System written in C** that simulates common ATM operations such as PIN authentication, balance checking, deposits, withdrawals, transaction receipts, user sessions, logout, and ATM exit.

This project was created to practice fundamental **C programming concepts** by applying them to a real-world ATM scenario.

> 🚧 **Project Status:** Educational / Beginner C Project

---

## ✨ Features

- 🔐 **PIN Authentication** — Login using a 4-digit PIN.
    
- 🚫 **PIN Attempt Limit** — Maximum of 3 incorrect attempts.
    
- 👥 **Multiple Users** — Supports 10 predefined user accounts.
    
- 💰 **Balance Inquiry** — Check the current account balance.
    
- 💸 **Money Withdrawal** — Withdraw money with multiple validation checks.
    
- 💵 **Money Deposit** — Deposit money into the account.
    
- 🧾 **Transaction Receipt** — Displays transaction details after successful transactions.
    
- ⚠️ **Minimum Balance Protection** — Requires at least ₹500 to remain after a withdrawal.
    
- 📊 **Withdrawal Limit** — Maximum withdrawal of ₹20,000 per transaction.
    
- 🔄 **Logout** — Ends the current user session while keeping the ATM running.
    
- 🚪 **Exit ATM** — Saves the current balance and closes the program.
    
- 🔁 **Multiple Sessions** — Another user can log in after the previous user logs out.
    

---

## 🛠️ Technologies Used

|Technology|Usage|
|---|---|
|C|Main programming language|
|GCC|Compiler|
|`stdio.h`|Input and output|

---

## 📋 ATM Menu

After successful authentication, the user is presented with the following menu:

```text
===== ATM MENU =====
1. Check Balance
2. Withdraw Money
3. Deposit Money
4. Logout
5. Exit ATM
```

### 1. Check Balance

Displays the user's current account balance.

### 2. Withdraw Money

Allows the user to withdraw money after performing several validation checks.

### 3. Deposit Money

Allows the user to add money to their account.

### 4. Logout

Ends the current user's session and returns the ATM to the login screen.

### 5. Exit ATM

Saves the current account balance and completely terminates the program.

---

## 🔐 Authentication System

The program contains **10 predefined user accounts**.

Each account has:

- Account number
    
- 4-digit PIN
    
- Initial balance
    

Users authenticate by entering their PIN.

The program allows a maximum of **3 incorrect PIN attempts**.

Example:

```text
Enter your PIN: 1234
Incorrect PIN!
Attempts remaining: 2

Enter your PIN: 1111
Incorrect PIN!
Attempts remaining: 1

Enter your PIN: 9999
Incorrect PIN!
Attempts remaining: 0

Too many incorrect attempts.
Your session has been terminated.
```

---

## 👥 Sample Accounts

The program contains the following predefined accounts for testing:

|User|Account Number|PIN|Initial Balance|
|---|--:|--:|--:|
|A|1001|4827|₹12,450|
|B|1002|7319|₹8,760|
|C|1003|1654|₹25,320|
|D|1004|9082|₹5,875|
|E|1005|3461|₹18,940|
|F|1006|6275|₹31,500|
|G|1007|8193|₹7,240|
|H|1008|2548|₹42,180|
|I|1009|5706|₹15,630|
|J|1010|2094|₹9,415|

> ⚠️ These credentials are hard-coded for demonstration purposes only and should **never** be used in a real banking application.

---

## 💸 Withdrawal Rules

Before processing a withdrawal, the program checks:

1. The amount must be greater than ₹0.
    
2. The amount cannot exceed ₹20,000.
    
3. The amount cannot exceed the available balance.
    
4. At least ₹500 must remain in the account.
    
5. The user must confirm the transaction.
    

Example:

```text
Enter amount to withdraw: 5000

You are about to withdraw ₹5000.00
1. Confirm
2. Cancel
Enter your choice: 1

Withdrawal successful!
Your current balance is ₹7450.00
```

---

## 🧾 Transaction Receipt

After a successful withdrawal or deposit, the program generates a simple transaction receipt.

Example:

```text
================================
       TRANSACTION RECEIPT
================================
Transaction : Withdrawal
Amount      : ₹5000.00
Balance     : ₹7450.00
Status      : SUCCESS
================================
```

---

## 💵 Deposit System

The deposit system checks that the entered amount is greater than ₹0.

After a successful deposit, the program displays:

- Transaction type
    
- Deposited amount
    
- Updated balance
    
- Transaction status
    

Example:

```text
Enter amount to deposit: 2000

You have deposited ₹2000.00
Your current balance is ₹9450.00
```

---

## 🔄 Session Management

The ATM separates the program into two levels:

### ATM Session

Controls whether the ATM itself is running.

```c
while (atm == 1)
```

### User Session

Controls whether a user is currently logged in.

```c
while (session == 1)
```

This allows the following workflow:

```text
ATM Starts
     ↓
User Login
     ↓
PIN Verification
     ↓
ATM Menu
     ↓
User Operations
     ↓
Logout
     ↓
Login Screen
     ↓
Another User
```

This makes the program behave more like an actual ATM rather than simply ending after one user.

---

## 💾 Balance Persistence During Runtime

When a user logs out or exits the ATM, the modified balance is saved back to the corresponding account variable.

For example:

```c
if (pin == a_pin)
{
    a_balance = balance;
}
```

This means that if a user deposits or withdraws money and then logs out, their updated balance can be used when they log in again **during the same program execution**.

> ⚠️ The data is not permanently stored. Closing the program resets all accounts to their original values.

---

## 🧠 C Concepts Demonstrated

This project demonstrates several fundamental C programming concepts:

- Variables
    
- Data types
    
- `printf()`
    
- `scanf()`
    
- `if`
    
- `else if`
    
- `else`
    
- `while` loops
    
- `switch-case`
    
- Logical operators
    
- Comparison operators
    
- Arithmetic operators
    
- Nested conditions
    
- Menu-driven programming
    
- Input validation
    
- Authentication logic
    
- Session management
    
- Transaction processing
    
- Runtime data management
    
- Conditional expressions
    

---

## 📁 Project Structure

```text
ATM-Banking-Management-System/
│
├── atm.c
│
└── README.md
```

---

## 🚀 How to Run

### 1. Clone the repository

```bash
git clone YOUR_REPOSITORY_URL
```

### 2. Navigate into the project

```bash
cd ATM-Banking-Management-System
```

### 3. Compile the program

Using GCC:

```bash
gcc atm.c -o atm
```

### 4. Run the program

#### Windows

```bash
atm.exe
```

#### Linux / macOS

```bash
./atm
```

---

## 🧪 Testing

The program can be tested using the predefined accounts.

### Test 1 — Successful Login

Use:

```text
PIN: 4827
```

Expected result:

```text
PIN accepted!
Welcome, User 1001!
```

### Test 2 — Incorrect PIN

Enter an incorrect PIN three times.

Expected result:

```text
Too many incorrect attempts.
Your session has been terminated.
```

### Test 3 — Withdrawal

Login with:

```text
PIN: 4827
```

Then withdraw:

```text
₹5000
```

Expected balance:

```text
₹7450
```

### Test 4 — Insufficient Balance

Try withdrawing more money than the account contains.

Expected result:

```text
Insufficient balance!
```

### Test 5 — Minimum Balance

Try making a withdrawal that would leave less than ₹500.

Expected result:

```text
Transaction declined.
You must maintain a minimum balance of ₹500.
```

### Test 6 — Logout

Select:

```text
4. Logout
```

Expected result:

```text
Logging out...
Thank you, User 1001!
```

The ATM should then return to the login screen.

---

## ⚠️ Limitations

This is an **educational C project**, not a real banking application.

Current limitations include:

- User information is hard-coded.
    
- PINs are stored as plain integers.
    
- No database is used.
    
- No encryption or secure authentication is implemented.
    
- Account information is stored only during program execution.
    
- Data is lost when the program closes.
    
- The program uses repetitive `if-else` statements.
    
- Arrays and structures are not currently used.
    
- There is no permanent transaction history.
    
- Input handling is basic.
    

---

## 🔮 Future Improvements

Possible future versions could include:

- `struct` for user accounts
    
- Arrays for account management
    
- File handling for permanent account storage
    
- Transaction history
    
- Fund transfers
    
- Account creation
    
- Account deletion
    
- Better input validation
    
- Admin functionality
    
- Permanent PIN changes
    
- Improved authentication
    
- Database integration
    
- Graphical user interface
    

These improvements would gradually move the project from a beginner C program toward a more complete banking simulation.

---

## 📚 What I Learned

While developing this project, I practiced how to combine individual C programming concepts into a larger application.

The project helped me understand:

```text
Variables
   ↓
Conditions
   ↓
Logical Operators
   ↓
Loops
   ↓
Switch-Case
   ↓
Input Validation
   ↓
Authentication
   ↓
Transactions
   ↓
Session Management
   ↓
Complete C Application
```

Instead of writing isolated programs for individual concepts, this project combines them into one practical application.

---

## 🎯 Project Goal

The main goal of this project is to strengthen my understanding of **C programming fundamentals** by building a practical application based on an ATM system.

This project is part of my journey from learning basic C syntax and control flow toward developing larger and more structured programs.

---

## ⭐ Future Direction

The current version intentionally focuses on fundamental C concepts without using advanced features such as arrays, structures, or databases.

Future versions may gradually introduce these concepts as the project evolves.

---

## 📄 License

This project is intended for educational purposes.

You are free to study, modify, and improve the code.