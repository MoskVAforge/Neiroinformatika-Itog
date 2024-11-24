#include <iostream>
#include <cmath>

using namespace std;

double Verhparabola(int x, double epsilon, double offset) 
{
    return epsilon * pow(x, 2)+offset;
}

double Nizparabola(int x, double epsilon, double offset) 
{
    return -epsilon * pow(x, 2)-offset;
}

int main() 
{
    int koord1;
    int koord2;
    int priznaki[10];
    double rezf1, rezf2, rezf3;

    cout << "Author - Moskalenko Vitaly Alexandrovich UIB-311" << endl;
    for (int i=0;i<10;i++)
    {
        cin >> priznaki[i];
    }

    koord1=priznaki[2];
    koord2=priznaki[3];

    rezf1=-13.4444444444444*koord1+32.7111111111111*koord2-1971.83432098766;
    rezf2=6.13333333333333*koord1+60.6666666666667*koord2-3801.69777777779;
    rezf3=-20.9333333333333*koord1+25.0666666666667*koord2-333.333333333333;

    const double epsilon1 = 0.1;
    const double epsilon2 = 0.1;
    const double epsilon3 = 0.1;
    const double offset1 = 1.0;  
    const double offset2 = 2.0;

    bool neoprf1=(rezf1>=Nizparabola(koord1, epsilon1, offset2))&&(rezf1<=Verhparabola(koord1, epsilon1, offset1));
    bool neoprf2=(rezf2>=Nizparabola(koord1, epsilon2, offset2))&&(rezf2<=Verhparabola(koord1, epsilon2, offset1));
    bool neoprf3=(rezf3>=Nizparabola(koord1, epsilon3, offset2))&&(rezf3<=Verhparabola(koord1, epsilon3, offset1));

    if (neoprf1) 
    {
        cout << "Unknown class!" << endl;
    } 
    else if (neoprf2) 
    {
        cout << "Unknown class!" << endl;
    } 
    else if (neoprf3) 
    {
        cout << "Unknown class!" << endl;
    } 
    else 
    {
        if (rezf1 > 0) 
        {
            if (koord1 > 13) 
            {
                cout << "C" << endl;
            } 
            else 
            {
                cout << "D" << endl;
            }
        } 
        else 
        {
            if (rezf2 > 0) 
            {
                cout << "C" << endl;
            } 
            else 
            {
                if (rezf3 > 0) 
                {
                    cout << "A" << endl;
                } 
                else 
                {
                    cout << "B" << endl;
                }
            }
        }
    }

    return 0;
}
