/* DTS.exe	Logs with a date/time stamp to a text file.
 *			Reads file name from the DTS environmental variable.
 *			If it isn't present, error out.
 *			Echo what is written to the text file to screen for verification.
 *			If no parameters, dump what is in the file.
 */
#include <iostream>
#include <iomanip>      // Used by getstamp() for formatting
#include <fstream>
#include <time.h>       // Used by getstamp()
#include <stdlib.h>     // getenv()
#include <string>
#include <sstream>      // Used by getstamp() for formatting

void displayHelp()
{
	std::cerr <<
		"To use this program, just type its name followed by what you want to log.\n" <<
		"The line will be written to the log file above with a date/time stamp.\n" <<
		"You can use this program to read the log file, just execute it without any\n" <<
		"parameters.\n";
}

// Opens the file and dumps content to screen.
// If file is not present, display some simple help.
void displayFileorHelp(std::string & DTS)
{
    std::cout << "Showing " << DTS << ".\n";
	if (!DTS.empty())
	{
		std::ifstream ifile(DTS.c_str());

		if (!ifile.is_open())
		{
			// Can't open file, most likely due to it not existing yet.
			std::cerr << "Unable to open " << DTS << ".\n\n";
			displayHelp();
		} else {
			std::string readline;
			while (!ifile.eof())
			{
				std::getline( ifile, readline);
				if (!readline.empty())
                    std::cout << readline << "\n";
			}
			ifile.close();
		}
	} else {
		displayHelp();
    }
}

std::string getstamp()
{
    std::stringstream stamp("");
    // Get the local date/time for a stamp
    time_t rawTime;
    time( &rawTime);
	struct tm * splitTime = localtime( &rawTime);
	stamp	<< splitTime->tm_year + 1900 << "/"
			<< std::setw(2) << std::setfill('0') << splitTime->tm_mon + 1 << "/"
			<< std::setw(2) << std::setfill('0') << splitTime->tm_mday << " "
			<< std::setw(2) << std::setfill('0') << splitTime->tm_hour << ":"
			<< std::setw(2) << std::setfill('0') << splitTime->tm_min  << ":"
			<< std::setw(2) << std::setfill('0') << splitTime->tm_sec;

    std::string retstamp("");
    //stamp >> retstamp;
    // To get the whole line, since spaces are embedded.
    std::getline( stamp, retstamp);
    //std::cout << "Inside getstamp(): stamp=" << retstamp << ".\n";

    return retstamp;
}

std::string writetolog(std::string logfile, std::string sentence, bool stamp=true)
{
    std::string written("");

    // Add date/time stamp and then sentence
    if (stamp)
        written += getstamp() + " ";
    // If sentence is empty or NULL, pass out ""
    //written += ": ";
    if (sentence.empty())
        written += "\"\"";
    else
        written += sentence;
    //std::cout << "(Inside writetolog(" << logfile << ", " << sentence << ", " << stamp << "). written=" << written << ".\n";

    // Open the logfile for append.
    std::ofstream ofile(logfile.c_str(), std::ios::app);
    if (!ofile.is_open())
    {
        // Can't open file!
        std::cerr << "Unable to open " << logfile << ".\n\n";
        displayHelp();
    } else {
        ofile << written << std::endl;
	}

    ofile.close();
    return written;
}

std::string getenvstring()
{
    char * chDTS = getenv("DTS");
    if (chDTS != NULL)
        return std::string(chDTS);
    else
        return "";
}

/* This particular join will join an array of char * into a string.
 * The default separator is a space, ' ', but can be overriden.
 */
std::string join(char * cha[], int count, char separator=' ')
{
    std::string joined("");

	//std::cout << cha << ". (Inside join())\n";
	for(int i=0; (i<count-1 && cha[i] != NULL); ++i)
    {
        //std::cout << "cha[" << i << "]:" << cha[i] << ".\n";
        joined.append(cha[i]);
        joined += separator;
    }
    //joined += std::string(cha[count-1]);
    joined.append(cha[count-1]);

	//std::cout << "Inside join: joined=" << joined << ".\n";
    return joined;
}

int main(int argc, char *argv[])
{
    // First, need to find the file which means reading from the environment.
	std::string DTS = getenvstring();

    // If the string is empty, ask the user to set it.
	if (DTS.empty())
	{
		std::cerr << "Please set the DTS enviroment variable.\n";
		std::cerr << "For example, set DTS=%temp%\\TestComments.txt.\n";
		return 1;
	}
    // Display the filename being written to.
    //std::cout << "DTS = " << DTS << ".\n";

    // If no parameters are passed, dump the contents of the log file to the screen.
	if (argc == 1)
	{
		displayFileorHelp(DTS);
		return 0;
	} else {
        // Else, combine all the parameters into 1 string and write to the log file.
        std::string sentence = join(argv+1, argc-1);
        std::string stampedline = writetolog(DTS, sentence);
        std::cout << stampedline << std::endl;
    }

	return 0;
}
