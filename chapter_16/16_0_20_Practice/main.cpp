//Copyright (c) 2022 user1687569
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <iterator>
#include <algorithm>
#include <cctype>


char toLower(char ch) { return tolower(ch); }
std::string & ToLower(std::string & st);
void display(const std::string & s);


int main()
{
    std::vector<std::string> words;
    std::cout << "Enter words (enter quit to quit): " << std::endl;
    std::string input;
    while (std::cin >> input && input != "quit")
        words.push_back(input);

    std::cout << "You entered the following words: " << std::endl;
    for_each(words.begin(), words.end(), display);
    std::cout << std::endl;

    std::set<std::string> wordset;
    transform(words.begin(), words.end(),
            std::insert_iterator<std::set<std::string>> (wordset, wordset.begin()),
            ToLower);
    std::cout << std::endl << "Alphabetic list of words: " << std::endl;
    for_each(wordset.begin(), wordset.end(), display);
    std::cout << std::endl;

    std::map<std::string, int> wordmap;
    std::set<std::string>::iterator si;
    for(si = wordset.begin(); si != wordset.end(); si++)
        wordmap[*si] = count(words.begin(), words.end(), *si);
    
    std::cout << std::endl << "Word frequency:" << std::endl;
    for(si = wordset.begin(); si != wordset.end(); si++)
        std::cout << *si << ": " << wordmap[*si] << std::endl;
    
    return 0;
}


std::string & ToLower(std::string & st)
{
    transform(st.begin(), st.end(), st.begin(), toLower);
    return st;
}


void display(const std::string & s)
{
    std::cout << s << " ";
}



