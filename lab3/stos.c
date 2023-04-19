#include <stdio.h>

#define N 100 // rozmiar stosu

int top = -1; // indeks wierzchołka stosu

int stack[N]; // tablica jednowymiarowa reprezentująca stos

int Stack__push(int number){
    if (top == N - 1) 
    {
        return -1; // zwracamy -1, jeśli stos jest pełny
    }
    else
    {
        top++; 
        stack[top] = number; 
        return 0;
    }
}

int Stack__pop(){
    if (top == -1) 
    {
        return -2; // zwracamy -2, jeśli stos jest pusty
    }
    else
    {
        int number = stack[top];
        top--; // zmniejszamy indeks wierzchołka stosu
        return number; 
    }
}

void Stack__print(){
    printf("Stos od gory: ");
    for (int i = top; i >= 0; i--)
    {
        printf("\n%d ", stack[i]);
    }
    printf("\n");
}

int temp_stack1[N];  // pomocniczy stos do przechowywania elementów o wartości maksymalnej
int temp_stack2[N];  // pomocniczy stos do przechowywania pozostałych elementów

void Stack__move_max_to_bottom() {
    int max_value = stack[0];

    
    for (int i = 1; i < N && stack[i] != 0; i++) {
        if (stack[i] > max_value) {
            max_value = stack[i];
        }
    }

    
    int temp_stack1_top = 0;
    for (int i = 0; i < N && stack[i] != 0; i++) {
        if (stack[i] == max_value) {
            temp_stack1[temp_stack1_top] = stack[i];
            temp_stack1_top++;
        }
    }

    
    int temp_stack2_top = 0;
    for (int i = 0; i < N && stack[i] != 0; i++) {
        if (stack[i] != max_value) {
            temp_stack2[temp_stack2_top] = stack[i];
            temp_stack2_top++;
        }
    }

    
    int stack_top = 0;
    for (int i = 0; i < temp_stack1_top; i++) {
        stack[stack_top] = temp_stack1[i];
        stack_top++;
    }
    for (int i = 0; i < temp_stack2_top; i++) {
        stack[stack_top] = temp_stack2[i];
        stack_top++;
    }
}

int main(){
    int result;
    result = Stack__push(1);
    result = Stack__push(6);
    result = Stack__push(7);
    result = Stack__push(2);
    result = Stack__push(3);
    result = Stack__push(6);
    result = Stack__push(4);
    Stack__print();
    result = Stack__pop();
    result = Stack__pop();
    Stack__print();
    result = Stack__push(7);
    Stack__print();
    Stack__move_max_to_bottom();
    Stack__print();
    return 0;
}