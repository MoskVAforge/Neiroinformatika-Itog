#include <iostream>
#include <algorithm>
#include <ctime>
#include <cstring>

using namespace std;

int main()
{
    int Q=35;
    int Omega[15]={1,2,3,4,5,6,7,8,9,10,12,13,14,15,0};
    int OmegaFirst[15]={1,2,3,4,5,6,7,8,9,10,12,13,14,15,0};
    int ves[300][15];
    int mycifra[15]={1,0,1,1,0,1,1,1,1,0,0,1,0,0,1}; //Моя цифра 4 - по заданию
    int check[15];
    int key;
    int maxeras=15;
    int sumCheck=0;

    int cifri[10][16]=
    {
        {1,1,1,1,0,1,1,0,1,1,0,1,1,1,1,0}, //0
        {0,0,1,0,1,1,1,0,1,0,0,1,0,0,1,1}, //1
        {1,1,1,0,0,1,1,1,1,1,0,0,1,1,1,2}, //2
        {1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,3}, //3
        {1,0,1,1,0,1,1,1,1,0,0,1,0,0,1,4}, //4
        {1,1,1,1,0,0,1,1,1,0,0,1,1,1,1,5}, //5 
        {1,1,1,1,0,0,1,1,1,1,0,1,1,1,1,6}, //6
        {1,1,1,0,0,1,0,1,0,0,1,0,0,1,0,7}, //7
        {1,1,1,1,0,1,1,1,1,1,0,1,1,1,1,8}, //8
        {1,1,1,1,0,1,1,1,1,0,0,1,1,1,1,9}  //9
    };

    int randommassiv[300]=
    {
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
        2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
        3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
        4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
        5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,
        6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,
        7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,
        8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,
        9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9
    };
    int viborka[300][16];
    int kolvo=0;

    random_shuffle(randommassiv, randommassiv + 300);

    for (int i=0;i<300;i++)
    {
        for (int j=0;j<16;j++)
        {
            viborka[i][j]=cifri[randommassiv[i]][j];
        }
    }
    cout << "Author - Moskalenko Vitaly Alexandrovich UIB-311";
    cout << endl;
    int KolvoOshibki;
    cout << "Enter the number of errors: " << ' ';
    cin >> KolvoOshibki;

    for (int i=0;i<300;i++)
    {
        int OshibkiAdd=0;
        bool IzmeneniyBit[15]={false}; 
        while (OshibkiAdd<KolvoOshibki)
        {
            int SluchBit=rand()%15;
            if (!IzmeneniyBit[SluchBit])
            {
                viborka[i][SluchBit]=!viborka[i][SluchBit];  
                IzmeneniyBit[SluchBit]=true; 
                OshibkiAdd++;
            }
        }
    }


    cout << "Training sample: " << endl;
    for (int i=0;i<300;i++)
    {
        cout << i+1 << " | ";
        for (int j=0;j<16;j++)
        {
            cout << viborka[i][j] << ' ';
        }
        cout << "|";
        cout << endl;
    }

    cout << endl;

    while (kolvo<maxeras)
    {
        kolvo++;
        int IzmeneniyVes=0;  
        int Sovpad=0; 
        cout << "Epoha " << kolvo << " :";
        cout << endl;
        cout << "Omega1: ";
        for (int i=0;i<15;i++)
        {
            cout << Omega[i] << ' ';
        }
        cout << endl;

        for (int i=0;i<300;i++)
        {
            int sum=0;
            for (int j=0;j<15;j++)
            {
                ves[i][j]=Omega[j]*viborka[i][j];
                sum+=ves[i][j];
            }

            // Проверка правильности предсказания
            if ((viborka[i][15]==4&&sum>Q)||(viborka[i][15]!=4&&sum<=Q))
            {
                Sovpad++;
            }

            if ((viborka[i][15]==4)&&(sum<=Q))
            {
                for (int x=0;x<15;x++)
                {
                    Omega[x]+=viborka[i][x];
                }
                IzmeneniyVes++;
            }

            if ((viborka[i][15]!=4) && (sum > Q))
            {
                for (int x = 0; x < 15; x++)
                {
                    Omega[x] -= viborka[i][x];
                }
                IzmeneniyVes++;
            }

        }
        cout << "Omega2: ";
        for (int i=0;i<15;i++)
        {
            cout << Omega[i] << ' ';
        }
        cout << endl;
        cout << "Number of changes: " << IzmeneniyVes << ' ';
        cout << endl;
        float tochnost=static_cast<float>(Sovpad)/300*100;
        cout << "Accuracy: " << tochnost << "%" << endl;
        cout << endl;
    }    

    cout << "Final Results: " << endl;
    cout << "First Omega: ";
    for (int i=0;i<15;i++)
    {
        cout << OmegaFirst[i] << ' ';
    }
    cout << endl;
    cout << "Last Omega: ";
    for (int i=0;i<15;i++)
    {
        cout << Omega[i] << ' ';
    }
    cout << endl;
    cout << "Number of eras - " << kolvo;
    cout << endl;

    return 0;
}