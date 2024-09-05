#include "Serializer.hpp"
#include "Data.hpp"

int main() {
	Data data;
	data.name = "test";

	uintptr_t serialized = Serializer::serialize(&data);
	std::cout << "Serialized value: " << serialized << std::endl;

	Data* deserializedData = Serializer::deserialize(serialized);
	if (deserializedData == &data)
	{
		std::cout << "Deserialization successful." << std::endl;
		std::cout << "Deserialized Data: name = " << deserializedData->name << std::endl;
	}
	else
	{
		std::cout << "Deserialization failed." << std::endl;
	}
}