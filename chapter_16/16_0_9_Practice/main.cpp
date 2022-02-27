//Copyright (c) 2022 user1687569
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


struct Review
{
    std::string title;
    int rating;
};

bool operator<(const Review & r1, const Review & r2);
bool worseThan(const Review & r1, const Review & r2);
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
        std::cout << "Thank you. You entered the following "
                  << books.size() << "ratings:" << std::endl 
                  << "Rating\t Book" << std::endl;
        for_each(books.begin(), books.end(), ShowReview);
        
        std::sort(books.begin(), books.end());
        std::cout << "Sorted by title:\nRating\tBook\n";
        for_each(books.begin(), books.end(), ShowReview);

        std::sort(books.begin(), books.end(), worseThan);
        std::cout << "Sorted by rating:\nRating\tBook\n";
        for_each(books.begin(), books.end(), ShowReview);

        random_shuffle(books.begin(), books.end());
        std::cout << "After shuffling:\nRating\tBook\n";
        for_each(books.begin(), books.end(), ShowReview);
    }
    else
        std::cout << "No entries." << std::endl;

    std::cout << "Bye." << std::endl;
    return 0;
}


// 降序
bool operator<(const Review & r1, const Review & r2)
{
    if(r1.title < r2.title)
        return true;
    else if(r1.title == r2.title && r1.rating < r2.rating)
        return true;
    else
        return false;
}


// 升序
bool worseThan(const Review & r1, const Review & r2)
{
    if(r1.rating < r2.rating)
        return true;
    else
        return false;
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





