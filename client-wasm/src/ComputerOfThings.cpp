#include "ComputerOfThings.h"
#include <iostream>
#include <fstream>
using namespace workpackage;
using namespace workpackage::response;
using namespace workpackage::common;
static int response_length = 0;
float add(float arg1, float arg2){
    return arg1 + arg2;
}

std::vector<float> add(const workpackage::common::Matrix2D* a, const workpackage::common::Matrix2D* b){
    std::vector<float> elem;
    float result[a -> n_rows()][a -> n_cols()];
    for (unsigned int i = 1; i <= a -> n_rows(); i++){
        for (unsigned int j = 1; j <= a -> n_cols(); j++){
            elem.push_back(a ->elements() -> Get(((j-1) * a->n_rows() + i)-1) + b ->elements() -> Get(((j-1) * a->n_rows() + i)-1));
        }
    }
    return elem;
}

float subtract(float arg1, float arg2){
    return arg1 - arg2;
}

std::vector<float> subtract(const workpackage::common::Matrix2D* a, const workpackage::common::Matrix2D* b){
    std::vector<float> elem;
    float result[a -> n_rows()][a -> n_cols()];
    for (unsigned int i = 1; i <= a -> n_rows(); i++){
        for (unsigned int j = 1; j <= a -> n_cols(); j++){
            elem.push_back(a ->elements() -> Get(((j-1) * a->n_rows() + i)-1) - b ->elements() -> Get(((j-1) * a->n_rows() + i)-1));
        }
    }
    return elem;
}

float mult(float arg1, float arg2){
    return arg1 * arg2;
}

std::vector<float> mult(const workpackage::common::Matrix2D* a, const workpackage::common::Matrix2D* b){
    std::vector<float> elem;
    for (unsigned int i = 1; i <= a -> n_rows(); i++){
        for (unsigned int j = 1; j <= b -> n_cols(); j++){
            float sum = 0.0f;
            for (unsigned int k = 1; k <= b -> n_rows(); k++){
                int index_b = (k-1) * a -> n_rows() + i;
                int index_a = (j-1) * b -> n_rows() + k;
                sum += a ->elements() -> Get(index_a-1) * b ->elements() -> Get(index_b-1);
            }
            
            elem.push_back(sum);
        }
    }
    return elem;
}


char* /**OperationResponse*/ processWorkPackages(/**const OperationRequest* request_*/char* data){
    //std::cout << "Converting byte array to operation request type pointer" << std::endl;
    const WorkpackageRequest* request_ = flatbuffers::GetRoot<workpackage::WorkpackageRequest>(data);
    //std::cout << "Done" << std::endl;
    long requestId_ = request_ -> id();
    Operation operation_ = request_ -> op_type();
    float responseValue = 0.0f;
    std::vector<float> elem;
    if (operation_ == Operation_ADD ){
        if (request_ -> request_type() == request::Request::Request_BivariateScalarRequest)
            responseValue = add(request_ -> request_as_BivariateScalarRequest() -> a(), request_ -> request_as_BivariateScalarRequest() -> b());
        else
            elem = add (request_ -> request_as_BivariateMatrixRequest() -> a_as_Matrix2D(), request_ -> request_as_BivariateMatrixRequest() -> b_as_Matrix2D());
    }
    else if (operation_ == Operation_SUBTRACT){
        if (request_ -> request_type() == request::Request::Request_BivariateScalarRequest)
            responseValue = subtract(request_ -> request_as_BivariateScalarRequest() -> a(), request_ -> request_as_BivariateScalarRequest() -> b());
        else
            elem =  subtract (request_ -> request_as_BivariateMatrixRequest() -> a_as_Matrix2D(), request_ -> request_as_BivariateMatrixRequest() -> b_as_Matrix2D());

    }
    else{
        if (request_ -> request_type() == request::Request::Request_BivariateScalarRequest)
            responseValue = mult(request_ -> request_as_BivariateScalarRequest() -> a(), request_ -> request_as_BivariateScalarRequest() -> b());
        else
            elem =  mult (request_ -> request_as_BivariateMatrixRequest() -> a_as_Matrix2D(), request_ -> request_as_BivariateMatrixRequest() -> b_as_Matrix2D());
    }
    	
    flatbuffers::FlatBufferBuilder builder(1024);
    if (request_ -> request_type() == request::Request::Request_BivariateScalarRequest){
        auto scalarResponse = CreateScalarResponse(builder, responseValue);
        auto response_ = CreateWorkpackageResponse(builder, requestId_,  Reponse::Reponse_ScalarResponse , scalarResponse.Union());
        builder.Finish(response_);
        response_length = builder.GetSize();
        //std::cout << "response length: " << response_length <<std::endl;
        return (char*)builder.GetBufferPointer();
        //return flatbuffers::GetRoot<workpackage::OperationResponse>(builder.GetBufferPointer());
    }
    else{
        auto elements = builder.CreateVector(elem);
        auto matrix2D = CreateMatrix2D(builder, 2, 2, elements);
        auto matrixResponse = CreateMatrixResponse(builder, Matrix::Matrix_Matrix2D, matrix2D.Union());
        auto response_ = CreateWorkpackageResponse(builder, requestId_,  Reponse::Reponse_MatrixResponse , matrixResponse.Union());
        builder.Finish(response_);
        response_length = builder.GetSize();
        //std::cout << "response length: " << response_length <<std::endl;
        return (char*)builder.GetBufferPointer();
        
        //return flatbuffers::GetRoot<workpackage::OperationResponse>(builder.GetBufferPointer());
    }
    
}

char* deserializeWorkpackage(const std::string & fileName){
	std::ifstream infile;
	infile.open(fileName, std::ios::binary | std::ios::in);
	infile.seekg(0, std::ios::end);
	int length = infile.tellg();
	infile.seekg(0, std::ios::beg);
	char* data = new char[length];
	infile.read(data, length);
    //std::cout << "Length: " << length << std::endl;
	infile.close();
	return data;
}

int getResponseLength(){
    return response_length;
}


