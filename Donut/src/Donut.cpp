#include "matrix/Matrix.h"
#include <cmath>
#include <iostream>
#include <windows.h>

#define M_PI 3.14159265358979323846

int main()
{
// Adopted constants
    const double r1 = 1.; // radious of the circle
    const double r2 = 2.; // radious of the torus
    const int thetaNum = 200; // number of points on the circle
    const int phiNum = 200; // number of torus circles

    const double a = 0.0872664626; // rotation speed per frame around the x axis in radians
    const double b = 0.0872664626; // rotation speed per frame around the z axis in radians

    const double K2 = 5.; // z-direction offset
    const int screenWidth = 50; // screen width
    const int screenHeight = 24; // screen height
    const double K1w = screenWidth*K2*3/(8*(r1+r2)); // focal length for the width of the screen
    const double K1h = screenHeight*K2*3/(8*(r1+r2)); // focal length for the height of the screen

// Constants calculated on the basis of the above ones
    const double thetaSpacing = 2*M_PI/thetaNum;
    const double phiSpacing = 2*M_PI/phiNum;
    const int torusSize = phiNum*thetaNum; // the size of the torusCoords array

    const double lightDir[3] = {0., 1., -1.}; // light direction (not normalized, because the appropriate range is used in selecting a sign based on illumination)
    double ilumi[torusSize]; // an array that stores the illumination values of the appropriate coordinates

    char output[screenHeight][screenWidth]; // output buffer
    for(int i=0; i<screenHeight; i++)
        for(int j=0; j<screenWidth; j++)
            output[i][j] = ' ';
    double zBuffer[screenHeight][screenWidth]; // z-buffer
    for(int i=0; i<screenHeight; i++)
        for(int j=0; j<screenWidth; j++)
            zBuffer[i][j] = 0.;

    const char outputChars[14] = ".-~:;=!*#$@@"; // successive signs arranged along with their increasing illumination
// --------------------------------------------------------------------
// Definition of the torus
    Matrix torusCoords(torusSize, 3);

    {
    // circle coordinates, shifted by the radius of the torus,
    // written in matrix form
    Matrix circleCoords(thetaNum, 3);
    double d=0;
    for(int i=0; i<thetaNum; i++)
    {
        circleCoords(i, 0) = r1*sin(d) + r2;
        circleCoords(i, 1) = r1*cos(d);
        d += thetaSpacing;
    }

    // rotation matrix
    double cosPhi = cos(phiSpacing);
    double sinPhi = sin(phiSpacing);
    double a[3][3] = {
        {cosPhi , 0., sinPhi},
        {0.     , 1., 0.    },
        {-sinPhi, 0., cosPhi}
    };
    Matrix rotMat(3, 3);
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            rotMat(i, j) = a[i][j];
    
    // definition of torus coordinates
    for(int i=0; i<thetaNum; i++)
        for(int j=0; j<3; j++)
            torusCoords(i, j) = circleCoords(i, j);
    
    int offset = thetaNum;
    for(int i=1; i<phiNum; i++)
    {
        circleCoords *= rotMat; // the result matrix, which should be appropriately assigned to torusCoords
        for(int j=0; j<thetaNum; j++)
            for(int k=0; k<3; k++)
            {
                torusCoords(j+offset, k) = circleCoords(j, k);
            }
        offset += thetaNum;
    }
    }
// --------------------------------------------------------------------
// Definition of vectors normal to torus coordinates
    Matrix torusNorm(torusSize, 3);

    {
    // unit circle coordinates written in matrix form (we can and should omit the r2 shift when calculating the normal vector)
    Matrix circleCoords(thetaNum, 3);
    double d=0;
    for(int i=0; i<thetaNum; i++)
    {
        circleCoords(i, 0) = sin(d);
        circleCoords(i, 1) = cos(d);
        d += thetaSpacing;
    }

    // rotation matrix
    double cosPhi = cos(phiSpacing);
    double sinPhi = sin(phiSpacing);
    double a[3][3] = {
        {cosPhi , 0., sinPhi},
        {0.     , 1., 0.    },
        {-sinPhi, 0., cosPhi}
    };
    Matrix rotMat(3, 3);
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            rotMat(i, j) = a[i][j];
    
    // definition of normal vectors
    for(int i=0; i<thetaNum; i++)
        for(int j=0; j<3; j++)
            torusNorm(i, j) = circleCoords(i, j);
    
    int offset = thetaNum;
    for(int i=1; i<phiNum; i++)
    {
        circleCoords *= rotMat; // the result matrix to be assigned appropriately to the torusNorm
        for(int j=0; j<thetaNum; j++)
            for(int k=0; k<3; k++)
            {
                torusNorm(j+offset, k) = circleCoords(j, k);
            }
        offset += thetaNum;
    }
    }
// --------------------------------------------------------------------
// Rotating torus
    // definition of the matrix of rotation around the x and z axes
    Matrix A(3, 3), B(3, 3);
    {
    double sinA = sin(a), cosA = cos(a), sinB = sin(b), cosB = cos(b);
    double aa[3][3] =
    {
        {1.,  0.,   0.},
        {0.,  cosA, sinA},
        {0., -sinA, cosA}
    };
    
    double bb[3][3] =
    {
        { cosB, sinB, 0.},
        {-sinB, cosB, 0.},
        { 0.,   0.,   1.}
    };

    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
        {
            A(i, j) = aa[i][j];
            B(i, j) = bb[i][j];
        }
    }

Matrix coords(torusCoords), norm(torusNorm);
while(true)
{
    // rotations of coordinates and their corresponding normal vectors
    coords *= A;
    coords *= B;
    for(int i=0; i<torusSize; i++)
        coords(i, 2) += K2; // z-direction offset

    norm *= A;
    norm *= B;
// --------------------------------------------------------------------
// Projection on the screen

    // calculation of illumination
    for(int i=0; i<torusSize; i++)
        ilumi[i] = norm(i, 0)*lightDir[0] + norm(i, 1)*lightDir[1]
        + norm(i, 2)*lightDir[2];

    // projection onto the screen
    for(int i=0; i<torusSize; i++)
    {
        if(ilumi[i] > 0.) // if the illumination is non-positive, you cannot see anything
        {
            double ooz = 1/coords(i, 2); // one over z
            int x = (int) (screenHeight/2 + K1h*ooz*coords(i, 0)); // x coordinate on the screen
            int y = (int) (screenWidth/2 - K1w*ooz*coords(i, 1)); // y coordinate on the screen

            if(ooz > zBuffer[x][y]) // z-buffer algorithm (only open pixels are considered)
            {
                zBuffer[x][y] = ooz; // update the zBuffer
                int ilumiIdx = ilumi[i]*8; // value range 0..11
                output[x][y] = outputChars[ilumiIdx]; // sign reflecting the value of illumination
            }
        }        
    }

    // displaying the result buffer
    for(int i=0; i<screenHeight; i++)
    {
        for(int j=0; j<screenWidth; j++)
            std::cout << output[i][j];
        std::cout << '\n';
    }

    // resetting buffers
    for(int i=0; i<screenHeight; i++)
        for(int j=0; j<screenWidth; j++)
            output[i][j] = ' ';

    for(int i=0; i<screenHeight; i++)
        for(int j=0; j<screenWidth; j++)
            zBuffer[i][j] = 0.;
        
    // return the torus to its previous location
    for(int i=0; i<torusSize; i++)
        coords(i, 2) -= K2;
    
    Sleep(50); // Sleep for 50 ms
    system("cls"); // wipe the terminal
}
}
