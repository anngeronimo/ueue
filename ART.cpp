#include <iostream>

void drawTriangle(int triangleHeight, int triangleSpacesBefore) {   

for (int i = 0; i < triangleHeight; ++i) {
    // Print leading spaces
    for (int j = 0; j < triangleSpacesBefore - i; ++j) {
        std::cout << ' ';
    }

    // Print the stars for the current row
    for (int j = 0; j < 2 * i + 1; ++j) {
        std::cout << '*';
    }
    std::cout << std::endl;
}
}

void drawRectangle(int length, int width, int spacesBefore) {
    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < spacesBefore; ++j) {
            std::cout << " ";
        }
        for (int j = 0; j < length; ++j) {
            if (i == 0 || i == width - 1 || j == 0 || j == length - 1) {
                std::cout << "*";
            } else {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }
}

void drawTrapezoid(int topBase, int bottomBase, int height) {
    if (topBase >= bottomBase || (bottomBase - topBase) % 2 != 0) {
        std::cout << "Invalid dimensions for an isosceles trapezoid." << std::endl;
        return;
    }

    int spaces = (bottomBase - topBase) / 2;
    int stars = topBase;

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < spaces; ++j) {
            std::cout << " ";
        }
        for (int j = 0; j < stars; ++j) {
            if (i == 0 || i == height - 1 || j == 0 || j == stars - 1) {
                std::cout << "*";
            } else {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
        spaces--;
        stars += 2;
    }
}

void drawBottomPart(int boxSize, int numberOfBoxes, int spacesBetweenBoxes) {
    for (int row = 0; row < boxSize; ++row) {
    for (int box = 0; box < numberOfBoxes; ++box) {
        // Print the stars for the current row of the current box
        for (int col = 0; col < boxSize; ++col) {
            if (row == 0 || row == boxSize - 1 || col == 0 || col == boxSize - 1) {
                std::cout << '*';
            } else {
                std::cout << ' ';
            }
        }
        // Print spaces between boxes
        for (int space = 0; space < spacesBetweenBoxes; ++space) {
            std::cout << ' ';
        }
    }
    std::cout << std::endl;
}
}

int main() {

    int triangleHeight = 5; // Height of the triangle
    int triangleSpacesBefore = 7; // Spaces before the triangle
    drawTriangle(triangleHeight, triangleSpacesBefore);

    int length = 9;
    int width = 5;
    int spacesBefore = 3;
    drawRectangle(length, width, spacesBefore);
    drawRectangle(length, width, spacesBefore);

    int topBase = 9;
    int bottomBase = 15;
    int height = 4;
    drawTrapezoid(topBase, bottomBase, height);

    int boxSize = 3; // Size of each box
    int numberOfBoxes = 4; // Number of boxes
    int spacesBetweenBoxes = 1; // Spaces between boxes
    drawBottomPart(boxSize, numberOfBoxes, spacesBetweenBoxes);

    return 0;
}