#include "readCommandLine.h"
#include "MyException.h"
#include "ExceptionCommandLine.h"

namespace po = boost::program_options;

std::vector<std::string> readCommandLine(int argc, char** argv){

    std::vector<std::string> input;

    po::options_description desc("Allowed options");
    desc.add_options()
    ("help", "produce help message")
    ("i", po::value< std::vector<std::string> >(), 
        "specify input txt-file for initilizing the game, \n"
        "e.g. --i \"InitialBoard.txt\"")
    ("o", po::value< std::vector<std::string> >(), 
        "specify output txt-file for the game history, \n"
        "e.g. --o \"GameHistory.txt\"")
    ("s", po::value<int>(), 
        "specify number of steps < 2000.\n"
        "e.g. --s 20")
    ;

    po::variables_map vm;        
    po::store(po::parse_command_line(argc, argv, desc), vm);
    po::notify(vm);    

    std::string sfileInitialBoard;
    std::string sfileGameHistory;
    int imaximumNumberOfSteps;

    std::string sbar = "------------------------------------------------------" 
        "----------------------------\n";
    std::cout << sbar;

    if (vm.count("help")) {
        std::cout << desc << "\n";
        input.push_back("help request");
        std::cout << sbar;
        return input;
    }

    if (vm.count("i")) {
        std::cout << "Input file given (" 
            << vm["i"].as< std::vector<std::string> >()[0] << ").\n";
        sfileInitialBoard = vm["i"].as< std::vector<std::string> >()[0];
    } 
    else {
        throw ExceptionCommandLine("Input file NOT given.");
    }

    if (vm.count("o")) {
        std::cout << "Output file for game history given (" 
            << vm["o"].as< std::vector<std::string> >()[0] << ").\n";

        sfileGameHistory = vm["o"].as< std::vector<std::string> >()[0];

        //***Check whether output file already exists:
        bool fileExists = ( access( sfileGameHistory.c_str(), F_OK ) != -1 );
        if (fileExists){
            throw ExceptionCommandLine("Output file already exists.");
        }

    } 
    else {
        throw ExceptionCommandLine("Output file for game history NOT given.");
    }

    if (vm.count("s")) {
        std::cout << "Number of steps of game given (" 
            << vm["s"].as<int>() << ").\n";

        imaximumNumberOfSteps = vm["s"].as<int>();

        if (imaximumNumberOfSteps >= 2000){
            throw ExceptionCommandLine("Number of maximum steps succeeded.");
        }
    } 
    else {
        throw ExceptionCommandLine("Number of steps of game NOT given.");
    }

    std::cout << sbar;

    // Exactly three input parameters (i.e. 2*3+1 arguments) must be given
    if (argc != 7){
        // std::string msg = "Number of input arguments = " 
        // + std::to_string((int) (argc-1)/2) + ". "
        throw ExceptionCommandLine("Input arguments are not correct.");
    }

    input.push_back(sfileInitialBoard);
    input.push_back(sfileGameHistory);
    input.push_back(std::to_string(imaximumNumberOfSteps));

    return input;
}