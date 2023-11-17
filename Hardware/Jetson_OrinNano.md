# NVIDIA Jetson Orin Nano 8 GB Specifications

## Graphics Processor
- **GPU Name**: GA10B
- **Architecture**: Ampere
- **Foundry**: Samsung
- **Process Size**: 8 nm
- **Cores**: 1024
- **TMUs**: 32
- **ROPs**: 16
- **Memory Size**: 8 GB
- **Memory Type**: LPDDR5
- **Bus Width**: 128 bit
- **Launch Price**: 299 USD
- **Current Price**: 499 USD (Nov 2023)

## Performance
- **GPU Clock**: 625 MHz
- **Memory Clock**: 1067 MHz (4.3 Gbps effective)
- **Shading Units**: 1024
- **TMUs**: 32
- **ROPs**: 16
- **SM Count**: 8
- **Tensor Cores**: 32
- **L1 Cache**: 128 KB (per SM)
- **L2 Cache**: 256 KB
- **Pixel Rate**: 10.00 GPixel/s
- **Texture Rate**: 20.00 GTexel/s
- **FP16 (half)**: 2.560 TFLOPS (2:1)
- **Memory Bandwidth**: 68.29 GB/s

## Board Design
- **Slot Width**: IGP
- **Length**: 70 mm
- **Width**: 45 mm
- **TDP**: 15 W
- **Outputs**: Portable Device Dependent

## Graphics Features
- **DirectX**: 12 Ultimate (12_2)
- **OpenGL**: 4.6
- **OpenCL**: 3.0
- **Vulkan**: 1.3
- **CUDA**: 8.6
- **Shader Model**: 6.7

*Note: The device was launched in March 2023 and is built on the 8 nm process. It's primarily intended for use in laptops/notebooks and does not have display connectivity as it uses the output of the host mobile device*&#8203;``【oaicite:0】``&#8203;.

# NVIDIA Jetson Orin Nano AI Performance

## Overview
- **AI Performance**: Up to 40 trillion operations per second (TOPS)
- **Efficiency**: Delivers 50x the performance per watt compared to the previous-generation Jetson Nano
- **Upgrade**: Provides 80x the performance of the previous-generation Jetson Nano

## Capabilities
- **Suitable Applications**: Ideal for a range of edge AI and robotics applications, including entry-level AI-powered robots, smart drones, and intelligent vision systems.
- **Advanced Models**: Capable of running advanced transformer and robotics models.
- **Software Support**: Compatible with NVIDIA Metropolis and Isaac Platforms, providing scalable software, modern AI stack, and application-specific AI workflow.

## Context
- The Jetson Orin Nano is part of the NVIDIA Jetson Orin series, which offers scalable performance for autonomous machines and robotics applications. It ranges from the entry-level Jetson Orin Nano to the high-performance Jetson AGX Orin.
- This module is designed for energy efficiency while delivering powerful AI computing, suitable for next-gen products and autonomous machines.

*Sources: [NVIDIA](https://www.nvidia.com/en-us/autonomous-machines/embedded-systems/jetson-orin/), [TechPowerUp](https://

# NVIDIA Jetson Orin Nano GPIO Setup

## 40-pin Expansion Header
- **Header Information**: The Jetson Orin Nano includes a 40-pin expansion header.
- **Power Indicators**: It features a power indicator LED and a USB-C port for data only.
- **Connectivity Options**: The board offers a Gigabit Ethernet port, four USB 3.1 Type A ports, a DisplayPort connector, and a DC Barrel jack for 19V power input.
- **Camera Connectors**: It includes MIPI CSI camera connectors.

## GPIO Pinout
- **I2C and UART Pins**: By default, I2C and UART pins are assigned on the expansion header.
- **GPIO Assignment**: All other pins, except power and ground, are assigned as GPIO. Pins labeled with other functions are suggested functions.
- **Power Supply**: The header includes 3.3VDC and 5.0VDC power pins.
- **Communication Protocols Supported**: Includes pins for I2C, UART, SPI, and PWM.
- **Special Functions**:
  - Pin 15 and 33 can be configured as PWM.
  - Pins 27 and 28 are on I2C bus 1.
- **Linux GPIO Numbering**: Each pin has a specific GPIO number within a GPIO controller and a global Linux GPIO number.

## Additional Notes
- **Layout Comparison**: The GPIO layout is the same as the Xavier NX.
- **GPIO Bases**: There are two GPIO bases, 316 & 348, with all pins based from 348.
- **PWM Configuration**: Details for configuring PWM on specific pins are provided.

*Note: For detailed pin assignments and configurations, refer to the NVIDIA Jetson Orin Nano Developer Kit Carrier Board Specification.*

Sources: 
- [NVIDIA Jetson Orin Nano Developer Kit Getting Started](https://developer.nvidia.com/embedded/learn/jetson-orin-nano-devkit-user-guide/hardware_spec.html)&#8203;``【oaicite:2】``&#8203;
- [JetsonHacks: NVIDIA Jetson Orin Nano GPIO Header Pinout](https://jetsonhacks.com/2023/04/26/nvidia-jetson-orin-nano-gpio-header-pinout/)&#8203;``【oaicite:1】``&#8203;
- [NVIDIA Jetson Orin Nano Developer Kit User Guide](https://developer.nvidia.com/embedded/learn/jetson-orin-nano-devkit-user-guide/hardware_spec.html)&#8203;``【oaicite:0】``&#8203;
