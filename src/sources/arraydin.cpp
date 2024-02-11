#include "../header/arraydin.hpp"

template <typename T>
Arraydin<T>::Arraydin():data(nullptr),length(0){
};

template <typename T>
Arraydin<T>::~Arraydin(){
    delete[] this->data;
}   

template <typename T>
void Arraydin<T>::push_back(T value){
    T* newData = new T[(this->length)+1];
    for(int i=0;i<(this->length);i++){
        newData[i] = data[i];
    }
    newData[this->length] = value;
    delete[] this->data;
    this->data = newData;
    this->length++;
}

template <typename T>
int Arraydin<T>::size(){
    return this->length;
}

// // Default constructor for Arraydin<T>
// template <typename T>
// Arraydin<T>::Arraydin() : data(nullptr), length(0) {
//     // Initialize data to nullptr initially
// }

// // Specialized constructor for Arraydin<std::string>
// template <>
// Arraydin<std::string>::Arraydin() : data(nullptr), length(0) {
//     // Initialize data to nullptr for std::string specialization
// }

// // Specialized constructor for Arraydin<Langkah>
// template <>
// Arraydin<Langkah>::Arraydin() : data(nullptr), length(0) {
//     // Initialize data to nullptr for Langkah specialization
// }

// // Destructor for Arraydin<T>
// template <typename T>
// Arraydin<T>::~Arraydin() {
//     delete[] data;
// }

// // Specialized destructor for Arraydin<std::string>
// template <>
// Arraydin<std::string>::~Arraydin() {
//     delete[] data;
//     // Additional cleanup specific to std::string specialization
// }

// // Specialized destructor for Arraydin<Langkah>
// template <>
// Arraydin<Langkah>::~Arraydin() {
//     delete[] data;
//     // Additional cleanup specific to Langkah specialization
// }
