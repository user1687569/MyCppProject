//Copyright (c) 2022 user1687569
#include <iostream>

struct box
{
    char maker[40];
    float height;
    float width;
    float length;
    float volume;
};

void showStructBox(box structBox);
void calculateVolume(box *pBox);

int main()
{
    box blackBox = {"Crypto Punk", 10.0f, 8.0f, 6.0f};
    
    calculateVolume(&blackBox);
    showStructBox(blackBox);

    return 0;
}


void showStructBox(box structBox)
{
    std::cout << "Box Maker: " << structBox.maker << std::endl;
    std::cout << "Box Height: " << structBox.height << std::endl;
    std::cout << "Box Width: " << structBox.width << std::endl;
    std::cout << "Box Length: " << structBox.length << std::endl;
    std::cout << "Box Volume: " << structBox.volume << std::endl;
}


void calculateVolume(box *pBox)
{
    pBox->volume = pBox->height * pBox->width * pBox->length;
}