#include <iostream>

int main(){
    int rows = 8;
    for(int i = 0; i < rows; i++){
        for(int j = rows; j > i; j--){
            std::cout << j << " ";
        }
        std::cout << std::endl;
    }
}
