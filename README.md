# Ethernet Packet Generator

## Overview

The Ethernet Packet Generator is a C++ application designed to generate and manage Ethernet packets based on configurable parameters. This project follows a modular and professional approach, ensuring seamless integration across various functionalities. It adheres to protocol standards and employs object-oriented programming principles to maintain a clean and maintainable codebase.

## Features

- **Modular Architecture**: Code is organized into multiple files, each responsible for a specific aspect of packet generation, burst management, and file handling.
- **Configuration-Driven**: Reads packet and burst configurations from a setup file to customize packet generation and output.
- **Alignment Handling**: Ensures packets are 4-byte aligned by adding Interframe Gaps (IFGs) where necessary.
- **Stream Management**: Manages packet generation and burst transmission based on streaming duration and periodic bursts.
- **Flexible Input/Output**: Accepts command-line arguments for specifying configuration and output files.

## Specifications

### Packet Structure

1. **Preamble**: Starts each packet.
2. **Start of Packet (SOP)**: Marks the beginning of the Ethernet frame.
3. **Destination Address**: 48-bit address of the packet recipient.
4. **Source Address**: 48-bit address of the packet sender.
5. **Ethernet Type**: Identifies the protocol used in the payload.
6. **Payload**: The data being transmitted.
7. **CRC**: Cyclic Redundancy Check for error detection.
8. **IFGs**: Interframe Gaps added for alignment if necessary.

### Setup File Format

The setup file defines the parameters for packet generation and burst management. Example parameters include:

- `Eth.LineRate`: Transmission rate in gigabits per second.
- `Eth.CaptureSizeMs`: Time window for packet generation (in milliseconds).
- `Eth.MinNumOfIFGsPerPacket`: Minimum number of IFGs after each packet.
- `Eth.DestAddress`: Destination address (48-bit hex format).
- `Eth.SourceAddress`: Source address (48-bit hex format).
- `Eth.MaxPacketSize`: Maximum packet size (including all components).
- `Eth.BurstSize`: Number of packets per burst.
- `Eth.BurstPeriodicity_us`: Periodicity of bursts (in microseconds).

### Example Setup File

```plaintext
Eth.LineRate = 10
Eth.CaptureSizeMs = 10
Eth.MinNumOfIFGsPerPacket = 12
Eth.DestAddress = 0x010101010101
Eth.SourceAddress = 0x333333333333
Eth.MaxPacketSize = 1500
Eth.BurstSize = 3
Eth.BurstPeriodicity_us = 100
```
## Usage

### Building the Project

1. **Open Command Prompt**: Navigate to the folder where the source files are located. You can do this by opening the directory in Windows Explorer, typing `cmd` in the directory bar, and pressing Enter.

2. **Compile the Code**: Use the following command to compile the project:

    ```bash
    g++ main.cpp PacketConfig.cpp EthernetPacket.cpp BurstGenerator.cpp FileWriter.cpp Utils.cpp -o program_output
    ```

   Press Enter and wait for the executable to be created.

### Running the Program

After building the project, you can run the program with the configuration and output files as arguments:

```bash
program_output.exe setup.txt data.txt
```




