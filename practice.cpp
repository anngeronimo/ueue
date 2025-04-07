#include <iostream>
using namespace std;

void drawTriangle(int height, int spacesBefore) {
for (int i = 0; i < height; ++i) {
    for (int j = 0; j < spacesBefore; ++j) {
        std::cout << ' ';
    }
    for (int j = 0; j <= i; ++j) {
        if (i == height - 1 || j == 0 || j == i) {
            std::cout << '*';
        } else {
            std::cout << ' ';
        }
    }
    std::cout << std::endl;
}
}

void drawHollowTrapezoid(int topBase, int bottomBase, int height1) {
    
    if (topBase >= bottomBase || height1 <= 0) {
        cout << "Invalid dimensions!" << endl;
        return;
    }

    int spaces = (bottomBase - topBase) / 2;  // Leading spaces for the top row
    int middleSpaces = topBase - 2;           // Number of spaces inside the trapezoid

    // Loop for each row of the trapezoid
    for (int i = 0; i < height1; ++i) {
        // Print leading spaces
        for (int j = 0; j < 15; ++j) {
            cout << " ";
        }
        for (int j = 0; j < spaces; ++j) {
            cout << " ";  // Print spaces before the stars
        }

        // Print the left boundary of the trapezoid
        cout << "*";

        // If it's the first row, print the stars for the top base
        if (i == 0) {
            for (int j = 0; j < topBase - 2; ++j) {
                cout << "*";  // Print stars for the top row
            }
        } else {
            // Otherwise, print spaces inside the trapezoid
            for (int j = 0; j < middleSpaces; ++j) {
                cout << " ";  // Print hollow space inside the trapezoid
            }
            if (middleSpaces >= 0) {
                cout << "*";  // Print the right boundary of the trapezoid
            }
        }

        // Print the right boundary of the trapezoid
        cout << "*" << endl;

        // Adjust spaces for the next row
        spaces--;
        middleSpaces += 2;
    }

    // Print the bottom base of the trapezoid
    for (int i = 0; i < bottomBase; ++i) {
        cout << "*";  // Print the bottom base
    }
    cout << endl;
}

void drawSquare(int side) {
    for (int i = 0; i < side; i++) {
        for (int j = 0; j < 15; j++) {
            cout << " ";  // Print leading spaces
        }
        for (int j = 0; j < side; j++) {
            if (i == 0 || i == side - 1 || j == 0 || j == side - 1) {
                cout << "*";  // Print border of the square
            } else {
                cout << " ";  // Print hollow space inside the square
            }
        }
        cout << endl;
    }
}

int main() {
    int height = 3;       // Triangle height
    int spacesBefore = 15; // Leading spaces for the triangle
    int side = 5;         // Side length for squares
    int topBase = 5;   // Top base width
    int bottomBase = 11; // Bottom base width
    int height1 = 3;    // Height of the trapezoid

    drawTriangle(height, spacesBefore);    // Draw the triangle
    drawSquare(side);        // Draw the first square
    drawSquare(side);        // Draw the second square
    drawHollowTrapezoid(topBase, bottomBase, height1);  // Draw the trapezoid

    return 0;
}
