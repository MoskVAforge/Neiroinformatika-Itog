#include <iostream>
#include <algorithm>
#include <ctime>
#include <cstring>

using namespace std;

int main()
{
    int maxeras=20;
    int kolich=0;
    int sums[2]={0}; 

    int cifri[10][10]=
    {
        {1,1,0,1,0,1,0,1,1,0}, //0
        {0,0,1,1,0,0,0,1,0,1}, //1
        {0,1,0,1,0,0,1,0,1,2}, //2
        {0,1,1,0,1,0,1,0,0,3}, //3
        {1,0,0,1,1,0,0,1,0,4}, //4
        {1,1,0,0,1,0,0,1,1,5}, //5 
        {0,0,1,0,1,1,0,1,1,6}, //6
        {0,1,1,0,0,1,0,0,0,7}, //7
        {1,1,0,1,1,1,0,1,1,8}, //8
        {1,1,0,1,1,0,1,0,0,9}  //9
    };

    int Omegi[2][10] =
    {
        {0,1,4,7,2,-8,1,9,2,0},  
        {8,7,0,3,-9,3,7,0,0,4}   
    };

    int randommassiv[500]=
    {
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
        2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
        3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
        4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
        5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,
        6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,
        7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,
        8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,
        9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9
    };

    random_shuffle(randommassiv, randommassiv + 500);

    int viborka[500][10];
    for (int i=0;i<500;i++)
    {
        for (int j=0;j<10;j++)
        {
            viborka[i][j]=cifri[randommassiv[i]][j];
        }
    }

    cout << "Author - Moskalenko Vitaly Alexandrovich UIB-311" << endl;

    int KolvoOshibki;
    cout << "Enter the number of errors: ";
    cin >> KolvoOshibki;

    for (int i=0;i<500;i++)
    {
        int OshibkiAdd=0;
        bool IzmeneniyBit[9]={false}; 
        while (OshibkiAdd<KolvoOshibki)
        {
            int SluchBit=rand()%9;
            if (!IzmeneniyBit[SluchBit])
            {
                viborka[i][SluchBit]=!viborka[i][SluchBit];  
                IzmeneniyBit[SluchBit]=true; 
                OshibkiAdd++;
            }
        }
    }

    cout << "Training sample: " << endl;
    for (int i=0;i<500;i++) 
    {
        cout << i+1 << " | ";
        for (int j=0;j<10;j++) 
        {
            cout << viborka[i][j] << ' ';
        }
        cout << "|";
        cout << endl;
    }


    while (kolich<maxeras) 
    {
        kolich++;
        int sovpad=0;

        for (int i=0;i<500;i++) 
        {
            for (int j=0;j<2;j++) 
            {
                sums[j] = 0;
                for (int x=0;x<9;x++) 
                {
                    sums[j]+=Omegi[j][x]*viborka[i][x];
                }
            }

            int max=*max_element(sums, sums+2);
            int kolvomax=0;

            for (int i=0;i<2;i++) 
            {
                if (sums[i]==max) 
                {   
                    kolvomax++;
                }
            }

            int PravKlass;
            if (viborka[i][9]==4) 
            {
                PravKlass=1;  
            } 
            else 
            {
                PravKlass=0;  
            }

            if ((sums[PravKlass]==max)&&(kolvomax==1)) 
            {
                sovpad++;  
            }
            else 
            {
                for (int x=0;x<2;x++) 
                {
                    if ((sums[x]==max)&&(x!=PravKlass)) 
                    {
                        for (int j=0;j<9;j++) 
                        {
                            Omegi[x][j]-=viborka[i][j]; 
                        }
                    }
                }

                for (int j=0;j<9;j++) 
                {
                    Omegi[PravKlass][j]+=viborka[i][j]; 
                }
            }
        }

        cout << endl;
        cout <<  "Era: " << kolich << endl;

        for (int i=0;i<2;i++) 
        {
            for (int j=0;j<9;j++) 
            {
                cout << Omegi[i][j] << ' ';
            }
            cout << endl;
        }

        double tochnost=(double)sovpad/500*100;
        cout << "Accuracy: "  << tochnost << "%" << endl;
    }

    cout << endl;

    return 0;
}
