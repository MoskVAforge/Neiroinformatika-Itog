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
    int maxeras=3;
    int sumCheck=0;

    int cifri[10][15]=
    {
        {1,1,1,1,0,1,1,0,1,1,0,1,1,1,1}, //0
        {0,0,1,0,1,1,1,0,1,0,0,1,0,0,1}, //1
        {1,1,1,0,0,1,1,1,1,1,0,0,1,1,1}, //2
        {1,1,1,0,0,1,1,1,1,0,0,1,1,1,1}, //3
        {1,0,1,1,0,1,1,1,1,0,0,1,0,0,1}, //4
        {1,1,1,1,0,0,1,1,1,0,0,1,1,1,1}, //5 
        {1,1,1,1,0,0,1,1,1,1,0,1,1,1,1}, //6
        {1,1,1,0,0,1,0,1,0,0,1,0,0,1,0}, //7
        {1,1,1,1,0,1,1,1,1,1,0,1,1,1,1}, //8
        {1,1,1,1,0,1,1,1,1,0,0,1,1,1,1}  //9
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
    int viborka[300][15];
    int kolvo=0;

    random_shuffle(randommassiv, randommassiv + 300);

    for (int i=0;i<300;i++)
    {
        for (int j=0;j<15;j++)
        {
            viborka[i][j]=cifri[randommassiv[i]][j];
        }
    }

    cout << "Author - Moskalenko Vitaly Alexandrovich UIB-311";
    cout << "Training sample: " << endl;
    for (int i=0;i<300;i++)
    {
        cout << i+1 << " | ";
        for (int j=0;j<15;j++)
        {
            cout << viborka[i][j] << ' ';
        }
        cout << "|";
        cout << endl;
    }

    while (kolvo<maxeras)
    {
        kolvo++;
        cout << endl;
        cout << "Era " << kolvo << ":";
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

            key=0;
            for (int j=0;j<15;j++)
            {
                if (viborka[i][j]==mycifra[j])
                {
                    key++;
                }
            }

            if ((key==15)&&(sum<=Q))
            {
                for (int x=0;x<15;x++)
                {
                    Omega[x]+=viborka[i][x];
                }
            }

            if ((key!=15)&&(sum>Q))
            {
                for (int x=0;x<15;x++)
                {
                    Omega[x]-=viborka[i][x];
                }
            }
        }

        cout << "Omega2: ";
        for (int i=0;i<15;i++)
        {
            cout << Omega[i] << ' ';
        }
        cout << endl;
    }

    cout << endl;

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
    cout << endl;

    memset(check,0,sizeof(check));
    sumCheck=0;

    int cifraCheck0[15]={1,1,1,1,0,1,1,0,1,1,0,1,1,1,1}; //0
    int cifraCheck1[15]={0,0,1,0,1,1,1,0,1,0,0,1,0,0,1}; //1
    int cifraCheck2[15]={1,1,1,0,0,1,1,1,1,1,0,0,1,1,1}; //2
    int cifraCheck3[15]={1,1,1,0,0,1,1,1,1,0,0,1,1,1,1}; //3
    int cifraCheck5[15]={1,1,1,1,0,0,1,1,1,0,0,1,1,1,1}; //5
    int cifraCheck6[15]={1,1,1,1,0,0,1,1,1,1,0,1,1,1,1}; //6
    int cifraCheck7[15]={1,1,1,0,0,1,0,1,0,0,1,0,0,1,0}; //7
    int cifraCheck8[15]={1,1,1,1,0,1,1,1,1,1,0,1,1,1,1}; //8
    int cifraCheck9[15]={1,1,1,1,0,1,1,1,1,0,0,1,1,1,1}; //9

    for (int i=0;i<15;i++)
    {
        check[i]=cifraCheck0[i]*Omega[i];
        sumCheck+=check[i];
    }

    cout << "Checking 0: ";
    if (sumCheck>Q)
    {
        cout << "Yes" << ", " << "sum 0f weights: " << sumCheck << " > " << Q << endl;
    }
    else
    {
        cout << "No" << ", " << "sum 0f weights: " << sumCheck << " <= " << Q << endl;
    }

    memset(check,0,sizeof(check));
    sumCheck = 0;

    for (int i=0;i<15;i++)
    {
        check[i]=cifraCheck1[i]*Omega[i];
        sumCheck+=check[i];
    }

    cout << "Checking 1: ";
    if (sumCheck > Q)
    {
        cout << "Yes" << ", " << "sum 0f weights: " << sumCheck << " > " << Q << endl;
    }
    else
    {
        cout << "No" << ", " << "sum 0f weights: " << sumCheck << " <= " << Q << endl;
    }

    memset(check,0,sizeof(check));
    sumCheck=0;

    for (int i=0;i<15;i++)
    {
        check[i]=cifraCheck2[i]*Omega[i];
        sumCheck+=check[i];
    }

    cout << "Checking 2: ";
    if (sumCheck>Q)
    {
        cout << "Yes" << ", " << "sum 0f weights: " << sumCheck << " > " << Q << endl;
    }
    else
    {
        cout << "No" << ", " << "sum 0f weights: " << sumCheck << " <= " << Q << endl;
    }

    memset(check,0,sizeof(check));
    sumCheck=0;

    for (int i=0;i<15;i++)
    {
        check[i]=cifraCheck3[i]*Omega[i];
        sumCheck+=check[i];
    }

    cout << "Checking 3: ";
    if (sumCheck>Q)
    {
        cout << "Yes" << ", " << "sum 0f weights: " << sumCheck << " > " << Q << endl;
    }
    else
    {
        cout << "No" << ", " << "sum 0f weights: " << sumCheck << " <= " << Q << endl;
    }

    memset(check,0,sizeof(check));
    sumCheck=0;

    for (int i=0;i<15;i++)
    {
        check[i]=mycifra[i]*Omega[i];
        sumCheck+=check[i];
    }

    cout << "Checking 4: ";
    if (sumCheck>Q)
    {
        cout << "Yes" << ", " << "sum 0f weights: " << sumCheck << " > " << Q << endl;
    }
    else
    {
        cout << "No" << ", " << "sum 0f weights: " << sumCheck << " <= " << Q << endl;
    }

    memset(check,0,sizeof(check));
    sumCheck=0;

    for (int i=0;i<15;i++)
    {
        check[i]=cifraCheck5[i]*Omega[i];
        sumCheck+=check[i];
    }

    cout << "Checking 5: ";
    if (sumCheck>Q)
    {
        cout << "Yes" << ", " << "sum 0f weights: " << sumCheck << " > " << Q << endl;
    }
    else
    {
        cout << "No" << ", " << "sum 0f weights: " << sumCheck << " <= " << Q << endl;
    }

    memset(check,0,sizeof(check));
    sumCheck=0;

    for (int i=0;i<15;i++)
    {
        check[i]=cifraCheck6[i]*Omega[i];
        sumCheck+=check[i];
    }

    cout << "Checking 6: ";
    if (sumCheck>Q)
    {
        cout << "Yes" << ", " << "sum 0f weights: " << sumCheck << " > " << Q << endl;
    }
    else
    {
        cout << "No" << ", " << "sum 0f weights: " << sumCheck << " <= " << Q << endl;
    }

    memset(check,0,sizeof(check));
    sumCheck=0;

    for (int i=0;i<15;i++)
    {
        check[i]=cifraCheck7[i]*Omega[i];
        sumCheck+=check[i];
    }

    cout << "Checking 7: ";
    if (sumCheck>Q)
    {
        cout << "Yes" << ", " << "sum 0f weights: " << sumCheck << " > " << Q << endl;
    }
    else
    {
        cout << "No" << ", " << "sum 0f weights: " << sumCheck << " <= " << Q << endl;
    }

    memset(check,0,sizeof(check));
    sumCheck=0;

    for (int i=0;i<15;i++)
    {
        check[i]=cifraCheck8[i]*Omega[i];
        sumCheck+=check[i];
    }

    cout << "Checking 8: ";
    if (sumCheck>Q)
    {
        cout << "Yes" << ", " << "sum 0f weights: " << sumCheck << " > " << Q << endl;
    }
    else
    {
        cout << "No" << ", " << "sum 0f weights: " << sumCheck << " <= " << Q << endl;
    }
    memset(check,0,sizeof(check));
    sumCheck=0;

    for (int i=0;i<15;i++)
    {
        check[i]=cifraCheck9[i]*Omega[i];
        sumCheck+=check[i];
    }

    cout << "Checking 9: ";
    if (sumCheck>Q)
    {
        cout << "Yes" << ", " << "sum 0f weights: " << sumCheck << " > " << Q << endl;
    }
    else
    {
        cout << "No" << ", " << "sum 0f weights: " << sumCheck << " <= " << Q << endl;
    }

    return 0;
}