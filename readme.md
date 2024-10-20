# Angle Navigation Class

## Overview

This C++ program implements a class named `angle` that allows users to input and display navigational angles in degrees and minutes, along with their respective cardinal directions (N, S, E, W). It supports dynamic memory allocation and includes features for data validation.


## How It Works

1. **Dynamic Memory Allocation**: The program uses pointers to dynamically allocate memory for the degrees, minutes, and direction variables.
2. **Input and Validation**: Users are prompted to enter the angle's degrees, minutes, and direction. The input is validated to ensure it falls within acceptable ranges.
3. **Display**: The program outputs the angle in the format `179°59.9’ E`.

## Features

- **Dynamic Memory Management**: Utilizes dynamic memory allocation for storing angle components.
- **User Input Validation**: Ensures that degrees, minutes, and directions are valid.
- **Copy Constructor**: Implements a copy constructor to create deep copies of angle objects.

## Member Functions

- **Constructors**:
  - Default Constructor: Initializes the angle class.
  - Parameterized Constructor: Accepts values for degrees, minutes, and direction.
  - Copy Constructor: Creates a deep copy of an existing angle object.

- **Destructor**: Releases dynamically allocated memory for angle components.

- **Display Function**: Outputs the angle in the specified format and checks for validity.

- **Dynamic Allocation Function**: Allocates memory for an angle object.

## Usage

To use the program:

1. Compile the code using a C++ compiler.
2. Run the executable.
3. Input the angle's degrees, minutes, and direction when prompted.
4. The program will display the entered angle in the required format.
5. You can continue entering angles until you choose to exit.

### Example Interaction

Enter the degree: 149 Enter the minutes: 34.8 Enter the directions (N, S, E, W): W Angle: 149° 34.8' W

Do you want to enter another angle for navigation (Y, N): Y Enter the degree: 17 Enter the minutes: 31.5 Enter the directions (N, S, E, W): S Angle: 17° 31.5' S

Do you want to enter another angle for navigation (Y, N): N


## Contributing

Feel free to contribute by submitting issues or pull requests. Suggestions for enhancements are always welcome!
email: muhammadannas.2356@gmail.com

## License

This project is licensed under the MIT License. See the LICENSE file for more details.
