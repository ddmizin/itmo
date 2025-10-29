#include <iostream>
#include <vector>
#include <set>
#include <string>

const int L = 600;
const int MAX_BLOCKS = 30000;

struct BlockEvent {
    int time;
    int block_no;
};

std::vector<BlockEvent> release_heap;

void sift_up(int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (release_heap[index].time >= release_heap[parent].time) {
            break;
        }
        std::swap(release_heap[index], release_heap[parent]);
        index = parent;
    }
}

void sift_down(int index) {
    int size = release_heap.size();
    while (true) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int smallest = index;
        
        if (left < size && release_heap[left].time < release_heap[smallest].time) {
            smallest = left;
        }
        if (right < size && release_heap[right].time < release_heap[smallest].time) {
            smallest = right;
        }
        if (smallest == index) {
            break;
        }
        std::swap(release_heap[index], release_heap[smallest]);
        index = smallest;
    }
}

void insert(int time, int block_no) {
    BlockEvent event;
    event.time = time;
    event.block_no = block_no;
    release_heap.push_back(event);
    sift_up(release_heap.size() - 1);
}

BlockEvent extract_min() {
    BlockEvent min_element = release_heap[0];
    release_heap[0] = release_heap.back();
    release_heap.pop_back();
    if (!release_heap.empty()) {
        sift_down(0);
    }
    return min_element;
}

bool is_empty() {
    return release_heap.empty();
}

BlockEvent get_min() {
    return release_heap[0];
}

int main() {
    std::vector<bool> block_status(MAX_BLOCKS + 1, false);
    std::vector<int> release_time(MAX_BLOCKS + 1, 0);
    std::set<int> free_blocks;
    std::vector<std::string> output;
    
    // Инициализация свободных блоков
    for (int i = 1; i <= MAX_BLOCKS; i++) {
        free_blocks.insert(i);
    }
    
    // Чтение входных данных
    std::string line;
    while (getline(std::cin, line)) {
        if (line.empty()) continue;
        
        // Парсинг времени
        int time = 0;
        int i = 0;
        while (i < line.length() && line[i] >= '0' && line[i] <= '9') {
            time = time * 10 + (line[i] - '0');
            i++;
        }
        
        // Пропускаем пробелы
        while (i < line.length() && line[i] == ' ') {
            i++;
        }
        
        if (i >= line.length()) continue;
        
        char type = line[i];
        
        // Освобождаем блоки с истекшим временем
        while (!is_empty() && get_min().time <= time) {
            BlockEvent event = extract_min();
            int block_no = event.block_no;
            if (block_status[block_no] && release_time[block_no] <= time) {
                block_status[block_no] = false;
                free_blocks.insert(block_no);
            }
        }
        
        if (type == '+') {
            // Запрос на выделение блока
            if (!free_blocks.empty()) {
                int block_no = *free_blocks.begin();
                free_blocks.erase(free_blocks.begin());
                block_status[block_no] = true;
                release_time[block_no] = time + L;
                insert(time + L, block_no);
                output.push_back(std::to_string(block_no));
            }
        } else if (type == '.') {
            // Запрос доступа к блоку
            i++; // пропускаем точку
            int block_no = 0;
            while (i < line.length() && line[i] >= '0' && line[i] <= '9') {
                block_no = block_no * 10 + (line[i] - '0');
                i++;
            }
            
            if (block_no >= 1 && block_no <= MAX_BLOCKS && block_status[block_no]) {
                output.push_back("+");
                release_time[block_no] = time + L;
                insert(time + L, block_no);
            } else {
                output.push_back("-");
            }
        }
    }
    
    // Вывод результатов
    for (const auto& result : output) {
        std::cout << result << "\n";
    }
    return 0;
}