# Keylogger Tutorial (C++)

This is a small Windows keylogger project written in C++ as part of a learning exercise.  
It captures keystrokes using the Windows API and writes them to a log file for study and testing purposes only.

## Educational Use Only

This project is for **educational** and **ethical** use only.  
Do not use it on any system you do not own or have explicit permission to test.

## Features

- Captures keyboard input using `GetAsyncKeyState`
- Converts key codes to readable characters
- Logs keystrokes to a text file
- Demonstrates basic use of the Windows API in C++

## Requirements

- Windows 10/11  
- g++ (MinGW) or another C++ compiler  
- Visual Studio Code (optional, for editing)

## How to Build and Run

```bash
g++ main.cpp -o keylogger.exe
keylogger.exe
