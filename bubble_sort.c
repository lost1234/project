#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
/* 
比较两个相邻的元素，将值较大的元素交换至右端
依次比较两个数，将小数放在前面，大数放在后面。
第一遍循环：比较第一个和第二个数字， 小数放在前面，大数在后；然后第二个和第三个比较，以此类推。
第一遍循环结束后，最后一位一定是值最大的元素。
第二遍循环时最后一个数不参与此次循环，等到第二次循环结束后，倒数第二个数字也是值第二大的数，不参与下一次循环。
每一遍循环，比较次数 -1 .
n 个元素需要排序的完成的话, 需要进行 n - 1 遍排序， 每i遍的排序次数为（n - i）次。
所以就是外层控制循环多少遍，内层控制每一遍的循环次数。
外：提取当前数组中最大数，

*/

int int_cmp(const void* a, const void* b) 
{
    int* a_ptr = (int*) a ;
    int* b_ptr = (int*) b ;
    return *a_ptr - *b_ptr ;
}

int str_cmp(const void* a, const void* b) 
{
    char** a_ptr = (char**) a ;
    char** b_ptr = (char**) b ; 
    return **a_ptr - **b_ptr ;
}

void bubble_sort(void* elements, size_t n_elements,
                    size_t size_element, int(*cmp)(const void*, const void*) )
{   
    void* temp = malloc(size_element);
    for(int i = 0; i < n_elements; i++) {
        for(int j = 0; j < n_elements-1; j++) {
            if(cmp(elements+(j*size_element), elements+((j+1)*size_element)) > 0) {
                    memcpy(temp, elements+(j*size_element), size_element);
                    memcpy(elements+(j*size_element), elements+((j+1)*size_element), size_element);
                    memcpy(elements+((j+1)*size_element), temp, size_element);
            }
        }
    }
    free(temp);
}

int main() {
    // int array[] = {3, 10, 5, 1, 100, 44};
    // bubble_sort(array, 6, sizeof(int), int_cmp);

    char* str[] = {"Hello", "China", "Australia"};//char**
    bubble_sort(str, 3, sizeof(char*), str_cmp);


    //qsort(str,  3, sizeof(char*), str_cmp);
    for(int i = 0; i < 3; i++) {
        printf("%s ", str[i]);
    }
    puts("");
    
    return 0 ;
}