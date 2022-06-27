#include "include/ComputerOfThings.h"
using namespace workpackage;
using namespace workpackage::response;
using namespace workpackage::common;

float add(float arg1, float arg2){
    return arg1 + arg2;
}

float subtract(float arg1, float arg2){
    return arg1 - arg2;
}

std::vector<flatbuffers::Offset<float>> mult(const workpackage::common::Matrix2D* a, const workpackage::common::Matrix2D* b){
    std::vector<flatbuffers::Offset<float>> elem;
    //flatbuffers::Offset<flatbuffers::Vector<float>> elements;
    float result[a -> n_rows()][a -> n_cols()];
    for (unsigned int i = 1; i <= a -> n_rows(); i++){
        for (unsigned int j = 1; j <= b -> n_cols(); j++){
            float sum = 0.0f;
            for (unsigned int k = 1; k <= b -> n_rows(); k++){
                sum += a ->elements() -> Get((k-1) * a -> n_rows() + i) * b ->elements() -> Get((j-1) * b -> n_rows() + k);
            }
            elem.push_back(sum);
        }
    }
    return elem;
}


uint8_t* process_work_packages(OperationRequest* request){
    requestId_ = request -> id();
    operation_ = request -> op_type();
    float responseValue = 0.0f;
    std::vector<flatbuffers::Offset<float>> elem;
    if (operation_ == Operation_ADD ){
        responseValue = add(request -> request_as_BivariateScalarRequest() -> a(), request -> request_as_BivariateScalarRequest() -> b());
    }
    else if (operation_ == Operation_SUBTRACT){
        responseValue = subtract(request -> request_as_BivariateScalarRequest() -> a(), request -> request_as_BivariateScalarRequest() -> b());
    }
    else{
        elem =  mult (request -> request_as_BivariateMatrixRequest() -> a_as_Matrix2D(), request -> request_as_BivariateMatrixRequest() -> b_as_Matrix2D());
    }
    	
    flatbuffers::FlatBufferBuilder builder(1024);
    if (operation_ == Operation_MULTIPLY){
        auto elements = builder.CreateVector(elem);
        auto matrixResponse = CreateMatrixResponse(builder, Matrix::Matrix_Matrix2D, elements.Union());
        auto response = CreateOperationResponse(builder, requestId_, operation_,  Reponse::Reponse_MatrixResponse , matrixResponse.Union());
        return  builder.GetBufferPointer();
    }
    else{
        auto scalarResponse = CreateScalarResponse(builder, responseValue);
        auto response = CreateOperationResponse(builder, requestId_, operation_,  Reponse::Reponse_ScalarResponse , scalarResponse.Union());
        return  builder.GetBufferPointer();
    }
    
}



