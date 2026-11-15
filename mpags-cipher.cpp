#include <cctype>
#include <iostream>
#include <string>
#include <vector>
#include <cctype>

std::string transformChar(const char in_char){
    std::string result{};
    if (std::isalpha(in_char)) {
        result += std::toupper(in_char);
    }

        // Transliterate digits to English words
    switch (in_char) {
            case '0':
                result += "ZERO";
                break;
            case '1':
                result += "ONE";
                break;
            case '2':
                result += "TWO";
                break;
            case '3':
                result += "THREE";
                break;
            case '4':
                result += "FOUR";
                break;
            case '5':
                result += "FIVE";
                break;
            case '6':
                result += "SIX";
                break;
            case '7':
                result += "SEVEN";
                break;
            case '8':
                result += "EIGHT";
                break;
            case '9':
                result += "NINE";
                break;
        }

    return result;
    
}


bool processCommandLine(const std::vector<std::string>& cmdLineArgs, std::string& inputFile, std::string& outputFile, bool helpRequested, bool versionRequested){
    const std::size_t nCmdLineArgs{cmdLineArgs.size()};
    
    
    for (std::size_t i{1}; i < nCmdLineArgs; ++i) {
        if (cmdLineArgs[i] == "-h" || cmdLineArgs[i] == "--help") {
            helpRequested = true;
        } else if (cmdLineArgs[i] == "--version") {
            versionRequested = true;
        } else if (cmdLineArgs[i] == "-i") {
            // Handle input file option
            // Next element is filename unless "-i" is the last argument
            if (i == nCmdLineArgs - 1) {
                std::cerr << "[error] -i requires a filename argument"
                          << std::endl;
                // exit main with non-zero return to indicate failure
                return false;
            } else {
                // Got filename, so assign value and advance past it
                inputFile = cmdLineArgs[i + 1];
                ++i;
            }
        } else if (cmdLineArgs[i] == "-o") {
            // Handle output file option
            // Next element is filename unless "-o" is the last argument
            if (i == nCmdLineArgs - 1) {
                std::cerr << "[error] -o requires a filename argument"
                          << std::endl;
                // exit main with non-zero return to indicate failure
                return false;
            } else {
                // Got filename, so assign value and advance past it
                outputFile = cmdLineArgs[i + 1];
                ++i;
            }
        } else {
            // Have an unknown flag to output error message and return non-zero
            // exit status to indicate failure
            std::cerr << "[error] unknown argument '" << cmdLineArgs[i]
                      << "'\n";
            return false;
        }
    }

    // Handle help, if requested
    if (helpRequested) {
        // Line splitting for readability
        std::cout
            << "Usage: mpags-cipher [-h/--help] [--version] [-i <file>] [-o <file>]\n\n"
            << "Encrypts/Decrypts input alphanumeric text using classical ciphers\n\n"
            << "Available options:\n\n"
            << "  -h|--help        Print this help message and exit\n\n"
            << "  --version        Print version information\n\n"
            << "  -i FILE          Read text to be processed from FILE\n"
            << "                   Stdin will be used if not supplied\n\n"
            << "  -o FILE          Write processed text to FILE\n"
            << "                   Stdout will be used if not supplied\n\n"
            << std::endl;
        // Help requires no further action, so return from main
        // with 0 used to indicate success
        return 0;
    }

    // Handle version, if requested
    // Like help, requires no further action,
    // so return from main with zero to indicate success
    if (versionRequested) {
        std::cout << "0.1.0" << std::endl;
        return 0;
    }

    // Warn that input file option not yet implemented
    if (!inputFile.empty()) {
        std::cerr << "[warning] input from file ('" << inputFile
                  << "') not implemented yet, using stdin\n";
                  
    }

    return true;

}

int main(int argc, char* argv[])
{
    // Convert the command-line arguments into a more easily usable form
    const std::vector<std::string> cmdLineArgs{argv, argv + argc};
    std::string inputFile{""};
    std::string outputFile{""};
    bool helpRequested{false};
    bool versionRequested{false};

    
    

    processCommandLine(cmdLineArgs, inputFile, outputFile, helpRequested, versionRequested);

    // Initialise variables
    std::string inputText {""};

    // Read in user input from stdin/file
    

    char in_char {};
    while(std::cin >> in_char){
        inputText += transformChar(in_char);
    }
    // Print out the transliterated text
    

    // Warn that output file option not yet implemented
    if (!outputFile.empty()) {
        std::cerr << "[warning] output to file ('" << outputFile
                  << "') not implemented yet, using stdout\n";
    }

    std::cout << inputText << std::endl;

    // No requirement to return from main, but we do so for clarity
    // and for consistency with other functions
    return 0;
}
