#include<fstream>
#include<iostream>

void fileInputOutput(int argc, char* argv[]) {

    // std::cout << "\nCreating the file with name < " << argv[1] << " >\n";

    std::ofstream fOut(argv[1], std::ios::app );

    std::cout << "\nOpened the < " << argv[1] << " > file for appending.\n";
    
    // std::cout << "\nargv[3] : " << argv[3];
    // std::cout << "\nargv[2] : " << argv[2];       
    
    while(argc>2){
                
        fOut << argv[--argc] << "\n";
        // std::cout << argv[argc] << "\n";       
        // std::cout << "\nargc : " << argc;
        // argc--;
    }

    std::cout << "\nReading the file now...\n";

    //move file pointer to the begning of the file
    fOut.close();
    
    std::cout << "\nClosed the < " << argv[1] << " > file after appending.\n";
    
    std::string line;
            
    std::ifstream fIn(argv[1], std::ios::in);

    std::cout << "\nOpened the < " << argv[1] << " > file for reading.\n";        
    
    while(fIn){
        std::getline(fIn, line);//getline will ignore the endline character at the end of every line

        std::cout << line << "\n";
    }


    fIn.close();
    std::cout << "\nClosed the < " << argv[1] << " > file after reading.\n"; 

}

int main(int argc, char *argv[]) {

    
    try {
        if(argc>1) {
            fileInputOutput(argc, argv);
        }
        else {
            throw "\nNo file name is provided!" ;
        }
    }
    catch(const char* e) {
        std::cout << e << "\n" ;
    }
    
    

    return 0;
}
