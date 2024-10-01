#include <iostream>
#include <algorithm>
#include <ctime>
#include <cstring>

using namespace std;

int main()
{
    int Q=35;
    int Omega[9]={8,7,0,3,-9,3,7,0,0};
    int OmegaFirst[9]={8,7,0,3,-9,3,7,0,0};
    int ves[500][9];
    int mycifra[9]={1,0,0,1,1,0,0,1,0}; //Моя цифра 4 - по заданию
    int key;
    int maxeras=20;
    int sumCheck=0;

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

    int viborka[500][10];
    int kolvo=0;

    random_shuffle(randommassiv, randommassiv+500);

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

    while (kolvo<maxeras)
    {
        kolvo++;
        int IzmeneniyVes=0;  
        int Sovpad=0; 
        cout << "Epoha " << kolvo << " :";
        cout << endl;
        cout << "Omega1: ";
        for (int i=0;i<9;i++)
        {
            cout << Omega[i] << ' ';
        }
        cout << endl;

        for (int i=0;i<500;i++)
        {
            int sum=0;
            for (int j=0;j<9;j++)
            {
                ves[i][j]=Omega[j]*viborka[i][j];
                sum+=ves[i][j];
            }

            if ((viborka[i][9]==4&&sum>Q)||(viborka[i][9]!=4&&sum<=Q))
            {
                Sovpad++;
            }

            if ((viborka[i][9]==4)&&(sum<=Q))
            {
                for (int x=0;x<9;x++)
                {
                    Omega[x]+=viborka[i][x];
                }
                IzmeneniyVes++;
            }

            if ((viborka[i][9]!=4) && (sum > Q))
            {
                for (int x = 0; x < 9; x++)
                {
                    Omega[x] -= viborka[i][x];
                }
                IzmeneniyVes++;
            }

        }
        cout << "Omega2: ";
        for (int i=0;i<9;i++)
        {
            cout << Omega[i] << ' ';
        }
        cout << endl;
        cout << "Number of changes: " << IzmeneniyVes << ' ';
        cout << endl;
        float tochnost=static_cast<float>(Sovpad)/500*100;
        cout << "Accuracy: " << tochnost << "%" << endl;
        cout << endl;
    }    

    cout << "Final Results: " << endl;
    cout << "First Omega: ";
    for (int i=0;i<9;i++)
    {
        cout << OmegaFirst[i] << ' ';
    }
    cout << endl;
    cout << "Last Omega: ";
    for (int i=0;i<9;i++)
    {
        cout << Omega[i] << ' ';
    }
    cout << endl;
    cout << "Number of eras - " << kolvo;
    cout << endl;


    return 0;
}
