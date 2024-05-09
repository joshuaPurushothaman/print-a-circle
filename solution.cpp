#include <iostream>
#include <cmath>
#include <string>

#include "./colors.h"

using namespace std;

void printOut(int radius, double tolerance, bool ascii_compatible) {
    const int v_border = 5;
    const int h_border = v_border;

    for (int y = -(radius + v_border); y <= radius + v_border; y++) {
        // ║: 186; 
        // ╗: 187; 
        // ╝: 188; 
        // ╚: 200; 
        // ╔: 201; 
        // ═: 205; 
        if (abs(y) == radius + v_border) {
            for (int x = -(radius + h_border); x <= radius + h_border; x++) {
                if (ascii_compatible) {
                    cout << "=";
                }
                else {
                    cout << (char)205;
                }
            }
            cout << endl;
            continue;
        }

        for (int x = -(radius + h_border); x <= radius + h_border; x++) {
            if (abs(x) == radius + h_border) {
                if (ascii_compatible) {
                    cout << "|";
                }
                else {
                    cout << (char)186;
                }
                continue;
            }
            else {
                double x2y2 = pow(x, 2) + pow(y, 2);
                double r2 = pow(radius, 2);

                double prox_to_circle = abs(x2y2 - r2);
                if (prox_to_circle < tolerance) {
                    // cout << CYN << 'O' << CRESET;
                    // ░▒▓ = (char)176 to 178
                    int char_choice = (prox_to_circle / tolerance) * 3;
                    char char_out = 178 - char_choice;

                    if (ascii_compatible) {
                        char_out = '#';
                    }


                    string colors[] = { BLU, CYN, GRN, YEL, RED }; // TODO: Background colors for combo
                    int color_choice = (prox_to_circle / tolerance) * sizeof(colors) / sizeof(colors[0]);
                    string color_out = colors[color_choice];

                    cout << color_out << char_out << CRESET;
                }
                else {  // background
                    if (ascii_compatible) {
                        cout << ' ';
                    }
                    else {
                        cout << (char)176;
                    }
                    // cout << RED << '.' << CRESET;
                }
            }
        }
        cout << endl;
    }
}

int main(int argc, char const* argv[])
{
    if (argc != 4) {
        // TODO: not checking for complete input validation...
        printf("ERROR: Expected arguments: [radius: int] [tolerance: double] [ascii_compatible: bool]\n");
        return -1;
    }

    int radius = atoi(argv[1]);
    double tolerance = atof(argv[2]);
    bool ascii_compatible = (bool)atoi(argv[3]);

    // int radius = 16;
    // double tolerance = 150;

    printOut(radius, tolerance, ascii_compatible);

    return 0;
}