# Feetech SCS Servo GUI

Cross-platform Qt GUI application for controlling Feetech SCS215 and similar servos via serial communication.

## Features

- Real-time servo position monitoring and control
- Position slider and numeric input controls
- Torque enable/disable functionality
- Register read/write operations
- Servo parameter configuration
- **Serial port selection with auto-detection**
- Cross-platform support (Linux, macOS, Windows)

## Requirements

- Qt 5.x or Qt 6.x with SerialPort module
- C++11 compatible compiler
- Serial-to-USB adapter (for servo communication)

## Installation

### Dependencies

#### Linux (Ubuntu/Debian)
```bash
# For Qt 5
sudo apt install qt5-default libqt5serialport5-dev

# For Qt 6
sudo apt install qt6-base-dev qt6-serialport-dev
```

#### macOS
```bash
# Install Qt via Homebrew
brew install qt

# Qt will be installed in /opt/homebrew (Apple Silicon) or /usr/local (Intel)
```

#### Windows
Download and install Qt from https://www.qt.io/download

### Building

1. Clone or download this repository
2. Navigate to the project directory
3. Build using qmake:

```bash
# Generate Makefile
qmake Feetech_servo_gui.pro

# Build the application
make

# Clean build artifacts (if needed)
make clean
```

### Running

#### Linux
```bash
./Feetech_servo_gui
```

#### macOS
```bash
# Run from terminal
open Feetech_servo_gui.app

# Or run the binary directly
./Feetech_servo_gui.app/Contents/MacOS/Feetech_servo_gui
```

#### Windows
```cmd
Feetech_servo_gui.exe
```

## Usage

### Serial Port Configuration

The application now includes automatic serial port detection:

1. **Automatic Detection**: The app scans for available serial ports on startup
2. **Port Selection**: Use the dropdown menu to select your servo's serial port
3. **Refresh Ports**: Click "Refresh" to rescan for newly connected devices
4. **Connection Status**: Check the status bar for connection information

#### Default Port Patterns

- **Linux**: `/dev/ttyUSB*`, `/dev/ttyACM*`
- **macOS**: `/dev/cu.*`, `/dev/tty.*`
- **Windows**: `COM*`

### Servo Control

1. **Set Servo ID**: Enter the ID of the servo you want to control (default: 1)
2. **Enable Torque**: Check the "Torque Enabled" checkbox to enable servo movement
3. **Position Control**: 
   - Use the position slider for real-time control
   - Or enter a specific value in the spin box
4. **Monitor Position**: The current position is displayed and updated in real-time
5. **Register Operations**:
   - Read individual register values
   - Write custom values to registers
   - Set default parameters optimized for SCS servos

### Communication Settings

- **Baud Rate**: Fixed at 1,000,000 bps (1M)
- **Protocol**: SCS servo communication protocol
- **Timeout**: 2ms I/O timeout

## Troubleshooting

### Port Access Issues (Linux)
Add your user to the dialout group:
```bash
sudo usermod -a -G dialout $USER
# Log out and back in for changes to take effect
```

### Permission Denied (macOS)
Grant terminal app access to serial ports in System Preferences > Security & Privacy > Privacy > Developer Tools.

### No Servo Response
1. Verify the correct serial port is selected
2. Check servo power supply
3. Ensure correct servo ID is set
4. Verify servo is connected and working with other tools

## Development

See `CLAUDE.md` for detailed development guidance and architecture information.

