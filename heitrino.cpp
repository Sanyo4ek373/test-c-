#include <iostream>

void fill_pitch(int **pitch,int height, int width) {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            pitch[i][j] = 0;
        }
    }           
} 

void show_pitch(int **pitch,int height, int width){
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            std::cout << pitch[i][j] << " ";
        }
        std::cout << std::endl; 
    }
}

void setup_pitch(int array[]) {
    
}
int main() {
    const int WIDTH = 10;
    const int HEIGHT = 10;

    int **pitch = new int * [HEIGHT];
    for (int i = 0; i < WIDTH; ++i) {
        pitch[i] = new int[WIDTH];
    }
    
    fill_pitch(pitch, HEIGHT, WIDTH);
    show_pitch(pitch, HEIGHT, WIDTH);
    
    return 0;
}