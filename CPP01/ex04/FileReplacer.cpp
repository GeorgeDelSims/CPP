#include "FileReplacer.hpp"

// FileReplacer::FileReplacer(const std::string& filename, const std::string& s1, const std::string& s2) : _filename(_filename), _s1(s1), _s2(s2) {}

// Constructor
FileReplacer::FileReplacer() {}

//Copy Constructor
FileReplacer::FileReplacer(const FileReplacer& other) : _filename(other._filename), _s1(other._s1), _s2(other._s2) {}

// Destructor
FileReplacer::~FileReplacer() {}

//Copy Assignment Operator 
FileReplacer& FileReplacer::operator=(const FileReplacer& other)
{
    if (this != &other)
    {
        this->_filename = other._filename;
        this->_s1 = other._s1;
        this->_s2 = other._s2;
    }
    return (*this);
}

void    FileReplacer::replace()
{
    std::ifstream   inputFile(_filename.c_str()); // creates input file that reads content of "filename"
    std::string     outputFilename = _filename + ".replace";
    std::ofstream   outputFile(outputFilename.c_str());  // creates output file stream w/ outputFilename
    std::string     line;

    if (!inputFile)
        throw std::runtime_error("Error opening input file");
    if (!outputFile)
        throw std::runtime_error("Error opening output file");
    while (std::getline(inputFile, line))
    {
        outputFile << FileReplacer::replaceString(line, _s1, _s2) << "\n";
    }
    inputFile.close();
    outputFile.close();
}

std::string FileReplacer::replaceString(const std::string& str, const std::string& s1, const std::string& s2)
{
    std::string     result;
    size_t          current_pos = 0; // starting index of the current occurence of s1 
    size_t          prev = 0; //  starting index of the previous occurence of s1

    // string.find() searches the string for the first occurrence of the sequence specified by its arguments.
    while ((current_pos = str.find(s1, prev)) != std::string::npos) // std::string::npos == "not found" / " no position"
    {
        result.append(str, prev, current_pos - prev); // appends right up to start of next occurence of s1
        result += s2;
        prev = current_pos + s1.size(); // moves the prev index to the end of last occurence of s1
    }
    result.append(str, prev, std::string::npos); // appends the rest of the string (until "npos" / no position)
    return (result);
}
