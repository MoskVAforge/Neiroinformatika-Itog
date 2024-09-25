#include <iostream>
#include <algorithm>
#include <ctime>
#include <cstring>

using namespace std;

int main()
{
    int maxeras=3;
    int kolich=0;
    int sums[10]={0}; 

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

    int Omegi[10][10]=
    {
        {0,1,4,7,2,-8,1,9,2,0},
        {7,3,9,4,9,0,1,7,4,1},
        {1,7,9,2,6,0,7,6,0,2},
        {3,9,8,6,-9,6,2,0,0,3},
        {8,7,0,3,-9,3,7,0,4},
        {9,0,8,8,4,7,4,9,3,5},
        {2,8,7,4,-1,7,9,1,1,6},
        {9,8,4,0,8,7,0,8,7,7},
        {5,7,8,5,7,8,4,0,2,8},
        {9,4,8,5,7,1,9,-8,5,9}
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

    random_shuffle(randommassiv, randommassiv+500);

    int viborka[500][10];
    for (int i=0;i<500;i++) 
    {
        for (int j=0;j<10;j++) 
        {
            viborka[i][j]=cifri[randommassiv[i]][j];
        }
    }

    cout << "Author - Moskalenko Vitaly Alexandrovich UIB-311";
    cout << endl;

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
    cout << endl;

    cout << "First Omegas :" << endl;
    for (int i=0;i<10;i++) 
    {
        for (int j=0;j<10;j++) 
        {
            cout << Omegi[i][j] << ' ';
        }
        cout << endl;
    }


    while (kolich<maxeras) 
    {
        kolich++;
        int sovpad=0;
        for (int i=0;i<500;i++) 
        {
            for (int j=0;j<10;j++) 
            {
                sums[j]=0;
                for (int x=0;x<9;x++) 
                {
                    sums[j]+=Omegi[j][x]*viborka[i][x];
                }
            }

            int max=*max_element(sums, sums+10);
            int kolvomax=0;
            for (int i=0;i<10;i++) 
            {
                if (sums[i]==max) 
                {   
                    kolvomax++;
                }
            }

            if ((sums[viborka[i][9]]==max)&&(kolvomax==1)) 
            {
                sovpad++;  
            }
            else 
            {
                for (int x=0;x<10;x++) 
                {
                    if ((sums[x]==max)&&(x!=viborka[i][9])) 
                    {
                        for (int j=0;j<9;j++) 
                        {
                            Omegi[x][j]-=viborka[i][j];
                        }
                    }
                }
                for (int j=0;j<9;j++) 
                {
                    Omegi[viborka[i][9]][j]+=viborka[i][j];
                }
            }

        }
        cout << endl;
        cout <<  "Era: " << kolich << endl;

        for (int i=0;i<10;i++) 
        {
            for (int j=0;j<10;j++) 
            {
                cout << Omegi[i][j] << ' ';
            }
            cout << endl;
        }

        double tochnost=(double)sovpad/500*100;
        cout << "Accuracy: " << tochnost << "%" << endl;
    }
    cout << endl;

    for (int i=0;i<10;i++) 
    {
        cout << "Checking " << i << ": ";
        bool uspex=true;

        for (int x=0;x<10;x++) 
        {
            sums[x]=0;
            for (int j=0;j<9;j++) 
            {
                sums[x]+=Omegi[x][j]*cifri[i][j];
            }
        }

        int max=*max_element(sums, sums+10);
        int kolvomax=0;
        for (int i=0;i<10;i++) 
        {
            if (sums[i]==max) 
            {
                kolvomax++;
            }
        }

        if ((sums[i]!=max)||(kolvomax>1)) 
        {
            uspex=false;
        }

        if (uspex) 
        {
            cout << "Success!" << endl;
        } 

        else 
        {
            cout << "Fail!" << endl;
        }
    }

    return 0;
}
