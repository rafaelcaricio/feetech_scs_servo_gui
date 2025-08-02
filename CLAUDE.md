# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project Overview

This is a Qt-based GUI application for controlling Feetech SCS215 and similar servos over serial communication. The application provides a graphical interface for servo control operations including position control, speed control, and parameter configuration.

## Build System

This project uses Qt's qmake build system with a `.pro` project file.

### Build Commands

```bash
# Generate Makefile from .pro file
qmake Feetech_servo_gui.pro

# Build the application
make

# Clean build artifacts
make clean
```

### Dependencies

- Qt 5 with the following modules:
  - core
  - gui 
  - widgets
  - serialport
- On Ubuntu/Debian: `sudo apt install libqt5serialport5`

## Architecture

### Core Components

1. **MainWindow** (`mainwindow.h/cpp`) - Main Qt GUI window that handles user interface
2. **SCServo** (`SCServo.h/cpp`) - Qt serial port implementation for servo communication
3. **SCSProtocol** (`SCSProtocol.h/cpp`) - Low-level servo protocol implementation with command definitions

### Key Design Patterns

- **Inheritance**: `SCServo` inherits from `SCSProtocol` to provide Qt-specific serial communication
- **Abstract Interface**: `SCSProtocol` defines virtual methods for communication that `SCServo` implements
- **Protocol Abstraction**: Clean separation between protocol logic and hardware communication

### Serial Communication

- Default port: `/dev/ttyUSB0`
- Default baud rate: 1M (1,000,000 bps)
- Configuration can be modified in `SCServo.cpp`

### Protocol Features

The SCS protocol supports:
- Position control with time and speed parameters
- Continuous rotation mode
- Synchronous and asynchronous operations
- Parameter reading/writing (voltage, temperature, position)
- Servo ping and reset operations

## File Structure

- `main.cpp` - Application entry point
- `mainwindow.*` - Main GUI window
- `SCServo.*` - Qt serial communication layer
- `SCSProtocol.*` - Servo protocol implementation
- `mainwindow.ui` - Qt Designer UI file
- `icons.qrc` - Qt resource file for icons
- `Feetech_servo_gui.pro` - Qt project configuration

## Development Notes

- The project uses C++11 features
- Qt deprecated API warnings are enabled
- Serial communication timeout is configurable via `IOTimeOut` property
- Protocol supports both individual servo control and synchronized multi-servo operations