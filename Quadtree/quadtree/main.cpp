#include <iostream>
#include <string>
#include <sstream>
void ma_fonction(){

}

class ma_structure_t{
  protected:
    int x;
  public:
    ma_structure_t(int x0):x(x0){}
    int get_x() const{
      return x;
    }
};

int main(){
  ma_fonction();
  ma_structure_t s(7);
  std::cout << s.get_x() << std::endl;
  return 0;
}
