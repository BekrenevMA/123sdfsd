#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    cout<<"Entre your file: ";
    char in_file[15];
    cin>>in_file;

    int i = 0;
    while (in_file[i])
    {
        tolower(in_file[i]);
        i++;
    }

    const char* start = in_file;
    const char* illegal_characters="*\"<>?|";

    if (strcspn(in_file, illegal_characters)==strlen(in_file))
    {
        if (((strchr(in_file, ':')==strrchr(in_file, ':'))&&(strcspn( in_file, ":")==1)&&(strcspn( in_file, "\\")==2))||(strcspn(in_file, ":")==strlen(in_file)))
        {
            const size_t dot = strcspn(in_file, ".");
            start+=dot;
            if (strcmp(start, ".txt")==0||strcmp(start, ".")==0||strcmp(start, "")==0)
            {
                if (strcmp(start, "")==0)
                    strcat(in_file, ".txt");
                if (strcmp(start, ".")==0)
                    strcat(in_file, "txt");
                FILE * ptrFile = fopen(in_file, "r");
                if (ptrFile == NULL)
                {
                    perror ("Error opening file");
                }
                else
                {
                    fseek( ptrFile, 0, SEEK_END );
                    long size_of_file = ftell(ptrFile);
                    fseek( ptrFile, 0, SEEK_SET );

                    char *my_array = new char[size_of_file];
                    size_t result = fread(my_array, 1, size_of_file, ptrFile);
                    for (size_t i=0; i<size_of_file; i++)
                    {
                        cout<<my_array[i];
                    }
                    // ... new[size_of_file+1]
                    // my_array[size_of_file] = '\0';
                    // cout << my_array;
                    //
                    // cout.write(my_array, size_of_file);
                    cout<<'\n';
                    char input_string[15];
                    cin >> input_string;

                    size_t o=0;
                    char* place;
                    place =my_array;

                    place=strstr(my_array, input_string);
                    while (place)
                    {
                        place=strstr(place, input_string);
                        if (place)
                        {
                            o++;
                            place+=strlen(input_string);
                        }
                    }

                    cout<<o;

                    delete[] my_array;

                }
                fclose (ptrFile);
            } else
            {
                cout<<"Incorrect file extension";
            }
        }
        else
        {
            cout<<"Your file contains two or more \":\" or the position of \":\" not the second or it is't \"/\" after the \":\"";
        }
    }
    else
    {
        cout<<"Your file contains one of illegal characters *\"<>?|";
    }

    return 0;
}
