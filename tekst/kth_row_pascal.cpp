// https://www.interviewbit.com/problems/kth-row-of-pascals-triangle/?fbclid=IwAR1Tj8YJ5cl1_jNyzMowNcnwSwVHHjLCwIJcXgbM5_XJym5cmUAIZMh_FyY

#include <iostream>
#include <vector>

void f(std::vector<int> &array, int n)
{
    int tmp = array[0], tmp_1;

    array[0] = 1;
    for (int i = 1; i < n; i++) {
        tmp_1 = array[i];
        array[i] = tmp + array[i];
        tmp = tmp_1;
    }

    array[n] = 1;

}
void kth_row(int k, std::vector<int> &array, int n)
{   
    if (k == 0) {
        f(array, n);

        for (int i = 0; i < n + 1; i++) 
            std::cout << array[i] << " ";
        std::cout << "\n";
        return ;
    }

    f(array, n);

    kth_row(k - 1, array, n + 1);
}

int main ()
{
    int k;

    std::cin >> k;

    std::vector<int> array;

    if (k == 1)
        array.reserve(k);
    else
        array.reserve(k + 1);


    if (k == 1 || k == 0)
        std::cout << "1\n";
    else if (k == 2) {
        std::cout << "1 2 1\n";
    }
    else {    
        array[0] = 1;
        array[1] = 2;
        array[2] = 1;

        kth_row(k - 3, array, 3);
    }

    return 0;
}



// void f(std::vector<int> &array, int n)
// {
//     int tmp = array[0], tmp_1;

//     array[0] = 1;
//     for (int i = 1; i < n; i++) {
//         tmp_1 = array[i];
//         array[i] = tmp + array[i];
//         tmp = tmp_1;
//     }

//     array[n] = 1;

// }
// void kth_row(int k, std::vector<int> &array, int n)
// {   
//     if (k == 0) {
//         f(array, n);

//         // for (int i = 0; i < n + 1; i++) 
//         //     std::cout << array[i] << " ";
//         // std::cout << "\n";
//         return ;
//     }

//     f(array, n);

//     kth_row(k - 1, array, n + 1);
// }

// vector<int> Solution::getRow(int k) {
//     vector<int> array(k + 1);
    
//     if (k == 0)
//         return {1};
//     else if (k == 1)
//         return {1, 1};
//     else if (k == 2) {
//         array[0] = 1;
//         array[1] = 2;
//         array[2] = 1;
//     }
//     else {    
//         array[0] = 1;
//         array[1] = 2;
//         array[2] = 1;

//         kth_row(k - 3, array, 3);
//     }
    
//     return array;
// }
