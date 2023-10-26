#include <list>
#include <iostream>

int main(){
    std::list<int*> li;
    li.push_back(new int{1});
    li.push_back(new int{2});
    li.push_back(new int{3});
    int* i{new int{2}};
    li.push_back(i);

    std::list<int*>::iterator it{li.begin()};
    for(; it!= li.end(); ++it){
        if(**it == 2){
            delete *it;
            it = li.erase(it);
        }
    }

    for(auto it : li){
        std::cout << *it << " ";
    } std::cout << '\n';
}