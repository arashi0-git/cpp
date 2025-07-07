#include "Serialization.hpp"

Serializer::Serializer()
{
	std::cout << "Serializer Default Constructor called" << std::endl;
}

Serializer::Serializer(const Serializer &src)
{
	std::cout << "Serializer Copy Constructor called" << std::endl;
	*this = src;
}

Serializer::~Serializer()
{
	std::cout << "Serializer Deconstructor called" << std::endl;
}

Serializer &Serializer::operator=(const Serializer &src)
{
	std::cout << "Serializer Assignation operator called" << std::endl;
	if (this == &src)
		return *this;

	return *this;
}

uintptr_t Serializer::serialize(Data *data){
    return reinterpret_cast<uintptr_t>(data);
}

Data *Serializer::deserialize(uintptr_t serialized_data) {
    return reinterpret_cast<Data*>(serialized_data);
}