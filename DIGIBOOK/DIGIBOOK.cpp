#include <stdlib.h>
#include <dos.h>
#include <ctype.h>
#include <conio.h>
#include <fstream.h>
#include <string.h>
#include <process.h>
#include<stdio.h>

class term
{
    char type[65], model[745];

public:
    void Getdata();
    void Showdata()
    {

        cout << "\n"
             << "HEADING :" << type << "\n"
             << "NOTE POINT : ";
        puts(model);
        cout << "\n\t------------------------------------------------------------";
    }

} v; // CLASS ENDS HERE
void loading2();
void Dis();

void term ::Getdata() // Function to get data from user
{
    clrscr();
    Dis();
    cout << "\n\t\t********************************************";
    cout << "\n\t\t\t\tCREATING NEW NOTE";
    cout << "\n\t\t********************************************";
    cout << "\n\n\nEnter heading of note \n";
    gets(type);
    cout << "\n\nEnter the notepoint\n";
    gets(model);
}

void Insertion()
{
    term v1;
    int n;
    char choice = 'y';
    ofstream f;
    f.open("concentration.dat", ios::binary | ios::app);
    while (choice == 'y' || choice == 'Y')
    {
        v1.Getdata();
        f.write((char *)&v1, sizeof(v1));
        cout << "\n\nDo you want to enter more(Y\\N)  ";
        cin >> choice;
        cout << endl
             << endl;
    }
    f.close();
}

void Display()
{
    ifstream f;
    int flag = 0;
    f.open("concentration.dat", ios::binary);
    term v1;
    while (f.read((char *)&v1, sizeof(v1)))
    {
        flag = 1;
        v1.Showdata();
    }
    if (flag == 0)
        cout << "\n\tNo Record Found" << endl;
    f.close();
    getch();
}

void Dis()
{
    textcolor(LIGHTBLUE);
    cout << "\n\n\n\t\t\n\n";
    cprintf("******************************************************************************");
    cout << "\n\t\t\t";
    cprintf("        CHEMISTRY PROJECT ");
    textcolor(MAGENTA);
}

void exit1()
{
    clrscr();
    gotoxy(10, 13);
    textcolor(LIGHTMAGENTA);
    cprintf("THANK YOU ALL GUYS FOR BEING AN HUMBLE AUDIENCE,HOPE YOU ALL LIKED IT ");
    gotoxy(32, 16);
    textcolor(YELLOW);
    cprintf("CLOSING IN ");
    for (int i = 1; i <= 5; i++)
    {
        gotoxy(43, 16);
        cout << (6 - i);
        delay(1000);
    }
    exit(0);
}
void credit()
{
    clrscr();
    char ch, ch1;
    textcolor(LIGHTBLUE);
    cout << "\n\n\t\t\n";
    cprintf("******************************************************************************");
    cout << "\n\t\t\t";
    textcolor(YELLOW);
    cprintf("        CHEMISTRY PROJECT ");
    cout << "\n";
    textcolor(LIGHTBLUE);
    cprintf("******************************************************************************");
    cout << "\n\n";
    textcolor(YELLOW);
    cout << "\n******************************************************************************";
    cout << "\n\t\t\t\t";
    textcolor(LIGHTCYAN);
    cprintf("CREDITS FOR THE PROGRAM");
    textcolor(YELLOW);
    cout << "\n******************************************************************************";
    gotoxy(10, 13);
    textcolor(LIGHTMAGENTA);
    cprintf("PROJECT SUBMITTED TO : ");
    textcolor(LIGHTCYAN);
    gotoxy(10, 14);
    cprintf("PROFESSOR DEENAN SANTHIYA");

    gotoxy(45, 13);
    textcolor(LIGHTMAGENTA);
    cprintf("PROJECT SUBMITTED BY : ");
    textcolor(LIGHTCYAN);
    gotoxy(45, 14);
    cprintf("KESHAV PRAKASH SHARMA ");
    textcolor(LIGHTCYAN);
    gotoxy(45, 15); 
    cprintf("KHUSHPREET SINGH ");
    cout << endl
         << endl;
    getch();
    loading2();
}

void calc()
{
    clrscr();
    char ch, ch1;
    textcolor(LIGHTBLUE);
    cout << "\n\n\t\t\n";
    cprintf("******************************************************************************");
    cout << "\n\t\t\t";
    cprintf("        CHEMISTRY PROJECT ");
    cout << "\n";
    cprintf("******************************************************************************");
    cout << "\n\n";
    textcolor(YELLOW);
    cout << "\n******************************************************************************";
    cout << "\n\t\t\t\t";
    textcolor(LIGHTCYAN);
    cprintf("CALCULATOR");
    textcolor(YELLOW);
    cout << "\n******************************************************************************";
    cout << endl
         << "Select the desired concentration term form the list :";
    cout << "\n1.)Mass percentage\t\t\t\t5.)Molality"
         << "\n2.)Mass Volume percentage\t\t\t6.)Normality"
         << "\n3.)Volume Volume Percentage\t\t\t7.)Formal\n"
         << "4.)Molarity\t\t\t\t\t8.)Parts per million\n";
    cout << "\n";
    cin >> ch1;
    clrscr();
    textcolor(LIGHTBLUE);
    cout << "\n\n\t\t\n";
    cprintf("******************************************************************************");
    cout << "\n\t\t\t";
    cprintf("        CHEMISTRY PROJECT ");
    cout << "\n";
    cprintf("******************************************************************************");
    cout << "\n\n";
    textcolor(YELLOW);
    cout << "\n******************************************************************************";
    cout << "\n\t\t\t\t";
    textcolor(LIGHTCYAN);
    cprintf("CALCULATOR");
    textcolor(YELLOW);
    cout << "\n******************************************************************************";
    cout << "  The selected choice is :";
    float msolute, mper, msoln;
    switch (ch1)
    {
    case '1':
        textcolor(YELLOW);
        cprintf("1.) Mass Percentage");
        cout << "\n\n";
        textcolor(LIGHTCYAN);
        cprintf("Performing calculations for Mass Percentage :");
        cout << endl;
        textcolor(WHITE);
        textcolor(YELLOW);
        cprintf("FORMULA ");
        textcolor(WHITE);
        cprintf(":");
        cout << "\nFormula = (mass of solute)/(mass of solution) x100 ";
        cout << "\n\nProvide mass of solute (in g) : \n";
        cin >> msolute;
        cout << "\nProvide mass of solution (in g) : \n";
        cin >> msoln;
        mper = ((msolute) / (msoln)) * 100;
        cout << "\n\nThe mass percentage of solution is " << mper << " %";
        cout << endl
             << endl
             << endl;
        cprintf("Do you want to calculate for other terms ?(Y/N)");
        cout << endl;
        cin >> ch;
        if (ch == 'N' || ch == 'n')
            loading2();
        else
            calc();
        break;
    case '2':
        textcolor(YELLOW);
        cprintf("2.) Mass Volume Percentage");
        cout << "\n\n";
        textcolor(LIGHTCYAN);
        cprintf("Performing calculations for Mass Volume Percentage :");
        cout << endl;
        textcolor(WHITE);
        // cprintf("The mass/volume percent of a solution is defined as the ratio of the mass of solute that is present in a solution, relative to the volume of the solution, as a whole. Because this type of concentration is expressed as a percentage, the indicated proportion must be multiplied by 100,");
        // cout<<endl;
        textcolor(YELLOW);
        cprintf("FORMULA ");
        textcolor(WHITE);
        cprintf(":");
        cout << "\nFormula = (mass of solute)/(volume of solution) x100 ";
        cout << "\n\nProvide mass of solute(in g) : \n";
        cin >> msolute;
        cout << "\nProvide volume of solution(in L): \n";
        cin >> msoln;
        mper = ((msolute) / (msoln)) * 100;
        cout << "\n\nThe mass volume percentage of solution is " << mper << " %";
        cout << endl
             << endl
             << endl;
        cprintf("Do you want to calculate for other terms ?(Y/N)");
        // cout<<endl<<endl<<endl;
        // cprintf("Do you want to learn about other terms ?(Y/N)");
        cout << endl;
        cin >> ch;
        if (ch == 'N' || ch == 'n')
            loading2();
        else
            calc();

        break;
    case '3':
        textcolor(YELLOW);
        cprintf("3.) Volume Volume Percentage");
        cout << "\n\n";
        textcolor(LIGHTCYAN);
        cprintf("Performing calculations for Volume Volume Percentage :");
        cout << endl;
        textcolor(WHITE);
        // cprintf("Volume/volume percentage (v/v percent) is a measure of the concentration of a substance in a solution. It is expressed as the ratio of the volume of the solute to the total volume of the solution multiplied by 100");
        // cout<<endl;
        textcolor(YELLOW);
        cprintf("FORMULA ");
        textcolor(WHITE);
        cprintf(":");
        cout << "\nFormula = (volume of solute)/(volume of solution) x 100 ";
        cout << "\n\nProvide volume of solute(in L) : \n";
        cin >> msolute;
        cout << "\nProvide volume of solution(in L) : \n";
        cin >> msoln;
        mper = ((msolute) / (msoln)) * 100;
        cout << "\n\nThe volume volume percentage of solution is " << mper << " %";
        cout << endl
             << endl
             << endl;
        cprintf("Do you want to calculate for other terms ?(Y/N)");
        cout << endl
             << endl
             << endl;
        cout << endl;
        cin >> ch;
        if (ch == 'N' || ch == 'n')
            loading2();
        else
            calc();
        break;
    case '4':
        textcolor(YELLOW);
        cprintf("4.) Molarity");
        cout << "\n\n";
        textcolor(LIGHTCYAN);
        cprintf("Performing calculations for Molarity :");
        cout << endl;
        textcolor(WHITE);
        // cprintf("Molarity (M) is the amount of a substance in a certain volume of solution. Molarity is defined as the moles of a solute per liters of a solution. Molarity is also known as the molar concentration of a solution ");
        // cout<<endl;
        textcolor(YELLOW);
        cprintf("FORMULA ");
        textcolor(WHITE);
        cprintf(":");
        cout << "\nFormula = (Number of moles solute)/(Volume of solution (in L) ) ";
        cout << "\n\nProvide no. of moles of solute(in moles) : \n";
        cin >> msolute;
        cout << "\nProvide volume of solution(in L) : \n";
        cin >> msoln;
        mper = ((msolute) / (msoln));
        cout << "\n\nThe molarity of solution is " << mper << " M";
        cout << endl
             << endl
             << endl;
        cprintf("Do you want to calculate for other terms ?(Y/N)");
        cout << endl
             << endl
             << endl;
        cout << endl;
        cin >> ch;
        if (ch == 'N' || ch == 'n')
            loading2();
        else
            calc();
        break;
    case '5':
        textcolor(YELLOW);
        cprintf("5.) Molality");
        cout << "\n\n";
        textcolor(LIGHTCYAN);
        cprintf("Performing calculations for Molality :");
        cout << endl;
        textcolor(YELLOW);
        cprintf("FORMULA ");
        textcolor(WHITE);
        cprintf(":");
        cout << "\nFormula = (Number of moles solute)/(Mass of solvent (in Kg))";
        cout << "\n\nProvide no. of moles of solute(in moles) : \n";
        cin >> msolute;
        cout << "\nProvide mass of solvent(in Kg) : \n";
        cin >> msoln;
        mper = ((msolute) / (msoln));
        cout << "\n\nThe molarity of solution is " << mper << " m";
        cout << endl
             << endl
             << endl;
        cprintf("Do you want to calculate for other terms ?(Y/N)");
        cout << endl
             << endl
             << endl;
        cout << endl;
        cin >> ch;
        if (ch == 'N' || ch == 'n')
            loading2();
        else
            calc();
        break;
    case '6':
        textcolor(YELLOW);
        cprintf("6.) Normality");
        cout << "\n\n";
        textcolor(LIGHTCYAN);
        cprintf("Performing Calculations for Normality :");
        cout << endl;
        textcolor(YELLOW);
        cprintf("FORMULA ");
        textcolor(WHITE);
        cprintf(":");
        cout << "\nFormulas are:\n";
        cout << "Normality = Number of gram equivalents/[volume of solution in litres]\n";
        cout << "Number of gram equivalents = weight of solute/[Equivalent weight of solute] \n";
        cout << "N = Weight of Solute (gram) x [Equivalent weight x Volume (L)] \n";
        cout << "N = Molarity x Molar mass x [Equivalent mass]^(-1) \n";
        cout << "N = Molarity x Basicity = Molarity x Acidity \n";
        cout << "\n\nProvide no. of gm equivalents : \n";
        cin >> msolute;
        cout << "\nProvide volume of solution(in L) : \n";
        cin >> msoln;
        mper = ((msolute) / (msoln));
        cout << "\n\nThe normality of solution is " << mper << " N";
        cout << endl
             << endl
             << endl;
        cprintf("Do you want to calculate for other terms ?(Y/N)");
        cout << endl
             << endl
             << endl;
        cout << endl;
        cin >> ch;
        if (ch == 'N' || ch == 'n')
            loading2();
        else
            calc();
        break;
    case '7':
        textcolor(YELLOW);
        cprintf("7.) Formality");
        cout << "\n\n";
        textcolor(LIGHTCYAN);
        cprintf("Performing calculations for Formality :");
        cout << endl;
        textcolor(WHITE);
        // cprintf("Formality of a solution may be defined as the number of gram formula masses of the ionic solute dissolved per litre of the solution. It is represented by F. Commonly, the term formality is used to express the concentration of the ionic solids which do not exist as molecules but exist as network of ions. A solution containing one gram formula mass of solute per litre of the solution has formality equal to one and is called formal solution.");
        // cout<<endl;
        textcolor(YELLOW);
        cprintf("FORMULA ");
        textcolor(WHITE);
        cprintf(":");
        cout << "\nFormula = (Number of gram formula masses of solute)/(volume of solution (in L)";
        cout << "\n\nProvide no. of gram formula masses : \n";
        cin >> msolute;
        cout << "\nProvide volume of solution(in L) : \n";
        cin >> msoln;
        mper = ((msolute) / (msoln));
        cout << "\n\nThe formality of solution is " << mper << " formals";
        cout << endl
             << endl
             << endl;
        cprintf("Do you want to calculate for other terms ?(Y/N)");
        cout << endl
             << endl
             << endl;
        cout << endl;
        cin >> ch;
        if (ch == 'N' || ch == 'n')
            loading2();
        else
            calc();
        break;
    case '8':
        textcolor(YELLOW);
        cprintf("8.) Parts per million");
        cout << "\n\n";
        textcolor(LIGHTCYAN);
        cprintf("Performing calculations for Parts Per Million :");
        cout << endl;
        textcolor(WHITE);
        // cprintf("A weight to weight ratio used to describe concentrations. Parts per million (ppm) is the number of units of mass of a contaminant per million units of total mass.ppm (or ppmV) is often used to describe concentrations of contaminants in air (as a volume fraction) or for finding the contamination of water by the impurities");
        // cout<<endl;
        textcolor(YELLOW);
        cprintf("FORMULA ");
        textcolor(WHITE);
        cprintf(":");
        cout << "\nFormula = (mass of solute)/(mass of solution) x10^6 ";
        cout << "\n\nProvide mass of solute(in g) : \n";
        cin >> msolute;
        cout << "\nProvide mass of solution(in g) : \n";
        cin >> msoln;
        mper = ((msolute) / (msoln)) * 1000000;
        cout << "\n\nThe parts per million concentration of solution is " << mper << " ppm";
        cout << endl
             << endl
             << endl;
        cprintf("Do you want to calculate for other terms ?(Y/N)");
        cout << endl
             << endl
             << endl;
        cout << endl;
        cin >> ch;
        if (ch == 'N' || ch == 'n')
            loading2();
        else
            calc();
        break;
    }
    getch();
}

void oldnotes()
{
    clrscr();
    char ch, ch1;
    textcolor(LIGHTBLUE);
    cout << "\n\n\t\t\n";
    cprintf("******************************************************************************");
    cout << "\n\t\t\t";
    cprintf("        CHEMISTRY PROJECT ");
    cout << "\n";
    cprintf("******************************************************************************");
    cout << "\n\n";
    textcolor(YELLOW);
    cprintf("ABOUT THE TERM CONCENTRATION");
    cout << "\n";
    textcolor(WHITE);
    cprintf("The amount of the substance present in the definite quantity of the solution is called concentration of the solutions.Concentration is a concept that is encountered in our everyday life all the time. For example,most of the household chemicals are solutions in which the a specific concentration is veru cruicial for the subsatnce like vinegar,it is a solution of 5% acetic acid.");
    cout << "\n\nThe concentration can be expressed by various methods like : \n";
    cout << "1.)Mass percentage\t\t\t\t5.)Molality"
         << "\n2.)Mass Volume percentage\t\t\t6.)Normality"
         << "\n3.)Volume Volume Percentage\t\t\t7.)Formality\n"
         << "4.)Molarity\t\t\t\t\t8.)Parts per million\n";
    cout << "\n";
    textcolor(LIGHTCYAN);
    cprintf("Do you want to learn more about the terms ?(Y/N)");
    cout << endl;
    cin >> ch;
    if (ch == 'N' || ch == 'n')
        loading2();
    else
    {
        cout << "\nProvide the list no. for the desired term\n";
        cin >> ch1;
        clrscr();
        textcolor(LIGHTCYAN);
        cout << "\n\n\n\t\t";
        cprintf("********************************************");
        cout << endl
             << "\t\t\t";
        cprintf("   CHEMISTRY PROJECT ");
        cout << endl
             << "\t\t";
        cprintf("********************************************");
        textcolor(YELLOW);
        cout << "\n Your selected choice is ";

        switch (ch1)
        {
        case '1':
            textcolor(YELLOW);
            cprintf("1.) Mass Percentage");
            cout << "\n\n";
            textcolor(LIGHTCYAN);
            cprintf("Mass Percentage :");
            cout << endl;
            textcolor(WHITE);
            cprintf("Mass percentage is one way of representing the concentration of an element in a compound or a component in a mixture. Mass percentage is calculated as the mass of a component divided by the total mass of the mixture, multiplied by 100% ");
            cout << endl;
            textcolor(YELLOW);
            cprintf("FORMULA ");
            textcolor(WHITE);
            cprintf(":");
            cout << "\nFormula = (mass of solute)/(mass of solution) x100 ";
            cout << endl
                 << endl
                 << endl;
            cprintf("Do you want to learn about other terms ?(Y/N)");
            cout << endl;
            cin >> ch;
            if (ch == 'N' || ch == 'n')
                loading2();
            else
                oldnotes();
            break;
        case '2':
            textcolor(YELLOW);
            cprintf("2.) Mass Volume Percentage");
            cout << "\n\n";
            textcolor(LIGHTCYAN);
            cprintf("Mass Volume Percentage :");
            cout << endl;
            textcolor(WHITE);
            cprintf("The mass/volume percent of a solution is defined as the ratio of the mass of solute that is present in a solution, relative to the volume of the solution, as a whole. Because this type of concentration is expressed as a percentage, the indicated proportion must be multiplied by 100,");
            cout << endl;
            textcolor(YELLOW);
            cprintf("FORMULA ");
            textcolor(WHITE);
            cprintf(":");
            cout << "\nFormula = (mass of solute)/(volume of solution) x100 ";
            cout << endl
                 << endl
                 << endl;
            cprintf("Do you want to learn about other terms ?(Y/N)");
            cout << endl;
            cin >> ch;
            if (ch == 'N' || ch == 'n')
                loading2();
            else
                oldnotes();

            break;
        case '3':
            textcolor(YELLOW);
            cprintf("3.) Volume Volume Percentage");
            cout << "\n\n";
            textcolor(LIGHTCYAN);
            cprintf("Volume Volume Percentage :");
            cout << endl;
            textcolor(WHITE);
            cprintf("Volume/volume percentage (v/v percent) is a measure of the concentration of a substance in a solution. It is expressed as the ratio of the volume of the solute to the total volume of the solution multiplied by 100");
            cout << endl;
            textcolor(YELLOW);
            cprintf("FORMULA ");
            textcolor(WHITE);
            cprintf(":");
            cout << "\nFormula = (volume of solute)/(volume of solution) x 100 ";
            cout << endl
                 << endl
                 << endl;
            cprintf("Do you want to learn about other terms ?(Y/N)");
            cout << endl;
            cin >> ch;
            if (ch == 'N' || ch == 'n')
                loading2();
            else
                oldnotes();
            break;
        case '4':
            textcolor(YELLOW);
            cprintf("4.) Molarity");
            cout << "\n\n";
            textcolor(LIGHTCYAN);
            cprintf("Molarity :");
            cout << endl;
            textcolor(WHITE);
            cprintf("Molarity (M) is the amount of a substance in a certain volume of solution. Molarity is defined as the moles of a solute per liters of a solution. Molarity is also known as the molar concentration of a solution ");
            cout << endl;
            textcolor(YELLOW);
            cprintf("FORMULA ");
            textcolor(WHITE);
            cprintf(":");
            cout << "\nFormula = (Number of moles solute)/(Volume of solution (in L) ) ";
            cout << endl
                 << endl
                 << endl;
            cprintf("Do you want to learn about other terms ?(Y/N)");
            cout << endl;
            cin >> ch;
            if (ch == 'N' || ch == 'n')
                loading2();
            else
                oldnotes();
            break;
        case '5':
            textcolor(YELLOW);
            cprintf("5.) Molality");
            cout << "\n\n";
            textcolor(LIGHTCYAN);
            cprintf("Molality :");
            cout << endl;
            textcolor(WHITE);
            cprintf("Molality is a measure of the number of moles of solute in a solution corresponding to 1 kg or 1000 g of solvent or in simple words The molality (m), of a solution is defined as the amount of substance (in moles) of solute, divided by the mass (in kg) of the solvent ");
            cout << endl
                 << "A commonly used unit for molality in chemistry is mol/kg. A solution of concentration 1 mol/kg is also sometimes denoted as 1 molal";
            cout << endl;
            textcolor(YELLOW);
            cprintf("FORMULA ");
            textcolor(WHITE);
            cprintf(":");
            cout << "\nFormula = (Number of moles solute)/(Mass of solvent (in Kg))";
            cout << endl
                 << endl
                 << endl;
            cprintf("Do you want to learn about other terms ?(Y/N)");
            cout << endl;
            cin >> ch;
            if (ch == 'N' || ch == 'n')
                loading2();
            else
                oldnotes();

            break;
        case '6':
            textcolor(YELLOW);
            cprintf("6.) Normality");
            cout << "\n\n";
            textcolor(LIGHTCYAN);
            cprintf("Mass Percentage :");
            cout << endl;
            textcolor(WHITE);
            cprintf("Normality is described as the number of gram or mole equivalents of solute present in one litre of a solution. When we say equivalent, it is the number of moles of reactive units in a compound.Normality is often denoted by the letter N.");
            cout << endl;
            textcolor(YELLOW);
            cprintf("FORMULA ");
            textcolor(WHITE);
            cprintf(":");
            // cout<<"\nFormulas are:\n";
            cout << "\nNormality = Number of gram equivalents/[volume of solution in litres]\n";
            cout << "Number of gram equivalents = weight of solute/[Equivalent weight of solute] \n";
            cout << "N = Weight of Solute (gram) x [Equivalent weight x Volume (L)] \n";
            cout << "N = Molarity x Molar mass x [Equivalent mass]^(-1) \n";
            cout << "N = Molarity x Basicity = Molarity x Acidity \n";
            cout << endl
                 << endl
                 << endl;
            cprintf("Do you want to learn about other terms ?(Y/N)");
            cout << endl;
            cin >> ch;
            if (ch == 'N' || ch == 'n')
                loading2();
            else
                oldnotes();
            break;
        case '7':
            textcolor(YELLOW);
            cprintf("7.) Formality");
            cout << "\n\n";
            textcolor(LIGHTCYAN);
            cprintf("Formality :");
            cout << endl;
            textcolor(WHITE);
            cprintf("Formality of a solution may be defined as the number of gram formula masses of the ionic solute dissolved per litre of the solution. It is represented by F. Commonly, the term formality is used to express the concentration of the ionic solids which do not exist as molecules but exist as network of ions. A solution containing one gram formula mass of solute per litre of the solution has formality equal to one and is called formal solution.");
            cout << endl;
            textcolor(YELLOW);
            cprintf("FORMULA ");
            textcolor(WHITE);
            cprintf(":");
            cout << "\nFormula = (Number of gram formula masses of solute)/(volume of solution (in L)";
            cout << endl
                 << endl;
            cprintf("Do you want to learn about other terms ?(Y/N)");
            cout << endl;
            cin >> ch;
            if (ch == 'N' || ch == 'n')
                loading2();
            else
                oldnotes();
            break;
        case '8':
            textcolor(YELLOW);
            cprintf("8.) Parts per million");
            cout << "\n\n";
            textcolor(LIGHTCYAN);
            cprintf("Parts Per Million :");
            cout << endl;
            textcolor(WHITE);
            cprintf("A weight to weight ratio used to describe concentrations. Parts per million (ppm) is the number of units of mass of a contaminant per million units of total mass.ppm (or ppmV) is often used to describe concentrations of contaminants in air (as a volume fraction) or for finding the contamination of water by the impurities");
            cout << endl;
            textcolor(YELLOW);
            cprintf("FORMULA ");
            textcolor(WHITE);
            cprintf(":");
            cout << "\nFormula = (mass of solute)/(mass of solution) x10^6 ";
            cout << endl
                 << endl
                 << endl;
            cprintf("Do you want to learn about other terms ?(Y/N)");
            cout << endl;
            cin >> ch;
            if (ch == 'N' || ch == 'n')
                loading2();
            else
                oldnotes();
            break;
        }
        getch();
    }
}

void Owner()
{
    textcolor(LIGHTMAGENTA);
    int f1 = 0;
    char ch2;
    char ch;
    char user[7];
    char pass[7];
    cout << "\t\t\tEnter Username" << endl;
    while (1)
    {
        cout << "\t\t\t";
        gets(user);
        if (strcmpi(user, "deenan") == 0 || strcmpi(user, "keshav") == 0 || strcmpi(user, "khushpreet") == 0)
            break;
        else
        {
            cout << "\n\t\t\tWrong Username,Press any key to enter again" << endl;
            cout << "\n\t\t\t";
            getch();
            // des();
            cout << "\nRetry Entering username " << endl;
            continue;
        }
    }
    cout << "\n\t\t\tEnter  Password" << endl;
password:
    cout << "\t\t\t";
    for (int i = 0;; i++)
    {
        ch = getch();
        if (ch >= 'A' && ch <= 'Z')
        {
            cout << "*";
            pass[i] = ch;
        }
        else if (ch >= 'a' && ch <= 'z')
        {
            cout << "*";
            pass[i] = ch;
        }
        else if (ch == '\b')
        {
            cout << "\b"
                 << " "
                 << "\b";
            i = i - 2;
        }
        else if (ch == '\r')
        {
            pass[i] = '\0';
            break;
        }
    }

    if ((strcmpi(pass, "deenan") == 0) || (strcmpi(pass, "keshav") == 0) || (strcmpi(pass, "khushpreet") == 0))
        f1 = 1;
    else
    {
        cout << "\n\t\t\tWrong Password,,Press any key to enter again" << endl;
        cout << "\n\t\t\t";
        getch();
        // des();
        cout << "\nRe-try Entering Password" << endl;
        goto password;
    }

    if (f1 == 1)
    {
        clrscr();

    label2:

        Dis();
        textcolor(YELLOW);
        cout << "\n******************************************************************************";
        cout << "\n\t\t\t\t";
        textcolor(LIGHTCYAN);
        cprintf("ADD NOTES MODE");
        textcolor(YELLOW);
        cout << "\n******************************************************************************";
        cout << "\n\t\t\t1.CREATE NEW NOTES";
        cout << "\n\t\t\t2.DISPLAY STORED NOTES";
        cout << "\n\t\t\t3.ROLLBACK TO MAIN MENU";
        cout << "\n\t\t\t4.EXIT THE PROGRAM";
        textcolor(BROWN);
        cout << "\n";
        cprintf("------------------------------------------------------------------------------");
        cout << "\n\t\t";
        textcolor(YELLOW);
        cprintf("   ENTER YOUR CHOICE  : ");
        cin >> ch2;
        if ((ch2 >= 'A' && ch2 <= 'Z') || (ch2 >= 'a' && ch2 <= 'z'))
        {
            cout << "\n\t\tWrong Input"
                 << "\n\t\tKindly Re-ENTER,Press any key to enter again";
            getch();
            clrscr();
            goto label2;
        }

        else if (ch2 >= '1' && ch2 <= '8')
        {
            switch (ch2)
            {
            case '1':
                clrscr();
                Dis();
                cout << "\n******************************************************************************";
                cout << "\n\t\t\t\t";
                textcolor(LIGHTBLUE);
                cprintf("INSERTION");
                textcolor(YELLOW);
                cout << "\n******************************************************************************";
                Insertion();
                clrscr();
                goto label2;

            case '2':
                clrscr();
                Dis();
                cout << "\n******************************************************************************";
                cout << "\n\t\tDISPLAYING THE STORED NOTES";
                cout << "\n******************************************************************************";
                Display();
                clrscr();
                goto label2;

            case '4':
                Dis();
                cout << "\n\n\n\t\t********************************************";
                cout << "\n\t\t\t\tRETURNING";
                cout << "\n\t\t********************************************";
                exit1();
                break;
            case '3':
                loading2();
            default:
                cout << "\nWRONG INPUT\n";
            }
        }

        else
        {

            cout << "\n\t\tWrong Input"
                 << "\n\t\tKindly Re-ENTER,Press any key to enter again";
            getch();
            clrscr();
            goto label2;
        }
    }
}

void menu1()
{
    char ch1;
label:
    clrscr();
    textcolor(LIGHTCYAN);
    cout << "\n\n\n\t\t";
    cprintf("********************************************");
    cout << endl
         << "\t\t\t";
    cprintf("   CHEMISTRY PROJECT ");
    cout << endl
         << "\t\t";
    cprintf("********************************************");
    textcolor(LIGHTMAGENTA);
    cout << "\n\n\t\t\t1.PREDEDINED NOTES";
    cout << "\n\n\t\t\t2.NOTES";
    cout << "\n\n\t\t\t3.PERFORM CONCENTRATION CALCULATIONS";
    cout << "\n\n\t\t\t4.CREDITS";
    cout << "\n\n\t\t\t5.EXIT";
    textcolor(BROWN);
    cout << "\n\t\t";
    cprintf("--------------------------------------------");
    cout << "\n\t\t";
    textcolor(YELLOW);
    cprintf("   ENTER YOUR CHOICE  : ");
    cin >> ch1;
    if ((ch1 >= 'A' && ch1 <= 'Z') || (ch1 >= 'a' && ch1 <= 'z'))
    {
        goto label;
    }
    if (ch1 >= '1' && ch1 <= '5')
    {
        switch (ch1)
        {
        case '2':
            Owner();
            break;
        case '1':
            clrscr();
            oldnotes();
            break;
        case '3':
            clrscr();
            calc();
            break;
        case '4':
            clrscr();
            credit();
            break;
        case '5':
            exit1();
            break;
        }
    }
    else
    {
        while (1)
        {
            cout << "\n\t\tWrong Input"
                 << "\n\t\tKindly Re-ENTER,Press any key to enter again";
            getch();
            menu1();
        }
    }
}

void loading2()
{
    textcolor(LIGHTBLUE);
    clrscr();
    textcolor(LIGHTCYAN);
    gotoxy(30, 12);
    cprintf("LOADING....");
    int x = 0, a = 219, num = 5;
    char ch;
    ch = a;
    for (int i = 1; i <= 20; i++)
    {
        gotoxy(30 + x, 13);
        delay(150);
        cout << ch;
        x = x + 1;
        gotoxy(53, 13);
        cout << num << "%";
        num = num + 5;
    }
    a = 1;
    ch = a;
    gotoxy(35, 14);
    textcolor(LIGHTCYAN);
    cprintf("COMPLETING YOUR REQUEST ");
    cout << ch << " " << ch << " ";
    for (int k = 1; k < 6; k++)
    {
        cout << ".";
        delay(100);
    }
    textcolor(LIGHTMAGENTA);
    menu1();
}

void loading()
{

    clrscr();
    Dis();
    textcolor(LIGHTCYAN);
    cout << "\n\t\t\t";
    cprintf("    CONCENTRATION ENCYCLOPEDIA");
    textcolor(LIGHTBLUE);
    cout << "\n";
    cprintf("******************************************************************************");
    cout << "\n\t\t\t";
    textcolor(LIGHTRED);
    gotoxy(30, 14);
    cprintf("LOADING ");
    int x = 0, a = 219, num = 0;
    char ch;
    ch = a;
    for (int i = 1; i <= 26; i++)
    {
        gotoxy(30 + x, 15);
        delay(250);
        cout << ch;
        x = x + 1;
        gotoxy(58, 15);
        cout << num << "%";
        num = num + 4;
    }
    a = 1;
    ch = a;
    textcolor(LIGHTGREEN);
    gotoxy(38, 16);
    cprintf("COMPLETE ", ch, " ", ch, " ");
    delay(200);
    cprintf("!");
    delay(200);
    cprintf("!");
    delay(300);
    gotoxy(30, 21);
    textcolor(LIGHTCYAN + BLINK);
    cprintf("Press any key to continue...........");
    getch();
}


void main()
{
    textcolor(YELLOW);
    loading();
    textcolor(LIGHTMAGENTA);
    menu1();
    getch();
}
