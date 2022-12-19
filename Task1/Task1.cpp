// IF ARRAY IS SORTED
#include <filesystem>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>


int main()
{
    //get absolute path
    namespace fs = std::filesystem;
    const std::string filename = "Input.txt";
    std::string path = (fs::current_path().string() + "\\" + filename);
    

    std::string line;

    int n,count = 0;

    std::ifstream in(path);  
    if (in.is_open())
    {

        //get count of numbers
        while (in >> n) ++count;

        in.clear();
        in.seekg(0, std::ios::beg);

        int* data = new int[count];

        int k = 0;

        while (in >> n) data[k++] = n;

        std::sort(data, data + count);

        int leftIndex = 0; 
        int rightIndex = count - 1; 
        while (leftIndex != rightIndex)
        {
            int curSum = data[leftIndex] + data[rightIndex];
            if (curSum < 2023)
                leftIndex++;
            else if (curSum > 2023)
                rightIndex--;
            else 
            {
                std::cout << data[leftIndex] << " + " << data[rightIndex] << " = 2023" << std::endl;
                return 0;
            }
        }
    }
    in.close();
    std::cout << "End of program" << std::endl;
    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
