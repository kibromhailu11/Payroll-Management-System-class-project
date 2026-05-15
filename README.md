# Payroll Management System – Class Project

A comprehensive **C++ console-based payroll management application** developed for Addis Ababa Science and Technology University.
The system helps manage employee records, calculate salary taxation accurately, and generate organized payroll reports.

---

## 📌 Features

### 🔐 Secure Data Entry

* Validates employee names (letters only)
* Ensures unique employee IDs
* Checks for valid positive salary inputs

### 💰 Automated Tax Calculation

* Calculates employee tax automatically
* Supports multiple tax brackets from **0% to 35%**

### 🔍 Employee Search System

* Search employees using:

  * Employee ID
  * First Name

### 📊 Professional Payroll Reports

* Displays payroll information in a clean tabular format
* Automatic column alignment for better readability

---

## 🧾 Taxation Logic

The system applies taxation based on salary ranges as follows:

| Salary Range   | Tax Rate |
| -------------- | -------- |
| ≥ 10,500       | 35%      |
| 8,500 – 10,499 | 30%      |
| 6,500 – 8,499  | 25%      |
| 4,500 – 6,499  | 20%      |
| 2,500 – 4,499  | 15%      |
| 1,000 – 2,499  | 10%      |
| < 1,000        | 0%       |

---

## ⚙️ How to Run

### 1️⃣ Install a C++ Compiler

Make sure you have a C++ compiler installed such as **g++**.

---

### 2️⃣ Clone the Repository

```bash
git clone https://github.com/kibromhailu11/Payroll-Management-System-class-project.git
```

---

### 3️⃣ Compile the Program

```bash
g++ main.cpp -o payroll_system
```

---

### 4️⃣ Run the Application

```bash
./payroll_system
```

---

## 🛠️ Technical Implementation

### Language

* C++

### Concepts Used

* Structs
* Arrays
* Modular Functions
* Input Validation
* String Manipulation

---

## 🏫 Institution

Developed as a class project for:

Addis Ababa Science and Technology University

---

