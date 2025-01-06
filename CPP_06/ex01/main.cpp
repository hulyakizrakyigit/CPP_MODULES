#include "Serializer.hpp"

int main() {
    Data *data =  new Data;
    data->name = "Hulya";
    data->id = 42;
    data->value = 42.42;

    std::cout << "Data: " << data << std::endl;
    uintptr_t serialized = Serializer::serialize(data);
    std::cout << "Serialized: " << serialized << std::endl;
    Data *deserialized = Serializer::deserialize(serialized);
    std::cout << "Deserialized: " << deserialized << std::endl;

    std::cout << "Name: " << deserialized->name << std::endl;
    std::cout << "ID: " << deserialized->id << std::endl;
    std::cout << "Value: " << deserialized->value << std::endl;

    delete data;

    return 0;
}