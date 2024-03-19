#include <algorithm>
#include <iostream>
#include <string>

void fill_pitch(int **pitch, int height, int width) {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            pitch[i][j] = 0;
        }
    }           
} 

void show_pitch(int **pitch, int height, int width){
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            std::cout << pitch[i][j] << " ";
        }
        std::cout << std::endl; 
    }
    std::cout << std::endl;
}

void setup_pitch(int **pitch, std::string cells) {
    for(int i = 0; i < cells.length() / 2; ++i) {
        int index = i * 2;
        pitch[cells[index] - '0'][cells[index + 1] - '0'] = 1;
    } 
}

int find_live_cells(int **pitch, int column, int line) {
    int live_cells = 0;
    
    int c = 0;
    int l = 0;
    int m = 3;
    int n = 3;

    if (column == 0) c = 1;
    if (line == 0) l = 1;
    if (column == 9) m = 2;
    if (line == 9) n = 2;

    for (int i = c; i < m; ++i) {
        for (int j = l; j < n; ++j) {
            live_cells += pitch[column - 1 + i][line - 1 + j];
        }
    }
    return live_cells - pitch[column][line];
}

void find_next_generation(int **pitch, int height, int width) {
    int **next_pitch = new int * [height];
    
    for (int i = 0; i < width; ++i) {
        next_pitch[i] = new int[width];
    }
    fill_pitch(next_pitch, height, width);

    int loops = 0;

    while (true) {
        int live_cells_count = 0;

        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                int live_cells = find_live_cells(pitch, i, j);
                live_cells_count += pitch[i][j];
                std::cout << live_cells;

                if (live_cells == 3 || live_cells == 2 && pitch[i][j] == 1) next_pitch[i][j] = 1;
                else next_pitch[i][j] = 0;
            }
        }
        std::cout << std::endl;

        show_pitch(pitch, height, width);
        std::cout << live_cells_count << std::endl;
        if (next_pitch == pitch || live_cells_count == 0 || loops >= 8) break;
        
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                pitch[i][j] = next_pitch[i][j];
            }
        }
        loops += 1;          
    }
}

int main() {
    const int WIDTH = 10;
    const int HEIGHT = 10;

    int **pitch = new int * [HEIGHT];
    for (int i = 0; i < WIDTH; ++i) {
        pitch[i] = new int[WIDTH];
    }

    std::string cells; 

    std::cout << "Write numbers of live cells from 0 to 9: ";
    std::cin >> cells;
    
    fill_pitch(pitch, HEIGHT, WIDTH);
    setup_pitch(pitch, cells);
    find_next_generation(pitch, HEIGHT, WIDTH);
    return 0;
}