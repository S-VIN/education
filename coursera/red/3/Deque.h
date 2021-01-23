#include <vector>
#include <stdexcept>
using namespace std;

template <typename T>
struct Deque{
    vector<T> deqFront;
    vector<T> deqBack;
    //Deque(){}

    const bool Empty() const {
        return deqBack.empty() && deqFront.empty();
    }

    const int Size() const{
        return deqBack.size() + deqFront.size();
    }

    T& operator[](size_t index) {
        if(index < deqFront.size()){
            return deqFront[deqFront.size() - index - 1];
        }else{
            return deqBack[index - deqFront.size()];
        }
    }

    const T& operator[](size_t index) const {
        if(index < deqFront.size()){
            return deqFront[deqFront.size() - index - 1];
        }else{
            return deqBack[index - deqFront.size()];
        }
    }

    T& Front(){
        if(!deqFront.empty()) {
            return deqFront[deqFront.size() - 1];
        }else{
            return deqBack[0];
        }
    }

    const T& Front() const{
        if(!deqFront.empty()) {
            return deqFront[deqFront.size() - 1];
        }else{
            return deqBack[0];
        }
    }

    T& Back(){
        if(!deqBack.empty()) {
            return deqBack[deqBack.size() - 1];
        }else{
            return deqFront[0];
        }
    }

    const T& Back() const{
        if(!deqBack.empty()) {
            return deqBack[deqBack.size() - 1];
        }else{
            return deqFront[0];
        }
    }

    T& At(size_t index){
        if(index >= Size()){
            throw out_of_range("");
        }
        if(index < deqFront.size()){
            return deqFront[deqFront.size() - index - 1];
        }else{
            return deqBack[index - deqFront.size()];
        }
    }

    const T& At(size_t index) const{
        if(index >= Size()){
            throw out_of_range("");
        }
        if(index < deqFront.size()){
            return deqFront[deqFront.size() - index - 1];
        }else{
            return deqBack[index - deqFront.size()];
        }
    }

    void PushFront(T elem){
        deqFront.push_back(elem);
    }

    void PushBack(T elem){
        deqBack.push_back(elem);
    }

};