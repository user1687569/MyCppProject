//Copyright (c) 2022 user1687569
#include <iostream>
#include <string>
#include <vector>


struct Review
{
    std::string title;
    int rating;
};
bool FillReview(Review & rr);
void ShowReview(const Review & rr);


int main()
{
    std::vector<Review> books;
    Review temp;
    while (FillReview(temp))
        books.push_back(temp);
    
    int num = books.size();
    if(num > 0)
    {
        std::cout << "Thank you. You entered the following: " << std::endl
                  << "Rating\t Book" << std::endl;
        for(int i = 0; i < num; i++)
            ShowReview(books[i]);
        
        std::cout << "Reprising: " << std::endl
                  << "Rating\tBook" << std::endl;
        std::vector<Review>::iterator pr;
        for(pr = books.begin(); pr != books.end(); pr++)
            ShowReview(*pr);
        
        std::vector<Review> oldlist(books);
        if(num > 3)
        {
            books.erase(books.begin() + 1, books.begin() + 3);
            std::cout << "After erase: " << std::endl;
            for(pr = books.begin(); pr != books.end(); pr++)
                ShowReview(*pr);
            books.insert(books.begin(), oldlist.begin() + 1, oldlist.begin() + 2);
            std::cout << "After insertion: " << std::endl;
            for(pr = books.begin(); pr != books.end(); pr++)
                ShowReview(*pr);
        }

        books.swap(oldlist);
        std::cout << "Swapping oldlist with books: " << std::endl;
        for(pr = books.begin(); pr != books.end(); pr++)
            ShowReview(*pr);
        std::cout << "After swapping oldlist: " << std::endl;
        for(pr = oldlist.begin(); pr != oldlist.end(); pr++)
                ShowReview(*pr);
    }
    else
        std::cout << "Nothing entered, nothing gained." << std::endl;

    return 0;
}


bool FillReview(Review & rr)
{
    std::cout << "Enter book title (quit to quit): ";
    std::getline(std::cin, rr.title);
    if(rr.title == "quit")
        return false;
    
    std::cout << "Enter book rating: ";
    std::cin >> rr.rating;
    if(!std::cin)
        return false;
    
    while (std::cin.get() != '\n')
        continue;
    
    return true;
}


void ShowReview(const Review & rr)
{
    std::cout << rr.rating << "\t" << rr.title << std::endl;
}





