#include "Serialization.hpp"

int main() {
    Data *data = new Data;
    data->id = 123456789;
    data->name = "hello world";
    data->active = 0;

    uintptr_t serialize_data = Serializer::serialize(data);
    Data *deserialize_data = Serializer::deserialize(serialize_data);

    std::cout << "Uintptr Data: " << serialize_data << std::endl;
    std::cout << "Deserialize Data: " << deserialize_data->id << std::endl;
    std::cout << "Deserialize Data: " << deserialize_data->name << std::endl;
    std::cout << "Deserialize Data: " << deserialize_data->active << std::endl;
    

    return 0;
}  