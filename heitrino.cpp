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
}

void setup_pitch(int **pitch, std::string cells) {
    for(int i = 0; i < cells.length() / 2; ++i) {
        int index = i * 2;
        pitch[cells[index] - '0'][cells[index + 1] - '0'] = 1;
    } 
}

int find_live_cells(int **pitch, int column, int line) {
    int live_cells = 0;

    int i = 0;
    int j = 0;

    int m = 0;
    int n = 0;

    if (column == 0) i += 1;
    if (column == 9) m += 1;

    if (line == 0) j += 1;
    if (line == 9) n += 1;

    for (i; i < 3 - m; ++i) {
        for (j; j < 3 - n; ++j) {
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
    next_pitch = pitch;

    while (true)
    {
        int live_cells_count = 0;

        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                int live_cells = find_live_cells(pitch, i, j);
                live_cells_count += pitch[i][j];

                if (live_cells == 3) next_pitch[i][j] = 1;
                if (live_cells < 2 || live_cells > 3) next_pitch[i][j] = 0;
            }
        }
        show_pitch(pitch, height, width);
        
        if (next_pitch == pitch || live_cells_count == 0) {
            pitch = next_pitch;
            break;
        }
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