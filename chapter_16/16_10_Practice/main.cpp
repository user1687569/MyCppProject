//Copyright (c) 2022 user1687569
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>

struct Review
{
    std::string title;
    int rating;
    double price;
};

// bool operator<(const Review & r1, const Review & r2);
// bool worseThan(const Review & r1, const Review & r2);
// bool FillReview(Review & rr);
// void ShowReview(const Review & rr);

bool operator<(const std::shared_ptr<Review> & r1, const std::shared_ptr<Review> & r2);
bool RatingAsc(const std::shared_ptr<Review> & r1, const std::shared_ptr<Review> & r2);
// bool RatingDesc(const std::shared_ptr<Review> & r1, const std::shared_ptr<Review> & r2);
bool PriceAsc(const std::shared_ptr<Review> & r1, const std::shared_ptr<Review> & r2);
// bool PriceDesc(const std::shared_ptr<Review> & r1, const std::shared_ptr<Review> & r2);
bool FillReview(std::shared_ptr<Review> & ptr);
void ShowReview(const std::shared_ptr<Review> & rr);
void ShowMenu();


int main()
{
    // std::vector<Review> books;
    std::vector<std::shared_ptr<Review>> books;

    // initialize books
    // Review temp;
    std::shared_ptr<Review> temp_ptr;
    while(FillReview(temp_ptr))
        books.push_back(temp_ptr);
    
    int num = books.size();
    if(num > 0)
    {
        std::cout << "Thank you. You entered the following "
                  << books.size() << "ratings:" << std::endl 
                  << "Rating\t Book" << std::endl;
        for_each(books.begin(), books.end(), ShowReview);
        
        // title ascending
        std::sort(books.begin(), books.end());
        std::cout << "Sorted by title:\nRating\tBook\n";
        for_each(books.begin(), books.end(), ShowReview);

        // rating ascending
        std::sort(books.begin(), books.end(), RatingAsc);
        std::cout << "Sorted by rating ascendig:\nRating\tBook\n";
        for_each(books.begin(), books.end(), ShowReview);

        // rating descending
        std::sort(books.rbegin(), books.rend(), RatingAsc);
        std::cout << "Sorted by rating descending:\nRating\tBook\n";
        for_each(books.rbegin(), books.rend(), ShowReview);

        // price ascending
        std::sort(books.begin(), books.end(), PriceAsc);
        std::cout << "Sorted by price ascendig:\nRating\tBook\n";
        for_each(books.begin(), books.end(), ShowReview);

        // price descending
        std::sort(books.rbegin(), books.rend(), PriceAsc);
        std::cout << "Sorted by price descending:\nRating\tBook\n";
        for_each(books.rbegin(), books.rend(), ShowReview);

        random_shuffle(books.begin(), books.end());
        std::cout << "After shuffling:\nRating\tBook\n";
        for_each(books.begin(), books.end(), ShowReview);
    }
    else
        std::cout << "No entries." << std::endl;

    std::cout << "Bye." << std::endl;
    return 0;
}


// 按 title 降序
bool operator<(const std::shared_ptr<Review> & r1, const std::shared_ptr<Review> & r2)
{
    if(r1->title < r2->title)
        return true;
    else if(r1->title == r2->title && r1->rating < r2->rating)
        return true;
    else
        return false;
}


// 按 rating 升序
bool RatingAsc(const std::shared_ptr<Review> & r1, const std::shared_ptr<Review> & r2)
{
    if(r1->rating < r2->rating)
        return true;
    else
        return false;
}


// 按 rating 降序
// bool RatingDesc(const std::shared_ptr<Review> & r1, const std::shared_ptr<Review> & r2)
// {
//     if(r1->rating > r2->rating)
//         return true;
//     else
//         return false;
// }


// 按 price 升序
bool PriceAsc(const std::shared_ptr<Review> & r1, const std::shared_ptr<Review> & r2)
{
    if(r1->price < r2->price)
        return true;
    else
        return false;
}


// 按 price 降序
// bool PriceDesc(const std::shared_ptr<Review> & r1, const std::shared_ptr<Review> & r2)
// {
//     if(r1->price > r2->price)
//         return true;
//     else
//         return false;
// }


bool FillReview(std::shared_ptr<Review> & ptr)
{
    // allocate memory
    ptr = std::shared_ptr<Review>(new Review);

    std::cout << "Enter book title (quit to quit): ";
    std::getline(std::cin, ptr->title);
    if(ptr->title == "quit")
        return false;
    
    std::cout << "Enter book rating: ";
    std::cin >> ptr->rating;
    if(!std::cin)
        return false;

    std::cout << "Enter book price: ";
    std::cin >> ptr->price;
    if(!std::cin)
        return false;
    
    while (std::cin.get() != '\n')
        continue;
    
    return true;
}


void ShowReview(const std::shared_ptr<Review> & rr)
{
    std::cout << rr->rating << "\t" << rr->title  << "\t" << rr->price << std::endl;
}





