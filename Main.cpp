#include <iostream>
#include <fstream>
#include "EulerMethod.h"
using namespace std;
int main()
{
    int range = 4;
    double x0 = -2, y0 = 4, delta;
    cout << "enter range, x0, y0, and delta" << endl;
    cin >> range >> x0 >> y0 >> delta;
    EulerMethod obj1(range, x0, y0);

    fstream myPoints;
    myPoints.open("data.txt", ios::out);
    for (int i = 0; i < (int)(obj1.length); i++)
    {
        myPoints << obj1.Eulerpoints[i].P[0] << " " << obj1.Eulerpoints[i].P[1] << std::endl;
    }
    myPoints.close();

    FILE *gnuplotPipe = popen("gnuplot -persist", "w");
    std::cout << " - 2 - " << std::endl;
    if (gnuplotPipe)
    {
        // plot style and labels
        fprintf(gnuplotPipe, "set title 'Euler Method Points'\n");
        fprintf(gnuplotPipe, "set xlabel 'x'\n");
        fprintf(gnuplotPipe, "set ylabel 'y'\n");

        // plot the data from the file
        fprintf(gnuplotPipe, "plot 'data.txt' with lines\n");
        fflush(gnuplotPipe);

        // w9 for user input before closing the plot window
        std::cout << "Press enter to exit..." << std::endl;
        std::cin.ignore();

        // close GNU Plot pipe
        pclose(gnuplotPipe);
    }
    return 0;
}
