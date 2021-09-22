#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<fstream>
#include <bits/stdc++.h>
#include<cstring>
#include<cstdio>
#include<vector>
#include<windows.h>

using namespace std;
void add_record();
void view_numbers();
void search_record();
void modify_record();
void delete_record();
int line_count();
void wrong_key();
void Exit();
void modify(int key, string na);
void del(string nam);


string name;
int main()
{
    int key;
    system("cls");
    system("color 5f");
    cout<<"\t\t\t\t****************************************\n";
    cout<<"\t\t\t\t**\t \t\t\t      **\n";
    cout<<"\t\t\t\t**\t PHONEBOOK APPLICATION\t      **\n";
    cout<<"\t\t\t\t**\t \t\t\t      **\n";
    cout<<"\t\t\t\t****************************************\n";
    cout<<"\t\t\t\t**\t \t\t\t      **\n";
    cout<<"\t\t\t\t**\t1. Add record\t\t      **\n";
    cout<<"\t\t\t\t**\t \t\t\t      **\n";
    cout<<"\t\t\t\t**\t2. View numbers\t\t      **\n";
    cout<<"\t\t\t\t**\t \t\t\t      **\n";
    cout<<"\t\t\t\t**\t3. Search a Number\t      **\n";
    cout<<"\t\t\t\t**\t \t\t\t      **\n";
    cout<<"\t\t\t\t**\t4. Edit number of information **\n";
    cout<<"\t\t\t\t**\t \t\t\t      **\n";
    cout<<"\t\t\t\t**\t5. Delete Number\t      **\n";
    cout<<"\t\t\t\t**\t \t\t\t      **\n";
    cout<<"\t\t\t\t**\t6. EXIT\t\t\t      **\n";
    cout<<"\t\t\t\t**\t \t\t\t      **\n";
    cout<<"\t\t\t\t****************************************\n";
    cout<<"\n\t\t\t\t\t** Enter keyword: ";
    cin>>key;
    if(key>6 || key<0)
    {
        wrong_key();
    }
    switch(key)
    {
    case 1:
        add_record();
        break;
    case 2:
        view_numbers();
        break;
    case 3:
        search_record();
        break;
    case 4:
        modify_record();
        break;
    case 5:
        delete_record();
        break;
    case 6:
        Exit();
        break;
    }
}


void add_record()
{
    string name_add,number_add,address, gender;
    system("cls");
    cout<<"\t\t\t\t****************************************\n";
    cout<<"\t\t\t\t**\t \t\t\t      **\n";
    cout<<"\t\t\t\t**\t PHONEBOOK APPLICATION\t      **\n";
    cout<<"\t\t\t\t**\t \t\t\t      **\n";
    cout<<"\t\t\t\t****************************************\n";
    cout<<"\t\t\t\t**                                    **\n";
    cout<<"\t\t\t\t**  Enter Name  : ";
    fflush(stdin);
    getline(cin, name_add);
    cout<<"\t\t\t\t**                                    **\n";
    cout<<"\t\t\t\t****************************************\n";
    cout<<"\t\t\t\t**                                    **\n";
    cout<<"\t\t\t\t**  Phone Number: ";
    getline(cin,number_add);
    cout<<"\t\t\t\t**                                    **\n";
    cout<<"\t\t\t\t****************************************\n";
    cout<<"\t\t\t\t**                                    **\n";
    cout<<"\t\t\t\t**  Address : ";
    getline(cin,address);
    cout<<"\t\t\t\t**                                    **\n";
    cout<<"\t\t\t\t****************************************\n";
    cout<<"\t\t\t\t**                                    **\n";
    cout<<"\t\t\t\t**  Gender  : ";
    getline(cin,gender);
    cout<<"\t\t\t\t**                                    **\n";
    cout<<"\t\t\t\t****************************************\n";

    ofstream input, mai;
    input.open(name_add+".txt");
    mai.open("Aaa main.txt", ios::app );
    input<<name_add<<"\n"<<number_add<<"\n"<<address<<"\n"<<gender<<"\n";
    mai<<name_add<<"\n";
    input.close();
    mai.close();
    char a;
    cout<<"\t\t\t\t**         **             **          **\n";
    cout<<"\t\t\t\t**  0-EXIT ** 1-Main Menu ** 2-Again  **\n";
    cout<<"\t\t\t\t**         **             **          **\n";
    cout<<"\t\t\t\t****************************************\n";
    cout<<"\n\t\t\t\t\t** Enter keyword: ";
    cin>>a;
    if(a=='0')
    {
        Exit();
    }
    else if(a=='2')
    {
        add_record();
    }
    else
        main();
}


void view_numbers()
{
    int i=0,j=0,k=0,l=0;
    string Count,Count2;
    char temp[100];
    int number_add;
    system("cls");
    ifstream file;
    cout<<"\t\t\t\t****************************************\n";
    cout<<"\t\t\t\t**\t \t\t\t      **\n";
    cout<<"\t\t\t\t**\t PHONEBOOK APPLICATION\t      **\n";
    cout<<"\t\t\t\t**\t \t\t\t      **\n";
    cout<<"\t\t\t\t****************************************\n";
    fflush(stdin);
    file.open("Aaa main.txt");
    while(file>>Count)
    {
        i++;
    }
    file.close();
    string name_add;
    char name_ad[i+1][100], name[100];
    file.open("Aaa main.txt");
    j=0;
    while(getline(file, name_add))
    {
        strcpy(name,name_add.c_str());
        strcpy(name_ad[j], name);
        j++;
    }

    for(k=0; k<=j; k++)
    {
        for(l=k+1; l<=j; l++)
        {
            if(strcmp(name_ad[k],name_ad[l])>0)
            {
                strcpy(temp,name_ad[k]);
                strcpy(name_ad[k],name_ad[l]);
                strcpy(name_ad[l],temp);
            }
        }
    }
    file.close();
    ifstream file2;
    for(k=1; k<j+2; k++)
    {
        name_add= name_ad[k];
        file2.open(name_add+".txt");
        i=0;
        while(getline(file2,Count))
        {
            if(i==0)
            {
                cout<<"\t\t\t\t**                                    **\n";
                cout<<"\t\t\t\t**   Name   : "<<Count<<endl;
                cout<<"\t\t\t\t**                                    **\n";

            }
            else if(i==1)
            {
                cout<<"\t\t\t\t**   Number : "<<Count<<endl;
                cout<<"\t\t\t\t**                                    **\n";
            }
            else if(i==2)
            {
                cout<<"\t\t\t\t**   Address : "<<Count<<endl;
                cout<<"\t\t\t\t**                                    **\n";
            }
            else
            {
                cout<<"\t\t\t\t**   Gender  : "<<Count<<endl;
                cout<<"\t\t\t\t**                                    **\n";
            }
            i++;
        }
        cout<<"\t\t\t\t****************************************\n";
        file2.close();
    }
    cout<<"\t\t\t\t**         **             **          **\n";
    cout<<"\t\t\t\t**  0-EXIT ** 2-Main Menu ** 1-Again  **\n";
    cout<<"\t\t\t\t**         **             **          **\n";
    cout<<"\t\t\t\t****************************************\n";
    cout<<"\n\t\t\t\t\t** Enter keyword: ";
    char a;
    cin>>a;
    if(a=='0')
    {
        Exit();
    }
    else if(a=='1')
    {
        view_numbers();
    }
    else
        main();
}

void search_record()
{
    string name_add;
    int number_add;
    system("cls");
    cout<<"\t\t\t\t****************************************\n";
    cout<<"\t\t\t\t**\t \t\t\t      **\n";
    cout<<"\t\t\t\t**\t PHONEBOOK APPLICATION\t      **\n";
    cout<<"\t\t\t\t**\t \t\t\t      **\n";
    cout<<"\t\t\t\t****************************************\n";
    cout<<"\t\t\t\t** \t \t \t \t      **\n";
    cout<<"\t\t\t\t**  Enter Name which record you want  **"<<endl;
    cout<<"\t\t\t\t**  to search :->\t";
    fflush(stdin);
    string name_a2;
    getline(cin,name_a2);
    cout<<"\t\t\t\t**                                    **\n";
    cout<<"\t\t\t\t****************************************\n";
    cout<<"\t\t\t\t****************************************\n";
    char name_a3[]=".txt";
    ifstream file;
    string Count, a4=name_a2;
    file.open(name_a2+".txt");
    int i=0;
    while(getline(file,Count))
    {
        if(i==0)
        {
            cout<<"\t\t\t\t**                                    **\n";
            cout<<"\t\t\t\t**   Name    : "<<Count<<endl;
            cout<<"\t\t\t\t**                                    **\n";

        }
        else if(i==1)
        {
            cout<<"\t\t\t\t**   Number  : "<<Count<<endl;
            cout<<"\t\t\t\t**                                    **\n";
        }
        else if(i==2)
        {
            cout<<"\t\t\t\t**   Address : "<<Count<<endl;
            cout<<"\t\t\t\t**                                    **\n";
        }
        else
        {
            cout<<"\t\t\t\t**   Address : "<<Count<<endl;
            cout<<"\t\t\t\t**                                    **\n";
            cout<<"\t\t\t\t****************************************\n";
        }
        i++;
    }

    if(i==0)
    {
        cout<<"\t\t\t\t** File not exists     "<<endl;
        cout<<"\t\t\t\t****************************************\n";
    }
    file.close();
    cout<<"\t\t\t\t**         **             **          **\n";
    cout<<"\t\t\t\t**  0-EXIT ** 2-Main Menu ** 1-Again  **\n";
    cout<<"\t\t\t\t**         **             **          **\n";
    cout<<"\t\t\t\t****************************************\n";
    cout<<"\n\t\t\t\t\t** Enter keyword: ";
    char a;
    cin>>a;
    if(a=='0')
    {
        Exit();
    }
    else if(a=='1')
    {
        search_record();
    }
    else
        main();

}

void modify_record()
{
    system("cls");
    string mod_name;
    cout<<"\t\t\t\t****************************************\n";
    cout<<"\t\t\t\t**\t \t\t\t      **\n";
    cout<<"\t\t\t\t**\t PHONEBOOK APPLICATION\t      **\n";
    cout<<"\t\t\t\t**\t \t\t\t      **\n";
    cout<<"\t\t\t\t****************************************\n";
    cout<<"\t\t\t\t**                                    **\n";
    cout<<"\t\t\t\t**    Enter Name :";
    fflush(stdin);
    getline(cin, mod_name);
    cout<<"\t\t\t\t**                                    **\n";
    //cout<<"\t\t\t\t****************************************\n";
    //cout<<"\t\t\t\t** Enter any key to continue          **\n";
    //cout<<"\t\t\t\t****************************************\n";
    string name, number, address, gender;
    //system("cls");
    cout<<"\t\t\t\t****************************************\n";
    //cout<<"\t\t\t\t**\t \t\t\t      **\n";
    //cout<<"\t\t\t\t**\t PHONEBOOK APPLICATION\t      **\n";
    //cout<<"\t\t\t\t**\t \t\t\t      **\n";
    cout<<"\t\t\t\t****************************************\n";
    cout<<"\t\t\t\t**                                    **\n";
    cout<<"\t\t\t\t**    0. Change WHOLE information     **\n";
    cout<<"\t\t\t\t**                                    **\n";
    cout<<"\t\t\t\t**    1. Change Name                  **\n";
    cout<<"\t\t\t\t**                                    **\n";
    cout<<"\t\t\t\t**    2. Change Number                **\n";
    cout<<"\t\t\t\t**                                    **\n";
    cout<<"\t\t\t\t**    3. Change Address               **\n";
    cout<<"\t\t\t\t**                                    **\n";
    cout<<"\t\t\t\t**    4. Change Gender                **\n";
    cout<<"\t\t\t\t**                                    **\n";
    cout<<"\t\t\t\t**    5. EXIT                         **\n";
    cout<<"\t\t\t\t**                                    **\n";
    cout<<"\t\t\t\t**    6. Main Menu                    **\n";
    cout<<"\t\t\t\t**                                    **\n";
    cout<<"\t\t\t\t****************************************\n";
    cout<<"\t\t\t\t****************************************\n";
    cout<<"\n\t\t\t\t\t** Enter keyword: ";
    int key;
    cin>>key;
    if(key>5 || key<0)
    {
        system("cls");
        cout<<"\t\t\t\t****************************************\n";
        cout<<"\t\t\t\t**\t \t\t\t      **\n";
        cout<<"\t\t\t\t**\t PHONEBOOK APPLICATION\t      **\n";
        cout<<"\t\t\t\t**\t \t\t\t      **\n";
        cout<<"\t\t\t\t****************************************\n";
        cout<<"\t\t\t\t****************************************\n";
        cout<<"\t\t\t\t**\t \t\t\t      **\n";
        cout<<"\t\t\t\t**   YOU HAVE ENTERED WRONG KEY       **\n";
        cout<<"\t\t\t\t**\t \t\t\t      **\n";
        cout<<"\t\t\t\t**   Press any key to main menu and   **\n";
        cout<<"\t\t\t\t**   plese this time enter right key  **\n";
        cout<<"\t\t\t\t**\t \t\t\t      **\n";
        cout<<"\t\t\t\t****************************************\n";
        getch();
        modify_record();
    }

    switch(key)
    {
    case 0:
        del(mod_name);
        break;
    case 1:
        {
        modify(key, mod_name);
         break;
        }
    case 2:
        modify(key, mod_name);
        break;
    case 3:
        modify(key, mod_name);
        break;
    case 4:
        modify(key, mod_name);
        break;
    case 5:
        Exit();
        break;
    case 6:
        main();
        break;
    }

}


void delete_record()
{
    string number_add;
    string name_add;
    system("cls");
    cout<<"\t\t\t\t****************************************\n";
    cout<<"\t\t\t\t**\t \t\t\t      **\n";
    cout<<"\t\t\t\t**\t PHONEBOOK APPLICATION\t      **\n";
    cout<<"\t\t\t\t**\t \t\t\t      **\n";
    cout<<"\t\t\t\t****************************************\n";
    cout<<"\t\t\t\t**\n";
    cout<<"\t\t\t\t**  Enter Name: ";
    fflush(stdin);
    char name_a2[20];
    cin.getline(name_a2, 20);
    cout<<"\t\t\t\t**\n";
    cout<<"\t\t\t\t****************************************\n";
    int status;
    char name_a3[]=".txt";
    string name_a1;
    name_a1=name_a2;
    strcat(name_a2,name_a3);
    status = remove(name_a2);
    if(status!=0)
    {
        cout<<"\t\t\t\t****************************************\n";
        cout<<"\t\t\t\t**\t \t\t\t      **\n";
        cout<<"\t\t\t\t**   File Deletion Failed. Probably   **\n";
        cout<<"\t\t\t\t**   no such file in the directory    **\n";
        cout<<"\t\t\t\t**\t \t\t\t      **\n";
        cout<<"\t\t\t\t****************************************\n";
    }
    else
    {
        cout<<"\t\t\t\t****************************************\n";
        cout<<"\t\t\t\t**\t \t\t\t      **\n";
        cout<<"\t\t\t\t**    Successfully deleted record.    **\n";
        cout<<"\t\t\t\t**\t \t\t\t      **\n";
        cout<<"\t\t\t\t****************************************\n";
    }
    cout<<endl;
    cout<<"\t\t\t\t**         **             **          **\n";
    cout<<"\t\t\t\t**  0-EXIT ** 2-Main Menu ** 1-Again  **\n";
    cout<<"\t\t\t\t**         **             **          **\n";
    cout<<"\t\t\t\t****************************************\n";
    cout<<"\n\t\t\t\t\t** Enter keyword: ";
    char a;
    cin>>a;
    ifstream Aaa;
    string A[100], b;
    Aaa.open("Aaa main.txt");
    int i=0,j=0;
    while(getline(Aaa, b))
    {
        if(b!=name_a1)
        {
            int ii=b.length();
            if(ii!=1 || ii!=0)
            {
            A[i]=b;
            i++;
            }
        }
        j++;
    }
    Aaa.close();
    remove("Aaa main.txt");
    ofstream Aa;
    j=i;
    Aa.open("Aaa main.txt");
    for(i=0; i<j; i++)
    {
        Aa<<A[i]+"/n";
    }
    Aa.close();
    if(a=='0')
    {
        Exit();
    }
    else if(a=='1')
    {
        delete_record();
    }
    else
        main();

}
void Aa_main(string inpt, string mother)
{

    ifstream Aaa;
    string A[100], b;
    Aaa.open("Aaa main.txt");
    int i=0,j=0;
    while(getline(Aaa, b))
    {
        if(b == mother)
        {
            A[i]= inpt;
            i++;
        }
        else
            {
            A[i]=b;
            i++;
        }
        j++;
    }
    Aaa.close();
    remove("Aaa main.txt");
    ofstream Aa;
    Aa.open("Aaa main.txt");
    for(i=0; i<=j; i++)
    {
        Aa<<A[i]<<"\n";
    }
    Aa.close();
}

void modify(int key, string na)
{
    int m;
    ofstream f;
    system("cls");
    cout<<"\t\t\t\t****************************************\n";
    cout<<"\t\t\t\t**\t \t\t\t      **\n";
    cout<<"\t\t\t\t**\t PHONEBOOK APPLICATION\t      **\n";
    cout<<"\t\t\t\t**\t \t\t\t      **\n";
    cout<<"\t\t\t\t****************************************\n";
    cout<<"\t\t\t\t****************************************\n";
    cout<<"\t\t\t\t**                                    **\n";
    cout<<"\t\t\t\t** Enter  ";
    if(key == 1)
    {
        cout<<"Name :";
    }
    else if(key == 2)
    {
        cout<<"Number :";
    }
    else if(key == 3)
    {
        cout<<"Address :";
    }
    else if(key == 4)
    {
        cout<<"Gender :";
    }

    string name_a1, inpu;
    fflush(stdin);
    getline(cin, inpu);
    cout<<"\t\t\t\t**                                    **\n";
    cout<<"\t\t\t\t****************************************\n";
    char name_a2[20];
    strcpy(name_a2, na.c_str());
    char name_a3[]=".txt";
    name_a1=name_a2;
    strcat(name_a2,name_a3);

    ifstream Aaa;
    string A[100], b;
    Aaa.open(name_a2);
    int i=0,j=0;
    while(getline(Aaa, b))
    {
        A[i]=b;
        i++;
        j++;
    }
    Aaa.close();
    int status;
    remove(name_a2);
    ofstream Aa;
    if(key==1){
        Aa.open(inpu+".txt");
        Aa_main(inpu, na);
    }
    else
    {
        Aa.open(name_a2);
    }

    for(i=0; i<j; i++)
    {
        if((i+1)!= key)
        {
        Aa<<A[i]<<"\n";
        }
        else
            Aa<<inpu<<"\n";
    }
    Aa.close();

    cout<<"\t\t\t\t**         **             **          **\n";
    cout<<"\t\t\t\t**  0-EXIT ** 2-Main Menu ** 1-Again  **\n";
    cout<<"\t\t\t\t**         **             **          **\n";
    cout<<"\t\t\t\t****************************************\n";
    cout<<"\n\t\t\t\t\t** Enter keyword: ";
    char a;
    cin>>a;
    if(a=='0')
    {
        Exit();
    }
    else if(a=='1')
    {
        modify_record();
    }
    else
        main();

}
void del(string nam)
{
    string number_add;
    string name_add;
    system("cls");
    cout<<"\t\t\t\t****************************************\n";
    cout<<"\t\t\t\t**\t \t\t\t      **\n";
    cout<<"\t\t\t\t**\t PHONEBOOK APPLICATION\t      **\n";
    cout<<"\t\t\t\t**\t \t\t\t      **\n";
    cout<<"\t\t\t\t****************************************\n";
    cout<<"\t\t\t\t**\n";
    cout<<"\t\t\t\t**  Enter Name: ";
    fflush(stdin);
    char name_a2[20];
    strcpy(name_a2, nam.c_str());
    //cin.getline(name_a2, 20);
    cout<<"\t\t\t\t**\n";
    cout<<"\t\t\t\t****************************************\n";
    int status;
    char name_a3[]=".txt";
    string name_a1;
    name_a1=name_a2;
    strcat(name_a2,name_a3);
    status = remove(name_a2);
    if(status!=0)
    {
        cout<<"\t\t\t\t****************************************\n";
        cout<<"\t\t\t\t**\t \t\t\t      **\n";
        cout<<"\t\t\t\t**   File Deletion Failed. Probably   **\n";
        cout<<"\t\t\t\t**   no such file in the directory    **\n";
        cout<<"\t\t\t\t**\t \t\t\t      **\n";
        cout<<"\t\t\t\t****************************************\n";
    }
    else
    {
        cout<<"\t\t\t\t****************************************\n";
        cout<<"\t\t\t\t**\t \t\t\t      **\n";
        cout<<"\t\t\t\t**    Successfully deleted record.    **\n";
        cout<<"\t\t\t\t**\t \t\t\t      **\n";
        cout<<"\t\t\t\t****************************************\n";
    }
    cout<<endl;
    cout<<"\t\t\t\t**         **             **          **\n";
    cout<<"\t\t\t\t**  0-EXIT ** 2-Main Menu ** 1-Again  **\n";
    cout<<"\t\t\t\t**         **             **          **\n";
    cout<<"\t\t\t\t****************************************\n";
    cout<<"\n\t\t\t\t\t** Enter keyword: ";
    char a;
    //cin>>a;
    ifstream Aaa;
    string A[100], b;
    Aaa.open("Aaa main.txt");
    int i=0,j=0;
    while(getline(Aaa, b))
    {
        if(b!=name_a1)
        {
            A[i]=b;
            i++;
        }
        j++;
    }
    Aaa.close();
    remove("Aaa main.txt");
    ofstream Aa;
    Aa.open("Aaa main.txt");
    for(i=0; i<j; i++)
    {
        Aa<<A[i]<<"\n";
    }
    Aa.close();
    add_record();
}

void wrong_key()
{
    system("cls");
    cout<<"\t\t\t\t****************************************\n";
    cout<<"\t\t\t\t**\t \t\t\t      **\n";
    cout<<"\t\t\t\t**\t PHONEBOOK APPLICATION\t      **\n";
    cout<<"\t\t\t\t**\t \t\t\t      **\n";
    cout<<"\t\t\t\t****************************************\n";
    cout<<"\t\t\t\t****************************************\n";
    cout<<"\t\t\t\t**\t \t\t\t      **\n";
    cout<<"\t\t\t\t**   YOU HAVE ENTERED WRONG KEY       **\n";
    cout<<"\t\t\t\t**\t \t\t\t      **\n";
    cout<<"\t\t\t\t**   Press any key to main menu and   **\n";
    cout<<"\t\t\t\t**   plese this time enter right key  **\n";
    cout<<"\t\t\t\t**\t \t\t\t      **\n";
    cout<<"\t\t\t\t****************************************\n";
    getch();
    main();
}

void Exit()
{
    int i;
    system("cls");
    cout<<"\t\t\t\t****************************************\n";
    Sleep(300);
    cout<<"\t\t\t\t**\t \t\t\t      **\n";
     Sleep(300);
    cout<<"\t\t\t\t**\t PHONEBOOK APPLICATION\t      **\n";
     Sleep(300);
     cout<<"\t\t\t\t**\t \t\t\t      **\n";
     Sleep(300);cout<<"\t\t\t\t****************************************\n";
    cout<<"\t\t\t\t****************************************\n";
     Sleep(300);
     cout<<"\t\t\t\t**\t \t\t\t      **\n";
     Sleep(300);cout<<"\t\t\t\t**         Exited Successfully        **\n";
    cout<<"\t\t\t\t**\t \t\t\t      **\n";
     Sleep(300);cout<<"\t\t\t\t**  THANKS FOR CHOOSING OUR SOFTWARE  **\n";
    cout<<"\t\t\t\t**           :(YN GROUP LTD):         **\n";
     Sleep(300);
    cout<<"\t\t\t\t**\t \t\t\t      **\n";
     Sleep(300);
    cout<<"\t\t\t\t****************************************\n";
     Sleep(300);
    cout<<"\t\t\t\t\t   **  Contact - 01829130344  **\n";
    cout<<"\t\t\t\t\t   *****************************\n";
     Sleep(1000);

}
