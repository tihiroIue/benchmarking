#include <iostream>
#include <fstream>
#include <bits/stdc++.h> 

using namespace std;

int main(){
    // Create an empty file and fill in enough content (1GB).
    std::vector<char> empty(1024, 0);
    std::ofstream outs("output.img", std::ios::binary | std::ios::out);

    for(int i = 0; i < 1024*1024; i++)
    {
        if (!outs.write(&empty[0], empty.size()))
        {
            std::cerr << "problem writing to file" << std::endl;
            return 255;
        }
    }


    FILE *fp = fopen("output.img", "r");

    time_t start, end;
    char buffer[4096];
    // Record the time of the start and end of the reading to calculate the time of running.
    time(&start);
    // Read the file until the end.
    while(!feof(fp)){
        fread(buffer, sizeof(buffer), 1, fp);
    }
    time(&end);
    fclose(fd);
    double time_taken = double(end - start); 
    
    cout << "It take " << time_taken << "seconds to read the file \n";
    cout << "The speed is " << time_taken / (1024 * 1024) << " seconds each bytes\n";

    return 0;
}