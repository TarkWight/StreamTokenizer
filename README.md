# StreamTokenizer

StreamTokenizer is an application for lexical and syntactic analysis of `std::cout` commands in C++. The application is implemented using Windows Forms and provides a graphical interface for inputting strings, analyzing them, and displaying the results.

## Table of Contents

- [Installation](#installation)
- [Usage](#usage)
- [Project Structure](#project-structure)
- [Support](#support)
- [Authors](#authors)
- [License](#license)

## Installation

To run the project, follow these steps:

1. Install Visual Studio with C++ and Windows Forms development support.
2. Clone the repository:
    ```sh
    git clone https://github.com/TarkWight/StreamTokenizer.git
    ```
3. Open the project in Visual Studio.
4. Build the solution and run the project.

## Usage

1. Launch the application.
2. Enter a `std::cout` command in the input text box.
3. Click the "Confirm" button to analyze the entered string.
4. The analysis result will be displayed in the output text box, showing each token and its type.

## Project Structure

- `MainWindow.h`: The main header file for the Windows Forms application.
- `LexerParser.hpp`: Contains the lexer and parser logic.
- `LexerParser.cpp`: Implements the lexer and parser functions.

## Support

For any issues, please open an issue on the [StreamTokenizer issues](https://github.com/TarkWight/StreamTokenizer/issues).

## Authors

- **Arsentiy** - [Tark Wight](https://github.com/TarkWight)

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
