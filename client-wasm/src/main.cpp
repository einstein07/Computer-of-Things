#include "include/ComputerOfThings.h"
#include <iostream>
#include <fstream>
using namespace workpackage;
using namespace workpackage::response;
using namespace workpackage::request;
using namespace workpackage::common;

flatbuffers::FlatBufferBuilder buildOperationRequest();
void storeOnDisk(const flatbuffers::FlatBufferBuilder& builder, const std::string & fileName );
//const OperationRequest* deserializeWorkpackage(const std::string & fileName);


int main(){
    std::cout << "[INIT] Flatbuffers - Serializing workpackage. . ." << std::endl;

    flatbuffers::FlatBufferBuilder builder = buildOperationRequest();

    std::cout << "Done Serializing. Writing to file. . ." << std::endl;
    storeOnDisk(builder, "Workpackage.data");
        
    std::cout << "Done Writing to file. . . Will read from the file now. . ." << std::endl;

    const OperationRequest* request_ = deserializeWorkpackage("Workpackage.data");

    std::cout << "Work Package ID: " << request_ -> id() << " read from file. Processing. . ."<< std::endl;
    std::cout << "Matrix A: \n" 
              << request_ -> request_as_BivariateMatrixRequest() -> a_as_Matrix2D() -> elements() ->  Get(0) << " "
              << request_ -> request_as_BivariateMatrixRequest() -> a_as_Matrix2D() -> elements() ->  Get(1) << " " 
              << request_ -> request_as_BivariateMatrixRequest() -> a_as_Matrix2D() -> elements() ->  Get(2) << " " 
              << request_ -> request_as_BivariateMatrixRequest() -> a_as_Matrix2D() -> elements() ->  Get(3) << std::endl;
    
    std::cout << "Matrix B: \n" 
              << request_ -> request_as_BivariateMatrixRequest() -> b_as_Matrix2D() -> elements() ->  Get(0) << " "
              << request_ -> request_as_BivariateMatrixRequest() -> b_as_Matrix2D() -> elements() ->  Get(1) << " " 
              << request_ -> request_as_BivariateMatrixRequest() -> b_as_Matrix2D() -> elements() ->  Get(2) << " " 
              << request_ -> request_as_BivariateMatrixRequest() -> b_as_Matrix2D() -> elements() ->  Get(3) << std::endl;

    const OperationResponse* response_ = process_work_packages(request_);
    std::cout << "Workpackage processed: \n" 
              << "Response id: "<<response_ ->id() << "\n"
              << "Result: " << response_ -> response_as_MatrixResponse() -> response_as_Matrix2D() ->elements() ->  Get(0) << " "
              << response_ -> response_as_MatrixResponse() -> response_as_Matrix2D() ->elements() ->  Get(1) << " " 
              << response_ -> response_as_MatrixResponse() -> response_as_Matrix2D() ->elements() -> Get(2) << " " 
              << response_ -> response_as_MatrixResponse() -> response_as_Matrix2D() ->elements() -> Get(3) << std::endl;



}

flatbuffers::FlatBufferBuilder buildOperationRequest(){

	flatbuffers::FlatBufferBuilder builder(1024);
    long id = 1;
    Operation op_type = Operation_MULTIPLY;
    request::Request request_type = request::Request_BivariateMatrixRequest;
    //auto scalarRequest = CreateBivariateScalarRequest(builder, 2.5f, 0.5f);
    // Create matrices to query
    std::vector<float> elem_a;
    elem_a.push_back(1);elem_a.push_back(2);
    elem_a.push_back(3);elem_a.push_back(4);
    auto elements_a = builder.CreateVector(elem_a);
    auto matrix_a = CreateMatrix2D(builder, 2, 2, elements_a);
    std::vector<float> elem_b;
    elem_b.push_back(5);elem_b.push_back(10);
    elem_b.push_back(15);elem_b.push_back(20);
    auto elements_b = builder.CreateVector(elem_b);
    auto matrix_b = CreateMatrix2D(builder, 2, 2, elements_b);
    auto matrixRequest = CreateBivariateMatrixRequest(builder, Matrix::Matrix_Matrix2D, matrix_a.Union(), Matrix::Matrix_Matrix2D, matrix_b.Union());

    auto operationRequest = CreateOperationRequest(builder, id, op_type, request_type, matrixRequest.Union());
    builder.Finish(operationRequest);
	return builder;
}

void storeOnDisk(const flatbuffers::FlatBufferBuilder& builder, const std::string & fileName ){

	std::ofstream ofs(fileName, std::ofstream::binary);
	ofs.write((char*)builder.GetBufferPointer(), builder.GetSize());
	ofs.close();
}

/**const OperationRequest* deserializeWorkpackage(const std::string & fileName)
{
	std::ifstream infile;
	infile.open(fileName, std::ios::binary | std::ios::in);
	infile.seekg(0, std::ios::end);
	int length = infile.tellg();
	infile.seekg(0, std::ios::beg);
	char* data = new char[length];
	infile.read(data, length);
	infile.close();
	return flatbuffers::GetRoot<workpackage::OperationRequest>(data);
}*/