#include "student_generated.h"
#include <iostream>
#include <fstream>
using namespace Person::Scholar;
flatbuffers::FlatBufferBuilder  buildStudent();
void storeOnDisk(const flatbuffers::FlatBufferBuilder& builder, const std::string & fileName );
const Student* deserializeStudent(const std::string & fileName);


int main(){
    std::cout << "[INIT] Flatbuffers - Serializing. . ." << std::endl;

    flatbuffers::FlatBufferBuilder builder = buildStudent();

    std::cout << "Done Serializing. Writing to file. . ." << std::endl;
    storeOnDisk(builder, "student_data.data");
        
    std::cout << "Done Writing to file. . . Will read from the file now. . ." << std::endl;

    const Student* student = deserializeStudent("student_data.data");

    std::cout << "Student name: " << student -> name() -> str() << std::endl;


}

flatbuffers::FlatBufferBuilder  buildStudent(){

	flatbuffers::FlatBufferBuilder builder(1024);
    auto name = builder.CreateString("Joe Mama");
    auto student_number = builder.CreateString("JM0001");
    auto date_of_birth = builder.CreateString("01-01-2005");
    auto course_one_name = builder.CreateString("Computer Science");
    auto course_two_name = builder.CreateString("Mathematics");
    std::vector<flatbuffers::Offset<flatbuffers::String>> courses_vector;
    courses_vector.push_back(course_one_name);
    courses_vector.push_back(course_two_name);
    auto courses = builder.CreateVector(courses_vector);

    auto student = CreateStudent(builder, name, student_number, date_of_birth, courses);

    builder.Finish(student);
	return builder;
}

void storeOnDisk(const flatbuffers::FlatBufferBuilder& builder, const std::string & fileName ){

	std::ofstream ofs(fileName, std::ofstream::binary);
	ofs.write((char*)builder.GetBufferPointer(), builder.GetSize());
	ofs.close();
}

const Student* deserializeStudent(const std::string & fileName)
{
	std::ifstream infile;
	infile.open(fileName, std::ios::binary | std::ios::in);
	infile.seekg(0, std::ios::end);
	int length = infile.tellg();
    std::cout << "length: " << length<<std::endl;
	infile.seekg(0, std::ios::beg);
	char* data = new char[length];
	infile.read(data, length);
	infile.close();
	return GetStudent(data);
}