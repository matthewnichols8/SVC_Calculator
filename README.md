# SVC Exception Calculator

This project is a simple **SVC (Supervisor Call) Exception Calculator** that performs basic arithmetic operations (addition, subtraction, multiplication, and division) on two input numbers using a custom `SVC_Handler()` function. It demonstrates how SVC exceptions can be leveraged to handle arithmetic operations at the system level.

## Features

- Add two numbers
- Subtract two numbers
- Multiply two numbers
- Divide two numbers (with error handling for division by zero)

## How it Works

The core functionality of the calculator is implemented using an SVC (Supervisor Call) exception handler. The SVC exception allows the program to trigger a software interrupt, passing control to the `SVC_Handler()` function. This handler processes the operation using the r0 and r1 registers and returns the result.

### Supported Operations:
1. **Addition**: Adds two numbers.
2. **Subtraction**: Subtracts the second number from the first.
3. **Multiplication**: Multiplies two numbers.
4. **Division**: Divides the first number by the second (includes error handling for division by zero).
5. 
### Prerequisites

- ARM Cortex-M compatible microcontroller (e.g., STM32, NXP, etc.)
- ARM GCC Toolchain for compiling (or an appropriate toolchain for your platform)
- A debugger to upload and debug the program on the target microcontroller

## Contributing

Feel free to open issues or submit pull requests if you have any improvements or suggestions for the project!

1. Fork the repository
2. Create your feature branch (`git checkout -b feature-name`)
3. Commit your changes (`git commit -m 'Add feature'`)
4. Push to the branch (`git push origin feature-name`)
5. Create a new pull request

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

---

Feel free to modify or extend this README to suit your specific project requirements!
